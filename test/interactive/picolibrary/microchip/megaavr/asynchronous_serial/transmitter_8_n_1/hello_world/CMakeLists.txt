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

# File: test/interactive/picolibrary/microchip/megaavr/asynchronous_serial/transmitter_8_n_1/hello_world/CMakeLists.txt
# Description: picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter_8_N_1
#       hello world interactive test CMake rules.

# build the picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter_8_N_1 hello
# world interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_TRANSMITTER_8_N_1_ENABLE_HELLO_WORLD_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr: enable the picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter_8_N_1 hello world interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_TRANSMITTER_8_N_1_ENABLE_HELLO_WORLD_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_TRANSMITTER_8_N_1_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter_8_N_1 hello world interactive test transmitter USART"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_TRANSMITTER_8_N_1_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter_8_N_1 hello world interactive test transmitter clock generator operating speed"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_TRANSMITTER_8_N_1_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter_8_N_1 hello world interactive test transmitter clock generator scaling factor"
        )

        add_executable(
            test-interactive-picolibrary-microchip-megaavr-asynchronous_serial-transmitter_8_n_1-hello_world
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-megaavr-asynchronous_serial-transmitter_8_n_1-hello_world
            PRIVATE TRANSMITTER_USART=${PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_TRANSMITTER_8_N_1_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART}
            PRIVATE TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED=${PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_TRANSMITTER_8_N_1_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED}
            PRIVATE TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_TRANSMITTER_8_N_1_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-megaavr-asynchronous_serial-transmitter_8_n_1-hello_world
            picolibrary-microchip-megaavr
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-microchip-megaavr-asynchronous_serial-transmitter_8_n_1-hello_world
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET}"
            CONFIGURATION_FILE  "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE}"
            PORT                "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT}"
            PROGRAM_FLASH       ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAM_FLASH}
            VERBOSITY           "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY}"
            VERIFY_FLASH        ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERIFY_FLASH}
        )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_TRANSMITTER_8_N_1_ENABLE_HELLO_WORLD_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
