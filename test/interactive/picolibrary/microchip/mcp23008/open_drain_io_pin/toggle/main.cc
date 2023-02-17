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
 * \brief picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle interactive test
 *        program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/microchip/mcp23008.h"
#include "picolibrary/microchip/megaavr/i2c.h"
#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/testing/interactive/microchip/mcp23008.h"
#include "picolibrary/testing/interactive/microchip/megaavr/log.h"

namespace {

using ::picolibrary::Microchip::MCP23008::Address_Numeric;
using ::picolibrary::Microchip::MCP23008::Address_Transmitted;
using ::picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin;
using ::picolibrary::Microchip::megaAVR::I2C::Controller;
using ::picolibrary::Microchip::megaAVR::I2C::TWI_Bit_Rate_Generator_Prescaler_Value;
using ::picolibrary::Testing::Interactive::Microchip::MCP23008::toggle;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR::Log;

using namespace ::picolibrary::Microchip::megaAVR::Peripheral;

} // namespace

/**
 * \brief Execute the picolibrary::Microchip::MCP23008::Open_Drain_IO_Pin toggle
 *        interactive test.
 *
 * \return N/A
 */
int main() noexcept
{
    Log::initialize();

    toggle<Open_Drain_IO_Pin>(
        Controller{ CONTROLLER_TWI::instance(),
                    TWI_Bit_Rate_Generator_Prescaler_Value::CONTROLLER_TWI_BIT_RATE_GENERATOR_PRESCALER_VALUE,
                    CONTROLLER_TWI_BIT_RATE_GENERATOR_SCALING_FACTOR },
        MCP23008_ADDRESS,
        MCP23008_PIN_MASK,
        []() { avrlibcpp::delay_ms( 500 ); } );

    for ( ;; ) {} // for
}
