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

# Description: picolibrary-microchip-megaavr ATmega328/P release configuration.

# build configuration
set( CMAKE_BUILD_TYPE                                             "MinSizeRel" CACHE INTERNAL "" )
set( CMAKE_EXPORT_COMPILE_COMMANDS                                ON           CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_F_CPU                          "16000000UL" CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_MCU                            "atmega328p" CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_BUILD_FLAGS OFF          CACHE INTERNAL "" )

# avr-libcpp configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_AVRLIBCPP OFF CACHE INTERNAL "" )

# picolibrary configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR_USE_PARENT_PROJECT_PICOLIBRARY OFF CACHE INTERNAL "" )
set( PICOLIBRARY_SUPPRESS_ASSERTION_FAILURE_LOCATION_INFORMATION  ON  CACHE INTERNAL "" )
set( PICOLIBRARY_SUPPRESS_HUMAN_READABLE_ERROR_INFORMATION        OFF CACHE INTERNAL "" )
set( PICOLIBRARY_SUPPRESS_HUMAN_READABLE_EVENT_INFORMATION        OFF CACHE INTERNAL "" )

# interactive testing configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR_ENABLE_INTERACTIVE_TESTING OFF CACHE INTERNAL "" )
