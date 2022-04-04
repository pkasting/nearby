// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/connections_enums.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2fconnections_5fenums_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_proto_2fconnections_5fenums_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_proto_2fconnections_5fenums_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2fconnections_5fenums_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE
namespace location {
namespace nearby {
namespace proto {
namespace connections {

enum EventType : int {
  UNKNOWN_EVENT_TYPE = 0,
  CLIENT_SESSION = 1,
  START_CLIENT_SESSION = 2,
  STOP_CLIENT_SESSION = 3,
  START_STRATEGY_SESSION = 4,
  STOP_STRATEGY_SESSION = 5,
  ERROR_CODE = 6
};
bool EventType_IsValid(int value);
constexpr EventType EventType_MIN = UNKNOWN_EVENT_TYPE;
constexpr EventType EventType_MAX = ERROR_CODE;
constexpr int EventType_ARRAYSIZE = EventType_MAX + 1;

const std::string& EventType_Name(EventType value);
template<typename T>
inline const std::string& EventType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, EventType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function EventType_Name.");
  return EventType_Name(static_cast<EventType>(enum_t_value));
}
bool EventType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, EventType* value);
enum ConnectionsStrategy : int {
  UNKNOWN_STRATEGY = 0,
  MDNS_LOCAL_WIFI PROTOBUF_DEPRECATED_ENUM = 1,
  RADIO_P2P PROTOBUF_DEPRECATED_ENUM = 2,
  P2P_CLUSTER = 3,
  P2P_STAR = 4,
  P2P_POINT_TO_POINT = 5
};
bool ConnectionsStrategy_IsValid(int value);
constexpr ConnectionsStrategy ConnectionsStrategy_MIN = UNKNOWN_STRATEGY;
constexpr ConnectionsStrategy ConnectionsStrategy_MAX = P2P_POINT_TO_POINT;
constexpr int ConnectionsStrategy_ARRAYSIZE = ConnectionsStrategy_MAX + 1;

const std::string& ConnectionsStrategy_Name(ConnectionsStrategy value);
template<typename T>
inline const std::string& ConnectionsStrategy_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ConnectionsStrategy>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ConnectionsStrategy_Name.");
  return ConnectionsStrategy_Name(static_cast<ConnectionsStrategy>(enum_t_value));
}
bool ConnectionsStrategy_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ConnectionsStrategy* value);
enum SessionRole : int {
  UNKNOWN_SESSION_ROLE = 0,
  ADVERTISER = 1,
  DISCOVERER = 2
};
bool SessionRole_IsValid(int value);
constexpr SessionRole SessionRole_MIN = UNKNOWN_SESSION_ROLE;
constexpr SessionRole SessionRole_MAX = DISCOVERER;
constexpr int SessionRole_ARRAYSIZE = SessionRole_MAX + 1;

const std::string& SessionRole_Name(SessionRole value);
template<typename T>
inline const std::string& SessionRole_Name(T enum_t_value) {
  static_assert(::std::is_same<T, SessionRole>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function SessionRole_Name.");
  return SessionRole_Name(static_cast<SessionRole>(enum_t_value));
}
bool SessionRole_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, SessionRole* value);
enum Medium : int {
  UNKNOWN_MEDIUM = 0,
  MDNS PROTOBUF_DEPRECATED_ENUM = 1,
  BLUETOOTH = 2,
  WIFI_HOTSPOT = 3,
  BLE = 4,
  WIFI_LAN = 5,
  WIFI_AWARE = 6,
  NFC = 7,
  WIFI_DIRECT = 8,
  WEB_RTC = 9,
  BLE_L2CAP = 10
};
bool Medium_IsValid(int value);
constexpr Medium Medium_MIN = UNKNOWN_MEDIUM;
constexpr Medium Medium_MAX = BLE_L2CAP;
constexpr int Medium_ARRAYSIZE = Medium_MAX + 1;

