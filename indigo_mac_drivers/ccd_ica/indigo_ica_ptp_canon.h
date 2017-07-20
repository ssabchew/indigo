//
//  indigo_ica_canon.h
//  IndigoApps
//
//  Created by Peter Polakovic on 11/07/2017.
//  Copyright © 2017 CloudMakers, s. r. o. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "indigo_ica_ptp.h"

enum PTPCanonOperationCodeEnum {
  PTPRequestCodeCanonGetStorageIDs = 0x9101,
  PTPRequestCodeCanonGetStorageInfo = 0x9102,
  PTPRequestCodeCanonGetObjectInfo = 0x9103,
  PTPRequestCodeCanonGetObject = 0x9104,
  PTPRequestCodeCanonDeleteObject = 0x9105,
  PTPRequestCodeCanonFormatStore = 0x9106,
  PTPRequestCodeCanonGetPartialObject = 0x9107,
  PTPRequestCodeCanonGetDeviceInfoEx = 0x9108,
  PTPRequestCodeCanonGetObjectInfoEx = 0x9109,
  PTPRequestCodeCanonGetThumbEx = 0x910A,
  PTPRequestCodeCanonSendPartialObject = 0x910B,
  PTPRequestCodeCanonSetObjectAttributes = 0x910C,
  PTPRequestCodeCanonGetObjectTime = 0x910D,
  PTPRequestCodeCanonSetObjectTime = 0x910E,
  PTPRequestCodeCanonRemoteRelease = 0x910F,
  PTPRequestCodeCanonSetDevicePropValueEx = 0x9110,
  PTPRequestCodeCanonGetRemoteMode = 0x9113,
  PTPRequestCodeCanonSetRemoteMode = 0x9114,
  PTPRequestCodeCanonSetEventMode = 0x9115,
  PTPRequestCodeCanonGetEvent = 0x9116,
  PTPRequestCodeCanonTransferComplete = 0x9117,
  PTPRequestCodeCanonCancelTransfer = 0x9118,
  PTPRequestCodeCanonResetTransfer = 0x9119,
  PTPRequestCodeCanonPCHDDCapacity = 0x911A,
  PTPRequestCodeCanonSetUILock = 0x911B,
  PTPRequestCodeCanonResetUILock = 0x911C,
  PTPRequestCodeCanonKeepDeviceOn = 0x911D,
  PTPRequestCodeCanonSetNullPacketMode = 0x911E,
  PTPRequestCodeCanonUpdateFirmware = 0x911F,
  PTPRequestCodeCanonTransferCompleteDT = 0x9120,
  PTPRequestCodeCanonCancelTransferDT = 0x9121,
  PTPRequestCodeCanonSetWftProfile = 0x9122,
  PTPRequestCodeCanonGetWftProfile = 0x9123,
  PTPRequestCodeCanonSetProfileToWft = 0x9124,
  PTPRequestCodeCanonBulbStart = 0x9125,
  PTPRequestCodeCanonBulbEnd = 0x9126,
  PTPRequestCodeCanonRequestDevicePropValue = 0x9127,
  PTPRequestCodeCanonRemoteReleaseOn = 0x9128,
  PTPRequestCodeCanonRemoteReleaseOff = 0x9129,
  PTPRequestCodeCanonRegistBackgroundImage = 0x912A,
  PTPRequestCodeCanonChangePhotoStudioMode = 0x912B,
  PTPRequestCodeCanonGetPartialObjectEx = 0x912C,
  PTPRequestCodeCanonResetMirrorLockupState = 0x9130,
  PTPRequestCodeCanonPopupBuiltinFlash = 0x9131,
  PTPRequestCodeCanonEndGetPartialObjectEx = 0x9132,
  PTPRequestCodeCanonMovieSelectSWOn = 0x9133,
  PTPRequestCodeCanonMovieSelectSWOff = 0x9134,
  PTPRequestCodeCanonGetCTGInfo = 0x9135,
  PTPRequestCodeCanonGetLensAdjust = 0x9136,
  PTPRequestCodeCanonSetLensAdjust = 0x9137,
  PTPRequestCodeCanonGetMusicInfo = 0x9138,
  PTPRequestCodeCanonCreateHandle = 0x9139,
  PTPRequestCodeCanonSendPartialObjectEx = 0x913A,
  PTPRequestCodeCanonEndSendPartialObjectEx = 0x913B,
  PTPRequestCodeCanonSetCTGInfo = 0x913C,
  PTPRequestCodeCanonSetRequestOLCInfoGroup = 0x913D,
  PTPRequestCodeCanonSetRequestRollingPitchingLevel = 0x913E,
  PTPRequestCodeCanonGetCameraSupport = 0x913F,
  PTPRequestCodeCanonSetRating = 0x9140,
  PTPRequestCodeCanonRequestInnerDevelopStart = 0x9141,
  PTPRequestCodeCanonRequestInnerDevelopParamChange = 0x9142,
  PTPRequestCodeCanonRequestInnerDevelopEnd = 0x9143,
  PTPRequestCodeCanonGpsLoggingDataMode = 0x9144,
  PTPRequestCodeCanonGetGpsLogCurrentHandle = 0x9145,
  PTPRequestCodeCanonInitiateViewfinder = 0x9151,
  PTPRequestCodeCanonTerminateViewfinder = 0x9152,
  PTPRequestCodeCanonGetViewFinderData = 0x9153,
  PTPRequestCodeCanonDoAf = 0x9154,
  PTPRequestCodeCanonDriveLens = 0x9155,
  PTPRequestCodeCanonDepthOfFieldPreview = 0x9156,
  PTPRequestCodeCanonClickWB = 0x9157,
  PTPRequestCodeCanonZoom = 0x9158,
  PTPRequestCodeCanonZoomPosition = 0x9159,
  PTPRequestCodeCanonSetLiveAfFrame = 0x915A,
  PTPRequestCodeCanonTouchAfPosition = 0x915B,
  PTPRequestCodeCanonSetLvPcFlavoreditMode = 0x915C,
  PTPRequestCodeCanonSetLvPcFlavoreditParam = 0x915D,
  PTPRequestCodeCanonAfCancel = 0x9160,
  PTPRequestCodeCanonSetDefaultCameraSetting = 0x91BE,
  PTPRequestCodeCanonGetAEData = 0x91BF,
  PTPRequestCodeCanonNotifyNetworkError = 0x91E8,
  PTPRequestCodeCanonAdapterTransferProgress = 0x91E9,
  PTPRequestCodeCanonTransferComplete2 = 0x91F0,
  PTPRequestCodeCanonCancelTransfer2 = 0x91F1,
  PTPRequestCodeCanonFAPIMessageTX = 0x91FE,
  PTPRequestCodeCanonFAPIMessageRX = 0x91FF
};

