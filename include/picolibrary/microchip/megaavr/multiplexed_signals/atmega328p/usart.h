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
 * \brief picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P usart
 *        interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_USART_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_USART_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/microchip/megaavr/peripheral/atmega328p.h"
#include "picolibrary/microchip/megaavr/peripheral/port.h"
#include "picolibrary/microchip/megaavr/peripheral/usart.h"
#include "picolibrary/precondition.h"

namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P {

/**
 * \brief Lookup a USART peripheral's pins PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::usart_port_address().
 *
 * \param[in] usart_address The address of the USART peripheral whose pins PORT peripheral
 *            address is to be looked up.
 *
 * \return The USART peripheral's pins PORT peripheral address.
 */
constexpr auto usart_port_address( std::uintptr_t usart_address ) noexcept -> std::uintptr_t
{
    switch ( usart_address ) {
        case Peripheral::ATmega328P::USART0::ADDRESS:
            return Peripheral::ATmega328P::PORTD::ADDRESS;
    } // switch

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a USART peripheral's pins PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::usart_port().
 *
 * \param[in] usart The USART peripheral whose pins PORT peripheral is to be looked up.
 *
 * \return The USART peripheral's pins PORT peripheral.
 */
inline auto usart_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return *reinterpret_cast<Peripheral::PORT *>(
        usart_port_address( reinterpret_cast<std::uintptr_t>( &usart ) ) );
}

/**
 * \brief Lookup a USART peripheral's XCK pin PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_port_address().
 *
 * \param[in] usart_address The address of the USART peripheral whose XCK pin PORT
 *            peripheral address is to be looked up.
 *
 * \return The USART peripheral's XCK pin PORT peripheral address.
 */
constexpr auto xck_port_address( std::uintptr_t usart_address ) noexcept -> std::uintptr_t
{
    return usart_port_address( usart_address );
}

/**
 * \brief Lookup a USART peripheral's XCK pin PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_port().
 *
 * \param[in] usart The USART peripheral whose XCK pin PORT peripheral is to be looked up.
 *
 * \return The USART peripheral's XCK pin PORT peripheral.
 */
inline auto xck_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's XCK pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_number().
 *
 * \param[in] usart_address The address of the USART peripheral whose XCK pin number is to
 *            be looked up.
 *
 * \return The USART peripheral's XCK pin number.
 */
constexpr auto xck_number( std::uintptr_t usart_address ) noexcept -> std::uint_fast8_t
{
    switch ( usart_address ) {
        case Peripheral::ATmega328P::USART0::ADDRESS: return 4;
    } // switch

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a USART peripheral's XCK pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_number().
 *
 * \param[in] usart The USART peripheral whose XCK pin number is to be looked up.
 *
 * \return The USART peripheral's XCK pin number.
 */
inline auto xck_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    return xck_number( reinterpret_cast<std::uintptr_t>( &usart ) );
}

/**
 * \brief Lookup a USART peripheral's XCK pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_mask().
 *
 * \param[in] usart_address The address of the USART peripheral whose XCK pin mask is to
 *            be looked up.
 *
 * \return The USART peripheral's XCK pin mask.
 */
constexpr auto xck_mask( std::uintptr_t usart_address ) noexcept -> std::uint8_t
{
    return 1 << xck_number( usart_address );
}

/**
 * \brief Lookup a USART peripheral's XCK pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_mask().
 *
 * \param[in] usart The USART peripheral whose XCK pin mask is to be looked up.
 *
 * \return The USART peripheral's XCK pin mask.
 */
inline auto xck_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return xck_mask( reinterpret_cast<std::uintptr_t>( &usart ) );
}

/**
 * \brief Lookup a USART peripheral's TXD pin PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_port_address().
 *
 * \param[in] usart_address The address of the USART peripheral whose TXD pin PORT
 *            peripheral address is to be looked up.
 *
 * \return The USART peripheral's TXD pin PORT peripheral address.
 */
constexpr auto txd_port_address( std::uintptr_t usart_address ) noexcept -> std::uintptr_t
{
    return usart_port_address( usart_address );
}