const std::string& Medium_Name(Medium value);
template<typename T>
inline const std::string& Medium_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Medium>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Medium_Name.");
  return Medium_Name(static_cast<Medium>(enum_t_value));
}
bool Medium_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Medium* value);
enum ConnectionTechnology : int {
  CONNECTION_TECHNOLOGY_UNKNOWN_TECHNOLOGY = 0,
  CONNECTION_TECHNOLOGY_BLE_GATT = 1,
  CONNECTION_TECHNOLOGY_BLE_L2CAP = 2,
  CONNECTION_TECHNOLOGY_HOTSPOT_DIRECT = 3,
  CONNECTION_TECHNOLOGY_HOTSPOT_LOCALONLY = 4,
  CONNECTION_TECHNOLOGY_HOTSPOT_SOFTAP = 5,
  CONNECTION_TECHNOLOGY_WEBRTC_WIFI = 6,
  CONNECTION_TECHNOLOGY_WEBRTC_MOBILE = 7,
  CONNECTION_TECHNOLOGY_WEBRTC_ETHERNET = 8,
  CONNECTION_TECHNOLOGY_WEBRTC_VPN = 9,
  CONNECTION_TECHNOLOGY_WEBRTC_LOOPBACK = 10,
  CONNECTION_TECHNOLOGY_WEBRTC_ADAPTER_TYPE_ANY = 11
};
bool ConnectionTechnology_IsValid(int value);
constexpr ConnectionTechnology ConnectionTechnology_MIN = CONNECTION_TECHNOLOGY_UNKNOWN_TECHNOLOGY;
constexpr ConnectionTechnology ConnectionTechnology_MAX = CONNECTION_TECHNOLOGY_WEBRTC_ADAPTER_TYPE_ANY;
constexpr int ConnectionTechnology_ARRAYSIZE = ConnectionTechnology_MAX + 1;

const std::string& ConnectionTechnology_Name(ConnectionTechnology value);
template<typename T>
inline const std::string& ConnectionTechnology_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ConnectionTechnology>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ConnectionTechnology_Name.");
  return ConnectionTechnology_Name(static_cast<ConnectionTechnology>(enum_t_value));
}
bool ConnectionTechnology_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ConnectionTechnology* value);
enum ConnectionBand : int {
  CONNECTION_BAND_UNKNOWN_BAND = 0,
  CONNECTION_BAND_WIFI_BAND_2GHZ = 1,
  CONNECTION_BAND_WIFI_BAND_5GHZ = 2,
  CONNECTION_BAND_WIFI_BAND_6GHZ = 3,
  CONNECTION_BAND_CELLULAR_BAND_2G = 4,
  CONNECTION_BAND_CELLULAR_BAND_3G = 5,
  CONNECTION_BAND_CELLULAR_BAND_4G = 6,
  CONNECTION_BAND_CELLULAR_BAND_5G = 7
};
bool ConnectionBand_IsValid(int value);
constexpr ConnectionBand ConnectionBand_MIN = CONNECTION_BAND_UNKNOWN_BAND;
constexpr ConnectionBand ConnectionBand_MAX = CONNECTION_BAND_CELLULAR_BAND_5G;
constexpr int ConnectionBand_ARRAYSIZE = ConnectionBand_MAX + 1;

const std::string& ConnectionBand_Name(ConnectionBand value);
template<typename T>
inline const std::string& ConnectionBand_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ConnectionBand>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ConnectionBand_Name.");
  return ConnectionBand_Name(static_cast<ConnectionBand>(enum_t_value));
}
bool ConnectionBand_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ConnectionBand* value);
enum ConnectionRequestResponse : int {
  UNKNOWN_CONNECTION_REQUEST_RESPONSE = 0,
  ACCEPTED = 1,
  REJECTED = 2,
  IGNORED = 3,
  NOT_SENT = 4
};
bool ConnectionRequestResponse_IsValid(int value);
constexpr ConnectionRequestResponse ConnectionRequestResponse_MIN = UNKNOWN_CONNECTION_REQUEST_RESPONSE;
constexpr ConnectionRequestResponse ConnectionRequestResponse_MAX = NOT_SENT;
constexpr int ConnectionRequestResponse_ARRAYSIZE = ConnectionRequestResponse_MAX + 1;

const std::string& ConnectionRequestResponse_Name(ConnectionRequestResponse value);
template<typename T>
inline const std::string& ConnectionRequestResponse_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ConnectionRequestResponse>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ConnectionRequestResponse_Name.");
  return ConnectionRequestResponse_Name(static_cast<ConnectionRequestResponse>(enum_t_value));
}
bool ConnectionRequestResponse_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ConnectionRequestResponse* value);
enum ConnectionAttemptResult : int {
  UNKNOWN_CONNECTION_ATTEMPT_RESULT = 0,
  RESULT_SUCCESS = 1,
  RESULT_ERROR = 2,
  RESULT_CANCELLED = 3
};
bool ConnectionAttemptResult_IsValid(int value);
constexpr ConnectionAttemptResult ConnectionAttemptResult_MIN = UNKNOWN_CONNECTION_ATTEMPT_RESULT;
constexpr ConnectionAttemptResult ConnectionAttemptResult_MAX = RESULT_CANCELLED;
constexpr int ConnectionAttemptResult_ARRAYSIZE = ConnectionAttemptResult_MAX + 1;

