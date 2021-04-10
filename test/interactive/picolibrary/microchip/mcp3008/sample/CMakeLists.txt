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

# File: test/interactive/picolibrary/microchip/mcp3008/sample/CMakeLists.txt
# Description: picolibrary::Microchip::MCP3008 sample interactive test CMake rules.

# build the picolibrary::Microchip::MCP3008 sample interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MCP3008_ENABLE_SAMPLE_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr: enable the picolibrary::Microchip::MCP3008 sample interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MCP3008_ENABLE_SAMPLE_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_USART
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test transmitter USART"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test transmitter clock generator operating speed"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test transmitter clock generator scaling factor"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_SCK_PORT
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test SCK port"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_SCK_MASK
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test SCK mask"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_MOSI_PORT
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test MOSI port"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_MOSI_MASK
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test MOSI mask"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test controller SPI"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_CONTROLLER_CLOCK_RATE
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test controller clock rate"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_SS_PORT
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test SS port"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_SS_MASK
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test SS mask"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_MCP3008_INPUT
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP3008 sample interactive test MCP3008 input"
        )

        add_executable(
            test-interactive-picolibrary-microchip-mcp3008-sample
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-mcp3008-sample
            PRIVATE TRANSMITTER_USART=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_USART}
            PRIVATE TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED}
            PRIVATE TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR}
            PRIVATE SCK_PORT=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_SCK_PORT}
            PRIVATE SCK_MASK=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_SCK_MASK}
            PRIVATE MOSI_PORT=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_MOSI_PORT}
            PRIVATE MOSI_MASK=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_MOSI_MASK}
            PRIVATE CONTROLLER_SPI=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_CONTROLLER_SPI}
            PRIVATE CONTROLLER_CLOCK_RATE=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_CONTROLLER_CLOCK_RATE}
            PRIVATE SS_PORT=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_SS_PORT}
            PRIVATE SS_MASK=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_SS_MASK}
            PRIVATE MCP3008_INPUT=${PICOLIBRARY_MICROCHIP_MCP3008_SAMPLE_INTERACTIVE_TEST_MCP3008_INPUT}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-mcp3008-sample
            picolibrary-microchip-megaavr
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-microchip-mcp3008-sample
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_ALWAYS_RECOVER_FUSES}"
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE}"
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_VERIFY}"
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_FUSE_CHECKS}"
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_WRITES}"
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_ERASE_CHIP}"
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_OVERRIDE_SIGNATURE_CHECK}"
            BAUD_RATE           "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_BAUD_RATE}"
            BIT_CLOCK           "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_BIT_CLOCK}"
            CONFIGURATION_FILE  "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE}"
            DELAY               "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DELAY}"
            EXIT_SPECIFICATION  "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_EXIT_SPECIFICATION}"
            EXTENDED_PARAMETERS "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_EXTENDED_PARAMETERS}"
            PART                "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PART}"
            PORT                "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT}"
            PROGRAMMER          "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAMMER}"
            VERBOSITY           "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY}"
            MEMORY_OPERATIONS_POST_FLASH_PROGRAM ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_MEMORY_OPERATIONS_POST_FLASH_PROGRAM}
            MEMORY_OPERATIONS_PRE_FLASH_PROGRAM  ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_MEMORY_OPERATIONS_PRE_FLASH_PROGRAM}
        )
    endif( ${PICOLIBRARY_MICROCHIP_MCP3008_ENABLE_SAMPLE_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
