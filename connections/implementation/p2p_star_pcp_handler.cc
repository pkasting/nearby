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

#include "connections/implementation/p2p_star_pcp_handler.h"

#include <vector>

#include "internal/platform/logging.h"

namespace location {
namespace nearby {
namespace connections {

P2pStarPcpHandler::P2pStarPcpHandler(
    Mediums& mediums, EndpointManager& endpoint_manager,
    EndpointChannelManager& channel_manager, BwuManager& bwu_manager,
    InjectedBluetoothDeviceStore& injected_bluetooth_device_store, Pcp pcp)
    : P2pClusterPcpHandler(&mediums, &endpoint_manager, &channel_manager,
                           &bwu_manager, injected_bluetooth_device_store, pcp) {
}

std::vector<proto::connections::Medium>
P2pStarPcpHandler::GetConnectionMediumsByPriority() {
  std::vector<proto::connections::Medium> mediums;
  if (mediums_->GetWifiHotspot().IsAvailable()) {
    mediums.push_back(proto::connections::WIFI_HOTSPOT);
  }
  if (mediums_->GetWifiLan().IsAvailable()) {
    mediums.push_back(proto::connections::WIFI_LAN);
  }
  if (mediums_->GetWebRtc().IsAvailable()) {
    mediums.push_back(proto::connections::WEB_RTC);
  }
  if (mediums_->GetBluetoothClassic().IsAvailable()) {
    mediums.push_back(proto::connections::BLUETOOTH);
  }
  if (mediums_->GetBle().IsAvailable()) {
    mediums.push_back(proto::connections::BLE);
  }
  return mediums;
}

proto::connections::Medium P2pStarPcpHandler::GetDefaultUpgradeMedium() {
  return proto::connections::Medium::WIFI_HOTSPOT;
}

bool P2pStarPcpHandler::CanSendOutgoingConnection(ClientProxy* client) const {
  // For star, we can only send an outgoing connection while we have no other
  // connections.
  return !this->HasOutgoingConnections(client) &&
         !this->HasIncomingConnections(client);
}

bool P2pStarPcpHandler::CanReceiveIncomingConnection(
    ClientProxy* client) const {
  // For star, we can only receive an incoming connection if we've sent no
  // outgoing connections.
  return !this->HasOutgoingConnections(client);
}

}  // namespace connections
}  // namespace nearby
}  // namespace location
