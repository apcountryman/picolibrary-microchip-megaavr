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

# Description: picolibrary-microchip-megaavr ATmega328/P Adafruit Metro Mini
#       picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<Peripheral::USART>
#       echo interactive test configuration.

set( PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ENABLE_ECHO_INTERACTIVE_TEST OFF CACHE BOOL "" FORCE )
mark_as_advanced(
    PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ENABLE_ECHO_INTERACTIVE_TEST
)
