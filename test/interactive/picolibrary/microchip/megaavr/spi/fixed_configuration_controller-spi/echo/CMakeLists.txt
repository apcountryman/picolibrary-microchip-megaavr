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

# File: test/interactive/picolibrary/microchip/megaavr/spi/fixed_configuration_controller-spi/echo/CMakeLists.txt
# Description: picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI>
#       echo interactive test CMake rules.

# build the
# picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI>
# echo interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ENABLE_ECHO_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr: enable the picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ENABLE_ECHO_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI clock rate"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI clock polarity"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI clock phase"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_BIT_ORDER
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI bit order"
        )

        add_executable(
            test-interactive-picolibrary-microchip-megaavr-spi-fixed_configuration_controller-spi-echo
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-megaavr-spi-fixed_configuration_controller-spi-echo
            PRIVATE CONTROLLER_SPI=${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI}
            PRIVATE CONTROLLER_SPI_CLOCK_RATE=${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE}
            PRIVATE CONTROLLER_SPI_CLOCK_POLARITY=${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY}
            PRIVATE CONTROLLER_SPI_CLOCK_PHASE=${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE}
            PRIVATE CONTROLLER_SPI_BIT_ORDER=${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_BIT_ORDER}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-megaavr-spi-fixed_configuration_controller-spi-echo
            picolibrary
            picolibrary-microchip-megaavr
            picolibrary-microchip-megaavr-testing-interactive-fatal_error
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-microchip-megaavr-spi-fixed_configuration_controller-spi-echo
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT}"
            PROGRAM_FLASH      "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAM_FLASH}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY}"
            VERIFY_FLASH       "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ENABLE_ECHO_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
