# picolibrary-microchip-megaavr
#
# Copyright 2020, 2021 Andrew Countryman <apcountryman@gmail.com>
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

# File: test/interactive/picolibrary/asynchronous_serial/unbuffered_output_stream/hello_world/microchip/megaavr/CMakeLists.txt
# Description: picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream hello world
#       Microchip megaAVR interactive test CMake rules.

# build the picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream hello world
# Microchip megaAVR interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_ASYNCHRONOUS_SERIAL_UNBUFFERED_OUTPUT_STREAM_ENABLE_HELLO_WORLD_MICROCHIP_MEGAAVR_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr: enable the picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream hello world Microchip megaAVR interactive test"
        OFF
    )

    if( ${PICOLIBRARY_ASYNCHRONOUS_SERIAL_UNBUFFERED_OUTPUT_STREAM_ENABLE_HELLO_WORLD_MICROCHIP_MEGAAVR_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_ASYNCHRONOUS_SERIAL_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_MICROCHIP_MEGAAVR_INTERACTIVE_TEST_TRANSMITTER_USART
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream hello world Microchip megaAVR interactive test transmitter USART"
        )
        set(
            PICOLIBRARY_ASYNCHRONOUS_SERIAL_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_MICROCHIP_MEGAAVR_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream hello world Microchip megaAVR interactive test transmitter clock generator operating speed"
        )
        set(
            PICOLIBRARY_ASYNCHRONOUS_SERIAL_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_MICROCHIP_MEGAAVR_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream hello world Microchip megaAVR interactive test transmitter clock generator scaling factor"
        )

        add_executable(
            test-interactive-picolibrary-asynchronous_serial-unbuffered_output_stream-hello_world-microchip-megaavr
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-asynchronous_serial-unbuffered_output_stream-hello_world-microchip-megaavr
            PRIVATE TRANSMITTER_USART=${PICOLIBRARY_ASYNCHRONOUS_SERIAL_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_MICROCHIP_MEGAAVR_INTERACTIVE_TEST_TRANSMITTER_USART}
            PRIVATE TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED=${PICOLIBRARY_ASYNCHRONOUS_SERIAL_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_MICROCHIP_MEGAAVR_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED}
            PRIVATE TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_ASYNCHRONOUS_SERIAL_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_MICROCHIP_MEGAAVR_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR}
        )
        target_link_libraries(
            test-interactive-picolibrary-asynchronous_serial-unbuffered_output_stream-hello_world-microchip-megaavr
            picolibrary-microchip-megaavr
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-asynchronous_serial-unbuffered_output_stream-hello_world-microchip-megaavr
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_ALWAYS_RECOVER_FUSES}"
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE}"
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_VERIFY}"
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_FUSE_CHECKS}"
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_WRITES}"
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
        )
    endif( ${PICOLIBRARY_ASYNCHRONOUS_SERIAL_UNBUFFERED_OUTPUT_STREAM_ENABLE_HELLO_WORLD_MICROCHIP_MEGAAVR_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
