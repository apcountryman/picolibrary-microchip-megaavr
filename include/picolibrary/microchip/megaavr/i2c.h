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
 * \brief picolibrary::Microchip::megaAVR::I2C interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H

#include <cstdint>

#include "picolibrary/microchip/megaavr/peripheral/twi.h"

/**
 * \brief Microchip megaAVR Inter-Integrated Circuit (I2C) facilities.
 */
namespace picolibrary::Microchip::megaAVR::I2C {

/**
 * \brief TWI bit rate generator prescaler value.
 */
enum class TWI_Bit_Rate_Generator_Prescaler_Value : std::uint8_t {
    _1  = Peripheral::TWI::TWSR::TWPS_1,  ///< 1.
    _4  = Peripheral::TWI::TWSR::TWPS_4,  ///< 4.
    _16 = Peripheral::TWI::TWSR::TWPS_16, ///< 16.
    _64 = Peripheral::TWI::TWSR::TWPS_64, ///< 64.
};

} // namespace picolibrary::Microchip::megaAVR::I2C

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H
