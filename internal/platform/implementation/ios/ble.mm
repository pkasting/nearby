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

#import "internal/platform/implementation/ios/ble.h"

#include <CoreBluetooth/CoreBluetooth.h>

#include <string>

#include "internal/platform/implementation/ble_v2.h"
#import "internal/platform/implementation/ios/Mediums/Ble/GNCMBleCentral.h"
#import "internal/platform/implementation/ios/Mediums/Ble/GNCMBlePeripheral.h"
#include "internal/platform/implementation/ios/bluetooth_adapter.h"
#include "internal/platform/implementation/ios/utils.h"

namespace location {
namespace nearby {
namespace ios {

using ::location::nearby::api::ble_v2::BleAdvertisementData;
using ::location::nearby::api::ble_v2::PowerMode;
using ScanCallback = ::location::nearby::api::ble_v2::BleMedium::ScanCallback;

BleMedium::BleMedium(::location::nearby::api::BluetoothAdapter& adapter)
    : adapter_(static_cast<BluetoothAdapter*>(&adapter)) {}

bool BleMedium::StartAdvertising(const BleAdvertisementData& advertising_data,
                                 const BleAdvertisementData& scan_response_data,
                                 PowerMode power_mode) {
  const std::string& service_uuid = advertising_data.service_data.begin()->first;
  const ByteArray& service_data_bytes = advertising_data.service_data.begin()->second;
  peripheral_ = [[GNCMBlePeripheral alloc]
      initWithServiceUUID:ObjCStringFromCppString(service_uuid)
        advertisementData:NSDataFromByteArray(service_data_bytes)];

  return true;
}

bool BleMedium::StopAdvertising() {
  peripheral_ = nil;
  return true;
}

bool BleMedium::StartScanning(const std::vector<std::string>& service_uuids, PowerMode power_mode,
                              ScanCallback scan_callback) {
  central_ =
      [[GNCMBleCentral alloc] initWithServiceUUID:ObjCStringFromCppString(*service_uuids.begin())
                                scanResultHandler:^(NSString* serviceUUID, NSData* serviceData){
                                    // TODO(b/228751356): Add scan callback implementation.
                                }];

  return true;
}

bool BleMedium::StopScanning() {
  central_ = nil;
  return true;
}

std::unique_ptr<api::ble_v2::GattServer> StartGattServer(
    api::ble_v2::ServerGattConnectionCallback callback) {
  return nullptr;
}

std::unique_ptr<api::ble_v2::ClientGattConnection> ConnectToGattServer(
    BlePeripheral& peripheral, api::ble_v2::BleMedium::Mtu mtu, PowerMode power_mode,
    api::ble_v2::ClientGattConnectionCallback callback) {
  return nullptr;
}

std::unique_ptr<api::ble_v2::BleSocket> Connect(const std::string& service_id, PowerMode power_mode,
                                                api::ble_v2::BlePeripheral& peripheral,
                                                CancellationFlag* cancellation_flag) {
  return nullptr;
}

std::unique_ptr<api::ble_v2::GattServer> BleMedium::StartGattServer(
    api::ble_v2::ServerGattConnectionCallback callback) {
  return nullptr;
}

bool BleMedium::StartListeningForIncomingBleSockets(
    const api::ble_v2::ServerBleSocketLifeCycleCallback& callback) {
  return false;
}

void BleMedium::StopListeningForIncomingBleSockets() {}

std::unique_ptr<api::ble_v2::ClientGattConnection> BleMedium::ConnectToGattServer(
    api::ble_v2::BlePeripheral& peripheral, Mtu mtu, PowerMode power_mode,
    api::ble_v2::ClientGattConnectionCallback callback) {
  return nullptr;
}

std::unique_ptr<api::ble_v2::BleSocket> BleMedium::EstablishBleSocket(
    api::ble_v2::BlePeripheral* peripheral,
    const api::ble_v2::BleSocketLifeCycleCallback& callback) {
  return nullptr;
}

}  // namespace ios
}  // namespace nearby
}  // namespace location
