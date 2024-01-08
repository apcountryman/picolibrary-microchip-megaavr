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

# Description: picolibrary-microchip-megaavr ATmega2560 Arduino Mega 2560
#       picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream hello world
#       interactive test configuration.

set( PICOLIBRARY_ASYNCHRONOUS_SERIAL_RELIABLE_UNBUFFERED_OUTPUT_STREAM_ENABLE_HELLO_WORLD_INTERACTIVE_TEST ON CACHE INTERNAL "" )

set(
    PICOLIBRARY_ASYNCHRONOUS_SERIAL_RELIABLE_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_DATA_TYPE
    "std::uint8_t" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream hello world interactive test transmitter data type"
)
set(
    PICOLIBRARY_ASYNCHRONOUS_SERIAL_RELIABLE_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART
    "USART1" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream hello world interactive test transmitter USART"
)
set(
    PICOLIBRARY_ASYNCHRONOUS_SERIAL_RELIABLE_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_DATA_BITS
    "_8" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream hello world interactive test transmitter USART data bits"
)
set(
    PICOLIBRARY_ASYNCHRONOUS_SERIAL_RELIABLE_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_PARITY
    "NONE" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream hello world interactive test transmitter USART parity"
)
set(
    PICOLIBRARY_ASYNCHRONOUS_SERIAL_RELIABLE_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_STOP_BITS
    "_1" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream hello world interactive test transmitter USART stop bits"
)
set(
    PICOLIBRARY_ASYNCHRONOUS_SERIAL_RELIABLE_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_CLOCK_GENERATOR_OPERATING_SPEED
    "NORMAL" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream hello world interactive test transmitter USART clock generator operating speed"
)
set(
    PICOLIBRARY_ASYNCHRONOUS_SERIAL_RELIABLE_UNBUFFERED_OUTPUT_STREAM_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_CLOCK_GENERATOR_SCALING_FACTOR
    "103" CACHE STRING
    "picolibrary-microchip-megaavr: picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream hello world interactive test transmitter USART clock generator scaling factor"
)