const std::string& ConnectionAttemptResult_Name(ConnectionAttemptResult value);
template<typename T>
inline const std::string& ConnectionAttemptResult_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ConnectionAttemptResult>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ConnectionAttemptResult_Name.");
  return ConnectionAttemptResult_Name(static_cast<ConnectionAttemptResult>(enum_t_value));
}
bool ConnectionAttemptResult_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ConnectionAttemptResult* value);
enum ConnectionAttemptDirection : int {
  UNKNOWN_CONNECTION_ATTEMPT_DIRECTION = 0,
  INCOMING = 1,
  OUTGOING = 2
};
bool ConnectionAttemptDirection_IsValid(int value);
constexpr ConnectionAttemptDirection ConnectionAttemptDirection_MIN = UNKNOWN_CONNECTION_ATTEMPT_DIRECTION;
constexpr ConnectionAttemptDirection ConnectionAttemptDirection_MAX = OUTGOING;
constexpr int ConnectionAttemptDirection_ARRAYSIZE = ConnectionAttemptDirection_MAX + 1;

const std::string& ConnectionAttemptDirection_Name(ConnectionAttemptDirection value);
template<typename T>
inline const std::string& ConnectionAttemptDirection_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ConnectionAttemptDirection>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ConnectionAttemptDirection_Name.");
  return ConnectionAttemptDirection_Name(static_cast<ConnectionAttemptDirection>(enum_t_value));
}
bool ConnectionAttemptDirection_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ConnectionAttemptDirection* value);
enum ConnectionAttemptType : int {
  UNKNOWN_CONNECTION_ATTEMPT_TYPE = 0,
  INITIAL = 1,
  UPGRADE = 2
};
bool ConnectionAttemptType_IsValid(int value);
constexpr ConnectionAttemptType ConnectionAttemptType_MIN = UNKNOWN_CONNECTION_ATTEMPT_TYPE;
constexpr ConnectionAttemptType ConnectionAttemptType_MAX = UPGRADE;
constexpr int ConnectionAttemptType_ARRAYSIZE = ConnectionAttemptType_MAX + 1;

const std::string& ConnectionAttemptType_Name(ConnectionAttemptType value);
template<typename T>
inline const std::string& ConnectionAttemptType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ConnectionAttemptType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ConnectionAttemptType_Name.");
  return ConnectionAttemptType_Name(static_cast<ConnectionAttemptType>(enum_t_value));
}
bool ConnectionAttemptType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ConnectionAttemptType* value);
enum DisconnectionReason : int {
  UNKNOWN_DISCONNECTION_REASON = 0,
  LOCAL_DISCONNECTION = 1,
  REMOTE_DISCONNECTION = 2,
  IO_ERROR = 3,
  UPGRADED = 4,
  SHUTDOWN = 5,
  UNFINISHED = 6
};
bool DisconnectionReason_IsValid(int value);
constexpr DisconnectionReason DisconnectionReason_MIN = UNKNOWN_DISCONNECTION_REASON;
constexpr DisconnectionReason DisconnectionReason_MAX = UNFINISHED;
constexpr int DisconnectionReason_ARRAYSIZE = DisconnectionReason_MAX + 1;

const std::string& DisconnectionReason_Name(DisconnectionReason value);
template<typename T>
inline const std::string& DisconnectionReason_Name(T enum_t_value) {
  static_assert(::std::is_same<T, DisconnectionReason>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function DisconnectionReason_Name.");
  return DisconnectionReason_Name(static_cast<DisconnectionReason>(enum_t_value));
}
bool DisconnectionReason_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, DisconnectionReason* value);
enum PayloadType : int {
  UNKNOWN_PAYLOAD_TYPE = 0,
  BYTES = 1,
  FILE = 2,
  STREAM = 3
};
bool PayloadType_IsValid(int value);
constexpr PayloadType PayloadType_MIN = UNKNOWN_PAYLOAD_TYPE;
constexpr PayloadType PayloadType_MAX = STREAM;
constexpr int PayloadType_ARRAYSIZE = PayloadType_MAX + 1;

