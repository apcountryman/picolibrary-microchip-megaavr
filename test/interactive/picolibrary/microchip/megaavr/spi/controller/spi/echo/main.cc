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
 * \brief picolibrary::Microchip::megaAVR::SPI::Controller<picolibrary::Microchip::megaAVR::Peripheral::SPI>
 *        echo interactive test program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/asynchronous_serial/stream.h"
#include "picolibrary/microchip/megaavr/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr/gpio.h"
#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/microchip/megaavr/peripheral/usart.h"
#include "picolibrary/microchip/megaavr/spi.h"
#include "picolibrary/testing/interactive/spi.h"

namespace {

using namespace ::picolibrary::Microchip::megaAVR::Peripheral;

using ::picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream;
using ::picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter_8_N_1;
using ::picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin;
using ::picolibrary::Microchip::megaAVR::Peripheral::SPI;
using ::picolibrary::Microchip::megaAVR::Peripheral::USART;
using ::picolibrary::Testing::Interactive::SPI::echo;

using Controller = ::picolibrary::Microchip::megaAVR::SPI::Controller<SPI>;

} // namespace

/**
 * \brief Execute the
 *        picolibrary::Microchip::megaAVR::SPI::Controller<picolibrary::Microchip::megaAVR::Peripheral::SPI>
 *        echo interactive test.
 *
 * \return 0.
 */
int main()
{
    {
        auto ss = Push_Pull_IO_Pin{ SS_PORT::instance(), SS_MASK };

        static_cast<void>( ss.initialize() );

        echo<Unbuffered_Output_Stream>(
            Transmitter_8_N_1{ TRANSMITTER_USART::instance(),
                               { .operating_speed = USART::Operating_Speed::TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED,
                                 .scaling_factor = TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR } },
            Controller{ Push_Pull_IO_Pin{ SCK_PORT::instance(), SCK_MASK },
                        Push_Pull_IO_Pin{ MOSI_PORT::instance(), MOSI_MASK },
                        CONTROLLER_SPI::instance() },
            { SPI::Clock_Rate::CONTROLLER_CLOCK_RATE,
              SPI::Clock_Polarity::CONTROLLER_CLOCK_POLARITY,
              SPI::Clock_Phase::CONTROLLER_CLOCK_PHASE,
              SPI::Bit_Order::CONTROLLER_BIT_ORDER },
            []() { avrlibcpp::delay_ms( 100 ); } );
    }

    for ( ;; ) {}
}
