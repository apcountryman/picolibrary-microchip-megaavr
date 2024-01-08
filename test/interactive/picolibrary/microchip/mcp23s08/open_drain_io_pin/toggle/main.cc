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
 * \brief picolibrary::Microchip::MCP23S08::Open_Drain_IO_Pin toggle interactive test
 *        program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/gpio.h"
#include "picolibrary/microchip/mcp23s08.h"
#include "picolibrary/microchip/megaavr/gpio.h"
#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/microchip/megaavr/peripheral/spi.h"
#include "picolibrary/microchip/megaavr/spi.h"
#include "picolibrary/spi.h"
#include "picolibrary/testing/interactive/microchip/mcp23s08.h"
#include "picolibrary/testing/interactive/microchip/megaavr/log.h"

namespace {

using ::picolibrary::GPIO::Active_Low_IO_Pin;
using ::picolibrary::Microchip::MCP23S08::Address_Numeric;
using ::picolibrary::Microchip::MCP23S08::Address_Transmitted;
using ::picolibrary::Microchip::MCP23S08::Open_Drain_IO_Pin;
using ::picolibrary::Microchip::megaAVR::GPIO::Push_Pull_IO_Pin;
using ::picolibrary::Microchip::megaAVR::SPI::Fixed_Configuration_Controller;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Bit_Order;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Clock_Phase;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Clock_Polarity;
using ::picolibrary::Microchip::megaAVR::SPI::SPI_Clock_Rate;
using ::picolibrary::SPI::GPIO_Output_Pin_Device_Selector;
using ::picolibrary::Testing::Interactive::Microchip::MCP23S08::toggle;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR::Log;

using namespace ::picolibrary::Microchip::megaAVR::Peripheral;

} // namespace

/**
 * \brief Execute the picolibrary::Microchip::MCP23S08::Open_Drain_IO_Pin toggle
 *        interactive test.
 *
 * \return N/A
 */
int main() noexcept
{
    Log::initialize();

    toggle<Open_Drain_IO_Pin>(
        Fixed_Configuration_Controller<SPI>{ CONTROLLER_SPI::instance(),
                                             SPI_Clock_Rate::CONTROLLER_SPI_CLOCK_RATE,
                                             SPI_Clock_Polarity::CONTROLLER_SPI_CLOCK_POLARITY,
                                             SPI_Clock_Phase::CONTROLLER_SPI_CLOCK_PHASE,
                                             SPI_Bit_Order::MSB_FIRST },
        Fixed_Configuration_Controller<SPI>::Configuration{},
        GPIO_Output_Pin_Device_Selector<Active_Low_IO_Pin<Push_Pull_IO_Pin>>{
            DEVICE_SELECTOR_PORT::instance(), DEVICE_SELECTOR_MASK },
        MCP23S08_ADDRESS,
        MCP23S08_PIN_MASK,
        []() { avrlibcpp::delay_ms( 500 ); } );

    for ( ;; ) {} // for
}
