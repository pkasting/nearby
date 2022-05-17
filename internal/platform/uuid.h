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

#ifndef THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_UUID_H_
#define THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_UUID_H_

#include <cstdint>
#include <string>

#include "absl/strings/string_view.h"

namespace location {
namespace nearby {

// A type 3 name-based
// (https://en.wikipedia.org/wiki/Universally_unique_identifier#Versions_3_and_5_(namespace_name-based))
// UUID.
//
// https://developer.android.com/reference/java/util/UUID.html
class Uuid final {
 public:
  Uuid() = default;
  explicit Uuid(absl::string_view data);
  constexpr Uuid(std::uint64_t most_sig_bits, std::uint64_t least_sig_bits)
      : most_sig_bits_(most_sig_bits), least_sig_bits_(least_sig_bits) {}

  std::string data() const;

  // Returns the canonical textual representation
  // (https://en.wikipedia.org/wiki/Universally_unique_identifier#Format) of the
  // UUID.
  explicit operator std::string() const;

  // Get ABCD fom xxxxABCD-xxxx-xxxx-xxxx-xxxxxxxxxxxxxxxx
  //
  // This is needed because Android only support UUID 16 bits in service data
  // section in advertising data
  std::string Get16BitAsString() const;

  std::uint64_t GetMostSigBits() const { return most_sig_bits_; }
  std::uint64_t GetLeastSigBits() const { return least_sig_bits_; }

  // Hashable
  bool operator==(const Uuid &rhs) const;
  template <typename H>
  friend H AbslHashValue(H h, const Uuid &b) {
    return H::combine(std::move(h), b.most_sig_bits_, b.least_sig_bits_);
  }

  bool IsEmpty() const {
    return most_sig_bits_ == 0 && least_sig_bits_ == 0;
  }

 private:
  std::string ToCanonicalString(const std::string& data) const;

  std::uint64_t most_sig_bits_{0};
  std::uint64_t least_sig_bits_{0};
};

}  // namespace nearby
}  // namespace location

#endif  // THIRD_PARTY_NEARBY_INTERNAL_PLATFORM_UUID_H_
