// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "internal/platform/implementation/windows/ble_medium.h"

#include <array>

#include "gmock/gmock.h"
#include "protobuf-matchers/protocol-buffer-matchers.h"
#include "gtest/gtest.h"
#include "absl/synchronization/notification.h"
#include "internal/platform/implementation/ble.h"
#include "internal/platform/implementation/bluetooth_adapter.h"
#include "internal/platform/implementation/windows/ble.h"
#include "internal/platform/implementation/windows/bluetooth_adapter.h"

namespace location {
namespace nearby {
namespace windows {
namespace {

constexpr uint8_t kVersionBitmask = 0xE0;
constexpr uint8_t kSocketVersionBitmask = 0x1C;
constexpr uint8_t kFastAdvertisementFlagBitmask = 0x02;
constexpr uint8_t kPcpBitmask = 0x1F;
constexpr uint8_t kVisibilityBitmask = 0x01;

TEST(BleMedium, DISABLED_StartAdvertising) {
  BluetoothAdapter bluetoothAdapter;
  BleMedium ble_medium(bluetoothAdapter);

  std::array<char, 27> advertising_data_byte_array;

  // (1 byte) version [3-bits] + socket_version [3-bits] +
  // fast_advertisement_flag [1-bit] + reserved [1-bit]
  uint8_t ble_medium_version = 0x02;  // mediums::BleAdvertisement::Version::kV2
  uint8_t socket_version =
      0x02;  // mediums::BleAdvertisement::SocketVersion::kV2
  bool fast_advertisement = true;  // Is Fast Advertisement

  uint8_t ble_medium_advertisement_metadata_byte =
      (ble_medium_version << 5) & kVersionBitmask;
  ble_medium_advertisement_metadata_byte |=
      (socket_version << 2) & kSocketVersionBitmask;
  ble_medium_advertisement_metadata_byte |=
      ((fast_advertisement ? 1 : 0) << 1) & kFastAdvertisementFlagBitmask;

  advertising_data_byte_array.at(0) =
      static_cast<unsigned char>(ble_medium_advertisement_metadata_byte);

  // (1 byte) body_length
  advertising_data_byte_array.at(1) = static_cast<unsigned char>(
      0x19);  // always 25 bytes for Fast Advertisement

  // (1 byte) Nearby Connection version [3-bits] + pcp [5-bits]
  uint8_t ble_connections_version =
      0x01;            // connections::BleAdvertisement::Version::kV1
  uint8_t pcp = 0x02;  // connections::Pcp::kP2pCluster

  uint8_t ble_connections_advertisement_metadata_byte =
      (ble_connections_version << 5) & kVersionBitmask;
  ble_connections_advertisement_metadata_byte |= pcp & kPcpBitmask;
  advertising_data_byte_array.at(2) =
      static_cast<unsigned char>(ble_connections_advertisement_metadata_byte);

  // (4 bytes) endpoint_id
  for (int i = 0; i < 4; ++i) {
    advertising_data_byte_array.at(3 + i) = static_cast<unsigned char>(0x00);
  }

  // (1 byte) endpoint_info_size
  advertising_data_byte_array.at(7) = static_cast<unsigned char>(
      0x11);  // always 17-bytes for Fast Advertisement

  // =========endpoint_info [17-bytes]============
  // (1 byte) Nearby Share version [3-bits] + visibility [1-bit] + reserved
  // [4-bits]
  uint8_t nearby_share_version = 0x00;  // nearby share v1
  uint8_t visibility = 0x00;  // [placeholder] sharing::Visibility::kAllContacts

  uint8_t nearby_share_metadata_byte =
      (nearby_share_version << 5) & kVersionBitmask;
  nearby_share_metadata_byte |= ((visibility & kVisibilityBitmask) << 4);

  advertising_data_byte_array.at(8) = static_cast<unsigned char>(0x00);

  // (2 bytes) salt
  for (int i = 0; i < 2; ++i) {
    advertising_data_byte_array.at(9 + i) = static_cast<unsigned char>(0x00);
  }

  // (14 bytes) encrypted_metadata_key
  for (int i = 0; i < 14; ++i) {
    advertising_data_byte_array.at(11 + i) = static_cast<unsigned char>(0x00);
  }
  // =========endpoint_info [17-bytes]============

  // (2 bytes) device_token
  for (int i = 0; i < 2; ++i) {
    advertising_data_byte_array.at(25 + i) = static_cast<unsigned char>(0x00);
  }

  ByteArray advertising_data(advertising_data_byte_array);

  EXPECT_TRUE(
      ble_medium.StartAdvertising("NearbyShare", advertising_data, "\xfe\xf3"));
}

TEST(BleMedium, DISABLED_StopAdvertising) {
  BluetoothAdapter bluetoothAdapter;
  BleMedium ble_medium(bluetoothAdapter);

  std::array<char, 2> advertising_data_byte_array;

  // (2 bytes) 16-bit Service UUID 0xf3fe
  advertising_data_byte_array.at(0) = static_cast<unsigned char>(0xf3);
  advertising_data_byte_array.at(1) = static_cast<unsigned char>(0xfe);

  ByteArray advertising_data(advertising_data_byte_array);

  EXPECT_TRUE(
      ble_medium.StartAdvertising("NearbyShare", advertising_data, "\xfe\xf3"));
  EXPECT_TRUE(ble_medium.StopAdvertising("NearbyShare"));
}

TEST(BleMedium, DISABLED_StartScanning) {
  BluetoothAdapter bluetoothAdapter;
  BleMedium ble_medium(bluetoothAdapter);

  BleMedium::DiscoveredPeripheralCallback discovered_peripheral_callback = {
      .peripheral_discovered_cb = [this](api::BlePeripheral& peripheral,
                                         const std::string& service_id,
                                         bool fast_advertisement) {},
      .peripheral_lost_cb = [this](api::BlePeripheral& peripheral,
                                   const std::string& service_id) {}};

  EXPECT_TRUE(ble_medium.StartScanning("NearbyShare", "\xfe\xf3",
                                       discovered_peripheral_callback));
}

TEST(BleMedium, DISABLED_ReceiveAdvertisement) {
  absl::Notification advertisement_received_notification;

  BluetoothAdapter bluetoothAdapter;
  BleMedium ble_medium(bluetoothAdapter);

  BleMedium::DiscoveredPeripheralCallback discovered_peripheral_callback = {
      .peripheral_discovered_cb =
          [this, &advertisement_received_notification](
              api::BlePeripheral& peripheral, const std::string& service_id,
              bool fast_advertisement) {
            advertisement_received_notification.Notify();
          },
      .peripheral_lost_cb = [this](api::BlePeripheral& peripheral,
                                   const std::string& service_id) {}};

  EXPECT_TRUE(ble_medium.StartScanning("NearbyShare", "\xfe\xf3",
                                       discovered_peripheral_callback));
  EXPECT_TRUE(
      advertisement_received_notification.WaitForNotificationWithTimeout(
          absl::Seconds(5)));
}

TEST(BleMedium, DISABLED_StopScanning) {
  BluetoothAdapter bluetoothAdapter;
  BleMedium ble_medium(bluetoothAdapter);

  BleMedium::DiscoveredPeripheralCallback discovered_peripheral_callback = {
      .peripheral_discovered_cb =
          [this](api::BlePeripheral& peripheral, const std::string& service_id,
                 bool fast_advertisement) { EXPECT_TRUE(fast_advertisement); },
      .peripheral_lost_cb = [this](api::BlePeripheral& peripheral,
                                   const std::string& service_id) {}};

  EXPECT_TRUE(ble_medium.StartScanning("NearbyShare", "\xfe\xf3",
                                       discovered_peripheral_callback));
  EXPECT_TRUE(ble_medium.StopScanning("NearbyShare"));
}

}  // namespace
}  // namespace windows
}  // namespace nearby
}  // namespace location
