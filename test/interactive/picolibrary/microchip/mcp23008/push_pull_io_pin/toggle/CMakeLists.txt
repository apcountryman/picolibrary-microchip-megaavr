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

# File: test/interactive/picolibrary/microchip/mcp23008/push_pull_io_pin/toggle/CMakeLists.txt
# Description: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test
#       CMake rules.

# build the picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr: enable the picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_TRANSMITTER_USART
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test transmitter USART"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test transmitter clock generator operating speed"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test transmitter clock generator scaling factor"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test controller TWI"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_BIT_RATE_GENERATOR_PRESCALER
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test controller bit rate generator prescaler"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_BIT_RATE_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test controller bit rate generator scaling factor"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_ADDRESS
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test MCP23008 address"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_PIN_MASK
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test pin mask"
        )

        add_executable(
            test-interactive-picolibrary-microchip-mcp23008-push_pull_io_pin-toggle
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-mcp23008-push_pull_io_pin-toggle
            PRIVATE TRANSMITTER_USART=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_TRANSMITTER_USART}
            PRIVATE TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED}
            PRIVATE TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR}
            PRIVATE CONTROLLER_TWI=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI}
            PRIVATE CONTROLLER_BIT_RATE_GENERATOR_PRESCALER=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_BIT_RATE_GENERATOR_PRESCALER}
            PRIVATE CONTROLLER_BIT_RATE_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_BIT_RATE_GENERATOR_SCALING_FACTOR}
            PRIVATE MCP23008_ADDRESS=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_ADDRESS}
            PRIVATE PIN_MASK=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_PIN_MASK}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-mcp23008-push_pull_io_pin-toggle
            picolibrary-microchip-megaavr
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-microchip-mcp23008-push_pull_io_pin-toggle
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET}"
            CONFIGURATION_FILE  "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE}"
            PORT                "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT}"
            PROGRAM_FLASH       ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAM_FLASH}
            VERBOSITY           "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY}"
            VERIFY_FLASH        ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERIFY_FLASH}
        )
    endif( ${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
