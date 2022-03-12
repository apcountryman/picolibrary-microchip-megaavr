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
 * \brief picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560 interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_H

#include "picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/spi.h"
#include "picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/twi.h"
#include "picolibrary/microchip/megaavr/multiplexed_signals/atmega2560/usart.h"

/**
 * \brief Microchip megaAVR ATmega2560 multiplexed signals facilities.
 *
 * \attention The contents of this namespace should not be used directly. Instead, set the
 *            `-mmcu` compiler flag to `atmega2560` and use them through the
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals namespace.
 */
namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560 {
} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560

namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals {

#ifdef __AVR_ATmega2560__
using namespace ATmega2560;
#endif // __AVR_ATmega2560__

} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_H
