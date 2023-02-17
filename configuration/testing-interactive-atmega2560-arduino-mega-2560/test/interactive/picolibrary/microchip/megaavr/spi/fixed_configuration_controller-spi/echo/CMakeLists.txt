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
#       picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI>
#       echo interactive test configuration.

set( PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ENABLE_ECHO_INTERACTIVE_TEST ON CACHE INTERNAL "" )

set( PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI "SPI0" CACHE INTERNAL "" )

set(
    PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE
    "FOSC_2" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI clock rate"
)
set(
    PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY
    "IDLE_LOW" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI clock polarity"
)
set(
    PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE
    "CAPTURE_IDLE_TO_ACTIVE" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI clock phase"
)
set(
    PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_BIT_ORDER
    "MSB_FIRST" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI bit order"
)
