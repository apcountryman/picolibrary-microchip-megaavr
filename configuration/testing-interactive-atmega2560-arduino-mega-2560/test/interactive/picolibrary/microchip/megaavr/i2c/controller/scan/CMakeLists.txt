# picolibrary-microchip-megaavr
#
# Copyright 2020-2023, Andrew Countryman <apcountryman@gmail.com> and the
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

# Description: picolibrary-microchip-megaavr ATmega2560 Arduino Mega 2560
#       picolibrary::Microchip::megaAVR::I2C::Controller scan interactive test
#       configuration.

set( PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_CONTROLLER_ENABLE_SCAN_INTERACTIVE_TEST ON CACHE INTERNAL "" )

set( PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI "TWI0" CACHE INTERNAL "" )

set(
    PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_PRESCALER_VALUE
    "_1" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::I2C::Controller scan interactive test controller TWI bit rate generator prescaler value"
)
set(
    PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_SCALING_FACTOR
    "72" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::I2C::Controller scan interactive test controller TWI bit rate generator scaling factor"
)
