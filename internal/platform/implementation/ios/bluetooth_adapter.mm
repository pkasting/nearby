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

#import "internal/platform/implementation/ios/bluetooth_adapter.h"

#include <string>

#include "absl/strings/string_view.h"
#include "internal/platform/implementation/bluetooth_adapter.h"

namespace location {
namespace nearby {
namespace ios {

BlePeripheral::BlePeripheral(BluetoothAdapter* adapter) : adapter_(*adapter) {}

std::string BlePeripheral::GetAddress() const { return adapter_.GetMacAddress(); }

BluetoothAdapter::~BluetoothAdapter() { SetStatus(Status::kDisabled); }

bool BluetoothAdapter::SetStatus(Status status) {
  enabled_ = status == Status::kEnabled;
  return true;
}

bool BluetoothAdapter::IsEnabled() const { return enabled_; }

BluetoothAdapter::ScanMode BluetoothAdapter::GetScanMode() const { return mode_; }

bool BluetoothAdapter::SetScanMode(BluetoothAdapter::ScanMode mode) { return false; }

std::string BluetoothAdapter::GetName() const { return name_; }

bool BluetoothAdapter::SetName(absl::string_view name) {
  name_ = std::string(name);
  return true;
}

std::string BluetoothAdapter::GetMacAddress() const { return mac_address_; }

BlePeripheral& BluetoothAdapter::GetPeripheral() { return peripheral_; }

}  // namespace ios
}  // namespace nearby
}  // namespace location
