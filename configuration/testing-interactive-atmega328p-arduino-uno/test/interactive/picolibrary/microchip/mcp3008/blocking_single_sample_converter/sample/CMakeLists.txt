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
#       picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample
#       interactive test configuration.

set( PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_ENABLE_SAMPLE_INTERACTIVE_TEST ON CACHE INTERNAL "" )

set( PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI "SPI0" CACHE INTERNAL "" )

set(
    PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE
    "FOSC_8" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test controller SPI clock rate"
)
set(
    PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY
    "IDLE_LOW" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test controller SPI clock polarity"
)
set(
    PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE
    "CAPTURE_IDLE_TO_ACTIVE" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test controller SPI clock phase"
)

set(
    PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_DEVICE_SELECTOR_PORT
    "PORTB" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test device selector PORT"
)
set(
    PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_DEVICE_SELECTOR_MASK
    "1 << 2" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test device selector mask"
)
