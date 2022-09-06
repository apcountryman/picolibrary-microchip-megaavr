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

# Description: picolibrary-microchip-megaavr ATmega328/P Arduino Uno
#       picolibrary::Microchip::megaAVR::GPIO::Open_Drain_IO_Pin toggle interactive test
#       configuration.

set( PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_OPEN_DRAIN_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST ON CACHE INTERNAL "" )

set(
    PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_PIN_PORT
    "PORTD" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::GPIO::Open_Drain_IO_Pin toggle interactive test pin PORT"
)
set(
    PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_PIN_MASK
    "1 << 2" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::GPIO::Open_Drain_IO_Pin toggle interactive test pin mask"
)
