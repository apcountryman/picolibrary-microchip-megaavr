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

# Description: picolibrary-microchip-megaavr ATmega2560 Arduino Mega 2560
#       picolibrary::Microchip::megaAVR::GPIO::Internally_Pulled_Up_Input_Pin state
#       interactive test configuration.

set( PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST   ON       CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_PORT "PORTE"  CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_MASK "1 << 4" CACHE STRING "" FORCE )
mark_as_advanced(
    PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST
    PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_PORT
    PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_MASK
)
