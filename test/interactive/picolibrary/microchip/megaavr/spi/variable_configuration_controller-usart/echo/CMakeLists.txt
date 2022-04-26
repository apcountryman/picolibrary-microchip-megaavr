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

# Description: picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<Peripheral::USART>
#       echo interactive test CMake rules.

# build the
# picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<Peripheral::USART>
# echo interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ENABLE_ECHO_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr: enable the picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<Peripheral::USART> echo interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ENABLE_ECHO_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ECHO_INTERACTIVE_TEST_CONTROLLER_USART
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<Peripheral::USART> echo interactive test controller USART"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ECHO_INTERACTIVE_TEST_CONTROLLER_USART_CLOCK_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<Peripheral::USART> echo interactive test controller USART clock generator scaling factor"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ECHO_INTERACTIVE_TEST_CONTROLLER_USART_CLOCK_POLARITY
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<Peripheral::USART> echo interactive test controller USART clock polarity"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ECHO_INTERACTIVE_TEST_CONTROLLER_USART_CLOCK_PHASE
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<Peripheral::USART> echo interactive test controller USART clock phase"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ECHO_INTERACTIVE_TEST_CONTROLLER_USART_BIT_ORDER
            "" CACHE STRING
            "picolibrary-microchip-megaavr: picolibrary::Microchip::megaAVR::SPI::Variable_Configuration_Controller<Peripheral::USART> echo interactive test controller USART bit order"
        )

        add_executable(
            test-interactive-picolibrary-microchip-megaavr-spi-variable_configuration_controller-usart-echo
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-megaavr-spi-variable_configuration_controller-usart-echo
            PRIVATE CONTROLLER_USART=${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ECHO_INTERACTIVE_TEST_CONTROLLER_USART}
            PRIVATE CONTROLLER_USART_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ECHO_INTERACTIVE_TEST_CONTROLLER_USART_CLOCK_GENERATOR_SCALING_FACTOR}
            PRIVATE CONTROLLER_USART_CLOCK_POLARITY=${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ECHO_INTERACTIVE_TEST_CONTROLLER_USART_CLOCK_POLARITY}
            PRIVATE CONTROLLER_USART_CLOCK_PHASE=${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ECHO_INTERACTIVE_TEST_CONTROLLER_USART_CLOCK_PHASE}
            PRIVATE CONTROLLER_USART_BIT_ORDER=${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ECHO_INTERACTIVE_TEST_CONTROLLER_USART_BIT_ORDER}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-megaavr-spi-variable_configuration_controller-usart-echo
            picolibrary
            picolibrary-microchip-megaavr
            picolibrary-microchip-megaavr-testing-interactive-fatal_error
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-microchip-megaavr-spi-variable_configuration_controller-usart-echo
            "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT}"
            PROGRAM_FLASH      "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAM_FLASH}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY}"
            VERIFY_FLASH       "${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_VARIABLE_CONFIGURATION_CONTROLLER_USART_ENABLE_ECHO_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
