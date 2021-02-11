/**
 * picolibrary-microchip-megaavr
 *
 * Copyright 2020-2021, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Microchip::megaAVR::SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_H

#include "picolibrary/spi.h"

/**
 * \brief Microchip megaAVR Serial Peripheral Interface (SPI) facilities.
 */
namespace picolibrary::Microchip::megaAVR::SPI {

/**
 * \brief SPI basic controller.
 *
 * \tparam Peripheral The type of peripheral used to implement SPI basic controller
 *         functionality.
 */
template<typename Peripheral>
class Basic_Controller;

/**
 * \brief SPI controller.
 *
 * \tparam Peripheral The type of peripheral used to implement SPI controller
 *         functionality.
 */
template<typename Peripheral>
using Controller = ::picolibrary::SPI::Controller<Basic_Controller<Peripheral>>;

} // namespace picolibrary::Microchip::megaAVR::SPI

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_H