enum PTPCanonResponseCodeEnum {
  PTPResponseCodeCanonUnknownCommand = 0xA001,
  PTPResponseCodeCanonOperationRefused = 0xA005,
  PTPResponseCodeCanonLensCover = 0xA006,
  PTPResponseCodeCanonBatteryLow = 0xA101,
  PTPResponseCodeCanonNotReady = 0xA102
};

enum PTPCanonEventCodeEnum {
  PTPEventCodeCanonRequestGetEvent = 0xC101,
  PTPEventCodeCanonObjectAddedEx = 0xC181,
  PTPEventCodeCanonObjectRemoved = 0xC182,
  PTPEventCodeCanonRequestGetObjectInfoEx = 0xC183,
  PTPEventCodeCanonStorageStatusChanged = 0xC184,
  PTPEventCodeCanonStorageInfoChanged = 0xC185,
  PTPEventCodeCanonRequestObjectTransfer = 0xC186,
  PTPEventCodeCanonObjectInfoChangedEx = 0xC187,
  PTPEventCodeCanonObjectContentChanged = 0xC188,
  PTPEventCodeCanonPropValueChanged = 0xC189,
  PTPEventCodeCanonAvailListChanged = 0xC18A,
  PTPEventCodeCanonCameraStatusChanged = 0xC18B,
  PTPEventCodeCanonWillSoonShutdown = 0xC18D,
  PTPEventCodeCanonShutdownTimerUpdated = 0xC18E,
  PTPEventCodeCanonRequestCancelTransfer = 0xC18F,
  PTPEventCodeCanonRequestObjectTransferDT = 0xC190,
  PTPEventCodeCanonRequestCancelTransferDT = 0xC191,
  PTPEventCodeCanonStoreAdded = 0xC192,
  PTPEventCodeCanonStoreRemoved = 0xC193,
  PTPEventCodeCanonBulbExposureTime = 0xC194,
  PTPEventCodeCanonRecordingTime = 0xC195,
  PTPEventCodeCanonRequestObjectTransferTS = 0xC1A2,
  PTPEventCodeCanonAfResult = 0xC1A3,
  PTPEventCodeCanonCTGInfoCheckComplete = 0xC1A4,
  PTPEventCodeCanonOLCInfoChanged = 0xC1A5,
  PTPEventCodeCanonRequestObjectTransferFTP = 0xC1F1
};

