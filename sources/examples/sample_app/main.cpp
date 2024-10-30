// SPDX-FileCopyrightText: (c) 2024 Tenstorrent AI ULC
//
// SPDX-License-Identifier: Apache-2.0

#include <iostream>

#include "sample/sample_class.hpp"
#include "tt_metal/common/logger.hpp"
#include "ttnn/graph/graph_operation_queries.hpp"
#include "ttnn/graph/graph_processor.hpp"
#include "ttnn/graph/graph_trace_utils.hpp"
#include "ttnn/operations/core/core.hpp"
#include "ttnn/operations/creation.hpp"
#include "ttnn/operations/eltwise/binary/binary.hpp"
#include "ttnn/tensor/types.hpp"
#include "ttnn/types.hpp"

int main() {
    int device_id = 0;
    sample::DeviceWrapper wrapper(device_id);
    ttnn::MemoryConfig mem_config = ttnn::L1_MEMORY_CONFIG;
    ttnn::Shape shape = ttnn::Shape(tt::tt_metal::Array4D{1, 3, 32, 32});
    const auto input_tensor_a = ttnn::zeros(shape, DataType::BFLOAT16, ttnn::TILE_LAYOUT, wrapper.get_device(), mem_config);
    const auto input_tensor_b = ttnn::zeros(shape, DataType::BFLOAT16, ttnn::TILE_LAYOUT, wrapper.get_device(), mem_config);

    auto call = [&] {
        const auto output_tensor = ttnn::add(input_tensor_a, input_tensor_b);
        return output_tensor;
    };

    auto json_trace = ttnn::graph::query_trace(call);

    tt::log_info("Trace: {}", json_trace.dump(4));
    auto peak_L1_memory_usage = ttnn::graph::query_peak_L1_memory_usage(call);
    tt::log_info("peak_L1_memory_usage: {}", peak_L1_memory_usage);
}
