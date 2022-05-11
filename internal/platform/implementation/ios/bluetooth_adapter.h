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

#ifndef THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_IMPLEMENTATION_IOS_BLUETOOTH_ADAPTER_H_
#define THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_IMPLEMENTATION_IOS_BLUETOOTH_ADAPTER_H_

#include <string>

#include "internal/platform/implementation/ble_v2.h"
#include "internal/platform/implementation/bluetooth_adapter.h"

namespace location {
namespace nearby {
namespace ios {

class BluetoothAdapter;

// Concrete BlePeripheral implementation.
class BlePeripheral : public api::ble_v2::BlePeripheral {
 public:
  std::string GetAddress() const override;

 private:
  // Only BluetoothAdapter may instantiate BlePeripheral.
  friend class BluetoothAdapter;

  explicit BlePeripheral(BluetoothAdapter* adapter);

  BluetoothAdapter& adapter_;
};

// Concrete BluetoothAdapter implementation.
class BluetoothAdapter : public api::BluetoothAdapter {
 public:
  using Status = api::BluetoothAdapter::Status;
  using ScanMode = api::BluetoothAdapter::ScanMode;

  ~BluetoothAdapter() override;

  bool SetStatus(Status status) override;
  bool IsEnabled() const override;
  ScanMode GetScanMode() const override;
  bool SetScanMode(ScanMode mode) override;
  std::string GetName() const override;
  bool SetName(absl::string_view name) override;
  std::string GetMacAddress() const override;

  BlePeripheral& GetPeripheral();

 private:
  BlePeripheral peripheral_{this};
  ScanMode mode_ = ScanMode::kNone;
  std::string name_;
  std::string mac_address_;
  bool enabled_ = true;
};

}  // namespace ios
}  // namespace nearby
}  // namespace location

#endif  // THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_IMPLEMENTATION_IOS_BLUETOOTH_ADAPTER_H_