enum PTPCanonPropertyCode {
  PTPPropertyCodeCanonAperture = 0xD101,
  PTPPropertyCodeCanonShutterSpeed = 0xD102,
  PTPPropertyCodeCanonISOSpeed = 0xD103,
  PTPPropertyCodeCanonExpCompensation = 0xD104,
  PTPPropertyCodeCanonAutoExposureMode = 0xD105,
  PTPPropertyCodeCanonDriveMode = 0xD106,
  PTPPropertyCodeCanonMeteringMode = 0xD107,
  PTPPropertyCodeCanonFocusMode = 0xD108,
  PTPPropertyCodeCanonWhiteBalance = 0xD109,
  PTPPropertyCodeCanonColorTemperature = 0xD10A,
  PTPPropertyCodeCanonWhiteBalanceAdjustA = 0xD10B,
  PTPPropertyCodeCanonWhiteBalanceAdjustB = 0xD10C,
  PTPPropertyCodeCanonWhiteBalanceXA = 0xD10D,
  PTPPropertyCodeCanonWhiteBalanceXB = 0xD10E,
  PTPPropertyCodeCanonColorSpace = 0xD10F,
  PTPPropertyCodeCanonPictureStyle = 0xD110,
  PTPPropertyCodeCanonBatteryPower = 0xD111,
  PTPPropertyCodeCanonBatterySelect = 0xD112,
  PTPPropertyCodeCanonCameraTime = 0xD113,
  PTPPropertyCodeCanonAutoPowerOff = 0xD114,
  PTPPropertyCodeCanonOwner = 0xD115,
  PTPPropertyCodeCanonModelID = 0xD116,
  PTPPropertyCodeCanonPTPExtensionVersion = 0xD119,
  PTPPropertyCodeCanonDPOFVersion = 0xD11A,
  PTPPropertyCodeCanonAvailableShots = 0xD11B,
  PTPPropertyCodeCanonCaptureDestination = 0xD11C,
  PTPPropertyCodeCanonBracketMode = 0xD11D,
  PTPPropertyCodeCanonCurrentStorage = 0xD11E,
  PTPPropertyCodeCanonCurrentFolder = 0xD11F,
  PTPPropertyCodeCanonImageFormat = 0xD120	,
  PTPPropertyCodeCanonImageFormatCF = 0xD121	,
  PTPPropertyCodeCanonImageFormatSD = 0xD122	,
  PTPPropertyCodeCanonImageFormatExtHD = 0xD123	,
  PTPPropertyCodeCanonCompressionS = 0xD130,
  PTPPropertyCodeCanonCompressionM1 = 0xD131,
  PTPPropertyCodeCanonCompressionM2 = 0xD132,
  PTPPropertyCodeCanonCompressionL = 0xD133,
  PTPPropertyCodeCanonAEModeDial = 0xD138,
  PTPPropertyCodeCanonAEModeCustom = 0xD139,
  PTPPropertyCodeCanonMirrorUpSetting = 0xD13A,
  PTPPropertyCodeCanonHighlightTonePriority = 0xD13B,
  PTPPropertyCodeCanonAFSelectFocusArea = 0xD13C,
  PTPPropertyCodeCanonHDRSetting = 0xD13D,
  PTPPropertyCodeCanonPCWhiteBalance1 = 0xD140,
  PTPPropertyCodeCanonPCWhiteBalance2 = 0xD141,
  PTPPropertyCodeCanonPCWhiteBalance3 = 0xD142,
  PTPPropertyCodeCanonPCWhiteBalance4 = 0xD143,
  PTPPropertyCodeCanonPCWhiteBalance5 = 0xD144,
  PTPPropertyCodeCanonMWhiteBalance = 0xD145,
  PTPPropertyCodeCanonMWhiteBalanceEx = 0xD146,
  PTPPropertyCodeCanonUnknownPropD14D = 0xD14D  ,
  PTPPropertyCodeCanonPictureStyleStandard = 0xD150,
  PTPPropertyCodeCanonPictureStylePortrait = 0xD151,
  PTPPropertyCodeCanonPictureStyleLandscape = 0xD152,
  PTPPropertyCodeCanonPictureStyleNeutral = 0xD153,
  PTPPropertyCodeCanonPictureStyleFaithful = 0xD154,
  PTPPropertyCodeCanonPictureStyleBlackWhite = 0xD155,
  PTPPropertyCodeCanonPictureStyleAuto = 0xD156,
  PTPPropertyCodeCanonPictureStyleUserSet1 = 0xD160,
  PTPPropertyCodeCanonPictureStyleUserSet2 = 0xD161,
  PTPPropertyCodeCanonPictureStyleUserSet3 = 0xD162,
  PTPPropertyCodeCanonPictureStyleParam1 = 0xD170,
  PTPPropertyCodeCanonPictureStyleParam2 = 0xD171,
  PTPPropertyCodeCanonPictureStyleParam3 = 0xD172,
  PTPPropertyCodeCanonHighISOSettingNoiseReduction = 0xD178,
  PTPPropertyCodeCanonMovieServoAF = 0xD179,
  PTPPropertyCodeCanonContinuousAFValid = 0xD17A,
  PTPPropertyCodeCanonAttenuator = 0xD17B,
  PTPPropertyCodeCanonUTCTime = 0xD17C,
  PTPPropertyCodeCanonTimezone = 0xD17D,
  PTPPropertyCodeCanonSummertime = 0xD17E,
  PTPPropertyCodeCanonFlavorLUTParams = 0xD17F,
  PTPPropertyCodeCanonCustomFunc1 = 0xD180,
  PTPPropertyCodeCanonCustomFunc2 = 0xD181,
  PTPPropertyCodeCanonCustomFunc3 = 0xD182,
  PTPPropertyCodeCanonCustomFunc4 = 0xD183,
  PTPPropertyCodeCanonCustomFunc5 = 0xD184,
  PTPPropertyCodeCanonCustomFunc6 = 0xD185,
  PTPPropertyCodeCanonCustomFunc7 = 0xD186,
  PTPPropertyCodeCanonCustomFunc8 = 0xD187,
  PTPPropertyCodeCanonCustomFunc9 = 0xD188,
  PTPPropertyCodeCanonCustomFunc10 = 0xD189,
  PTPPropertyCodeCanonCustomFunc11 = 0xD18a,
  PTPPropertyCodeCanonCustomFunc12 = 0xD18b,
  PTPPropertyCodeCanonCustomFunc13 = 0xD18c,
  PTPPropertyCodeCanonCustomFunc14 = 0xD18d,
  PTPPropertyCodeCanonCustomFunc15 = 0xD18e,
  PTPPropertyCodeCanonCustomFunc16 = 0xD18f,
  PTPPropertyCodeCanonCustomFunc17 = 0xD190,
  PTPPropertyCodeCanonCustomFunc18 = 0xD191,
  PTPPropertyCodeCanonCustomFunc19 = 0xD192,
  PTPPropertyCodeCanonInnerDevelop = 0xD193,
  PTPPropertyCodeCanonMultiAspect = 0xD194,
  PTPPropertyCodeCanonMovieSoundRecord = 0xD195,
  PTPPropertyCodeCanonMovieRecordVolume = 0xD196,
  PTPPropertyCodeCanonWindCut = 0xD197,
  PTPPropertyCodeCanonExtenderType = 0xD198,
  PTPPropertyCodeCanonOLCInfoVersion = 0xD199,
  PTPPropertyCodeCanonUnknownPropD19A = 0xD19A ,
  PTPPropertyCodeCanonUnknownPropD19C = 0xD19C ,
  PTPPropertyCodeCanonUnknownPropD19D = 0xD19D ,
  PTPPropertyCodeCanonCustomFuncEx = 0xD1a0,
  PTPPropertyCodeCanonMyMenu = 0xD1a1,
  PTPPropertyCodeCanonMyMenuList = 0xD1a2,
  PTPPropertyCodeCanonWftStatus = 0xD1a3,
  PTPPropertyCodeCanonWftInputTransmission = 0xD1a4,
  PTPPropertyCodeCanonHDDirectoryStructure = 0xD1a5,
  PTPPropertyCodeCanonBatteryInfo = 0xD1a6,
  PTPPropertyCodeCanonAdapterInfo = 0xD1a7,
  PTPPropertyCodeCanonLensStatus = 0xD1a8,
  PTPPropertyCodeCanonQuickReviewTime = 0xD1a9,
  PTPPropertyCodeCanonCardExtension = 0xD1aa,
  PTPPropertyCodeCanonTempStatus = 0xD1ab,
  PTPPropertyCodeCanonShutterCounter = 0xD1ac,
  PTPPropertyCodeCanonSpecialOption = 0xD1ad,
  PTPPropertyCodeCanonPhotoStudioMode = 0xD1ae,
  PTPPropertyCodeCanonSerialNumber = 0xD1af,
  PTPPropertyCodeCanonEVFOutputDevice = 0xD1b0,
  PTPPropertyCodeCanonEVFMode = 0xD1b1,
  PTPPropertyCodeCanonDepthOfFieldPreview = 0xD1b2,
  PTPPropertyCodeCanonEVFSharpness = 0xD1b3,
  PTPPropertyCodeCanonEVFWBMode = 0xD1b4,
  PTPPropertyCodeCanonEVFClickWBCoeffs = 0xD1b5,
  PTPPropertyCodeCanonEVFColorTemp = 0xD1b6,
  PTPPropertyCodeCanonExposureSimMode = 0xD1b7,
  PTPPropertyCodeCanonEVFRecordStatus = 0xD1b8,
  PTPPropertyCodeCanonLvAfSystem = 0xD1ba,
  PTPPropertyCodeCanonMovSize = 0xD1bb,
  PTPPropertyCodeCanonLvViewTypeSelect = 0xD1bc,
  PTPPropertyCodeCanonMirrorDownStatus = 0xD1bd,
  PTPPropertyCodeCanonMovieParam = 0xD1be,
  PTPPropertyCodeCanonMirrorLockupState = 0xD1bf,
  PTPPropertyCodeCanonFlashChargingState = 0xD1C0,
  PTPPropertyCodeCanonAloMode = 0xD1C1,
  PTPPropertyCodeCanonFixedMovie = 0xD1C2,
  PTPPropertyCodeCanonOneShotRawOn = 0xD1C3,
  PTPPropertyCodeCanonErrorForDisplay = 0xD1C4,
  PTPPropertyCodeCanonAEModeMovie = 0xD1C5,
  PTPPropertyCodeCanonBuiltinStroboMode = 0xD1C6,
  PTPPropertyCodeCanonStroboDispState = 0xD1C7,
  PTPPropertyCodeCanonStroboETTL2Metering = 0xD1C8,
  PTPPropertyCodeCanonContinousAFMode = 0xD1C9,
  PTPPropertyCodeCanonMovieParam2 = 0xD1CA,
  PTPPropertyCodeCanonStroboSettingExpComposition = 0xD1CB,
  PTPPropertyCodeCanonMovieParam3 = 0xD1CC,
  PTPPropertyCodeCanonLVMedicalRotate = 0xD1CF,
  PTPPropertyCodeCanonArtist = 0xD1d0,
  PTPPropertyCodeCanonCopyright = 0xD1d1,
  PTPPropertyCodeCanonBracketValue = 0xD1d2,
  PTPPropertyCodeCanonFocusInfoEx = 0xD1d3,
  PTPPropertyCodeCanonDepthOfField = 0xD1d4,
  PTPPropertyCodeCanonBrightness = 0xD1d5,
  PTPPropertyCodeCanonLensAdjustParams = 0xD1d6,
  PTPPropertyCodeCanonEFComp = 0xD1d7,
  PTPPropertyCodeCanonLensName = 0xD1d8,
  PTPPropertyCodeCanonAEB = 0xD1d9,
  PTPPropertyCodeCanonStroboSetting = 0xD1da,
  PTPPropertyCodeCanonStroboWirelessSetting = 0xD1db,
  PTPPropertyCodeCanonStroboFiring = 0xD1dc,
  PTPPropertyCodeCanonLensID = 0xD1dd,
  PTPPropertyCodeCanonLCDBrightness = 0xD1de,
  PTPPropertyCodeCanonCADarkBright = 0xD1df,
  
