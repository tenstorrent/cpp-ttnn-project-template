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
)

target_link_libraries(sample_lib PUBLIC 
yaml-cpp::yaml-cpp)

target_compile_definitions(sample_lib PUBLIC
    FMT_HEADER_ONLY
)