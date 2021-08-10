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
 * \brief picolibrary::Microchip::MCP3008 sample interactive test program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/asynchronous_serial/stream.h"
#include "picolibrary/gpio.h"
#include "picolibrary/microchip/mcp3008.h"
#include "picolibrary/microchip/megaavr/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr/gpio.h"
#include "picolibrary/microchip/megaavr/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/microchip/megaavr/peripheral/spi.h"
#include "picolibrary/microchip/megaavr/spi.h"
#include "picolibrary/spi.h"
#include "picolibrary/testing/interactive/microchip/mcp3008.h"

namespace {

using namespace ::picolibrary::Microchip::megaAVR::Peripheral;

using ::picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream;
using ::picolibrary::GPIO::Active_Low_IO_Pin;
using ::picolibrary::Microchip::MCP3008::Channel;
using ::picolibrary::Microchip::MCP3008::Channel_Pair;
using ::picolibrary::Microchip::MCP3008::Input;
using ::picolibrary::Microchip::megaAVR::Asynchronous_Serial::Clock_Configuration;
using ::picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter_8_N_1;
using ::picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin;
using ::picolibrary::Microchip::megaAVR::Multiplexed_Signals::ds_mask;
using ::picolibrary::Microchip::megaAVR::Multiplexed_Signals::ds_port;
using ::picolibrary::Microchip::megaAVR::Peripheral::SPI;
using ::picolibrary::SPI::GPIO_Output_Pin_Device_Selector;
using ::picolibrary::Testing::Interactive::Microchip::MCP3008::sample;

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
    sample<Unbuffered_Output_Stream>(
        Transmitter_8_N_1{ TRANSMITTER_USART::instance(),
                           { .operating_speed = Clock_Configuration::Operating_Speed::TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED,
                             .scaling_factor = TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR } },
        Controller{ CONTROLLER_SPI::instance() },
        { .clock_rate     = SPI::Clock_Rate::CONTROLLER_CLOCK_RATE,
          .clock_polarity = SPI::Clock_Polarity::IDLE_LOW,
          .clock_phase    = SPI::Clock_Phase::CAPTURE_IDLE_TO_ACTIVE,
          .bit_order      = SPI::Bit_Order::MSB_FIRST },
        GPIO_Output_Pin_Device_Selector<Active_Low_IO_Pin<Push_Pull_IO_Pin>>{
            ds_port( CONTROLLER_SPI::instance() ), ds_mask( CONTROLLER_SPI::instance() ) },
        MCP3008_INPUT,
        []() { avrlibcpp::delay_ms( 1000 ); } );

    for ( ;; ) {}
}
