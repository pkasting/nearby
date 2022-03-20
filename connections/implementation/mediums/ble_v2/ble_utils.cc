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

#include "connections/implementation/mediums/ble_v2/ble_utils.h"

#include <string>

namespace location {
namespace nearby {
namespace connections {
namespace mediums {
namespace bleutils {

namespace {

// These two values make up the base UUID we use when advertising a slot.
// The base is an all zero Version-3 name-based UUID. To turn this into an
// advertisement slot UUID, we simply OR the least significant bits with the
// slot number.
//
// More info about the format can be found here:
// https://en.wikipedia.org/wiki/Universally_unique_identifier#Versions_3_and_5_(namespace_name-based)
constexpr std::int64_t kAdvertisementUuidMsb = 0x0000000000003000;
constexpr std::int64_t kAdvertisementUuidLsb = 0x8000000000000000;

}  // namespace

ByteArray GenerateHash(const std::string& source, size_t size) {
  return Utils::Sha256Hash(source, size);
}

ByteArray GenerateServiceIdHash(const std::string& service_id,
                                BleAdvertisement::Version version) {
  switch (version) {
      // legacy hash for testing only.
    case BleAdvertisement::Version::kV1:
      return Utils::Sha256Hash(StringToPrintableHexString(service_id),
                               BlePacket::kServiceIdHashLength);
    case BleAdvertisement::Version::kV2:
      [[fallthrough]];
    case BleAdvertisement::Version::kUndefined:
      [[fallthrough]];
    default:
      // Use the latest known hashing scheme.
      return Utils::Sha256Hash(service_id, BlePacket::kServiceIdHashLength);
  }
}

std::string StringToPrintableHexString(const std::string& source) {
  // Print out the byte array as a space separated listing of hex bytes.
  std::string out = "[ ";
  for (const char& c : source) {
    absl::StrAppend(&out, absl::StrFormat("%#04x ", c));
  }
  absl::StrAppend(&out, "]");
  return out;
}

ByteArray GenerateDeviceToken() {
  return Utils::Sha256Hash(std::to_string(Prng().NextUint32()),
                           mediums::BleAdvertisement::kDeviceTokenLength);
}

ByteArray GenerateAdvertisementHash(const ByteArray& advertisement_bytes) {
  return Utils::Sha256Hash(
      advertisement_bytes,
      BleAdvertisementHeader::kAdvertisementHashByteLength);
}

std::string GenerateAdvertisementUuid(int slot) {
  if (slot < 0) {
    return {};
  }
  return std::string(Uuid(kAdvertisementUuidMsb, kAdvertisementUuidLsb | slot));
}

}  // namespace bleutils
}  // namespace mediums
}  // namespace connections
}  // namespace nearby
}  // namespace location