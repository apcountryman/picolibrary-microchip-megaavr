/**
 * picolibrary-microchip-megaavr
 *
 * Copyright 2020-2024, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Microchip::megaAVR::I2C::Controller scan interactive test program.
 */

#include "picolibrary/microchip/megaavr/i2c.h"
#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/testing/interactive/i2c.h"
#include "picolibrary/testing/interactive/microchip/megaavr/log.h"

namespace {

using ::picolibrary::Microchip::megaAVR::I2C::Controller;
using ::picolibrary::Microchip::megaAVR::I2C::TWI_Bit_Rate_Generator_Prescaler_Value;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR::Log;

using namespace ::picolibrary::Microchip::megaAVR::Peripheral;

} // namespace

/**
 * \brief Execute the picolibrary::Microchip::megaAVR::I2C::Controller scan interactive
 *        test.
 *
 * \return N/A
 */
int main() noexcept
{
    Log::initialize();

    ::picolibrary::Testing::Interactive::I2C::scan(
        Log::instance(),
        Controller{ CONTROLLER_TWI::instance(),
                    TWI_Bit_Rate_Generator_Prescaler_Value::CONTROLLER_TWI_BIT_RATE_GENERATOR_PRESCALER_VALUE,
                    CONTROLLER_TWI_BIT_RATE_GENERATOR_SCALING_FACTOR } );

    for ( ;; ) {} // for
}
