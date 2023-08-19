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

# Description: picolibrary::Adafruit::PID781::Driver hello world interactive test CMake
#       rules.

# picolibrary::Adafruit::PID781::Driver hello world interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_ADAFRUIT_PID781_DRIVER_ENABLE_HELLO_WORLD_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr: enable the picolibrary::Adafruit::PID781::Driver hello world interactive test"
        OFF
    )

    if( ${PICOLIBRARY_ADAFRUIT_PID781_DRIVER_ENABLE_HELLO_WORLD_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_ADAFRUIT_PID781_DRIVER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Adafruit::PID781::Driver hello world interactive test transmitter USART"
        )
        set(
            PICOLIBRARY_ADAFRUIT_PID781_DRIVER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_CLOCK_GENERATOR_OPERATING_SPEED
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Adafruit::PID781::Driver hello world interactive test transmitter USART clock generator operating speed"
        )
        set(
            PICOLIBRARY_ADAFRUIT_PID781_DRIVER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_CLOCK_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Adafruit::PID781::Driver hello world interactive test transmitter USART clock generator scaling factor"
        )

        add_executable(
            test-interactive-picolibrary-adafruit-pid781-driver-hello_world
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-adafruit-pid781-driver-hello_world
            PRIVATE TRANSMITTER_USART=${PICOLIBRARY_ADAFRUIT_PID781_DRIVER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART}
            PRIVATE TRANSMITTER_USART_CLOCK_GENERATOR_OPERATING_SPEED=${PICOLIBRARY_ADAFRUIT_PID781_DRIVER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_CLOCK_GENERATOR_OPERATING_SPEED}
            PRIVATE TRANSMITTER_USART_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_ADAFRUIT_PID781_DRIVER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_CLOCK_GENERATOR_SCALING_FACTOR}
        )
        target_link_libraries(
            test-interactive-picolibrary-adafruit-pid781-driver-hello_world
            picolibrary
            picolibrary-microchip-megaavr
            picolibrary-microchip-megaavr-testing-interactive-fatal_error
        )
        add_avrdude_flash_programming_targets(
            test-interactive-picolibrary-adafruit-pid781-driver-hello_world
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY}"
            PROGRAM            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAM_FLASH}"
            VERIFY             "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_ADAFRUIT_PID781_DRIVER_ENABLE_HELLO_WORLD_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
