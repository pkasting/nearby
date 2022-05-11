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

#ifndef THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_IMPLEMENTATION_IOS_BLE_H_
#define THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_IMPLEMENTATION_IOS_BLE_H_

#import <Foundation/Foundation.h>

#include <string>

#include "internal/platform/cancellation_flag.h"
#include "internal/platform/implementation/ble_v2.h"
#import "internal/platform/implementation/bluetooth_adapter.h"
#import "internal/platform/implementation/ios/bluetooth_adapter.h"

@class GNCMBlePeripheral, GNCMBleCentral;

namespace location {
namespace nearby {
namespace ios {

/** Concrete BleMedium implementation. */
class BleMedium : public api::ble_v2::BleMedium {
 public:
  explicit BleMedium(api::BluetoothAdapter& adapter);

  // api::BleMedium:
  bool StartAdvertising(
      const api::ble_v2::BleAdvertisementData& advertising_data,
      const api::ble_v2::BleAdvertisementData& scan_response_data,
      api::ble_v2::PowerMode power_mode) override;
  bool StopAdvertising() override;
  bool StartScanning(
      const std::vector<std::string>& service_uuids,
      api::ble_v2::PowerMode power_mode,
      api::ble_v2::BleMedium::ScanCallback scan_callback) override;
  bool StopScanning() override;
  std::unique_ptr<api::ble_v2::GattServer> StartGattServer(
      api::ble_v2::ServerGattConnectionCallback callback) override;
  bool StartListeningForIncomingBleSockets(
      const api::ble_v2::ServerBleSocketLifeCycleCallback& callback) override;
  void StopListeningForIncomingBleSockets() override;
  std::unique_ptr<api::ble_v2::ClientGattConnection> ConnectToGattServer(
      api::ble_v2::BlePeripheral& peripheral, Mtu mtu,
      api::ble_v2::PowerMode power_mode,
      api::ble_v2::ClientGattConnectionCallback callback) override;
  std::unique_ptr<api::ble_v2::BleSocket> EstablishBleSocket(
      api::ble_v2::BlePeripheral* peripheral,
      const api::ble_v2::BleSocketLifeCycleCallback& callback) override;

 private:
  // // These are used to wait for all async BLE callbacks to finish.
  // dispatch_semaphore_t peripheral_callbacks_barrier_;
  // dispatch_semaphore_t central_callbacks_barrier_;
  BluetoothAdapter *adapter_;
  GNCMBlePeripheral *peripheral_;
  GNCMBleCentral *central_;
  dispatch_queue_t callback_queue_;
};

}  // namespace ios
}  // namespace nearby
}  // namespace location

#endif  // THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_IMPLEMENTATION_IOS_BLE_H_
