project (sample_lib)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp) # I am a bad person

#set(SOURCES)


add_library(sample_lib STATIC ${SOURCES})

add_library(stdlib INTERFACE)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
    find_library(LIBC++ c++)
    find_library(LIBC++ABI c++abi)
    if(NOT LIBC++ OR NOT LIBC++ABI)
        message(FATAL_ERROR "libc++ or libc++abi not found. Make sure you have libc++ and libc++abi installed and in your PATH")
    endif()

    target_link_libraries(sample_lib PUBLIC ${LIBC++} ${LIBC++ABI})
    target_compile_options(sample_lib PUBLIC -stdlib=libc++)
else()
    target_link_libraries(sample_lib PUBLIC stdc++)
    target_compile_options(sample_lib PUBLIC -fsized-deallocation)
endif()

target_include_directories(sample_lib PUBLIC
    # Metalium
    $ENV{TT_METAL_HOME}
    $ENV{TT_METAL_HOME}/tt_metal
    $ENV{TT_METAL_HOME}/tt_metal/third_party/umd
    $ENV{TT_METAL_HOME}/tt_metal/third_party/fmt
    $ENV{TT_METAL_HOME}/tt_metal/hw/inc/wormhole
    $ENV{TT_METAL_HOME}/tt_metal/hw/inc/wormhole/wormhole_b0_defines
    $ENV{TT_METAL_HOME}/tt_metal/hw/inc/
    $ENV{TT_METAL_HOME}/tt_metal/third_party/umd/src/firmware/riscv/wormhole
    $ENV{TT_METAL_HOME}/tt_metal/third_party/umd/device
    $ENV{TT_METAL_HOME}/.cpmcache/fmt/73b5ec45edbd92babfd91c3777a9e1ab9cac8238/include
    $ENV{TT_METAL_HOME}/.cpmcache/magic_enum/1e1af177d4ab0ef660f105434fd1017c4d1f8c17/include/magic_enum
    $ENV{TT_METAL_HOME}/.cpmcache/boost_core/e679bef5c160cf29d0f37d549881dc5f5a58c332/include
    $ENV{TT_METAL_HOME}/.cpmcache/boost_container/5fb02b14b46d0d84e7a0ce09e2ea5e963d5d93bd/include
    $ENV{TT_METAL_HOME}/.cpmcache/boost_config/0bad5ba3b48288a243894aa801ed6eccbef70b60/include
    $ENV{TT_METAL_HOME}/.cpmcache/boost_move/c59effd88face3140123440bc5425ee60328f08d/include
    $ENV{TT_METAL_HOME}/.cpmcache/boost_intrusive/4a7bf962355d8580809cea3c68f55bbaaa746e64/include
    $ENV{TT_METAL_HOME}/.cpmcache/boost_assert/3ab1f6f9db9a884ad9a641164dbb6589a5aa7e2d/include

    # TTNN
    $ENV{TT_METAL_HOME}/ttnn/cpp
    $ENV{TT_METAL_HOME}/ttnn/cpp/ttnn/deprecated
    $ENV{TT_METAL_HOME}/tt_metal/third_party/magic_enum
    ${reflect_SOURCE_DIR}
    ${flatbuffers_include_dir} 
    ${nng_include_dir}

)
target_include_directories(sample_lib PUBLIC ${PROJECT_SOURCE_DIR})
target_link_directories(sample_lib PUBLIC
    $ENV{TT_METAL_HOME}/build/lib
)
find_package(Python REQUIRED Development)

foreach(lib ${BoostPackages})
    target_include_directories(sample_lib PUBLIC ${Boost${lib}_SOURCE_DIR}/include)
endforeach()

target_link_libraries(sample_lib PUBLIC
    dl z pthread atomic
)

target_link_libraries(sample_lib PUBLIC
    tt_metal
    pthread
    Python::Python
    $ENV{TT_METAL_HOME}/build/lib/_ttnn.so
    $ENV{TT_METAL_HOME}/build/lib/libdevice.so
    $ENV{TT_METAL_HOME}/build/lib/libfmt.so
    $ENV{TT_METAL_HOME}/build/lib/libnng.so.1
)

target_link_libraries(sample_lib PUBLIC 
yaml-cpp::yaml-cpp)

target_compile_definitions(sample_lib PUBLIC
    FMT_HEADER_ONLY
)
