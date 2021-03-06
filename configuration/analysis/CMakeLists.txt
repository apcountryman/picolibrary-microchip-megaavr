# picolibrary-microchip-megaavr
#
# Copyright 2020-2021, Andrew Countryman <apcountryman@gmail.com> and the
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

# File: configuration/analysis/CMakeLists.txt
# Description: picolibrary-microchip-megaavr static analysis configuration.

# install prefix is not applicable
mark_as_advanced( CMAKE_INSTALL_PREFIX )

# build configuration
set( CMAKE_BUILD_TYPE                                             "MinSizeRel" CACHE STRING "" FORCE )
set( CMAKE_EXPORT_COMPILE_COMMANDS                                ON           CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_F_CPU                          "16000000UL" CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_MCU                            "atmega2560" CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_BUILD_FLAGS OFF          CACHE BOOL   "" FORCE )
mark_as_advanced(
    CMAKE_BUILD_TYPE
    CMAKE_EXPORT_COMPILE_COMMANDS
    PICOLIBRARY_MICROCHIP_MEGAAVR_F_CPU
    PICOLIBRARY_MICROCHIP_MEGAAVR_MCU
    PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_BUILD_FLAGS
)

# avr-libcpp configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP OFF CACHE BOOL "" FORCE )
mark_as_advanced( PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP )

# picolibrary configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY OFF CACHE BOOL "" FORCE )
mark_as_advanced( PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY )

# interactive testing configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING ON CACHE BOOL "" FORCE )
mark_as_advanced( PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING )
