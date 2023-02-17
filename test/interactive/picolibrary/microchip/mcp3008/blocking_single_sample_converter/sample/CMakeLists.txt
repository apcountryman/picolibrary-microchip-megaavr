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

# Description: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample
#       interactive test CMake rules.

# build the picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample
# interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_ENABLE_SAMPLE_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr: enable the picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_ENABLE_SAMPLE_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test controller SPI"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test controller SPI clock rate"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test controller SPI clock polarity"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test controller SPI clock phase"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_DEVICE_SELECTOR_PORT
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test device selector PORT"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_DEVICE_SELECTOR_MASK
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test device selector mask"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_MCP3008_INPUT
            "CH0" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008::Blocking_Single_Sample_Converter sample interactive test MCP3008 input"
        )

        add_executable(
            test-interactive-picolibrary-microchip-mcp3008-blocking_single_sample_converter-sample
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-mcp3008-blocking_single_sample_converter-sample
            PRIVATE CONTROLLER_SPI=${PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI}
            PRIVATE CONTROLLER_SPI_CLOCK_RATE=${PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE}
            PRIVATE CONTROLLER_SPI_CLOCK_POLARITY=${PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY}
            PRIVATE CONTROLLER_SPI_CLOCK_PHASE=${PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE}
            PRIVATE DEVICE_SELECTOR_PORT=${PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_DEVICE_SELECTOR_PORT}
            PRIVATE DEVICE_SELECTOR_MASK=${PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_DEVICE_SELECTOR_MASK}
            PRIVATE MCP3008_INPUT=${PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_SAMPLE_INTERACTIVE_TEST_MCP3008_INPUT}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-mcp3008-blocking_single_sample_converter-sample
            picolibrary
            picolibrary-microchip-megaavr
            picolibrary-microchip-megaavr-testing-interactive-fatal_error
        )
        add_avrdude_flash_programming_targets(
            test-interactive-picolibrary-microchip-mcp3008-blocking_single_sample_converter-sample
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY}"
            PROGRAM            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAM_FLASH}"
            VERIFY             "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_MICROCHIP_MCP3008_BLOCKING_SINGLE_SAMPLE_CONVERTER_ENABLE_SAMPLE_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
