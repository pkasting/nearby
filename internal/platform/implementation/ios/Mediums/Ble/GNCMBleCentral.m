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

#import "internal/platform/implementation/ios/Mediums/Ble/GNCMBleCentral.h"

#include <CoreBluetooth/CoreBluetooth.h>

// #import "googlemac/iPhone/Shared/Nearby/Connections/Source/Mediums/Ble/GNCMBleAdvertisement.h"
// #import "googlemac/iPhone/Shared/Nearby/Connections/Source/Mediums/Ble/GNCMBleConnection.h"
// #import "googlemac/iPhone/Shared/Nearby/Connections/Source/Mediums/Ble/GNCMBleUtils.h"
// #import "googlemac/iPhone/Shared/Nearby/Connections/Source/Mediums/Ble/GNCMBloomFilter.h"
#import "internal/platform/implementation/ios/Mediums/GNCMConnection.h"
// #import "googlemac/iPhone/Shared/Nearby/Sockets/Source/Central/GNSCentralManager.h"
// #import "googlemac/iPhone/Shared/Nearby/Sockets/Source/Central/GNSCentralPeerManager.h"
#import "GoogleToolboxForMac/GTMLogger.h"

// 1. Initializing the central manager
// centralManager = CBCentralManager(delegate: self, queue: nil)
// 2. Monitoring the central manager’s state
// centralManagerDidUpdateState
// 3. Scanning for peripherals
// scanForPeripherals and didDiscover:advertisementData:rssi
// 4. Connect to a peripheral
// Once you’ve obtained a reference to the desired CBPeripheral object, you may attempt to connect
// to it by simply calling the connect(_:options:) connectPeripheral
// 5. Discovering services and characteristics
// discoverServices([CBUUID]?), peripheral(_:didDiscoverServices:)

NS_ASSUME_NONNULL_BEGIN

@interface GNCMBleCentral () <CBCentralManagerDelegate,
                              CBPeripheralDelegate>

/** Service UUIDs the central is scanning for. */
@property(nonatomic, strong) CBUUID *serviceUUID;

@property(nonatomic, copy) GNCMScanResultHandler scanResultHandler;;

@property(nonatomic) CBCentralManager *centralManager;
@property(nonatomic) dispatch_queue_t selfQueue;

@end

@implementation GNCMBleCentral

- (instancetype)initWithServiceUUID:(NSString *)serviceUUID
                  scanResultHandler:(GNCMScanResultHandler)scanResultHandler {
  self = [super init];
  if (self) {
    _serviceUUID = [CBUUID UUIDWithString:serviceUUID];
    _scanResultHandler = scanResultHandler;

    // To make this class thread-safe, use a serial queue for all state changes, and have Core
    // Bluetooth also use this queue.
    _selfQueue = dispatch_queue_create("GNCCentralManagerQueue", DISPATCH_QUEUE_SERIAL);
    _centralManager = [[CBCentralManager alloc]
        initWithDelegate:self
                   queue:_selfQueue
                 options:@{CBCentralManagerOptionShowPowerAlertKey : @NO}];
  }
  return self;
}

- (void)dealloc {
  // These calls must be made on |selfQueue|.  Can't capture |self| in an async block, so must use
  // dispatch_sync.  This means dealloc must be called from an external queue, which means |self|
  // must never be captured by any escaping block used in this class.
  dispatch_sync(_selfQueue, ^{
    [_centralManager stopScan];
  });
}

#pragma mark CBCentralManagerDelegate

- (void)centralManagerDidUpdateState:(CBCentralManager *)central {
  if (central.state == CBManagerStatePoweredOn) {
    GTMLoggerInfo(@"[NEARBY] CBCentralManager powered on; starting scan");
    [_centralManager
        scanForPeripheralsWithServices:@[ _serviceUUID ]
                               options:@{CBCentralManagerScanOptionAllowDuplicatesKey : @YES}];
  } else {
    GTMLoggerInfo(@"[NEARBY] CBCentralManager not powered on; stopping scan");
    [_centralManager stopScan];
  }
}

@end

NS_ASSUME_NONNULL_END
