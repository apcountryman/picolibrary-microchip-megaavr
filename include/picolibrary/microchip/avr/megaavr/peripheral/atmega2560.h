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
 * \brief picolibrary::Microchip::AVR::megaAVR::Peripheral::ATmega2560 interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_ATMEGA2560_H
#define PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_ATMEGA2560_H

#include "picolibrary/microchip/avr/megaavr/peripheral/usart.h"

/**
 * \brief Microchip AVR megaAVR ATmega2560 peripherals.
 *
 * \attention The contents of this namespace should never be used directly. Instead, set
 *            the `-mmcu` compiler flag to `atmega2560` and use them through the
 *            picolibrary::Microchip::AVR::megaAVR::Peripheral namespace.
 */
namespace picolibrary::Microchip::AVR::megaAVR::Peripheral::ATmega2560 {

/**
 * \brief USART0.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::AVR::megaAVR::Peripheral::usart0().
 *
 * \return USART0.
 */
inline USART & usart0() noexcept
{
    return *reinterpret_cast<USART *>( 0x00C0 );
}

/**
 * \brief USART1.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::AVR::megaAVR::Peripheral::usart1().
 *
 * \return USART1.
 */
inline USART & usart1() noexcept
{
    return *reinterpret_cast<USART *>( 0x00C8 );
}

/**
 * \brief USART2.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::AVR::megaAVR::Peripheral::usart2().
 *
 * \return USART2.
 */
inline USART & usart2() noexcept
{
    return *reinterpret_cast<USART *>( 0x00D0 );
}

/**
 * \brief USART3.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::AVR::megaAVR::Peripheral::usart3().
 *
 * \return USART3.
 */
inline USART & usart3() noexcept
{
    return *reinterpret_cast<USART *>( 0x0130 );
}

} // namespace picolibrary::Microchip::AVR::megaAVR::Peripheral::ATmega2560

namespace picolibrary::Microchip::AVR::megaAVR::Peripheral {

#ifdef __AVR_ATmega2560__
using namespace ATmega2560;
#endif // __AVR_ATmega2560__

} // namespace picolibrary::Microchip::AVR::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_ATMEGA2560_H
