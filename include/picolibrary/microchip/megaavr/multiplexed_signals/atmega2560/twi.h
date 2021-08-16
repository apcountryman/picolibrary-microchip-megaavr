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
 * \brief picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560::TWI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_TWI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_TWI_H

#include <cstdint>

#include "picolibrary/fatal_error.h"
#include "picolibrary/microchip/megaavr/peripheral/atmega2560.h"
#include "picolibrary/microchip/megaavr/peripheral/port.h"
#include "picolibrary/microchip/megaavr/peripheral/twi.h"

namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560 {

/**
 * \brief Lookup a TWI peripheral's pins port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::twi_port().
 *
 * \param[in] twi The TWI peripheral whose pins port is to be looked up.
 *
 * \return The TWI peripheral's pins port.
 */
inline auto twi_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::ATmega2560::TWI0::ADDRESS:
            return Peripheral::ATmega2560::PORTD::instance();
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a TWI peripheral's SCL pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_port().
 *
 * \param[in] twi The TWI peripheral whose SCL pin port is to be looked up.
 *
 * \return The TWI peripheral's SCL pin port.
 */
inline auto & scl_port( Peripheral::TWI const & twi ) noexcept
{
    return twi_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_number().
 *
 * \param[in] twi The TWI peripheral whose SCL pin number is to be looked up.
 *
 * \return The TWI peripheral's SCL pin number.
 */
inline auto scl_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::ATmega2560::TWI0::ADDRESS: return 0;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a TWI peripheral's SCL pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_mask().
 *
 * \param[in] twi The TWI peripheral whose SCL pin mask is to be looked up.
 *
 * \return The TWI peripheral's SCL pin mask.
 */
inline auto scl_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return 1 << scl_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_port().
 *
 * \param[in] twi The TWI peripheral whose SDA pin port is to be looked up.
 *
 * \return The TWI peripheral's SDA pin port.
 */
inline auto & sda_port( Peripheral::TWI const & twi ) noexcept
{
    return twi_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_number().
 *
 * \param[in] twi The TWI peripheral whose SDA pin number is to be looked up.
 *
 * \return The TWI peripheral's SDA pin number.
 */
inline auto sda_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::ATmega2560::TWI0::ADDRESS: return 1;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a TWI peripheral's SDA pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_mask().
 *
 * \param[in] twi The TWI peripheral whose SDA pin mask is to be looked up.
 *
 * \return The TWI peripheral's SDA pin mask.
 */
inline auto sda_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return 1 << sda_number( twi );
}

} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_TWI_H
