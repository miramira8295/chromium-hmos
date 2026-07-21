# the minimum version of CMake.
cmake_minimum_required(VERSION 3.5.0)
project(chromium-ui)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

if(DEFINED PACKAGE_FIND_FILE)
    include(${PACKAGE_FIND_FILE})
endif()

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

# Keep the local host helper isolated to libentry.so. The real libweb_engine.so
# must always come from the Chromium build output synced into the Harmony app.
add_library(entry SHARED napi_init.cpp)
set(AURA_NATIVE_STAGE_DIR "${CMAKE_CURRENT_BINARY_DIR}/native-stage")
set_target_properties(entry PROPERTIES
                      OUTPUT_NAME "entry"
                      ARCHIVE_OUTPUT_DIRECTORY "${AURA_NATIVE_STAGE_DIR}"
                      LIBRARY_OUTPUT_DIRECTORY "${AURA_NATIVE_STAGE_DIR}"
                      RUNTIME_OUTPUT_DIRECTORY "${AURA_NATIVE_STAGE_DIR}")
target_link_libraries(entry PUBLIC libace_napi.z.so)
