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
 * \brief picolibrary::Microchip::megaAVR::Peripheral::PORT interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_PORT_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_PORT_H

#include <cstdint>

#include "picolibrary/register.h"

namespace picolibrary::Microchip::megaAVR::Peripheral {

/**
 * \brief Microchip megaAVR GPIO Port (PORT) peripheral.
 */
class PORT {
  public:
    /**
     * \brief Input Pins (PIN) register.
     */
    Register<std::uint8_t> pin;

    /**
     * \brief Data Direction (DDR) register.
     */
    Register<std::uint8_t> ddr;

    /**
     * \brief Data (PORT) register.
     */
    Register<std::uint8_t> port;

    PORT() = delete;

    PORT( PORT && ) = delete;

    PORT( PORT const & ) = delete;

    ~PORT() = delete;

    auto operator=( PORT && ) = delete;

    auto operator=( PORT const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_PORT_H
