# picolibrary-microchip-megaavr
#
# Copyright 2020-2024, Andrew Countryman <apcountryman@gmail.com> and the
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

# Description: picolibrary::Microchip interactive tests CMake rules.

# picolibrary::Microchip::MCP23008 interactive tests
add_subdirectory( mcp23008 )

# picolibrary::Microchip::MCP23S08 interactive tests
add_subdirectory( mcp23s08 )

# picolibrary::Microchip::MCP3008 interactive tests
add_subdirectory( mcp3008 )

# picolibrary::Microchip::megaAVR interactive tests
add_subdirectory( megaavr )
