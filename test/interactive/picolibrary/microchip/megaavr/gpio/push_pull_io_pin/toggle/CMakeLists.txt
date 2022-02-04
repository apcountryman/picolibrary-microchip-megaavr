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

# File: test/interactive/picolibrary/microchip/megaavr/gpio/push_pull_io_pin/toggle/CMakeLists.txt
# Description: picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin toggle interactive
#       test CMake rules.

# build the picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin toggle interactive
# test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr: enable the picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin toggle interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_PIN_PORT
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin toggle interactive test pin PORT"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_PIN_MASK
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin toggle interactive test pin mask"
        )

        add_executable(
            test-interactive-picolibrary-microchip-megaavr-gpio-push_pull_io_pin-toggle
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-megaavr-gpio-push_pull_io_pin-toggle
            PRIVATE PIN_PORT=${PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_PIN_PORT}
            PRIVATE PIN_MASK=${PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_PIN_MASK}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-megaavr-gpio-push_pull_io_pin-toggle
            picolibrary
            picolibrary-microchip-megaavr
            picolibrary-microchip-megaavr-testing-interactive-fatal_error
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-microchip-megaavr-gpio-push_pull_io_pin-toggle
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT}"
            PROGRAM_FLASH      "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAM_FLASH}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY}"
            VERIFY_FLASH       "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_GPIO_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
