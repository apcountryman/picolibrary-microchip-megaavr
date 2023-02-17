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
 * \brief picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI>
 *        echo interactive test program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/microchip/megaavr/peripheral/spi.h"
#include "picolibrary/microchip/megaavr/spi.h"
#include "picolibrary/testing/interactive/microchip/megaavr/log.h"
#include "picolibrary/testing/interactive/spi.h"

namespace {

using ::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Bit_Order;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Clock_Phase;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Clock_Polarity;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Clock_Rate;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR::Log;
using ::picolibrary::Testing::Interactive::SPI::echo;

using namespace ::picolibrary::Microchip::megaAVR::Peripheral;

} // namespace

/**
 * \brief Execute the
 *        picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller<Peripheral::SPI>
 *        echo interactive test.
 *
 * \return N/A
 */
int main() noexcept
{
    Log::initialize();

    echo(
        Log::instance(),
        Fixed_Configuration_Controller<SPI>{ CONTROLLER_SPI::instance(),
                                             SPI_Clock_Rate::CONTROLLER_SPI_CLOCK_RATE,
                                             SPI_Clock_Polarity::CONTROLLER_SPI_CLOCK_POLARITY,
                                             SPI_Clock_Phase::CONTROLLER_SPI_CLOCK_PHASE,
                                             SPI_Bit_Order::CONTROLLER_SPI_BIT_ORDER },
        Fixed_Configuration_Controller<SPI>::Configuration{},
        []() { avrlibcpp::delay_ms( 100 ); } );

    for ( ;; ) {} // for
}
