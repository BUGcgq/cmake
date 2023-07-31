/*
 * @Author: LIYAOHAN liyaohan@increase.com
 * @Date: 2023-04-20 10:38:29
 * @LastEditors: LIYAOHAN 1791002655@qq.com
 * @LastEditTime: 2023-05-06 17:35:13
 * @FilePath: \OCPP\ocpp_package.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: LIYAOHAN 1791002655@qq.com
 * @Date: 2023-04-01 13:26:13
 * @LastEditors: LIYAOHAN liyaohan@increase.com
 * @LastEditTime: 2023-04-10 14:34:07
 * @FilePath: /OCPP/ocpp_dataEncapsulation.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __OCPP_PACKAGE__H__
#define __OCPP_PACKAGE__H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ocpp_localAuthorization.h"



enum OCPP_PACKAGE{
	OCPP_PACKAGE_NONE = 0,
	OCPP_PACKAGE_AUTHORIZE,//身份认证
	OCPP_PACKAGE_BOOT_NOTIFICATION,//充电桩登录过程，用于通知中央系统充电站已启动并准备好接受充电请求。
	OCPP_PACKAGE_CANCEL_RESERVATION,//取消预约的包，用于取消之前设置的充电预约。
	OCPP_PACKAGE_CHANGE_AVAILABILITY,//改变可用性的包，用于更改充电点的可用性状态，如设置为可用或不可用。
	OCPP_PACKAGE_CHANGE_CONFIGURATION,//改变配置的包，用于更改充电站的配置参数。
	OCPP_PACKAGE_CLEAR_CACHE,//清除缓存的包，用于请求充电站清除缓存数据。
	OCPP_PACKAGE_CLEAR_CHARGINGPROFILE,//清除充电配置文件的包，用于删除充电站中特定的充电配置文件。
	OCPP_PACKAGE_DATATRANSFER,//数据传输的包，用于在充电站和中央系统之间传递自定义数据。
	OCPP_PACKAGE_DIAGNOSTICS_STATUS_NOTIFICATION,//诊断状态通知的包，用于通知充电站诊断操作的状态，例如诊断开始、进行中或完成等。
	OCPP_PACKAGE_FIRMWARE_STATUS_NOTIFICATION,//固件下载状态通知的包，用于通知固件下载操作的状态，例如下载开始、进行中或完成等。
	OCPP_PACKAGE_GET_COMPOSITESCAEDULE,//获取组合日程表的包，用于请求获取充电站中已定义的组合日程表。。
	OCPP_PACKAGE_GET_CONFIGURATION,//获取充电桩的配置信息的包，用于请求获取充电站的配置参数和设置。
	OCPP_PACKAGE_GET_DIAGNOSTICS,//获取诊断信息的包，用于请求获取充电站的诊断信息，例如日志文件、错误码等。
	OCPP_PACKAGE_GET_LOCALLISTVERSION,//请求本地存储的授权用户或车辆列表的版本号。
	OCPP_PACKAGE_HEARTBEAT,//用于指示充电站或中央系统仍处于活动状态并保持连接的心跳包。
	OCPP_PACKAGE_METERVALUES,//包含充电站当前电表值的信息，例如电流、电压、功率和能量测量。
	OCPP_PACKAGE_REMOTE_STARTTRANSACTION,//远程启动充电事务的包。
	OCPP_PACKAGE_REMOTE_STOPTRANSACTION,//远程停止充电事务的包。
	OCPP_PACKAGE_RESERVENOW,//预约当前充电点的包。
	OCPP_PACKAGE_RESET,//重置充电站的包，将其恢复到初始状态。
	OCPP_PACKAGE_SENDLOCALLIST,//将本地授权用户或车辆列表发送到充电站的包。
	OCPP_PACKAGE_SETCHARGINGPROFILE,//设置充电站的充电配置文件的包。
	OCPP_PACKAGE_STARTTRANSACTION,//启动充电事务的包。
	OCPP_PACKAGE_STATUS_NOTIFICATION,//发送充电站状态通知的包。
	OCPP_PACKAGE_STOPTRANSACTION,//停止充电事务的包。
	OCPP_PACKAGE_TRIGGER_MESSAGE,//触发通知,服务器请求充电点特定信息
	OCPP_PACKAGE_UNLOCK_CONNECTOR,//断开本地连接器的包。
	OCPP_PACKAGE_UPDATE_FIRMWARE,//更新充电站固件的包。


	OCPP_PACKAGE_CALLERROR,
	OCPP_PACKAGE_CALL,
	OCPP_PACKAGE_MAX

};

static const char * ocpp_package_text[] = {
	"None",
	"Authorize",
	"BootNotification",
	"CancelReservation",
	"ChangeAvailability",
	"ChangeConfiguration",
	"ClearCache",
	"ClearChargingProfile",
	"DataTransfer",
	"DiagnosticsStatusNotification",
	"FirmwareStatusNotification",
	"GetCompositeSchedule",
	"GetConfiguration",
	"GetDiagnostics",
	"GetLocalListVersion",
	"Heartbeat",
	"MeterValues",
	"RemoteStartTransaction",
	"RemoteStopTransaction",
	"ReserveNow",
	"Reset",
	"SendLocalList",
	"SetChargingProfile",
	"StartTransaction",
	"StatusNotification",
	"StopTransaction",
	"TriggerMessage",
	"UnlockConnector",
	"UpdateFirmware",
	"CallError",
	"Call"
};



enum OCPP_PACKAGE_MESSAGE_TYPES_E{
	OCPP_PACKAGE_CALL_MESSAGE = 2,
	OCPP_PACKAGE_CALL_RESULT = 3,
	OCPP_PACKAGE_CALL_ERROR = 4,

	OCPP_PACKAGE_CALL_MAX
};



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Authorize.req
typedef struct{
	char idTag[OCPP_AUTHORIZATION_IDTAG_LEN];        //IdToken is case insensitive.

}ocpp_package_Authorize_req_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Authorize.conf
typedef struct{
	char expiryDateIsUse:1;
	char expiryDate[32];
	char parentIdTagIsUse:1;
	char parentIdTag[OCPP_AUTHORIZATION_IDTAG_LEN];
	enum OCPP_LOCAL_AUTHORIZATION_STATUS_E AuthorizationStatus;
}ocpp_package_idTagInfo_t;

typedef struct{
	ocpp_package_idTagInfo_t idTagInfo;

}ocpp_package_Authorize_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BootNotification.req
enum OCPP_PACKAGE_CHARGEPOINT_MODEL{
	OCPP_PACKAGE_CHARGEPOINT_MODEL_AC_SINGLE_PHASE_CORE = 0,
	OCPP_PACKAGE_CHARGEPOINT_MODEL_AC_THREE_PHASE_CORE,
	OCPP_PACKAGE_CHARGEPOINT_MODEL_DC_CORE,
	OCPP_PACKAGE_CHARGEPOINT_MODEL_DC_EXTENDED,
	OCPP_PACKAGE_CHARGEPOINT_MODEL_DC_COMBO_CORE,
	OCPP_PACKAGE_CHARGEPOINT_MODEL_DC_UNIQUE,

	OCPP_PACKAGE_CHARGEPOINT_MODE_MAX
};

static const char * ocpp_package_chargePointModel_text[] = {
	"AC_single_phase_core",
	"AC_three_phase_core",
	"DC_core",
	"DC_extended",
	"DC_combo_core",
	"DC_unique"
};


typedef struct{
	char chargeBoxSerialNumberIsUse:1;
	char chargeBoxSerialNumber[25];

	char chargePointModel[20];     

	char chargePointSerialNumberIsUse:1;
	char chargePointSerialNumber[25];

	char chargePointVendor[20];

	char firmwareVersionIsUse:1;
	char firmwareVersion[50];

	char iccidIsUse:1;
	char iccid[20];

	char imsiIsUse:1;
	char imsi[20];

	char meterSerialNumberIsUse:1;
	char meterSerialNumber[25];

	char meterTypeIsUse:1;
	char meterType[25];

}ocpp_package_BootNotification_req_t;



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BootNotification.conf
enum OCPP_PACKAGE_REGISTRATION_STATUS_E{
	OCPP_PACKAGE_REGISTRATION_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_REGISTRATION_STATUS_PENDING,
	OCPP_PACKAGE_REGISTRATION_STATUS_REJECTED,

	OCPP_PACKAGE_REGISTRATION_STATUS_MAX
};

static const char * ocpp_package_RegistrationStatus_text[] = {
	"Accepted",
	"Pending",
	"Rejected"
};


typedef struct{
	char currentTime[32];
	int interval;
	enum OCPP_PACKAGE_REGISTRATION_STATUS_E status;

}ocpp_package_BootNotification_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>CancelReservation.req
typedef struct{
	int reservationId;

}ocpp_package_CancelReservation_req_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>CancelReservation.conf
enum OCPP_PACKAGE_CANCEL_RESERVATION_STATUS_E{
	OCPP_PACKAGE_CANCEL_RESERVATION_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_CANCEL_RESERVATION_STATUS_REJECTED,

	OCPP_PACKAGE_CANCEL_RESERVATION_STATUS_MAX

};

static const char * ocpp_package_CancelReservationStatus_text[] = {
	"Accepted",
	"Rejected"
};

typedef struct{
	enum OCPP_PACKAGE_CANCEL_RESERVATION_STATUS_E status;

}ocpp_package_CancelReservation_conf_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ChangeAvailability.req
enum OCPP_PACKAGE_AVAILABILITY_TYPE_E{

	OCPP_PACKAGE_AVAILABILITY_TYPE_INOPERATIVE = 0,
	OCPP_PACKAGE_AVAILABILITY_TYPE_OPERATIVE,

	OCPP_PACKAGE_AVAILABILITY_TYPE_MAX

};

static const char * ocpp_package_AvailabilityType_text[] = {
	"Inoperative",
	"Operative"
};

typedef struct{
	int connectorId;
	enum OCPP_PACKAGE_AVAILABILITY_TYPE_E type;

}ocpp_package_ChangeAvailability_req_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ChangeAvailability.conf
enum OCPP_PACKAGE_AVAILABILITY_STATUS_E{
	OCPP_PACKAGE_AVAILABILITY_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_AVAILABILITY_STATUS_REJECTED,
	OCPP_PACKAGE_AVAILABILITY_STATUS_SCHEDULED,

	OCPP_PACKAGE_AVAILABILITY_STATUS_MAX

};

static const char * ocpp_package_AvailabilityStatus_text[] = {
	"Accepted",
	"Rejected",
	"Scheduled"
};

typedef struct{
	enum OCPP_PACKAGE_AVAILABILITY_STATUS_E status;

}ocpp_package_ChangeAvailability_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ChangeConfiguration.req
typedef struct{
	char key[50];
	char value[500];

}ocpp_package_ChangeConfiguration_req_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ChangeConfiguration.conf
enum OCPP_PACKAGE_CONFIGURATION_STATUS_E{
	OCPP_PACKAGE_CONFIGURATION_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_CONFIGURATION_STATUS_REJECTED,
	OCPP_PACKAGE_CONFIGURATION_STATUS_REBOOT_REQUIRED,
	OCPP_PACKAGE_CONFIGURATION_STATUS_NOTSUPPORTED,

	OCPP_PACKAGE_CONFIGURATION_STATUS_MAX
};

static const char * ocpp_package_ConfigurationStatus_text[] = {
	"Accepted",
	"Rejected",
	"RebootRequired",
	"NotSupported"
};

typedef struct{
	enum OCPP_PACKAGE_CONFIGURATION_STATUS_E status;

}ocpp_package_ChangeConfiguration_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ClearCache.req
typedef struct{

}ocpp_package_ClearCache_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ClearCache.conf
enum OCPP_PACKAGE_CLEAR_CACHE_STATUS_E{
	OCPP_PACKAGE_CLEAR_CACHE_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_CLEAR_CACHE_STATUS_REJECTED,

	OCPP_PACKAGE_CLEAR_CACHE_STATUS_MAX

};

static const char * ocpp_package_ClearCacheStatus_text[] = {
	"accepted",
	"rejected"
};


typedef struct{
	enum OCPP_PACKAGE_CLEAR_CACHE_STATUS_E status;

}ocpp_package_ClearCache_conf_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ClearChargingProfile.req
enum OCPP_PACKAGE_CHARGING_PROFILE_PURPOSE_TYPE_E{
	OCPP_PACKAGE_CHARGING_PROFILE_PURPOSE_TYPE_CHARGEPOINTMAXPROFILE = 0,
	OCPP_PACKAGE_CHARGING_PROFILE_PURPOSE_TYPE_TXDEFAULTPROFILE,
	OCPP_PACKAGE_CHARGING_PROFILE_PURPOSE_TYPE_TXPROFILE,

	OCPP_PACKAGE_CHARGING_PROFILE_PURPOSE_TYPE_MAX
};

static const char * ocpp_package_ChargingProfilePurposeType_text[] = {
	"ChargePointMaxProfile",
	"TxDefaultProfile",
	"TxProfile"
};

typedef struct{
	char idIsUse:1;
	int id;

	char connectorIdIsUse:1;
	int connectorId;

	char chargingProfilePurposeIsUse:1;
	enum OCPP_PACKAGE_CHARGING_PROFILE_PURPOSE_TYPE_E chargingProfilePurpose;

	char stackLevelIsUse:1;
	int stackLevel;
}ocpp_package_ClearChargingProfile_req_t;

 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ClearChargingProfile.conf
enum OCPP_PACKAGE_CLEAR_CHARGING_PROFILE_STATUS_E{
	OCPP_PACKAGE_CLEAR_CHARGING_PROFILE_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_CLEAR_CHARGING_PROFILE_STATUS_UNKNOWN,

	OCPP_PACKAGE_CLEAR_CHARGING_PROFILE_STATUS_MAX

};

static const char * ocpp_package_ClearChargingProfileStatus_text[] = {
	"Accepted",
	"Unknown"
};

 
typedef struct{
	enum OCPP_PACKAGE_CLEAR_CHARGING_PROFILE_STATUS_E  status;

}ocpp_package_ClearChargingProfile_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>DataTransfer.req
typedef struct{
	char vendorId[255];

	char messageIdIsUse:1;
	char messageId[50];
	
	char dataIsUse:1;
	int dataLen;
	char data[0];

}ocpp_package_DataTransfer_req_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>DataTransfer.conf
enum OCPP_PACKAGE_DATATRANSFER_STATUS_E{
	OCPP_PACKAGE_DATATRANSFER_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_DATATRANSFER_STATUS_REJECTED,
	OCPP_PACKAGE_DATATRANSFER_STATUS_UNKNOWN_MESSAGEID,
	OCPP_PACKAGE_DATATRANSFER_STATUS_UNKNOWN_VENDORID,

	OCPP_PACKAGE_DATATRANSFER_STATUS_MAX

};

static const char * ocpp_package_DataTransferStatus_text[] = {
	"Accepted",
	"Rejected",
	"UnknownMessageId",
	"UnknownVendorId"
};


typedef struct{
	enum OCPP_PACKAGE_DATATRANSFER_STATUS_E status;

	char dataIsUse:1;
	int dataLen;
	char data[0];
}ocpp_package_DataTransfer_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>DiagnosticsStatusNotification.req
enum OCPP_PACKAGE_DIAGNOSTICS_STATUS_E{
	OCPP_PACKAGE_DIAGNOSTICS_STATUS_IDLE = 0,
	OCPP_PACKAGE_DIAGNOSTICS_STATUS_UPLOADED,
	OCPP_PACKAGE_DIAGNOSTICS_STATUS_UPLOAD_FAILED,
	OCPP_PACKAGE_DIAGNOSTICS_STATUS_UPLOADING,

	OCPP_PACKAGE_DIAGNOSTICS_STATUS_MAX

};
static const char * ocpp_package_DiagnosticsStatus_text[] = {
	"Idle",
	"Uploaded",
	"UploadFailed",
	"Uploading"
};

typedef struct{
	enum OCPP_PACKAGE_DIAGNOSTICS_STATUS_E status;

}ocpp_package_DiagnosticsStatusNotification_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>DiagnosticsStatusNotification.conf



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>FirmwareStatusNotification.req
enum OCPP_PACKAGE_FIRMWARE_STATUS_E{
	OCPP_PACKAGE_FIRMWARE_STATUS_DOWNLOADED = 0,
	OCPP_PACKAGE_FIRMWARE_STATUS_DOWNLOAD_FAILED,
	OCPP_PACKAGE_FIRMWARE_STATUS_DOWNLOADING,
	OCPP_PACKAGE_FIRMWARE_STATUS_IDLE,
	OCPP_PACKAGE_FIRMWARE_STATUS_INSTALLATION_FAILED,
	OCPP_PACKAGE_FIRMWARE_STATUS_INSTALLING,
	OCPP_PACKAGE_FIRMWARE_STATUS_INSTALLED,

	OCPP_PACKAGE_FIRMWARE_STATUS_MAX

};
static const char * ocpp_package_FirmwareStatus[] = {
	"Downloaded",
	"DownloadFailed",
	"Downloading",
	"Idle",
	"InstallationFailed",
	"Installing",
	"Installed"
};

typedef struct{
	enum OCPP_PACKAGE_FIRMWARE_STATUS_E status;

}ocpp_package_FirmwareStatusNotification_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>FirmwareStatusNotification.conf

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GetCompositeSchedule.req
enum OCPP_PACKAGE_CHARGING_RATE_UNIT_TYPE_E{
	OCPP_PACKAGE_CHARGING_RATE_UNIT_TYPE_W = 0,
	OCPP_PACKAGE_CHARGING_RATE_UNIT_TYPE_A,

	OCPP_PACKAGE_CHARGING_RATE_UNIT_TYPE_MAX,

};

static const char * ocpp_package_ChargingRateUnitType_text[] = {
	"W",
	"A"
};

typedef struct{
	int connectorId;
	int duration;

	char chargingRateUnitIsUse:1;
	enum OCPP_PACKAGE_CHARGING_RATE_UNIT_TYPE_E chargingRateUnit;

}ocpp_package_GetCompositeSchedule_req_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GetCompositeSchedule.conf
enum OCPP_PACKAGE_GETCOMPOSITESCHEDULE_STATUS_E{
	OCPP_PACKAGE_GETCOMPOSITESCHEDULE_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_GETCOMPOSITESCHEDULE_STATUS_REJECTED,

	OCPP_PACKAGE_GETCOMPOSITESCHEDULE_STATUS_MAX,
};
static const char * ocpp_package_GetCompositeScheduleStatus_text[] = {
	"Accepted",
	"Rejected"
};


typedef struct{
	int startPeriod;
	double limit;

	char numberPhasesIsUse:1;
	int numberPhases;
}ocpp_package_chargingSchedulePeriod_t;

typedef struct{

	char durationIsUse:1;
	int duration;

	char startScheduleIsUse:1;
	char startSchedule[32];

	enum OCPP_PACKAGE_CHARGING_RATE_UNIT_TYPE_E chargingRateUnit;

	int numberOfchargingSchedulePeriod;
	ocpp_package_chargingSchedulePeriod_t **chargingSchedulePeriod;


	char minChargingRateIsUse:1;
	double minChargingRate;

}ocpp_package_chargingSchedule_t;


typedef struct{
	enum OCPP_PACKAGE_GETCOMPOSITESCHEDULE_STATUS_E status;

	char connectorIdIsUse:1;
	int connectorId;

	char scheduleStartIsUse:1;
	char scheduleStart[32];

	char chargingScheduleIsUse:1;
	ocpp_package_chargingSchedule_t chargingSchedule;

}ocpp_package_GetCompositeSchedule_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GetConfiguration.req
typedef struct{
	char keyIsUse:1;
	int numberOfKey;
	char **key;
}ocpp_package_GetConfiguration_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GetConfiguration.conf
typedef struct{
	char key[50];
	bool readonly;
	
	char valueIsUse:1;
	char value[500];

}ocpp_package_KeyValue_t;


typedef struct{
	char configurationKeyIsUse:1;
	int numberOfConfigurationKey;
	ocpp_package_KeyValue_t **configurationKey;

	char unknownKeyIsUse:1;
	int numberOfUnknownKey;
	char **unknownKey;

}ocpp_package_GetConfiguration_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GetDiagnostics.req
typedef struct{
	char location[256];

	char retriesIsUse:1;
	int retries;

	char retryIntervalIsUse:1;
	int retryInterval;

	char startTimeIsUse:1;
	char startTime[32];

	char stopTimeIsUse:1;
	char stopTime[32];

}ocpp_package_GetDiagnostics_req_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GetDiagnostics.conf
typedef struct{
	char fileNameIsUse:1;
	char fileName[256];
}ocpp_package_GetDiagnostics_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GetLocalListVersion.req
typedef struct{

	char reserved;            //预留
}ocpp_package_GetLocalListVersion_req_t;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GetLocalListVersion.conf

typedef struct{
	int listVersion;

}ocpp_package_GetLocalListVersion_conf_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Heartbeat.req
typedef struct{

	char reserved;            //预留
}ocpp_package_Heartbeat_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Heartbeat.conf
typedef struct{

	char currentTime[32];
}ocpp_package_Heartbeat_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>MeterValues.req
//MS = MeterValue SampledValue
enum OCPP_PACKAGE_METERVALUES_MS_CONTEXT_E{
	OCPP_PACKAGE_METERVALUES_MS_CONTEXT_INTERRUPTION_BEGIN = 0,
	OCPP_PACKAGE_METERVALUES_MS_CONTEXT_INTERRUPTION_END,
	OCPP_PACKAGE_METERVALUES_MS_CONTEXT_OTHER,
	OCPP_PACKAGE_METERVALUES_MS_CONTEXT_SAMPLE_CLOCK,
	OCPP_PACKAGE_METERVALUES_MS_CONTEXT_SAMPLE_PERIODIC,
	OCPP_PACKAGE_METERVALUES_MS_CONTEXT_TRANSACTION_BEGIN,
	OCPP_PACKAGE_METERVALUES_MS_CONTEXT_TRANSACTION_END,
	OCPP_PACKAGE_METERVALUES_MS_CONTEXT_TRIGGER,

	OCPP_PACKAGE_METERVALUES_MS_CONTEXT_MAX
};
static const char * ocpp_package_MeterValues_MS_context_text[] = {
	"Interruption.Begin",
	"Interruption.End",
	"Other",
	"Sample.Clock",
	"Sample.Periodic",
	"Transaction.Begin",
	"Transaction.End",
	"Trigger"
};

enum OCPP_PACKAGE_METERVALUES_MS_FORMAT_E{
	OCPP_PACKAGE_METERVALUES_MS_FORMAT_RAW = 0,
	OCPP_PACKAGE_METERVALUES_MS_FORMAT_SIGNEDDATA,

	OCPP_PACKAGE_METERVALUES_MS_FORMAT_MAX

};
static const char * ocpp_package_MeterValues_MS_format_text[] = {
	"Raw",
	"SignedData"
};

enum OCPP_PACKAGE_METERVALUES_MS_MEASURAND_E{
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_CE = 0,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_CI,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_CO,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_EAER,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_EAIR,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_ERER,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_ERIR,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_EAEI,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_EAII,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_EREI,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_ERII,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_F,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_PAE,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_PAI,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_PF,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_PO,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_PRE,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_PRI,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_R,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_S,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_T,
	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_V,

	OCPP_PACKAGE_METERVALUES_MS_MEASURAND_MAX

};
static const char * ocpp_package_MeterValues_MS_measurand_text[] = {
	"Current.Export",
	"Current.Import",
	"Current.Offered",
	"Energy.Active.Export.Register",
	"Energy.Active.Import.Register",
	"Energy.Reactive.Export.Register",
	"Energy.Reactive.Import.Register",
	"Energy.Active.Export.Interval",
	"Energy.Active.Import.Interval",
	"Energy.Reactive.Export.Interval",
	"Energy.Reactive.Import.Interval",
	"Frequency",
	"Power.Active.Export",
	"Power.Active.Import",
	"Power.Factor",
	"Power.Offered",
	"Power.Reactive.Export",
	"Power.Reactive.Import",
	"RPM",
	"SoC",
	"Temperature",
	"Voltage"
};

enum OCPP_PACKAGE_METERVALUES_MS_PHASE_E{
	OCPP_PACKAGE_METERVALUES_MS_PHASE_L1 =0,
	OCPP_PACKAGE_METERVALUES_MS_PHASE_L2,
	OCPP_PACKAGE_METERVALUES_MS_PHASE_L3,
	OCPP_PACKAGE_METERVALUES_MS_PHASE_N,
	OCPP_PACKAGE_METERVALUES_MS_PHASE_L1_N,
	OCPP_PACKAGE_METERVALUES_MS_PHASE_L2_N,
	OCPP_PACKAGE_METERVALUES_MS_PHASE_L3_N,
	OCPP_PACKAGE_METERVALUES_MS_PHASE_L1_L2,
	OCPP_PACKAGE_METERVALUES_MS_PHASE_L2_L3,
	OCPP_PACKAGE_METERVALUES_MS_PHASE_L3_L1,

	OCPP_PACKAGE_METERVALUES_MS_PHASE_MAX

};
static const char * ocpp_package_MeterValues_MS_phase_text[] = {
	"L1",
	"L2",
	"L3",
	"N",
	"L1-N",
	"L2-N",
	"L3-N",
	"L1-L2",
	"L2-L3",
	"L3-L1"

};

enum OCPP_PACKAGE_METERVALUES_MS_LOCATION_E{
	OCPP_PACKAGE_METERVALUES_MS_LOCATION_BODY = 0,
	OCPP_PACKAGE_METERVALUES_MS_LOCATION_CABLE,
	OCPP_PACKAGE_METERVALUES_MS_LOCATION_CHARGE_POINT,
	OCPP_PACKAGE_METERVALUES_MS_LOCATION_EV,
	OCPP_PACKAGE_METERVALUES_MS_LOCATION_INLET,
	OCPP_PACKAGE_METERVALUES_MS_LOCATION_OUTLET,

	OCPP_PACKAGE_METERVALUES_MS_LOCATION_MAX
};
static const char * ocpp_package_MeterValues_MS_location_text[] = {
	"Body",
	"Cable",
	"Charge Point",
	"EV",
	"Inlet",
	"Outlet"
};

enum OCPP_PACKAGE_METERVALUES_MS_UNIT_E{
	OCPP_PACKAGE_METERVALUES_MS_UNIT_WH = 0,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_KWH,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_VARH,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_KVARH,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_W,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_KW,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_VA,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_KVA,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_VAR,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_KVAR,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_A,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_V,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_CELSIUS,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_FAHRENHEIT,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_K,
	OCPP_PACKAGE_METERVALUES_MS_UNIT_PERCENT,

	OCPP_PACKAGE_METERVALUES_MS_UNIT_MAX

};
static const char * ocpp_package_MeterValues_MS_unit_text[] = {
	"Wh",
	"kWh",
	"varh",
	"kvarh",
	"W",
	"kW",
	"VA",
	"kVA",
	"var",
	"kvar",
	"A",
	"V",
	"Celsius",
	"Fahrenheit",
	"K",
	"Percent",
};



typedef struct{
	char value[16];

	char contextIsUse:1;
	enum OCPP_PACKAGE_METERVALUES_MS_CONTEXT_E context;

	char formatIsUse:1;
	enum OCPP_PACKAGE_METERVALUES_MS_FORMAT_E format;

	char measurandIsUse:1;
	enum OCPP_PACKAGE_METERVALUES_MS_MEASURAND_E measurand;

	char phaseIsUse:1;
	enum OCPP_PACKAGE_METERVALUES_MS_PHASE_E phase;

	char locationIsUse:1;
	enum OCPP_PACKAGE_METERVALUES_MS_LOCATION_E location;

	char unitIsUse:1;
	enum OCPP_PACKAGE_METERVALUES_MS_UNIT_E unit;

}ocpp_package_MeterValues_M_SampledValue_t;


typedef struct{
	char timestamp[32];

	int sampledValueCnt;
	ocpp_package_MeterValues_M_SampledValue_t **sampledValue;
}ocpp_package_MeterValues_MeterValue_t;


typedef struct{
	int connectorId;

	char transactionIdIsUse;
	int transactionId;
	ocpp_package_MeterValues_MeterValue_t meterValue;
}ocpp_package_MeterValues_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>MeterValues.conf

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>RemoteStartTransaction.req
enum OCPP_PACKAGE_CHARGING_PROFILE_KIND_TYPE_E{
	OCPP_PACKAGE_CHARGING_PROFILE_KIND_TYPE_ABSOLUTE = 0,
	OCPP_PACKAGE_CHARGING_PROFILE_KIND_TYPE_RECURRING,
	OCPP_PACKAGE_CHARGING_PROFILE_KIND_TYPE_RELATIVE,

	OCPP_PACKAGE_CHARGING_PROFILE_KIND_TYPE_MAX

};

static const char * ocpp_package_ChargingProfileKindType_text[] = {

	"Absolute",
	"Recurring",
	"Relative"
};


enum OCPP_PACKAGE_RECURRENCY_KIND_TYPE_E{
	OCPP_PACKAGE_RECURRENCY_KIND_TYPE_DAILY = 0,
	OCPP_PACKAGE_RECURRENCY_KIND_TYPE_WEEKLY,
	OCPP_PACKAGE_RECURRENCY_KIND_TYPE_MAX

};

static const char * ocpp_package_RecurrencyKindType_text[] = {

	"Daily",
	"Weekly"
};




typedef struct{
	int chargingProfileId;

	char transactionIdIsUse:1;
	int transactionId;


	int stackLevel;

	enum OCPP_PACKAGE_CHARGING_PROFILE_PURPOSE_TYPE_E chargingProfilePurpose;
	enum OCPP_PACKAGE_CHARGING_PROFILE_KIND_TYPE_E ChargingProfileKindType;

	char recurrencyKindIsUse:1;
	enum OCPP_PACKAGE_RECURRENCY_KIND_TYPE_E  RecurrencyKindType;


	char validFromIsUse:1;
	char validFrom[32];

	char validToIsUse:1;
	char validTo[32];
	
	ocpp_package_chargingSchedule_t  chargingSchedule;

}ocpp_package_chargingProfile_t;


typedef struct{
	char connectorIdIsUse:1;
	int connectorId;

	char idTag[OCPP_AUTHORIZATION_IDTAG_LEN];

	char chargingProfileIsUse:1;
	//待实现
	ocpp_package_chargingProfile_t chargingProfile;

}ocpp_package_RemoteStartTransaction_req_t;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>RemoteStartTransaction.conf
enum OCPP_PACKAGE_REMOTE_STRATSTOP_STATUS_E{
	OCPP_PACKAGE_REMOTE_STRATSTOP_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_REMOTE_STRATSTOP_STATUS_REJECTED,

	OCPP_PACKAGE_REMOTE_STRATSTOP_STATUS_MAX
};

static const char * ocpp_package_RemoteStartStopStatus_text[] = {
	"Accepted",
	"Rejected"
};

typedef struct{
	enum OCPP_PACKAGE_REMOTE_STRATSTOP_STATUS_E status;

}ocpp_package_RemoteStartTransaction_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>RemoteStopTransaction.req
typedef struct{
	int transactionId;

}ocpp_package_RemoteStopTransaction_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>RemoteStopTransaction.conf
typedef struct{

	enum OCPP_PACKAGE_REMOTE_STRATSTOP_STATUS_E status;

}ocpp_package_RemoteStopTransaction_conf_t;


/////////////////////////////////////////////////////////////////////////////////

typedef struct{
	int chargingProfileId;

	char transactionIdIsUse:1;
	int transactionId;

	int stackLevel;
	enum OCPP_PACKAGE_CHARGING_PROFILE_PURPOSE_TYPE_E	chargingProfilePurpose;
	enum OCPP_PACKAGE_CHARGING_PROFILE_KIND_TYPE_E  chargingProfileKind;

	char recurrencyKindIsUse:1;
	enum OCPP_PACKAGE_RECURRENCY_KIND_TYPE_E  recurrencyKind;

	char validFromIsUse:1;
	char validFrom[32];

	
}ocpp_package_ChargingProfile_t;




//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ReserveNow.req
typedef struct{
	int connectorId;
	char expiryDate[32];
	char idTag[20];

	char parentIdTagIsUse:1;
	char parentIdTag[20];

	int reservationId;

}ocpp_package_ReserveNow_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ReserveNow.conf
enum OCPP_PCAKGE_RESERVATION_STATUS_E{
	OCPP_PCAKGE_RESERVATION_STATUS_ACCEPTED = 0,
	OCPP_PCAKGE_RESERVATION_STATUS_FAULTED,
	OCPP_PCAKGE_RESERVATION_STATUS_OCCUPIED,
	OCPP_PCAKGE_RESERVATION_STATUS_REJECTED,
	OCPP_PCAKGE_RESERVATION_STATUS_UNAVAILABLE,

	OCPP_PCAKGE_RESERVATION_STATUS_MAX
};

static const char * ocpp_package_ReservationStatus_text[] = {
	"Accepted",
	"Faulted",
	"Occupied",
	"Rejected",
	"Unavailable"
};

typedef struct{
	enum OCPP_PCAKGE_RESERVATION_STATUS_E status;

}ocpp_package_ReserveNow_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Reset.req
enum OCPP_PACKAGE_RESET_TYPE_E{
	OCPP_PACKAGE_RESET_TYPE_HARD = 0,
	OCPP_PACKAGE_RESET_TYPE_SOFT,

	OCPP_PACKAGE_RESET_TYPE_MAX

};

static const char * ocpp_package_ResetType_text[] = {
	"Hard",
	"Soft"
};

typedef struct{
	enum OCPP_PACKAGE_RESET_TYPE_E type;

}ocpp_package_Reset_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Reset.conf
enum OCPP_PACKAGE_RESET_STATUS_E{
	OCPP_PACKAGE_RESET_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_RESET_STATUS_REJECTED,

	OCPP_PACKAGE_RESET_STATUS_MAX

};
static const char *ocpp_package_ResetStatus_text[] = {
	"Accepted",
	"Rejected"
};
typedef struct{

	enum OCPP_PACKAGE_RESET_STATUS_E status;
}ocpp_package_Reset_conf_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SendLocalList.req

enum OCPP_PACKAGE_UPDATE_TYPE_E{
	OCPP_PACKAGE_UPDATE_TYPE_DIFFERENTIAL = 0,
	OCPP_PACKAGE_UPDATE_TYPE_FULL,
	OCPP_PACKAGE_UPDATE_TYPE_MAX


};

static const char * ocpp_package_UpdateType_text[] = {
	"Differential",
	"Full"
};


typedef struct{
	char idTag[20];
	char idTagInfoIsUse:1;
	ocpp_package_idTagInfo_t idTagInfo;

}ocpp_package_AuthorizationData_t;



typedef struct{
	int listVersion;
	char localAuthorizationListIsUse:1;
	int  numberOfAuthorizationData;
	ocpp_package_AuthorizationData_t **localAuthorizationList;

	enum OCPP_PACKAGE_UPDATE_TYPE_E UpdateType;
}ocpp_package_SendLocalList_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SendLocalList.conf
enum OCPP_PCAKGE_UPDATE_STATUS_E{
	OCPP_PCAKGE_UPDATE_STATUS_ACCEPTED = 0,
	OCPP_PCAKGE_UPDATE_STATUS_FAILED,
	OCPP_PCAKGE_UPDATE_STATUS_NOTSUPPORTED,
	OCPP_PCAKGE_UPDATE_STATUS_VERSION_MISMATCH,

	OCPP_PACKGE_UPDATE_STATUS_MAX
};

static const char * ocpp_package_UpdateStatus_text[] = {
	"Accepted",
	"Failed",
	"NotSupported",
	"VersionMismatch"
};

typedef struct{
	enum OCPP_PCAKGE_UPDATE_STATUS_E status;

}ocpp_package_SendLocalList_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SetChargingProfile.req
typedef struct{
	int connectorId;

	ocpp_package_chargingProfile_t  csChargingProfiles;

}ocpp_package_SetChargingProfile_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SetChargingProfile.conf
enum OCPP_PACKAGE_CHARGEING_PROFILE_STATUS_E{
	OCPP_PACKAGE_CHARGEING_PROFILE_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_CHARGEING_PROFILE_STATUS_REJECTED,
	OCPP_PACKAGE_CHARGEING_PROFILE_STATUS_NOTSUPPORTED,
	OCPP_PACKAGE_CHARGEING_PROFILE_STATUS_MAX


};
static const char * ocpp_package_ChargingProfileStatus_text[] = {

	"Accepted",
	"Rejected",
	"NotSupported"
};


typedef struct{
enum OCPP_PACKAGE_CHARGEING_PROFILE_STATUS_E status;

}ocpp_package_SetChargingProfile_conf_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>StartTransaction.req
typedef struct{
	int connectorId;
	char idTag[OCPP_AUTHORIZATION_IDTAG_LEN];
	int meterStart;

	char reservationIdIsUse:1;
	int reservationId;
	
	char timestamp[32];

}ocpp_package_StartTransaction_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>StartTransaction.conf
typedef struct{
	ocpp_package_idTagInfo_t idTagInfo;
	int transactionId;

}ocpp_package_StartTransaction_conf_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>StatusNotification.req

enum OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_E{
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_CONNECTOR_LOCK_FAILURE = 0,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_EV_COMMUNICATION_ERROR,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_GROUND_FAILURE,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_HIGH_TEMPERATURE,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_INTERNAL_ERROR,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_LOCALLIST_CONFLICT,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_NOERROE,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_OTHER_ERROR,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_OVERCURRENT_FAILURE,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_OVERVOLTAGE,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_POWERMETER_FAILURE,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_POWERSWITCH_FAILURE,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_READER_FAILURE,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_RESET_FAILURE,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_UNDERVOLTAGE,
	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_WEAKSIGNAL,


	OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_MAX
};

static const char *ocpp_package_ChargePointErrorCode_text[] = {
	"ConnectorLockFailure",
	"EVCommunicationError",
	"GroundFailure",
	"HighTemperature",
	"InternalError",
	"LocalListConflict",
	"NoError",
	"OtherError",
	"OverCurrentFailure",
	"OverVoltage",
	"PowerMeterFailure",
	"PowerSwitchFailure",
	"ReaderFailure",
	"ResetFailure",
	"UnderVoltage",
	"WeakSignal"
};

enum OCPP_PACKAGE_CHARGEPOINT_STATUS_E{
	OCPP_PACKAGE_CHARGEPOINT_STATUS_AVAILABLE = 0,
	OCPP_PACKAGE_CHARGEPOINT_STATUS_PREPARING,
	OCPP_PACKAGE_CHARGEPOINT_STATUS_CHARGING,
	OCPP_PACKAGE_CHARGEPOINT_STATUS_SUSPENDED_EVSE,
	OCPP_PACKAGE_CHARGEPOINT_STATUS_SUSPENDED_EV,
	OCPP_PACKAGE_CHARGEPOINT_STATUS_FINISHING,
	OCPP_PACKAGE_CHARGEPOINT_STATUS_RESERVED,
	OCPP_PACKAGE_CHARGEPOINT_STATUS_UNAVAILABLE,
	OCPP_PACKAGE_CHARGEPOINT_STATUS_FAULTED,

	OCPP_PACKAGE_CHARGEPOINT_STATUS_MAX
};


static const char * ocpp_package_ChargePointStatus_text[] = {
	"Available",
	"Preparing",
	"Charging",
	"SuspendedEVSE",
	"SuspendedEV",
	"Finishing",
	"Reserved",
	"Unavailable",
	"Faulted"
};


typedef struct{
	int connectorId;
	enum OCPP_PACKAGE_CHARGEPOINT_ERRORCODE_E errorCode;

	char infoIsUse:1;
	char info[50];

	enum OCPP_PACKAGE_CHARGEPOINT_STATUS_E status;

	char timestampIsUse:1;
	char timestamp[32];

	char vendorIdIsUse:1;
	char vendorId[255];

	char vendorErrorCodeIsUse:1;
	char vendorErrorCode[50];

}ocpp_package_StatusNotification_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>StatusNotification.conf
typedef struct{



}ocpp_package_StatusNotification_conf_t;



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>StopTransaction.req
enum OCPP_PACKAGE_STOP_REASON_E{
	OCPP_PACKAGE_STOP_REASON_EMERGENCYSTOP = 0,
	OCPP_PACKAGE_STOP_REASON_EVDISCONNECTED,
	OCPP_PACKAGE_STOP_REASON_HARDRESET,
	OCPP_PACKAGE_STOP_REASON_LOCAL,
	OCPP_PACKAGE_STOP_REASON_OTHER,
	OCPP_PACKAGE_STOP_REASON_POWERLOSS,
	OCPP_PACKAGE_STOP_REASON_REBOOT,
	OCPP_PACKAGE_STOP_REASON_REMOTE,
	OCPP_PACKAGE_STOP_REASON_SOFTRESET,
	OCPP_PACKAGE_STOP_REASON_UNLOCKCOMMAND,
	OCPP_PACKAGE_STOP_REASON_DEAUTHORIZED,
	OCPP_PACKAGE_STOP_REASON_MAX
};


static const char * ocpp_package_stop_reason_text[] = {
	"EmergencyStop",
	"EVDisconnected",
	"HardReset",
	"Local",
	"Other",
	"PowerLoss",
	"Reboot",
	"Remote",
	"SoftReset",
	"UnlockCommand",
	"DeAuthorized"
};

typedef struct{

	char idTagIsUse:1;
	char idTag[OCPP_AUTHORIZATION_IDTAG_LEN];
	int meterStop;
	char timestamp[32];
	int transactionId;

	char reasonIsUse:1;
	enum OCPP_PACKAGE_STOP_REASON_E reason;

	char transactionDataIsUse:1;
	ocpp_package_MeterValues_MeterValue_t transactionData;

}ocpp_package_StopTransaction_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>StopTransaction.conf
typedef struct{
	char idTagInfoIsUse:1;
	ocpp_package_idTagInfo_t idTagInfo;

}ocpp_package_StopTransaction_conf_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>TriggerMessage.req
enum OCPP_PCAKGE_MESSAGE_TRIGGER_E{
	OCPP_PCAKGE_MESSAGE_TRIGGER_BOOTNOTIFICATION = 0,
	OCPP_PCAKGE_MESSAGE_TRIGGER_DIAGNOSTICSSTATUS_NOTIFICATION,
	OCPP_PCAKGE_MESSAGE_TRIGGER_FIRMWARESTATUS_NOTIFICATION,
	OCPP_PCAKGE_MESSAGE_TRIGGER_HEARTBEAT,
	OCPP_PCAKGE_MESSAGE_TRIGGER_METERVALUES,
	OCPP_PCAKGE_MESSAGE_TRIGGER_STATUS_NOTIFICATION,

	OCPP_PACKGE_MESSAGE_TRIGGER_STATUS_MAX


};
static const char * ocpp_package_MessageTrigger_text[] = {
	"BootNotification",
	"DiagnosticsStatusNotification",
	"FirmwareStatusNotification",
	"Heartbeat",
	"MeterValues",
	"StatusNotification"
};
typedef struct{
	enum OCPP_PCAKGE_MESSAGE_TRIGGER_E requestedMessage;

	char connectorIdIsUse:1;
	int connectorId;

}ocpp_package_TriggerMessage_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>TriggerMessage.conf
enum OCPP_PACKAGE_TRIGGER_MESSAGE_STATUS_E{
	OCPP_PACKAGE_TRIGGER_MESSAGE_STATUS_ACCEPTED = 0,
	OCPP_PACKAGE_TRIGGER_MESSAGE_STATUS_REJECTED,
	OCPP_PACKAGE_TRIGGER_MESSAGE_STATUS_NOTIMPLEMENTED,

	OCPP_PACKAGE_TRIGGER_MESSAGE_STATUS_MAX

};
static const char * ocpp_package_TriggerMessageStatus_text[] = {
	"Accepted",
	"Rejected",
	"NotImplemented"
};
typedef struct{

	enum OCPP_PACKAGE_TRIGGER_MESSAGE_STATUS_E status;
}ocpp_package_TriggerMessage_conf_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>UnlockConnector.req
typedef struct{
	int connectorId;

}ocpp_package_UnlockConnector_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>UnlockConnector.conf
enum OCPP_PACKAGE_UNLOCK_STATUS_E{
	OCPP_PACKAGE_UNLOCK_STATUS_UNLOCKED = 0,
	OCPP_PACKAGE_UNLOCK_STATUS_UNLOCK_FAILED,
	OCPP_PACKAGE_UNLOCK_STATUS_NOTSUPPORTED,

	OCPP_PACKAGE_UNLOCK_STATUS_MAX

};

static const char * ocpp_package_UnlockStatus_text[] = {
	"Unlocked",
	"UnlockFailed",
	"NotSupported"
};

typedef struct{
	enum OCPP_PACKAGE_UNLOCK_STATUS_E status;

}ocpp_package_UnlockConnector_conf_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>UpdateFirmware.req
typedef struct{
	char location[256];
	
	char retriesIsUse:1;
	int retries;

	char retrieveDate[32];

	char retryIntervalIsUse:1;
	int retryInterval;

}ocpp_package_UpdateFirmware_req_t;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>UpdateFirmware.conf
typedef struct{
	char reserved;            //预留

}ocpp_package_UpdateFirmware_conf_t;










//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>CallError
// NotImplemented                      Requested Action is not known by receiver
// NotSupported                        Requested Action is recognized but not supported by the receiver
// InternalError                       An internal error occurred and the receiver was not able to process the requested Action successfully
// ProtocolError                       Payload for Action is incomplete
// SecurityError                       During the processing of Action a security issue occurred preventing receiver from completing the Action successfully
// FormationViolation                  Payload for Action is syntactically incorrect or not conform the PDU structure for Action
// PropertyConstraintViolation         Payload is syntactically correct but at least one field contains an invalid value
// OccurenceConstraintViolation        Payload for Action is syntactically correct but at least one of the fields violates occurence constraints
// TypeConstraintViolation             Payload for Action is syntactically correct but at least one of the fields violates data type constraints (e.g. “somestring”: 12)
// GenericError                        Any other error not covered by the previous ones


enum OCPP_PACKAGE_CALLERROR_ERRORCODE_E{
	OCPP_PACKAGE_CALLERROR_ERRORCODE_NOT_IMPLEMENTED = 0,
	OCPP_PACKAGE_CALLERROR_ERRORCODE_NOT_SUPPORTED,
	OCPP_PACKAGE_CALLERROR_ERRORCODE_INTERNAL_ERROR,
	OCPP_PACKAGE_CALLERROR_ERRORCODE_PROTOCOL_ERROR,
	OCPP_PACKAGE_CALLERROR_ERRORCODE_SECURITY_ERROR,
	OCPP_PACKAGE_CALLERROR_ERRORCODE_FORMATION_VILOLATION,
	OCPP_PACKAGE_CALLERROR_ERRORCODE_PROPERTY_CONSTRAINT_VIOLATION,
	OCPP_PACKAGE_CALLERROR_ERRORCODE_OCCURENCE_CONSTRAINT_VIOLATION,
	OCPP_PACKAGE_CALLERROR_ERRORCODE_TYPE_CONSTRAINT_VIOLATION,
	OCPP_PACKAGE_CALLERROR_ERRORCODE_GENERIC_ERROR,

	OCPP_PACKAGE_CALLERROR_ERRORCODE_MAX
};

static const char * ocpp_package_CallError_ErrorCode_text[] = {
	"NotImplemented",
	"NotSupported",
	"InternalError",
	"ProtocolError",
	"SecurityError",
	"FormationViolation",
	"PropertyConstraintViolation",
	"OccurenceConstraintViolation",
	"TypeConstraintViolation",
	"GenericError"
};


// typedef struct{

// 	char error[32];                              //错误
// 	char detail[256];                            //描述

// }ocpp_package_CallError_ErrorDetail_t;

typedef struct {
    enum OCPP_PACKAGE_CALLERROR_ERRORCODE_E errorCode;
    char errorDescriptionIsUse:1;
    char errorDescription[1024];
    int errorDetailCnt; // 错误描述的数量
    char detail[256];   // 描述
} ocpp_package_CallError_t;





char * ocpp_package_prepare_Authorize_Request(const char * UniqueId, ocpp_package_Authorize_req_t * Authorize);
char * ocpp_package_prepare_BootNotification_Request(const char * UniqueId, ocpp_package_BootNotification_req_t * BootNotification);
char *ocpp_package_prepare_DataTransfer_Request(const char * UniqueId,ocpp_package_DataTransfer_req_t * DataTransfer);
char *ocpp_package_prepare_DiagnosticsStatusNotification_Request(const char *UniqueId, ocpp_package_DiagnosticsStatusNotification_req_t * DiagnosticsStatusNotification);
char *ocpp_package_prepare_FirmwareStatusNotification_Request(const char *UniqueId, ocpp_package_FirmwareStatusNotification_req_t * FirmwareStatusNotification);
char *ocpp_package_prepare_Heartbeat_Request(const char *UniqueId,ocpp_package_Heartbeat_req_t * Heartbeat);
char *ocpp_package_prepare_MeterValues_Request(const char *UniqueId,ocpp_package_MeterValues_req_t * MeterValues);
char *ocpp_package_prepare_StartTransaction_Request(const char *UniqueId,ocpp_package_StartTransaction_req_t * StartTransaction);
char *ocpp_package_prepare_StatusNotification_Request(const char *UniqueId,ocpp_package_StatusNotification_req_t * StatusNotification);
char *ocpp_package_prepare_StopTransaction_Request(const char *UniqueId,ocpp_package_StopTransaction_req_t * StopTransaction);




char *ocpp_package_prepare_CancelReservation_Response(const char *UniqueId, ocpp_package_CancelReservation_conf_t * CancelReservation);
char *ocpp_package_prepare_ChangeAvailability_Response(const char *UniqueId, ocpp_package_ChangeAvailability_conf_t * ChangeAvailability);
char *ocpp_package_prepare_ChangeConfiguration_Response(const char *UniqueId, ocpp_package_ChangeConfiguration_conf_t * ChangeConfiguration);
char *ocpp_package_prepare_ClearCache_Response(const char *UniqueId, ocpp_package_ClearCache_conf_t * ClearCache);
char *ocpp_package_prepare_ClearChargingProfile_Response(const char *UniqueId, ocpp_package_ClearChargingProfile_conf_t * ClearChargingProfile);
char *ocpp_package_prepare_DataTransfer_Response(const char * UniqueId,ocpp_package_DataTransfer_conf_t * DataTransfer);
char *ocpp_package_prepare_GetLocalListVersion_Response(const char *UniqueId, ocpp_package_GetLocalListVersion_conf_t * GetLocalListVersion);
char *ocpp_package_prepare_GetCompositeSchedule_Response(const char *UniqueId, ocpp_package_GetCompositeSchedule_conf_t * GetCompositeSchedule);
char *ocpp_package_prepare_GetConfiguration_Response(const char *UniqueId, ocpp_package_GetConfiguration_conf_t * GetConfiguration);
char *ocpp_package_prepare_GetDiagnostics_Response(const char *UniqueId, ocpp_package_GetDiagnostics_conf_t * GetDiagnostics);
char *ocpp_package_prepare_RemoteStartTransaction_Response(const char *UniqueId, ocpp_package_RemoteStartTransaction_conf_t * RemoteStartTransaction);
char *ocpp_package_prepare_RemoteStopTransaction_Response(const char *UniqueId, ocpp_package_RemoteStopTransaction_conf_t * ReserveNow);
char *ocpp_package_prepare_ReserveNow_Response(const char *UniqueId, ocpp_package_ReserveNow_conf_t * ReserveNow);
char *ocpp_package_prepare_Reset_Response(const char *UniqueId, ocpp_package_Reset_conf_t * Reset);
char *ocpp_package_prepare_SendLocalList_Response(const char *UniqueId, ocpp_package_SendLocalList_conf_t * SendLocalList);
char *ocpp_package_prepare_SetChargingProfile_Response(const char *UniqueId, ocpp_package_SetChargingProfile_conf_t * SetChargingProfile);
char *ocpp_package_prepare_TriggerMessage_Response(const char *UniqueId, ocpp_package_TriggerMessage_conf_t * TriggerMessage);
char *ocpp_package_prepare_UnlockConnector_Response(const char *UniqueId, ocpp_package_UnlockConnector_conf_t * UnlockConnector);
char *ocpp_package_prepare_UpdateFirmware_Response(const char *UniqueId, ocpp_package_UpdateFirmware_conf_t * UpdateFirmware);


char * ocpp_package_prepare_CallError(const char *UniqueId, ocpp_package_CallError_t * callError);









#ifdef __cplusplus
}
#endif

#endif




















