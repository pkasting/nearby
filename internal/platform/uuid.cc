// Copyright 2020 Google LLC
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

#include "internal/platform/uuid.h"

#include <iomanip>
#include <sstream>
#include <string>

#include "absl/strings/escaping.h"
#include "internal/platform/implementation/crypto.h"

namespace location {
namespace nearby {
namespace {
std::ostream& write_hex(std::ostream& os, absl::string_view data) {
  for (const auto b : data) {
    os << std::setfill('0') << std::setw(2) << std::hex << std::uppercase
       << (static_cast<unsigned int>(b) & 0x0ff);
  }
  return os;
}
}  // namespace

Uuid::Uuid(absl::string_view data) {
  // Based on the Java counterpart at
  // http://androidxref.com/8.0.0_r4/xref/libcore/ojluni/src/main/java/java/util/UUID.java#162.
  std::string md5_data(Crypto::Md5(data));
  md5_data[6] &= 0x0f;  // Clear version.
  md5_data[6] |= 0x30;  // Set to version 3.
  md5_data[8] &= 0x3f;  // Clear variant.
  md5_data[8] |= 0x80;  // Set to IETF variant.

  std::uint64_t msb = 0;
  std::uint64_t lsb = 0;
  for (int i = 0; i < 8; i++) {
    msb = (msb << 8) | (md5_data[i] & 0xff);
  }
  for (int i = 8; i < 16; i++) {
    lsb = (lsb << 8) | (md5_data[i] & 0xff);
  }
  most_sig_bits_ = msb;
  least_sig_bits_ = lsb;
}

Uuid::operator std::string() const { return ToCanonicalString(data()); }

std::string Uuid::Get16BitAsString() const {
  std::ostringstream sixteen_bit_string;

  char data = static_cast<char>((most_sig_bits_ >> 40) & 0x0ff);
  write_hex(sixteen_bit_string, absl::string_view(&data, 1));
  data = static_cast<char>((most_sig_bits_ >> 32) & 0x0ff);
  write_hex(sixteen_bit_string, absl::string_view(&data, 1));

  return sixteen_bit_string.str();
}

std::string Uuid::data() const {
  return absl::StrCat(
      std::string(1, static_cast<char>((most_sig_bits_ >> 56) & 0x0ff)),
      std::string(1, static_cast<char>((most_sig_bits_ >> 48) & 0x0ff)),
      std::string(1, static_cast<char>((most_sig_bits_ >> 40) & 0x0ff)),
      std::string(1, static_cast<char>((most_sig_bits_ >> 32) & 0x0ff)),
      std::string(1, static_cast<char>((most_sig_bits_ >> 24) & 0x0ff)),
      std::string(1, static_cast<char>((most_sig_bits_ >> 16) & 0x0ff)),
      std::string(1, static_cast<char>((most_sig_bits_ >> 8) & 0x0ff)),
      std::string(1, static_cast<char>((most_sig_bits_ >> 0) & 0x0ff)),
      std::string(1, static_cast<char>((least_sig_bits_ >> 56) & 0x0ff)),
      std::string(1, static_cast<char>((least_sig_bits_ >> 48) & 0x0ff)),
      std::string(1, static_cast<char>((least_sig_bits_ >> 40) & 0x0ff)),
      std::string(1, static_cast<char>((least_sig_bits_ >> 32) & 0x0ff)),
      std::string(1, static_cast<char>((least_sig_bits_ >> 24) & 0x0ff)),
      std::string(1, static_cast<char>((least_sig_bits_ >> 16) & 0x0ff)),
      std::string(1, static_cast<char>((least_sig_bits_ >> 8) & 0x0ff)),
      std::string(1, static_cast<char>((least_sig_bits_ >> 0) & 0x0ff)));
}

std::string Uuid::ToCanonicalString(const std::string& data) const {
  // Based on the Java counterpart at
  // http://androidxref.com/8.0.0_r4/xref/libcore/ojluni/src/main/java/java/util/UUID.java#375.
  std::ostringstream md5_hex;
  write_hex(md5_hex, absl::string_view(&data[0], 4));
  md5_hex << "-";
  write_hex(md5_hex, absl::string_view(&data[4], 2));
  md5_hex << "-";
  write_hex(md5_hex, absl::string_view(&data[6], 2));
  md5_hex << "-";
  write_hex(md5_hex, absl::string_view(&data[8], 2));
  md5_hex << "-";
  write_hex(md5_hex, absl::string_view(&data[10], 6));

  return md5_hex.str();
}

bool Uuid::operator==(const Uuid& rhs) const {
  return GetMostSigBits() == rhs.GetMostSigBits() &&
         GetLeastSigBits() == rhs.GetLeastSigBits();
}

}  // namespace nearby
}  // namespace location
