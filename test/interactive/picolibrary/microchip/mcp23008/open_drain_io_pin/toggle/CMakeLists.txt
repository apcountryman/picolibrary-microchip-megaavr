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

# File: test/interactive/picolibrary/microchip/mcp23008/open_drain_io_pin/toggle/CMakeLists.txt
# Description: picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test
#       CMake rules.

# build the picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr: enable the picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test controller TWI"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_PRESCALER_VALUE
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test controller TWI bit rate generator prescaler value"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test controller TWI bit rate generator scaling factor"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_ADDRESS
            "Address_Numeric{ 0b0100'000 }" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test MCP23008 address"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_PIN_MASK
            "1 << 0" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test MCP23008 pin mask"
        )
        mark_as_advanced(
            PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_ADDRESS
            PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_PIN_MASK
        )

        add_executable(
            test-interactive-picolibrary-microchip-mcp23008-open_drain_io_pin-toggle
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-mcp23008-open_drain_io_pin-toggle
            PRIVATE CONTROLLER_TWI=${PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI}
            PRIVATE CONTROLLER_TWI_BIT_RATE_GENERATOR_PRESCALER_VALUE=${PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_PRESCALER_VALUE}
            PRIVATE CONTROLLER_TWI_BIT_RATE_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_BIT_RATE_GENERATOR_SCALING_FACTOR}
            PRIVATE MCP23008_ADDRESS=${PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_ADDRESS}
            PRIVATE MCP23008_PIN_MASK=${PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_PIN_MASK}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-mcp23008-open_drain_io_pin-toggle
            picolibrary
            picolibrary-microchip-megaavr
            picolibrary-microchip-megaavr-testing-interactive-fatal_error
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-microchip-mcp23008-open_drain_io_pin-toggle
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT}"
            PROGRAM_FLASH      "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAM_FLASH}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY}"
            VERIFY_FLASH       "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_MICROCHIP_MCP23008_OPEN_DRAIN_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
