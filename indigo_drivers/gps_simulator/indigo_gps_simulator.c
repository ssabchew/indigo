// Copyright (c) 2017 Rumen G. Bogdanovski
// All rights reserved.
//
// You can use this software under the terms of 'INDIGO Astronomy
// open-source license' (see LICENSE.md).
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHORS 'AS IS' AND ANY EXPRESS
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


// version history
// 2.0 by Rumen G. Bogdanovski

/** INDIGO GPS Simulator driver
 \file indigo_gps_simulator.c
 */

#define DRIVER_VERSION 0x0002
#define DRIVER_NAME	"idnigo_gps_simulator"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <assert.h>

#include "indigo_driver_xml.h"
#include "indigo_gps_simulator.h"

/* Sumulator uses coordinates of AO Belogradchik */
#define SIM_LONGITUDE 22.675
#define SIM_LATITUDE 43.625
#define SIM_ELEVATION 650

#define REFRESH_SECONDS (1.0)
#define TICKS_TO_2D_FIX    10
#define TICKS_TO_3D_FIX    20


#define PRIVATE_DATA        ((simulator_private_data *)device->private_data)

// gp_bits is used as boolean
#define is_connected                   gp_bits

typedef struct {
	int count_open;
	int timer_ticks;
	indigo_timer *gps_timer;
} simulator_private_data;

// -------------------------------------------------------------------------------- INDIGO GPS device implementation

static bool gps_open(indigo_device *device) {
	if (device->is_connected) return false;
	if (PRIVATE_DATA->count_open++ == 0) {
		srand(time(NULL));
		PRIVATE_DATA->timer_ticks = 0;
	}
	return true;
}


static void gps_close(indigo_device *device) {
	if (!device->is_connected) return;
	if (--PRIVATE_DATA->count_open == 0) {
		PRIVATE_DATA->timer_ticks = 0;
	}
}


static void gps_timer_callback(indigo_device *device) {
	int res;
	double ra, dec, lon, lat;

	if (PRIVATE_DATA->timer_ticks >= TICKS_TO_2D_FIX) {
		GPS_GEOGRAPHIC_COORDINATES_LONGITUDE_ITEM->number.value = SIM_LONGITUDE + rand() / ((double)(RAND_MAX)*1000);
		GPS_GEOGRAPHIC_COORDINATES_LATITUDE_ITEM->number.value = SIM_LATITUDE + rand() / ((double)(RAND_MAX)*1000);
		GPS_GEOGRAPHIC_COORDINATES_ELEVATION_ITEM->number.value = (int)(SIM_ELEVATION + 0.5 + (double)(rand())/RAND_MAX);
		GPS_GEOGRAPHIC_COORDINATES_ACCURACY_ITEM->number.value = (int)(5 + 0.5 + (double)(rand())/RAND_MAX);
		time_t ttime = time(NULL);
		indigo_timetoiso(ttime, GPS_UTC_ITEM->text.value, INDIGO_VALUE_SIZE);

		if (PRIVATE_DATA->timer_ticks == TICKS_TO_2D_FIX) {
			GPS_STATUS_HAVE_VALID_FIX_ITEM->light.value = INDIGO_BUSY_STATE;
			GPS_STATUS_PROPERTY->state = INDIGO_BUSY_STATE;
			indigo_update_property(device, GPS_STATUS_PROPERTY, "2D Fix");
		}

		if (PRIVATE_DATA->timer_ticks == TICKS_TO_3D_FIX) {
			GPS_STATUS_HAVE_VALID_FIX_ITEM->light.value = INDIGO_OK_STATE;
			GPS_STATUS_PROPERTY->state = INDIGO_OK_STATE;
			indigo_update_property(device, GPS_STATUS_PROPERTY, "3D Fix, position is valid");
			GPS_GEOGRAPHIC_COORDINATES_PROPERTY->state = INDIGO_OK_STATE;
			GPS_UTC_TIME_PROPERTY->state = INDIGO_OK_STATE;
		}

		indigo_update_property(device, GPS_GEOGRAPHIC_COORDINATES_PROPERTY, NULL);
		indigo_update_property(device, GPS_UTC_TIME_PROPERTY, NULL);
	} else {
		GPS_GEOGRAPHIC_COORDINATES_LONGITUDE_ITEM->number.value = 0;
		GPS_GEOGRAPHIC_COORDINATES_LATITUDE_ITEM->number.value = 0;
		GPS_GEOGRAPHIC_COORDINATES_ELEVATION_ITEM->number.value = 0;
		GPS_GEOGRAPHIC_COORDINATES_ACCURACY_ITEM->number.value = 0;
		GPS_GEOGRAPHIC_COORDINATES_PROPERTY->state = INDIGO_BUSY_STATE;
		indigo_update_property(device, GPS_GEOGRAPHIC_COORDINATES_PROPERTY, NULL);
		time_t ttime = 0;
		GPS_UTC_TIME_PROPERTY->state = INDIGO_BUSY_STATE;
		indigo_timetoiso(ttime, GPS_UTC_ITEM->text.value, INDIGO_VALUE_SIZE);
		indigo_update_property(device, GPS_UTC_TIME_PROPERTY, NULL);

		if (PRIVATE_DATA->timer_ticks == 0) {
			GPS_STATUS_HAVE_VALID_FIX_ITEM->light.value = INDIGO_ALERT_STATE;
			GPS_STATUS_PROPERTY->state = INDIGO_BUSY_STATE;
			indigo_update_property(device, GPS_STATUS_PROPERTY, "No position fix");
		}
	}

	PRIVATE_DATA->timer_ticks++;
	indigo_reschedule_timer(device, REFRESH_SECONDS, &PRIVATE_DATA->gps_timer);
}


