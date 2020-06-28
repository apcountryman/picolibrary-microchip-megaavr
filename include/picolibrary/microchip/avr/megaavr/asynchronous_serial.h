/**
 * picolibrary-microchip-avr-megaavr
 *
 * Copyright 2020 Andrew Countryman <apcountryman@gmail.com>
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
 * \brief picolibrary::Microchip::AVR::megaAVR::Asynchronous_Serial interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_ASYNCHRONOUS_SERIAL_H
#define PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_ASYNCHRONOUS_SERIAL_H

#include <cstdint>

#include "picolibrary/microchip/avr/megaavr/peripheral/usart.h"

/**
 * \brief Microchip AVR megaAVR asynchronous serial facilities.
 */
namespace picolibrary::Microchip::AVR::megaAVR::Asynchronous_Serial {

/**
 * \brief Microchip AVR megaAVR asynchronous serial clock configuration.
 */
struct Clock_Configuration {
    /**
     * \brief The clock generator operating speed.
     */
    Peripheral::USART::Operating_Speed operating_speed;

    /**
     * \brief The clock generator scaling factor.
     */
    std::uint16_t scaling_factor;
};

} // namespace picolibrary::Microchip::AVR::megaAVR::Asynchronous_Serial

#endif // PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_ASYNCHRONOUS_SERIAL_H