  PTPPropertyCodeCanonExExposureLevelIncrements = 0x8101,
  PTPPropertyCodeCanonExISOExpansion = 0x8103,
  PTPPropertyCodeCanonExFlasgSyncSpeedInAvMode = 0x810F,
  PTPPropertyCodeCanonExLongExposureNoiseReduction = 0x8201,
  PTPPropertyCodeCanonExHighISONoiseReduction = 0x8202,
  PTPPropertyCodeCanonExHHighlightTonePriority = 0x8203,
  PTPPropertyCodeCanonExAutoLightingOptimizer = 0x8204,
  PTPPropertyCodeCanonExAFAssistBeamFiring = 0x850E,
  PTPPropertyCodeCanonExAFDuringLiveView = 0x8511,
  PTPPropertyCodeCanonExMirrorLockup = 0x860f,
  PTPPropertyCodeCanonExShutterAELockButton = 0x8701,
  PTPPropertyCodeCanonExSetButtonWhenShooting = 0x8704,
  PTPPropertyCodeCanonExLCDDisplayWhenPowerOn = 0x8811,
  PTPPropertyCodeCanonExAddOriginalDecisionData = 0x880F,
  
};


@interface PTPCanonRequest : PTPRequest
+(NSString *)operationCodeName:(PTPRequestCode)operationCode;
@end

@interface PTPCanonResponse : PTPResponse
+(NSString *)responseCodeName:(PTPResponseCode)responseCode;
@end

@interface PTPCanonEvent : PTPEvent
+(NSString *)eventCodeName:(PTPEventCode)eventCode;
@end

@interface PTPCanonProperty : PTPProperty
+(NSString *)propertyCodeName:(PTPPropertyCode)propertyCode;
@end

@interface PTPCanonDeviceInfo : PTPDeviceInfo
@end

@interface PTPCanonCamera : PTPCamera
@end
