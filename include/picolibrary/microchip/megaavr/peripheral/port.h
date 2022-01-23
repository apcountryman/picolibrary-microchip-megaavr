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
 * \brief picolibrary::Microchip::megaAVR::Peripheral::Port interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_PORT_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_PORT_H

#include <cstdint>

#include "picolibrary/microchip/megaavr/peripheral/instance.h"
#include "picolibrary/microchip/megaavr/register.h"

namespace picolibrary::Microchip::megaAVR::Peripheral {

/**
 * \brief Microchip megaAVR General Purpose Input/Output (GPIO) Port (PORT) peripheral.
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

/**
 * \brief Microchip megaAVR General Purpose Input/Output (GPIO) Port (PORT) peripheral
 *        instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the PORT peripheral instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using PORT_Instance = Instance<PORT, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_PORT_H
