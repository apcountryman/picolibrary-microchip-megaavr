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

# File: configuration/testing-interactive-atmega328p-arduino-uno/CMakeLists.txt
# Description: picolibrary-microchip-megaavr ATmega328/P Arduino Uno interactive testing
#       configuration.

# install prefix is not applicable
mark_as_advanced( CMAKE_INSTALL_PREFIX )

# build configuration
set( CMAKE_BUILD_TYPE                                             "MinSizeRel" CACHE STRING "" FORCE )
set( CMAKE_EXPORT_COMPILE_COMMANDS                                ON           CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_F_CPU                          "16000000UL" CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_MCU                            "atmega328p" CACHE STRING "" FORCE )
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

# configure avrdude
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED          OFF          CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_BAUD_RATE                             "115200"     CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_BIT_CLOCK                             ""           CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DELAY                                 ""           CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED ON           CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED      OFF          CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED           OFF          CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_WRITES_ENABLED                OFF          CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_EXIT_SPECIFICATION                    ""           CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_EXTENDED_PARAMETERS                   ""           CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED      OFF          CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PART                                  "atmega328p" CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAMMER                            "arduino"    CACHE STRING "" FORCE )
mark_as_advanced(
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_BAUD_RATE
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_BIT_CLOCK
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DELAY
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_WRITES_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_EXIT_SPECIFICATION
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_EXTENDED_PARAMETERS
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PART
    PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAMMER
)

include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/asynchronous_serial/unbuffered_output_stream/hello_world/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/mcp23008/internally_pulled_up_input_pin/state/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr/asynchronous_serial/transmitter_8_n_1/hello_world/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr/gpio/internally_pulled_up_input_pin/state/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr/gpio/open_drain_io_pin/toggle/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr/gpio/push_pull_io_pin/toggle/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr/i2c/controller/scan/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr/spi/controller/spi/echo/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr/spi/controller/usart/echo/CMakeLists.txt" )