const std::string& PayloadType_Name(PayloadType value);
template<typename T>
inline const std::string& PayloadType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PayloadType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PayloadType_Name.");
  return PayloadType_Name(static_cast<PayloadType>(enum_t_value));
}
bool PayloadType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PayloadType* value);
enum PayloadStatus : int {
  UNKNOWN_PAYLOAD_STATUS = 0,
  SUCCESS = 1,
  LOCAL_ERROR = 2,
  REMOTE_ERROR = 3,
  ENDPOINT_IO_ERROR = 4,
  MOVED_TO_NEW_MEDIUM = 5,
  CONNECTION_CLOSED = 6,
  LOCAL_CANCELLATION = 7,
  REMOTE_CANCELLATION = 8,
  ENDPOINT_UNENCRYPTED = 9
};
bool PayloadStatus_IsValid(int value);
constexpr PayloadStatus PayloadStatus_MIN = UNKNOWN_PAYLOAD_STATUS;
constexpr PayloadStatus PayloadStatus_MAX = ENDPOINT_UNENCRYPTED;
constexpr int PayloadStatus_ARRAYSIZE = PayloadStatus_MAX + 1;

const std::string& PayloadStatus_Name(PayloadStatus value);
template<typename T>
inline const std::string& PayloadStatus_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PayloadStatus>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PayloadStatus_Name.");
  return PayloadStatus_Name(static_cast<PayloadStatus>(enum_t_value));
}
bool PayloadStatus_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PayloadStatus* value);
enum Bandwidth : int {
  BANDWIDTH_UNKNOWN = 0,
  BANDWIDTH_24_GHZ = 1,
  BANDWIDTH_5_GHZ = 2,
  BANDWIDTH_6_GHZ = 3
};
bool Bandwidth_IsValid(int value);
constexpr Bandwidth Bandwidth_MIN = BANDWIDTH_UNKNOWN;
constexpr Bandwidth Bandwidth_MAX = BANDWIDTH_6_GHZ;
constexpr int Bandwidth_ARRAYSIZE = Bandwidth_MAX + 1;

const std::string& Bandwidth_Name(Bandwidth value);
template<typename T>
inline const std::string& Bandwidth_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Bandwidth>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Bandwidth_Name.");
  return Bandwidth_Name(static_cast<Bandwidth>(enum_t_value));
}
bool Bandwidth_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Bandwidth* value);
enum BandwidthUpgradeResult : int {
  UNKNOWN_BANDWIDTH_UPGRADE_RESULT = 0,
  UPGRADE_RESULT_SUCCESS = 1,
  UPGRADE_RESULT_ERROR = 2,
  MEDIUM_ERROR = 3,
  PROTOCOL_ERROR = 4,
  RESULT_IO_ERROR = 5,
  CHANNEL_ERROR = 6,
  ALREADY_ON_MEDIUM_ERROR = 7,
  UNFINISHED_ERROR = 10,
  BLUETOOTH_MEDIUM_ERROR = 11,
  WIFI_AWARE_MEDIUM_ERROR = 12,
  WIFI_LAN_MEDIUM_ERROR = 13,
  WIFI_HOTSPOT_MEDIUM_ERROR = 14,
  WIFI_DIRECT_MEDIUM_ERROR = 15,
  WEB_RTC_MEDIUM_ERROR = 16,
  RESULT_REMOTE_ERROR = 17,
  ATTEMPT_SKIPPED = 18
};
bool BandwidthUpgradeResult_IsValid(int value);
constexpr BandwidthUpgradeResult BandwidthUpgradeResult_MIN = UNKNOWN_BANDWIDTH_UPGRADE_RESULT;
constexpr BandwidthUpgradeResult BandwidthUpgradeResult_MAX = ATTEMPT_SKIPPED;
constexpr int BandwidthUpgradeResult_ARRAYSIZE = BandwidthUpgradeResult_MAX + 1;

