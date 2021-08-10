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
 * \brief picolibrary::Microchip::megaAVR::GPIO::Internally_Pulled_Up_Input_Pin state
 *        interactive test program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/asynchronous_serial/stream.h"
#include "picolibrary/microchip/megaavr/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr/gpio.h"
#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/testing/interactive/gpio.h"

namespace {

using namespace ::picolibrary::Microchip::megaAVR::Peripheral;

using ::picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream;
using ::picolibrary::Microchip::megaAVR::Asynchronous_Serial::Clock_Configuration;
using ::picolibrary::Microchip::megaAVR::Asynchronous_Serial::Transmitter_8_N_1;
using ::picolibrary::Microchip::megaAVR::GPIO::Internally_Pulled_Up_Input_Pin;
using ::picolibrary::Testing::Interactive::GPIO::state;

} // namespace

/**
 * \brief Execute the
 *        picolibrary::Microchip::megaAVR::GPIO::Internally_Pulled_Up_Input_Pin state
 *        interactive test.
 *
 * \return 0.
 */
int main()
{
    state<Unbuffered_Output_Stream>(
        Transmitter_8_N_1{ TRANSMITTER_USART::instance(),
                           { .operating_speed = Clock_Configuration::Operating_Speed::TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED,
                             .scaling_factor = TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR } },
        Internally_Pulled_Up_Input_Pin{ PIN_PORT::instance(), PIN_MASK },
        []() { avrlibcpp::delay_ms( 1000 ); } );

    for ( ;; ) {}
}
