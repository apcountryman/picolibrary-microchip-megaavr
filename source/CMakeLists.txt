# picolibrary-microchip-megaavr
#
# Copyright 2020-2022, Andrew Countryman <apcountryman@gmail.com> and the
# picolibrary-microchip-megaavr contributors
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
# file except in compliance with the License. You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software distributed under
# the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the License for the specific language governing
# permissions and limitations under the License.

# File: source/CMakeLists.txt
# Description: picolibrary-microchip-megaavr CMake rules.

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/picolibrary/microchip/megaavr/version.cc.in"
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/microchip/megaavr/version.cc"
    @ONLY
)

set(
    PICOLIBRARY_MICROCHIP_MEGAAVR_SOURCE_FILES
    "picolibrary/microchip/megaavr.cc"
    "picolibrary/microchip/megaavr/peripheral.cc"
    "picolibrary/microchip/megaavr/peripheral/atmega2560.cc"
    "picolibrary/microchip/megaavr/peripheral/atmega328p.cc"
    "picolibrary/microchip/megaavr/register.cc"
)
list(
    APPEND PICOLIBRARY_MICROCHIP_MEGAAVR_LINK_LIBRARIES
    "picolibrary"
)

add_library(
    picolibrary-microchip-megaavr
    ${PICOLIBRARY_MICROCHIP_MEGAAVR_SOURCE_FILES}
)
target_include_directories(
    picolibrary-microchip-megaavr
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(
    picolibrary-microchip-megaavr
    ${PICOLIBRARY_MICROCHIP_MEGAAVR_LINK_LIBRARIES}
)

add_library(
    picolibrary-microchip-megaavr-version
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/microchip/megaavr/version.cc"
)
target_include_directories(
    picolibrary-microchip-megaavr-version
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)
