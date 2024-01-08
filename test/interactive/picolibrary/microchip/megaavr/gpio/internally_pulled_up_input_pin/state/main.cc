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
 * \brief picolibrary::Microchip::megaAVR::GPIO::Internally_Pulled_Up_Input_Pin state
 *        interactive test program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/microchip/megaavr/gpio.h"
#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/testing/interactive/gpio.h"
#include "picolibrary/testing/interactive/microchip/megaavr/log.h"

namespace {

using ::picolibrary::Microchip::megaAVR::GPIO::Internally_Pulled_Up_Input_Pin;
using ::picolibrary::Testing::Interactive::GPIO::state;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR::Log;

using namespace ::picolibrary::Microchip::megaAVR::Peripheral;

} // namespace

/**
 * \brief Execute the
 *        picolibrary::Microchip::megaAVR::GPIO::Internally_Pulled_Up_Input_Pin state
 *        interactive test.
 *
 * \return N/A
 */
int main() noexcept
{
    Log::initialize();

    state( Log::instance(), Internally_Pulled_Up_Input_Pin{ PIN_PORT::instance(), PIN_MASK }, []() {
        avrlibcpp::delay_ms( 1000 );
    } );

    for ( ;; ) {} // for
}
