/**
 * picolibrary-microchip-megaavr
 *
 * Copyright 2020-2022, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Microchip::megaAVR::Peripheral::ATmega2560 interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_ATMEGA2560_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_ATMEGA2560_H

#include "picolibrary/microchip/megaavr/peripheral/instance.h"
#include "picolibrary/microchip/megaavr/peripheral/port.h"
#include "picolibrary/microchip/megaavr/peripheral/twi.h"
#include "picolibrary/microchip/megaavr/peripheral/usart.h"

/**
 * \brief Microchip megaAVR ATmega2560 peripherals.
 *
 * \attention The contents of this namespace should not be used directly. Instead, set the
 *            `-mmcu` compiler flag to `atmega2560` and use them through the
 *            picolibrary::Microchip::megaAVR::Peripheral namespace.
 */
namespace picolibrary::Microchip::megaAVR::Peripheral::ATmega2560 {

/**
 * \brief PORTA.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTA.
 */
using PORTA = Instance<PORT, 0x0020>;

/**
 * \brief PORTB.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTB.
 */
using PORTB = Instance<PORT, 0x0023>;

/**
 * \brief PORTC.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTC.
 */
using PORTC = Instance<PORT, 0x0026>;

/**
 * \brief PORTD.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTD.
 */
using PORTD = Instance<PORT, 0x0029>;

/**
 * \brief PORTE.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTE.
 */
using PORTE = Instance<PORT, 0x002C>;

/**
 * \brief PORTF.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTF.
 */
using PORTF = Instance<PORT, 0x002F>;

/**
 * \brief PORTG.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTG.
 */
using PORTG = Instance<PORT, 0x0032>;

/**
 * \brief TWI0.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::TWI0.
 */
using TWI0 = Instance<TWI, 0x00B8>;

/**
 * \brief USART0.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::USART0.
 */
using USART0 = Instance<USART, 0x00C0>;

/**
 * \brief USART1.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::USART1.
 */
using USART1 = Instance<USART, 0x00C8>;

/**
 * \brief USART2.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::USART2.
 */
using USART2 = Instance<USART, 0x00D0>;

/**
 * \brief PORTH.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTH.
 */
using PORTH = Instance<PORT, 0x0100>;

/**
 * \brief PORTJ.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTJ.
 */
using PORTJ = Instance<PORT, 0x0103>;

/**
 * \brief PORTK.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTK.
 */
using PORTK = Instance<PORT, 0x0106>;

/**
 * \brief PORTL.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTL.
 */
using PORTL = Instance<PORT, 0x0109>;

/**
 * \brief USART3.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega2560` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::USART3.
 */
using USART3 = Instance<USART, 0x0130>;

} // namespace picolibrary::Microchip::megaAVR::Peripheral::ATmega2560

namespace picolibrary::Microchip::megaAVR::Peripheral {

#ifdef __AVR_ATmega2560__
using namespace ATmega2560;
#endif // __AVR_ATmega2560__

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_ATMEGA2560_H
