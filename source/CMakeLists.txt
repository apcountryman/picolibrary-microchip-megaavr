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

# File: source/CMakeLists.txt
# Description: picolibrary-microchip-megaavr CMake rules.

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/picolibrary/microchip/megaavr/version.cc.in"
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/microchip/megaavr/version.cc"
    @ONLY
)

set(
    PICOLIBRARY_MICROCHIP_MEGAAVR_SOURCE_FILES
    "picolibrary/microchip/megaavr.cc"
    "picolibrary/microchip/megaavr/asynchronous_serial.cc"
    "picolibrary/microchip/megaavr/gpio.cc"
    "picolibrary/microchip/megaavr/multiplexed_signals.cc"
    "picolibrary/microchip/megaavr/multiplexed_signals/atmega2560.cc"
    "picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/usart.cc"
    "picolibrary/microchip/megaavr/multiplexed_signals/atmega328p.cc"
    "picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/usart.cc"
    "picolibrary/microchip/megaavr/peripheral.cc"
    "picolibrary/microchip/megaavr/peripheral/atmega2560.cc"
    "picolibrary/microchip/megaavr/peripheral/atmega328p.cc"
    "picolibrary/microchip/megaavr/peripheral/instance.cc"
    "picolibrary/microchip/megaavr/peripheral/port.cc"
    "picolibrary/microchip/megaavr/peripheral/usart.cc"
    "picolibrary/microchip/megaavr/register.cc"
)
list(
    APPEND PICOLIBRARY_MICROCHIP_MEGAAVR_LINK_LIBRARIES
    "picolibrary"
)

if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    list(
        APPEND PICOLIBRARY_MICROCHIP_MEGAAVR_SOURCE_FILES
        "picolibrary/testing/interactive/microchip/megaavr.cc"
        "picolibrary/testing/interactive/microchip/megaavr/log.cc"
    )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )

add_library(
    picolibrary-microchip-megaavr
    ${PICOLIBRARY_MICROCHIP_MEGAAVR_SOURCE_FILES}
)
target_include_directories(
    picolibrary-microchip-megaavr
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(
    picolibrary-microchip-megaavr
    ${PICOLIBRARY_MICROCHIP_MEGAAVR_LINK_LIBRARIES}
)

if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART
        "" CACHE STRING
        "picolibrary-microchip-megaavr: picolibrary::Testing::Interactive::Microchip::megaAVR::Log USART"
    )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED
        "" CACHE STRING
        "picolibrary-microchip-megaavr: picolibrary::Testing::Interactive::Microchip::megaAVR::Log USART clock generator operating speed"
    )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR
        "" CACHE STRING
        "picolibrary-microchip-megaavr: picolibrary::Testing::Interactive::Microchip::megaAVR::Log USART clock generator scaling factor"
    )

    target_compile_definitions(
        picolibrary-microchip-megaavr
        PUBLIC "$<IF:$<BOOL:${PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART}>,PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART=${PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART},>"
        PUBLIC "$<IF:$<BOOL:${PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART}>,PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED=${PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED},>"
        PUBLIC "$<IF:$<BOOL:${PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART}>,PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_MICROCHIP_MEGAAVR_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR},>"
    )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )

add_library(
    picolibrary-microchip-megaavr-version
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/microchip/megaavr/version.cc"
)
target_include_directories(
    picolibrary-microchip-megaavr-version
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)

if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    add_library(
        picolibrary-microchip-megaavr-testing-interactive-fatal_error STATIC
        "picolibrary/testing/interactive/microchip/megaavr/fatal_error.cc"
    )
    target_link_libraries(
        picolibrary-microchip-megaavr-testing-interactive-fatal_error
        picolibrary
        picolibrary-microchip-megaavr
    )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
