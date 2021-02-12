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

# File: CMakeLists.txt
# Description: picolibrary-microchip-megaavr core CMake rules.

cmake_minimum_required( VERSION 3.12.4 )
project(
    picolibrary-microchip-megaavr
    LANGUAGES CXX
)

# project configuration
option( PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING     "picolibrary-microchip-megaavr: enable interactive testing"       OFF )
option( PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP   "picolibrary-microchip-megaavr: use parent project's avr-libcpp"  ON  )
option( PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_BUILD_FLAGS "picolibrary-microchip-megaavr: use parent project's build flags" ON  )
option( PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY "picolibrary-microchip-megaavr: use parent project's picolibrary" ON  )

# load additional CMake modules
list(
    APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/apcountryman-cmake-utilities"
)

# configure compilation and linking
if( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_BUILD_FLAGS} )
    set( CMAKE_CXX_STANDARD 17 )
    set( CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR_MCU   "" CACHE STRING "picolibrary-microchip-megaavr: MCU type"             )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR_F_CPU "" CACHE STRING "picolibrary-microchip-megaavr: CPU frequency, in Hz" )
    set(
        CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} \
        -mmcu=${PICOLIBRARY_MICROCHIP_MEGAAVR_MCU} \
        -DF_CPU=${PICOLIBRARY_MICROCHIP_MEGAAVR_F_CPU} \
        -Werror -Wall -Wextra \
        -Wcast-align=strict \
        -Wcast-qual \
        -Wduplicated-cond \
        -Wextra-semi \
        -Wfloat-equal \
        -Wimplicit-fallthrough=5 \
        -Wlogical-op \
        -Wmissing-field-initializers \
        -Wmissing-include-dirs \
        -Wold-style-cast \
        -Wplacement-new=2 \
        -Wpointer-arith \
        -Wshadow \
        -Wunsafe-loop-optimizations \
        "
    )
endif( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_BUILD_FLAGS} )

# configure avr-libcpp
if( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP} )
    set( AVRLIBCPP_USE_PARENT_PROJECT_BUILD_FLAGS ON CACHE BOOL "" FORCE )
    mark_as_advanced( AVRLIBCPP_USE_PARENT_PROJECT_BUILD_FLAGS )

    add_subdirectory( avr-libcpp )

    link_libraries( avr-libcpp )
endif( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP} )

# configure picolibrary
if( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY} )
    set( PICOLIBRARY_USE_PARENT_PROJECT_BUILD_FLAGS ON CACHE BOOL "" FORCE )
    mark_as_advanced( PICOLIBRARY_USE_PARENT_PROJECT_BUILD_FLAGS )

    set( PICOLIBRARY_SUPPRESS_HUMAN_READABLE_ERROR_INFORMATION OFF CACHE BOOL "" FORCE )
    mark_as_advanced( PICOLIBRARY_SUPPRESS_HUMAN_READABLE_ERROR_INFORMATION )

    set( PICOLIBRARY_ENABLE_UNIT_TESTING            OFF CACHE BOOL "" FORCE )
    set( PICOLIBRARY_USE_PARENT_PROJECT_GOOGLE_TEST OFF CACHE BOOL "" FORCE )
    mark_as_advanced(
        PICOLIBRARY_ENABLE_UNIT_TESTING
        PICOLIBRARY_USE_PARENT_PROJECT_GOOGLE_TEST
    )

    set( PICOLIBRARY_ENABLE_INTERACTIVE_TESTING "${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING}" CACHE BOOL "" FORCE )
    mark_as_advanced( PICOLIBRARY_ENABLE_INTERACTIVE_TESTING )

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
    if( "${CMAKE_AVRDUDE}" STREQUAL "CMAKE_AVRDUDE-NOTFOUND" )
        message( FATAL_ERROR "avrdude not found" )
    endif( "${CMAKE_AVRDUDE}" STREQUAL "CMAKE_AVRDUDE-NOTFOUND" )

    option( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED          "picolibrary-microchip-megaavr: avrdude always recover fuses"          OFF )
    option( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED "picolibrary-microchip-megaavr: avrdude disable automatic Flash erase" OFF )
    option( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED      "picolibrary-microchip-megaavr: avrdude disable automatic verify"      OFF )
    option( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED           "picolibrary-microchip-megaavr: avrdude disable fuse checks"           OFF )
    option( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_WRITES_ENABLED                "picolibrary-microchip-megaavr: avrdude disalbe writes"                OFF )
    option( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED      "picolibrary-microchip-megaavr: avrdude override signature check"      OFF )
    mark_as_advanced(
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_WRITES_ENABLED
        PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED
    )

    set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_BAUD_RATE           ""        CACHE STRING "picolibrary-microchip-megaavr: avrdude baud rate"           )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_BIT_CLOCK           ""        CACHE STRING "picolibrary-microchip-megaavr: avrdude bit clock"           )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_CONFIGURATION_FILE  ""        CACHE STRING "picolibrary-microchip-megaavr: avrdude configuration file"  )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DELAY               ""        CACHE STRING "picolibrary-microchip-megaavr: avrdude delay"               )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_EXIT_SPECIFICATION  ""        CACHE STRING "picolibrary-microchip-megaavr: avrdude exit specification"  )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_EXTENDED_PARAMETERS ""        CACHE STRING "picolibrary-microchip-megaavr: avrdude extended parameters" )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PART                ""        CACHE STRING "picolibrary-microchip-megaavr: avrdude part"                )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PORT                ""        CACHE STRING "picolibrary-microchip-megaavr: avrdude port"                )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_PROGRAMMER          ""        CACHE STRING "picolibrary-microchip-megaavr: avrdude programmer"          )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_VERBOSITY           "VERBOSE" CACHE STRING "picolibrary-microchip-megaavr: avrdude verbosity"           )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_ALWAYS_RECOVER_FUSES "ALWAYS_RECOVER_FUSES" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED} )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE "DISABLE_AUTOMATIC_FLASH_ERASE" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED} )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_VERIFY "DISABLE_AUTOMATIC_VERIFY" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED} )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_FUSE_CHECKS "DISABLE_FUSE_CHECKS" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED} )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_WRITES_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_WRITES "DISABLE_WRITES" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_DISABLE_WRITES_ENABLED} )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_OVERRIDE_SIGNATURE_CHECK "OVERRIDE_SIGNATURE_CHECK" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING} )

# build the library
add_subdirectory( source )

# build the library's tests
add_subdirectory( test )
