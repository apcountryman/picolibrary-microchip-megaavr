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
 * \brief picolibrary::Microchip::megaAVR::Peripheral::ATmega328P interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_ATMEGA328P_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_ATMEGA328P_H

#include "picolibrary/microchip/megaavr/peripheral/instance.h"
#include "picolibrary/microchip/megaavr/peripheral/port.h"
#include "picolibrary/microchip/megaavr/peripheral/spi.h"
#include "picolibrary/microchip/megaavr/peripheral/twi.h"
#include "picolibrary/microchip/megaavr/peripheral/usart.h"

/**
 * \brief Microchip megaAVR ATmega328/P peripherals.
 *
 * \attention The contents of this namespace should not be used directly. Instead, set the
 *            `-mmcu` compiler flag to `atmega328p` and use them through the
 *            picolibrary::Microchip::megaAVR::Peripheral namespace.
 */
namespace picolibrary::Microchip::megaAVR::Peripheral::ATmega328P {

/**
 * \brief PORTB.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega328p` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTB.
 */
using PORTB = Instance<PORT, 0x0023>;

/**
 * \brief PORTC.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega328p` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTC.
 */
using PORTC = Instance<PORT, 0x0026>;

/**
 * \brief PORTD.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega328p` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::PORTD.
 */
using PORTD = Instance<PORT, 0x0029>;

/**
 * \brief SPI0.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega328p` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::SPI0.
 */
using SPI0 = Instance<SPI, 0x004C>;

/**
 * \brief TWI0.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega328p` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::TWI0.
 */
using TWI0 = Instance<TWI, 0x00B8>;

/**
 * \brief USART0.
 *
 * \attention This type should not be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega328p` and use
 *            picolibrary::Microchip::megaAVR::Peripheral::USART0.
 */
using USART0 = Instance<USART, 0x00C0>;

} // namespace picolibrary::Microchip::megaAVR::Peripheral::ATmega328P

namespace picolibrary::Microchip::megaAVR::Peripheral {

#ifdef __AVR_ATmega328P__
using namespace ATmega328P;
#endif // __AVR_ATmega328P__

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_ATMEGA328P_H
