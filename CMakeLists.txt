# picolibrary-microchip-avr-megaavr
#
# Copyright 2020 Andrew Countryman <apcountryman@gmail.com>
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
# Description: picolibrary-microchip-avr-megaavr core CMake rules.

cmake_minimum_required( VERSION 3.12.4 )
project(
    picolibrary-microchip-avr-megaavr
    LANGUAGES CXX
)

# project configuration
option( PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_ENABLE_INTERACTIVE_TESTING     "picolibrary-microchip-avr-megaavr: enable interactive testing"       OFF )
option( PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP   "picolibrary-microchip-avr-megaavr: use parent project's avr-libcpp"  ON  )
option( PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_PARENT_PROJECT_BUILD_FLAGS "picolibrary-microchip-avr-megaavr: use parent project's build flags" ON  )
option( PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY "picolibrary-microchip-avr-megaavr: use parent project's picolibrary" ON  )

# load additional CMake modules
list(
    APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/apcountryman-cmake-utilities"
)

# configure compilation and linking
if( NOT ${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_PARENT_PROJECT_BUILD_FLAGS} )
    set(
        CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} \
        -std=c++17 \
        -Werror -Wall -Wextra \
        -Wcast-qual \
        -Wextra-semi \
        -Wfloat-equal \
        -Wmissing-field-initializers \
        -Wmissing-include-dirs \
        -Wold-style-cast \
        -Wpointer-arith \
        -Wshadow \
        "
    )

    option( PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_STATIC_ANALYSIS_BUILD_FLAGS "picolibrary-microchip-avr-megaavr: use static analysis build flags" OFF )
    if( NOT ${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_STATIC_ANALYSIS_BUILD_FLAGS} )
        set( PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_MCU "" CACHE STRING "picolibrary-microchip-avr-megaavr: MCU type" )

        set(
            CMAKE_CXX_FLAGS
            "${CMAKE_CXX_FLAGS} \
            -mmcu=${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_MCU} \
            -Wcast-align=strict \
            -Wduplicated-cond \
            -Wimplicit-fallthrough=5 \
            -Wlogical-op \
            -Wplacement-new=2 \
            -Wunsafe-loop-optimizations \
            "
        )
    endif( NOT ${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_STATIC_ANALYSIS_BUILD_FLAGS} )
endif( NOT ${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_PARENT_PROJECT_BUILD_FLAGS} )

# configure avr-libcpp
if( NOT ${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP} )
    set( AVRLIBCPP_USE_PARENT_PROJECT_BUILD_FLAGS ON CACHE BOOL "" FORCE )

    add_subdirectory( avr-libcpp )

    link_libraries( avr-libcpp )
endif( NOT ${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP} )

# configure picolibrary
if( NOT ${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY} )
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

    set( PICOLIBRARY_ENABLE_INTERACTIVE_TESTING "${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_ENABLE_INTERACTIVE_TESTING}" CACHE BOOL "" FORCE )
    mark_as_advanced( PICOLIBRARY_ENABLE_UNIT_TESTING )

    add_subdirectory( picolibrary )
endif( NOT ${PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY} )

# capture project version information
include( git-utilities )
execute_git_command(
    PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_VERSION
    COMMAND describe --match=none --always --dirty --broken
)

# configure Doxygen
find_package( Doxygen )
if( ${DOXYGEN_FOUND} )
    set(
        PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_DOCUMENTATION_EXCLUDE_PATTERNS
        " \
        */.git/* \
        */README.md \
        */avr-libcpp/* \
        */build/* \
        */cmake/modules/* \
        */picolibrary/README.md \
        */picolibrary/cmake/modules/* \
        */picolibrary/documentation/mainpage.md \
        */picolibrary/googletest/* \
        */picolibrary/lizard/* \
        */toolchain-avr-gcc/* \
        "
    )

    set( DOXYFILE "${CMAKE_CURRENT_BINARY_DIR}/documentation/Doxyfile" )
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/documentation/Doxyfile.in"
        "${DOXYFILE}"
        @ONLY
    )
    add_custom_target(
        picolibrary-microchip-avr-megaavr-documentation
        ALL
        COMMAND           "${DOXYGEN_EXECUTABLE}" "${DOXYFILE}"
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/documentation"
    )
endif( ${DOXYGEN_FOUND} )

# build the library
add_subdirectory( source )

# build the library's tests
add_subdirectory( test )
