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
 * \brief picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_H

#include "picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/twi.h"
#include "picolibrary/microchip/megaavr/multiplexed_signals/atmega328p/usart.h"

/**
 * \brief Microchip megaAVR ATmega328/P multiplexed signals facilities.
 *
 * \attention The contents of this namespace should not be used directly. Instead, set the
 *            `-mmcu` compiler flag to `atmega328p` and use them through the
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals namespace.
 */
namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P {
} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P

namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals {

#ifdef __AVR_ATmega328P__
using namespace ATmega328P;
#endif // __AVR_ATmega328P__

} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_H
