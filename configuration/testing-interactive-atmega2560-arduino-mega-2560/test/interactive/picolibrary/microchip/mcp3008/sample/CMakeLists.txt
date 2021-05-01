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

# File: configuration/testing-interactive-atmega2560-arduino-mega-2560/test/interactive/picolibrary/microchip/mcp3008/sample/CMakeLists.txt
# Description: picolibrary-microchip-megaavr ATmega2560 Arduino Mega 2560
#       picolibrary::Microchip::MCP3008 sample interactive test configuration.

set( PICOLIBRARY_MICROCHIP_MCP3008_ENABLE_SAMPLE_INTERACTIVE_TEST                                      ON            CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_USART                           "USART0"      CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED "DOUBLE"      CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR  "16"          CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI                              "SPI0"        CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_CONTROLLER_CLOCK_RATE                       "FOSC_8"      CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_MCP3008_INPUT                               "Channel::_0" CACHE STRING "" FORCE )
mark_as_advanced(
    PICOLIBRARY_MICROCHIP_MCP3008_ENABLE_SAMPLE_INTERACTIVE_TEST
    PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_USART
    PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED
    PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR
    PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI
    PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_CONTROLLER_CLOCK_RATE
    PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_MCP3008_INPUT
)
