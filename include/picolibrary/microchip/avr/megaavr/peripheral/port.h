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
 * \brief picolibrary::Microchip::AVR::megaAVR::Peripheral::PORT interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_PORT_H
#define PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_PORT_H

#include <cstdint>

#include "picolibrary/microchip/avr/megaavr/register.h"

namespace picolibrary::Microchip::AVR::megaAVR::Peripheral {

/**
 * \brief Microchip AVR megaAVR General Purpose Input/Output (GPIO) port.
 */
class PORT {
  public:
    /**
     * \brief Port Input Pins Register (PIN).
     */
    Register<std::uint8_t> pin;

    /**
     * \brief Data Direction Register (DDR).
     */
    Register<std::uint8_t> ddr;

    /**
     * \brief Data Register (PORT).
     */
    Register<std::uint8_t> port;

    PORT() = delete;

    /**
     * \todo #27
     */
    PORT( PORT && ) = delete;

    /**
     * \todo #27
     */
    PORT( PORT const & ) = delete;

    ~PORT() = delete;

    /**
     * \todo #27
     *
     * \return
     */
    auto operator=( PORT && ) = delete;

    /**
     * \todo #27
     *
     * \return
     */
    auto operator=( PORT const & ) = delete;
};

} // namespace picolibrary::Microchip::AVR::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_PORT_H
