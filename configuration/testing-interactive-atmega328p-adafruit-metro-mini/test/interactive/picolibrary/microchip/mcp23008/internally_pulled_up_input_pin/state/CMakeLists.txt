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

# File: configuration/testing-interactive-atmega328p-adafruit-metro-mini/test/interactive/picolibrary/microchip/mcp23008/internally_pulled_up_input_pin/state/CMakeLists.txt
# Description: picolibrary-microchip-megaavr ATmega328/P Adafruit Metro Mini
#       picolibrary::Microchip::MCP23008::Internally_Pulled_Up_Input_Pin state interactive
#       test configuration.

set( PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST                                            ON     CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI                                    "TWI0" CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_PRESCALER_VALUE "_1"   CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_SCALING_FACTOR  "12"   CACHE STRING "" FORCE )
mark_as_advanced(
    PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST
    PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI
    PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_PRESCALER_VALUE
    PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_SCALING_FACTOR
)
