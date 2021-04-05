/**
 * picolibrary-microchip-megaavr
 *
 * Copyright 2020-2021, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test
 *        program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/asynchronous_serial/stream.h"
#include "picolibrary/i2c.h"
#include "picolibrary/microchip/mcp23008.h"
#include "picolibrary/microchip/megaavr/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr/i2c.h"
#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/microchip/megaavr/peripheral/twi.h"
#include "picolibrary/microchip/megaavr/peripheral/usart.h"
#include "picolibrary/testing/interactive/microchip/mcp23008.h"

namespace {

using namespace ::picolibrary::Microchip::megaAVR::Peripheral;

using ::picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream;
using ::picolibrary::I2C::Address;
using ::picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin;
using ::picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter_8_N_1;
using ::picolibrary::Microchip::megaAVR::I2C::Controller;
using ::picolibrary::Microchip::megaAVR::Peripheral::TWI;
using ::picolibrary::Microchip::megaAVR::Peripheral::USART;
using ::picolibrary::Testing::Interactive::Microchip::MCP23008::toggle;

} // namespace

/**
 * \brief Execute the picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle
 *        interactive test.
 *
 * \return 0.
 */
int main()
{
    toggle<Unbuffered_Output_Stream, Push_Pull_IO_Pin>(
        Transmitter_8_N_1{ TRANSMITTER_USART::instance(),
                           { .operating_speed = USART::Operating_Speed::TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED,
                             .scaling_factor = TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR } },
        Controller{ CONTROLLER_TWI::instance(),
                    { .prescaler = TWI::Prescaler::CONTROLLER_BIT_RATE_GENERATOR_PRESCALER,
                      .scaling_factor = CONTROLLER_BIT_RATE_GENERATOR_SCALING_FACTOR } },
        { Address::NUMERIC, MCP23008_ADDRESS },
        PIN_MASK,
        []() { avrlibcpp::delay_ms( 500 ); } );

    for ( ;; ) {}
}
