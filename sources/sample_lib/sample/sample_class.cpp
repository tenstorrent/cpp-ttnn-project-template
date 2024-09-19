// SPDX-FileCopyrightText: (c) 2024 Tenstorrent AI ULC
//
// SPDX-License-Identifier: Apache-2.0

#include "sample_class.hpp"

#include "tt_metal/common/logger.hpp"
#include "tt_metal/host_api.hpp"
#include "tt_metal/impl/device/device.hpp"

namespace sample {

DeviceWrapper::DeviceWrapper(int device_index) {
    device = tt::tt_metal::CreateDevice(device_index);
    tt::log_info("Device #{} successfully created", device_index);
}
DeviceWrapper::~DeviceWrapper() { tt::tt_metal::CloseDevice(device); }

[[nodiscard]] tt::tt_metal::Device& DeviceWrapper::get_device() { return *device; }

int sum(int a, int b) { return a + b; }
}  // namespace sample
