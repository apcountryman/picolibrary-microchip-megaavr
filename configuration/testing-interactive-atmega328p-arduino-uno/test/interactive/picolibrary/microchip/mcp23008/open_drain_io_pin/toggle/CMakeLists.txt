# picolibrary-microchip-megaavr
#
# Copyright 2020-2024, Andrew Countryman <apcountryman@gmail.com> and the
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

# Description: picolibrary-microchip-megaavr ATmega328/P Arduino Uno
#       picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test
#       configuration.

set( PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST ON CACHE INTERNAL "" )

set( PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI "TWI0" CACHE INTERNAL "" )

set(
    PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_PRESCALER_VALUE
    "_1" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test controller TWI bit rate generator prescaler value"
)
set(
    PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_SCALING_FACTOR
    "12" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test controller TWI bit rate generator scaling factor"
)