const std::string& BandwidthUpgradeResult_Name(BandwidthUpgradeResult value);
template<typename T>
inline const std::string& BandwidthUpgradeResult_Name(T enum_t_value) {
  static_assert(::std::is_same<T, BandwidthUpgradeResult>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function BandwidthUpgradeResult_Name.");
  return BandwidthUpgradeResult_Name(static_cast<BandwidthUpgradeResult>(enum_t_value));
}
bool BandwidthUpgradeResult_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, BandwidthUpgradeResult* value);
enum BandwidthUpgradeErrorStage : int {
  UNKNOWN_BANDWIDTH_UPGRADE_ERROR_STAGE = 0,
  CLIENT_INTRODUCTION = 1,
  NETWORK_AVAILABLE = 2,
  LAST_WRITE_TO_PRIOR_CHANNEL = 3,
  SAFE_TO_CLOSE_PRIOR_CHANNEL = 4,
  SOCKET_CREATION = 5,
  PRIOR_ENDPOINT_CHANNEL = 6,
  UPGRADE_UNFINISHED = 7,
  UPGRADE_SUCCESS = 8,
  UPGRADE_CANCEL = 9,
  WIFI_START_HOTSPOT = 10,
  WIFI_LISTEN_INCOMING = 11,
  WIFI_CONNECT_TO_HOTSPOT = 12,
  WIFI_HOTSPOT_SOCKET_CREATION = 28,
  WIFI_LAN_LISTEN_INCOMING = 13,
  WIFI_LAN_IP_ADDRESS = 14,
  WIFI_LAN_SOCKET_CREATION = 29,
  WIFI_LAN_SOCKET_CONNECTION = 15,
  BLUETOOTH_LISTEN_INCOMING = 16,
  BLUETOOTH_OBTAIN_MAC_ADDRESS = 17,
  BLUETOOTH_CONNECT_OUTGOING = 18,
  BLUETOOTH_PARSE_MAC_ADDRESS = 19,
  BLUETOOTH_SOCKET_CREATION = 30,
  WIFI_AWARE_LISTEN_INCOMING = 20,
  WIFI_AWARE_PUBLISH = 21,
  WIFI_AWARE_SUBSCRIBE = 22,
  WIFI_AWARE_CONNECT_TO_NETWORK = 23,
  WIFI_AWARE_SOCKET_CREATION = 31,
  WIFI_DIRECT_LISTEN_INCOMING = 24,
  WIFI_DIRECT_CREATE_GROUP = 25,
  WIFI_DIRECT_CONNECT_OUTGOING = 26,
  WIFI_DIRECT_PARSE_DEVICE_ADDRESS = 27,
  WIFI_DIRECT_SOCKET_CREATION = 32,
  WEB_RTC_SOCKET_CREATION = 33,
  WEB_RTC_LISTEN_INCOMING = 34
};
bool BandwidthUpgradeErrorStage_IsValid(int value);
constexpr BandwidthUpgradeErrorStage BandwidthUpgradeErrorStage_MIN = UNKNOWN_BANDWIDTH_UPGRADE_ERROR_STAGE;
constexpr BandwidthUpgradeErrorStage BandwidthUpgradeErrorStage_MAX = WEB_RTC_LISTEN_INCOMING;
constexpr int BandwidthUpgradeErrorStage_ARRAYSIZE = BandwidthUpgradeErrorStage_MAX + 1;

const std::string& BandwidthUpgradeErrorStage_Name(BandwidthUpgradeErrorStage value);
template<typename T>
inline const std::string& BandwidthUpgradeErrorStage_Name(T enum_t_value) {
  static_assert(::std::is_same<T, BandwidthUpgradeErrorStage>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function BandwidthUpgradeErrorStage_Name.");
  return BandwidthUpgradeErrorStage_Name(static_cast<BandwidthUpgradeErrorStage>(enum_t_value));
}
bool BandwidthUpgradeErrorStage_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, BandwidthUpgradeErrorStage* value);
enum LogSource : int {
  UNSPECIFIED_SOURCE = 0,
  LAB_DEVICES = 1,
  INTERNAL_DEVICES = 2,
  BETA_TESTER_DEVICES = 3,
  OEM_DEVICES = 4,
  DEBUG_DEVICES = 5
};
bool LogSource_IsValid(int value);
constexpr LogSource LogSource_MIN = UNSPECIFIED_SOURCE;
constexpr LogSource LogSource_MAX = DEBUG_DEVICES;
constexpr int LogSource_ARRAYSIZE = LogSource_MAX + 1;

const std::string& LogSource_Name(LogSource value);
template<typename T>
inline const std::string& LogSource_Name(T enum_t_value) {
  static_assert(::std::is_same<T, LogSource>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function LogSource_Name.");
  return LogSource_Name(static_cast<LogSource>(enum_t_value));
}
bool LogSource_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LogSource* value);
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace connections
}  // namespace proto
}  // namespace nearby
}  // namespace location

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::location::nearby::proto::connections::EventType> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::ConnectionsStrategy> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::SessionRole> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::Medium> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::ConnectionTechnology> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::ConnectionBand> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::ConnectionRequestResponse> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::ConnectionAttemptResult> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::ConnectionAttemptDirection> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::ConnectionAttemptType> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::DisconnectionReason> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::PayloadType> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::PayloadStatus> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::Bandwidth> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::BandwidthUpgradeResult> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::BandwidthUpgradeErrorStage> : ::std::true_type {};
template <> struct is_proto_enum< ::location::nearby::proto::connections::LogSource> : ::std::true_type {};

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_proto_2fconnections_5fenums_2eproto