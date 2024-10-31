// SPDX-FileCopyrightText: (c) 2024 Tenstorrent AI ULC
//
// SPDX-License-Identifier: Apache-2.0

#pragma once

namespace tt::tt_metal {
inline namespace v0 {
class Device;
}
}

namespace sample {

class DeviceWrapper {
   public:
    DeviceWrapper(int device_index);

    ~DeviceWrapper();

    [[nodiscard]] tt::tt_metal::Device& get_device();

   private:
    tt::tt_metal::Device* device = nullptr;
};

int sum(int a, int b);
}  // namespace sample
