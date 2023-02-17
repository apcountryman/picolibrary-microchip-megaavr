/**
 * picolibrary-microchip-megaavr
 *
 * Copyright 2020-2023, Andrew Countryman <apcountryman@gmail.com> and the
 * picolibrary-microchip-megaavr contributors
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
 * \brief picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter hello world
 *        interactive test program.
 */

#include <cstdint>

#include "picolibrary/microchip/megaavr/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/testing/interactive/asynchronous_serial.h"
#include "picolibrary/testing/interactive/microchip/megaavr/log.h"

namespace {

using ::picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter;
using ::picolibrary::Microchip::megaAVR::Asynchronous_Serial::USART_Clock_Generator_Operating_Speed;
using ::picolibrary::Microchip::megaAVR::Asynchronous_Serial::USART_Data_Bits;
using ::picolibrary::Microchip::megaAVR::Asynchronous_Serial::USART_Parity;
using ::picolibrary::Microchip::megaAVR::Asynchronous_Serial::USART_Stop_Bits;
using ::picolibrary::Testing::Interactive::Asynchronous_Serial::hello_world;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR::Log;

using namespace ::picolibrary::Microchip::megaAVR::Peripheral;

} // namespace

/**
 * \brief Execute the picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter
 *        hello world interactive test.
 *
 * \return N/A
 */
int main() noexcept
{
    Log::initialize();

    hello_world( Transmitter<TRANSMITTER_DATA_TYPE>{
        TRANSMITTER_USART::instance(),
        USART_Data_Bits::TRANSMITTER_USART_DATA_BITS,
        USART_Parity::TRANSMITTER_USART_PARITY,
        USART_Stop_Bits::TRANSMITTER_USART_STOP_BITS,
        USART_Clock_Generator_Operating_Speed::TRANSMITTER_USART_CLOCK_GENERATOR_OPERATING_SPEED,
        TRANSMITTER_USART_CLOCK_GENERATOR_SCALING_FACTOR } );

    for ( ;; ) {} // for
}
