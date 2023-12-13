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

# Description: picolibrary-microchip-megaavr core CMake rules.

cmake_minimum_required( VERSION 3.12.4 )
project(
    picolibrary-microchip-megaavr
    LANGUAGES CXX
)

# general project configuration
option(
    PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING
    "picolibrary-microchip-megaavr: enable interactive testing"
    OFF
)

# load additional CMake modules
list(
    APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/apcountryman-cmake-utilities"
    "${CMAKE_CURRENT_SOURCE_DIR}/toolchain-avr-gcc"
)

# configure compilation and linking
if( "${PROJECT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}" )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR_MCU
        "" CACHE STRING
        "picolibrary-microchip-megaavr: MCU type"
    )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR_F_CPU
        "" CACHE STRING
        "picolibrary-microchip-megaavr: CPU frequency, in Hz"
    )

    set( CMAKE_CXX_STANDARD 17 )
    set( CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE )
    add_compile_options(
        -mmcu=${PICOLIBRARY_MICROCHIP_MEGAAVR_MCU}
        -Werror -Wall -Wextra
        -Wcast-align=strict
        -Wcast-qual
        -Wduplicated-cond
        -Wextra-semi
        -Wfloat-equal
        -Wimplicit-fallthrough=5
        -Wlogical-op
        -Wmissing-field-initializers
        -Wmissing-include-dirs
        -Wold-style-cast
        -Wplacement-new=2
        -Wpointer-arith
        -Wshadow
        -Wunsafe-loop-optimizations
        -fno-threadsafe-statics
    )
    add_compile_definitions(
        F_CPU=${PICOLIBRARY_MICROCHIP_MEGAAVR_F_CPU}
    )
    add_link_options(
        -mmcu=${PICOLIBRARY_MICROCHIP_MEGAAVR_MCU}
    )
endif( "${PROJECT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}" )

# configure avr-libcpp
option(
    PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP
    "picolibrary-microchip-megaavr: use parent project's avr-libcpp"
    ON
)

if( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP} )
    set( AVRLIBCPP_SUPPRESS_SFR_MACROS ON CACHE INTERNAL "" )
endif( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP} )

if( NOT ${AVRLIBCPP_SUPPRESS_SFR_MACROS} )
    message( FATAL_ERROR "AVRLIBCPP_SUPPRESS_SFR_MACROS must be ON" )
endif( NOT ${AVRLIBCPP_SUPPRESS_SFR_MACROS} )

if( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP} )
    add_subdirectory( avr-libcpp )

    link_libraries( avr-libcpp )
endif( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP} )

# configure picolibrary
option(
    PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY
    "picolibrary-microchip-megaavr: use parent project's picolibrary"
    ON
)

if( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY} )
    set( PICOLIBRARY_HIL_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include" CACHE INTERNAL "" )

    set( PICOLIBRARY_ENABLE_AUTOMATED_TESTING                        OFF CACHE INTERNAL "" )
    set( PICOLIBRARY_SUPPRESS_ASSERTION_FAILURE_LOCATION_INFORMATION ON  CACHE INTERNAL "" )

    set( PICOLIBRARY_ENABLE_INTERACTIVE_TESTING "${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING}" CACHE INTERNAL "" )
endif( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY} )

if( NOT "${PICOLIBRARY_HIL_INCLUDE_DIR}" STREQUAL "${PROJECT_SOURCE_DIR}/include" )
    message( FATAL_ERROR "PICOLIBRARY_HIL_INCLUDE_DIR must be ${PROJECT_SOURCE_DIR}/include" )
endif( NOT "${PICOLIBRARY_HIL_INCLUDE_DIR}" STREQUAL "${PROJECT_SOURCE_DIR}/include" )

if( ${PICOLIBRARY_ENABLE_AUTOMATED_TESTING} )
    message( FATAL_ERROR "PICOLIBRARY_ENABLE_AUTOMATED_TESTING must be OFF" )
endif( ${PICOLIBRARY_ENABLE_AUTOMATED_TESTING} )

if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} AND NOT ${PICOLIBRARY_ENABLE_INTERACTIVE_TESTING} )
    message( FATAL_ERROR "PICOLIBRARY_ENABLE_INTERACTIVE_TESTING must be ON if PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING is ON" )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} AND NOT ${PICOLIBRARY_ENABLE_INTERACTIVE_TESTING} )

if( NOT ${PICOLIBRARY_SUPPRESS_ASSERTION_FAILURE_LOCATION_INFORMATION} )
    message( FATAL_ERROR "PICOLIBRARY_SUPPRESS_ASSERTION_FAILURE_LOCATION_INFORMATION must be ON" )
endif( NOT ${PICOLIBRARY_SUPPRESS_ASSERTION_FAILURE_LOCATION_INFORMATION} )

if( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY} )
    add_subdirectory( picolibrary )
endif( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY} )

# capture project version information
include( git-utilities )
execute_git_command(
    PICOLIBRARY_MICROCHIP_MEGAAVR_VERSION
    COMMAND describe --match=none --always --dirty --broken
)

# configure avrdude
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )
    include( avrdude-utilities )

    option(
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET_ENABLED
        "picolibrary-microchip-megaavr: reset AVR before executing avrdude"
        OFF
    )

    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE
        "" CACHE STRING
        "picolibrary-microchip-megaavr: avrdude configuration file"
    )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT
        "" CACHE STRING
        "picolibrary-microchip-megaavr: avrdude port"
    )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAM_FLASH
        "" CACHE STRING
        "picolibrary-microchip-megaavr: flash programming avrdude arguments"
    )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY
        "VERBOSE" CACHE STRING
        "picolibrary-microchip-megaavr: avrdude verbosity"
    )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERIFY_FLASH
        "" CACHE STRING
        "picolibrary-microchip-megaavr: flash verification avrdude arguments"
    )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET "RESET" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_RESET_ENABLED} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )

# library
add_subdirectory( source )

# library tests
add_subdirectory( test )