static indigo_result gps_attach(indigo_device *device) {
	assert(device != NULL);
	assert(PRIVATE_DATA != NULL);
	if (indigo_gps_attach(device, DRIVER_VERSION) == INDIGO_OK) {
		SIMULATION_PROPERTY->hidden = true;
		DEVICE_PORT_PROPERTY->hidden = true;
		DEVICE_PORTS_PROPERTY->hidden = true;
		GPS_GEOGRAPHIC_COORDINATES_PROPERTY->hidden = false;
		GPS_GEOGRAPHIC_COORDINATES_PROPERTY->count = 4;
		GPS_UTC_TIME_PROPERTY->hidden = false;
		GPS_UTC_TIME_PROPERTY->count = 1;

		INDIGO_DRIVER_LOG(DRIVER_NAME, "%s attached", device->name);
		return indigo_gps_enumerate_properties(device, NULL, NULL);
	}
	return INDIGO_FAILED;
}


static indigo_result gps_change_property(indigo_device *device, indigo_client *client, indigo_property *property) {
	assert(device != NULL);
	assert(DEVICE_CONTEXT != NULL);
	assert(property != NULL);
	// -------------------------------------------------------------------------------- CONNECTION
	if (indigo_property_match(CONNECTION_PROPERTY, property)) {
		indigo_property_copy_values(CONNECTION_PROPERTY, property, false);
		if (CONNECTION_CONNECTED_ITEM->sw.value) {
			if (!device->is_connected) {
				if (gps_open(device)) {
					CONNECTION_PROPERTY->state = INDIGO_OK_STATE;
					device->is_connected = true;
					/* start updates */
					PRIVATE_DATA->gps_timer = indigo_set_timer(device, 0, gps_timer_callback);
				} else {
					CONNECTION_PROPERTY->state = INDIGO_ALERT_STATE;
					indigo_set_switch(CONNECTION_PROPERTY, CONNECTION_DISCONNECTED_ITEM, true);
				}
			}
		} else {
			if (device->is_connected) {
				indigo_cancel_timer(device, &PRIVATE_DATA->gps_timer);
				gps_close(device);
				device->is_connected = false;
				CONNECTION_PROPERTY->state = INDIGO_OK_STATE;
			}
		}
	}
	return indigo_gps_change_property(device, client, property);
}


static indigo_result gps_detach(indigo_device *device) {
	assert(device != NULL);
	if (CONNECTION_CONNECTED_ITEM->sw.value)
		indigo_device_disconnect(NULL, device->name);
	indigo_cancel_timer(device, &PRIVATE_DATA->gps_timer);

	INDIGO_DRIVER_LOG(DRIVER_NAME, "%s detached", device->name);
	return indigo_gps_detach(device);
}

// --------------------------------------------------------------------------------

static simulator_private_data *private_data = NULL;

static indigo_device *gps = NULL;

indigo_result indigo_gps_simulator(indigo_driver_action action, indigo_driver_info *info) {
	static indigo_device gps_template = {
		GPS_SIMULATOR_NAME, false, 0, NULL, NULL, INDIGO_OK, INDIGO_VERSION_CURRENT,
		gps_attach,
		indigo_gps_enumerate_properties,
		gps_change_property,
		NULL,
		gps_detach
	};

	static indigo_driver_action last_action = INDIGO_DRIVER_SHUTDOWN;

	SET_DRIVER_INFO(info, "GPS Simulator", __FUNCTION__, DRIVER_VERSION, last_action);

	if (action == last_action)
		return INDIGO_OK;

	switch (action) {
	case INDIGO_DRIVER_INIT:
		last_action = action;
		private_data = malloc(sizeof(simulator_private_data));
		assert(private_data != NULL);
		memset(private_data, 0, sizeof(simulator_private_data));
		private_data->count_open = 0;
		gps = malloc(sizeof(indigo_device));
		assert(gps != NULL);
		memcpy(gps, &gps_template, sizeof(indigo_device));
		gps->private_data = private_data;
		indigo_attach_device(gps);
		break;

	case INDIGO_DRIVER_SHUTDOWN:
		last_action = action;
		if (gps != NULL) {
			indigo_detach_device(gps);
			free(gps);
			gps = NULL;
		}
		if (private_data != NULL) {
			free(private_data);
			private_data = NULL;
		}
		break;

	case INDIGO_DRIVER_INFO:
		break;
	}

	return INDIGO_OK;
}