/**
 * \brief Lookup a USART peripheral's TXD pin PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_port().
 *
 * \param[in] usart The USART peripheral whose TXD pin PORT peripheral is to be looked up.
 *
 * \return The USART peripheral's TXD pin PORT peripheral.
 */
inline auto txd_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's TXD pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_number().
 *
 * \param[in] usart_address The address of the USART peripheral whose TXD pin number is to
 *            be looked up.
 *
 * \return The USART peripheral's TXD pin number.
 */
constexpr auto txd_number( std::uintptr_t usart_address ) noexcept -> std::uint_fast8_t
{
    switch ( usart_address ) {
        case Peripheral::ATmega328P::USART0::ADDRESS: return 1;
    } // switch

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a USART peripheral's TXD pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_number().
 *
 * \param[in] usart The USART peripheral whose TXD pin number is to be looked up.
 *
 * \return The USART peripheral's TXD pin number.
 */
inline auto txd_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    return txd_number( reinterpret_cast<std::uintptr_t>( &usart ) );
}

/**
 * \brief Lookup a USART peripheral's TXD pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_mask().
 *
 * \param[in] usart_address The address of the USART peripheral whose TXD pin mask is to
 *            be looked up.
 *
 * \return The USART peripheral's TXD pin mask.
 */
constexpr auto txd_mask( std::uintptr_t usart_address ) noexcept -> std::uint8_t
{
    return 1 << txd_number( usart_address );
}

/**
 * \brief Lookup a USART peripheral's TXD pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_mask().
 *
 * \param[in] usart The USART peripheral whose TXD pin mask is to be looked up.
 *
 * \return The USART peripheral's TXD pin mask.
 */
inline auto txd_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return txd_mask( reinterpret_cast<std::uintptr_t>( &usart ) );
}

/**
 * \brief Lookup a USART peripheral's RXD pin PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_port_address().
 *
 * \param[in] usart_address The address of the USART peripheral whose RXD pin PORT
 *            peripheral address is to be looked up.
 *
 * \return The USART peripheral's RXD pin PORT peripheral address.
 */
constexpr auto rxd_port_address( std::uintptr_t usart_address ) noexcept -> std::uintptr_t
{
    return usart_port_address( usart_address );
}

/**
 * \brief Lookup a USART peripheral's RXD pin PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_port().
 *
 * \param[in] usart The USART peripheral whose RXD pin PORT peripheral is to be looked up.
 *
 * \return The USART peripheral's RXD pin PORT peripheral.
 */
inline auto rxd_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's RXD pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_number().
 *
 * \param[in] usart_address The address of the USART peripheral whose RXD pin number is to
 *            be looked up.
 *
 * \return The USART peripheral's RXD pin number.
 */
constexpr auto rxd_number( std::uintptr_t usart_address ) noexcept -> std::uint_fast8_t
{
    switch ( usart_address ) {
        case Peripheral::ATmega328P::USART0::ADDRESS: return 0;
    } // switch

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a USART peripheral's RXD pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_number().
 *
 * \param[in] usart The USART peripheral whose RXD pin number is to be looked up.
 *
 * \return The USART peripheral's RXD pin number.
 */
inline auto rxd_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    return rxd_number( reinterpret_cast<std::uintptr_t>( &usart ) );
}

/**
 * \brief Lookup a USART peripheral's RXD pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_mask().
 *
 * \param[in] usart_address The address of the USART peripheral whose RXD pin mask is to
 *            be looked up.
 *
 * \return The USART peripheral's RXD pin mask.
 */
constexpr auto rxd_mask( std::uintptr_t usart_address ) noexcept -> std::uint8_t
{
    return 1 << rxd_number( usart_address );
}

/**
 * \brief Lookup a USART peripheral's RXD pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_mask().
 *
 * \param[in] usart The USART peripheral whose RXD pin mask is to be looked up.
 *
 * \return The USART peripheral's RXD pin mask.
 */
inline auto rxd_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return rxd_mask( reinterpret_cast<std::uintptr_t>( &usart ) );
}

} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_USART_H
