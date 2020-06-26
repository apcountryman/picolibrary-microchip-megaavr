# picolibrary-microchip-avr-megaavr
#
# Copyright 2020 Andrew Countryman <apcountryman@gmail.com>
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
# Description: picolibrary-microchip-avr-megaavr CMake rules.

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/picolibrary/microchip/avr/megaavr/version.cc.in"
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/microchip/avr/megaavr/version.cc"
    @ONLY
)

set(
    PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_SOURCE_FILES
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/microchip/avr/megaavr/version.cc"
    "picolibrary/microchip.cc"
    "picolibrary/microchip/avr.cc"
    "picolibrary/microchip/avr/megaavr.cc"
    "picolibrary/microchip/avr/megaavr/register.cc"
)
list(
    APPEND PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_LINK_LIBRARIES
    "picolibrary"
)

add_library(
    picolibrary-microchip-avr-megaavr
    ${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_SOURCE_FILES}
)
target_include_directories(
    picolibrary-microchip-avr-megaavr
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(
    picolibrary-microchip-avr-megaavr
    ${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_LINK_LIBRARIES}
)
