/**
 * picolibrary-microchip-avr-megaavr
 *
 * Copyright 2020 Andrew Countryman <apcountryman@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under
 * the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * \file
 * \brief picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream hello world Microchip
 *        AVR megaAVR interactive test program.
 */

#include "picolibrary/asynchronous_serial/stream.h"
#include "picolibrary/microchip/avr/megaavr/asynchronous_serial.h"
#include "picolibrary/microchip/avr/megaavr/peripheral.h"
#include "picolibrary/microchip/avr/megaavr/peripheral/usart.h"
#include "picolibrary/testing/interactive/asynchronous_serial/stream.h"

namespace {

using namespace ::picolibrary::Microchip::AVR::megaAVR::Peripheral;

using ::picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream;
using ::picolibrary::Microchip::AVR::megaAVR::Asynchronous_Serial::Transmitter_8_N_1;
using ::picolibrary::Microchip::AVR::megaAVR::Peripheral::USART;
using ::picolibrary::Testing::Interactive::Asynchronous_Serial::Stream::hello_world;

} // namespace

/**
 * \brief Execute the picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream hello
 *        world Microchip AVR megaAVR interactive test.
 *
 * \return 0.
 */
int main()
{
    hello_world<Unbuffered_Output_Stream>( Transmitter_8_N_1{
        TRANSMITTER_USART::instance(),
        { .operating_speed = USART::Operating_Speed::TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED,
          .scaling_factor = TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR } } );
}
