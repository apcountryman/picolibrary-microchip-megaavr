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
 * \brief picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560 TWI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_TWI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_TWI_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/microchip/megaavr/peripheral/atmega2560.h"
#include "picolibrary/microchip/megaavr/peripheral/port.h"
#include "picolibrary/microchip/megaavr/peripheral/twi.h"
#include "picolibrary/precondition.h"

namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560 {

/**
 * \brief Lookup a TWI peripheral's pins PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::twi_port_address().
 *
 * \param[in] twi_address The address of the TWI peripheral whose pins PORT peripheral
 *            address is to be looked up.
 *
 * \return The TWI peripheral's pins PORT peripheral address.
 */
constexpr auto twi_port_address( std::uintptr_t twi_address ) noexcept -> std::uintptr_t
{
    switch ( twi_address ) {
        case Peripheral::ATmega2560::TWI0::ADDRESS:
            return Peripheral::ATmega2560::PORTD::ADDRESS;
    } // switch

    expect( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a TWI peripheral's pins PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::twi_port().
 *
 * \param[in] twi The TWI peripheral whose pins PORT peripheral is to be looked up.
 *
 * \return The TWI peripheral's pins PORT peripheral.
 */
inline auto twi_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    return *reinterpret_cast<Peripheral::PORT *>(
        twi_port_address( reinterpret_cast<std::uintptr_t>( &twi ) ) );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_port_address().
 *
 * \param[in] twi_address The address of the TWI peripheral whose SCL pin PORT peripheral
 *            address is to be looked up.
 *
 * \return The TWI peripheral's SCL pin PORT peripheral address.
 */
constexpr auto scl_port_address( std::uintptr_t twi_address ) noexcept -> std::uintptr_t
{
    return twi_port_address( twi_address );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_port().
 *
 * \param[in] twi The TWI peripheral whose SCL pin PORT peripheral is to be looked up.
 *
 * \return The TWI peripheral's SCL pin PORT peripheral.
 */
inline auto scl_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    return twi_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_number().
 *
 * \param[in] twi_address The address of the TWI peripheral whose SCL pin number is to be
 *            looked up.
 *
 * \return The TWI peripheral's SCL pin number.
 */
constexpr auto scl_number( std::uintptr_t twi_address ) noexcept -> std::uint_fast8_t
{
    switch ( twi_address ) {
        case Peripheral::ATmega2560::TWI0::ADDRESS: return 0;
    } // switch

    expect( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_number().
 *
 * \param[in] twi The TWI peripheral whose SCL pin number is to be looked up.
 *
 * \return The TWI peripheral's SCL pin number.
 */
inline auto scl_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    return scl_number( reinterpret_cast<std::uintptr_t>( &twi ) );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_mask().
 *
 * \param[in] twi_address The address of the TWI peripheral whose SCL pin mask is to be
 *            looked up.
 *
 * \return The TWI peripheral's SCL pin mask.
 */
constexpr auto scl_mask( std::uintptr_t twi_address ) noexcept -> std::uint8_t
{
    return 1 << scl_number( twi_address );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_mask().
 *
 * \param[in] twi The TWI peripheral whose SCL pin mask is to be looked up.
 *
 * \return The TWI peripheral's SCL pin mask.
 */
inline auto scl_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return scl_mask( reinterpret_cast<std::uintptr_t>( &twi ) );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_port_address().
 *
 * \param[in] twi_address The address of the TWI peripheral whose SDA pin PORT peripheral
 *            address is to be looked up.
 *
 * \return The TWI peripheral's SDA pin PORT peripheral address.
 */
constexpr auto sda_port_address( std::uintptr_t twi_address ) noexcept -> std::uintptr_t
{
    return twi_port_address( twi_address );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_port().
 *
 * \param[in] twi The TWI peripheral whose SDA pin PORT peripheral is to be looked up.
 *
 * \return The TWI peripheral's SDA pin PORT peripheral.
 */
inline auto sda_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    return twi_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_number().
 *
 * \param[in] twi_address The address of the TWI peripheral whose SDA pin number is to be
 *            looked up.
 *
 * \return The TWI peripheral's SDA pin number.
 */
constexpr auto sda_number( std::uintptr_t twi_address ) noexcept -> std::uint_fast8_t
{
    switch ( twi_address ) {
        case Peripheral::ATmega2560::TWI0::ADDRESS: return 1;
    } // switch

    expect( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_number().
 *
 * \param[in] twi The TWI peripheral whose SDA pin number is to be looked up.
 *
 * \return The TWI peripheral's SDA pin number.
 */
inline auto sda_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    return sda_number( reinterpret_cast<std::uintptr_t>( &twi ) );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_mask().
 *
 * \param[in] twi_address The address of the TWI peripheral whose SDA pin mask is to be
 *            looked up.
 *
 * \return The TWI peripheral's SDA pin mask.
 */
constexpr auto sda_mask( std::uintptr_t twi_address ) noexcept -> std::uint8_t
{
    return 1 << sda_number( twi_address );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_mask().
 *
 * \param[in] twi The TWI peripheral whose SDA pin mask is to be looked up.
 *
 * \return The TWI peripheral's SDA pin mask.
 */
inline auto sda_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return sda_mask( reinterpret_cast<std::uintptr_t>( &twi ) );
}

} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_TWI_H
