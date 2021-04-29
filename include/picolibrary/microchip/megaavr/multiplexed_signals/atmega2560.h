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
 * \brief picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560 interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_H

#include <cstdint>

#include "picolibrary/microchip/megaavr/peripheral/atmega2560.h"
#include "picolibrary/microchip/megaavr/peripheral/port.h"
#include "picolibrary/microchip/megaavr/peripheral/usart.h"

/**
 * \brief Microchip megaAVR ATmega2560 multiplexed signals facilities.
 *
 * \attention The contents of this namespace should never be used directly. Instead, set
 *            the `-mmcu` compiler flag to `atmega2560` and use them through the
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals namespace.
 */
namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560 {

/**
 * \brief USART peripheral signals.
 */
inline namespace USART {

/**
 * \brief Lookup a USART peripheral's XCK pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_pin_port().
 *
 * \param[in] usart The USART peripheral whose XCK pin port is to be looked up.
 *
 * \return The USART peripheral's XCK pin port.
 */
inline auto xck_pin_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::USART0::ADDRESS:
            return Peripheral::ATmega2560::PORTE::instance();
        case Peripheral::ATmega2560::USART1::ADDRESS:
            return Peripheral::ATmega2560::PORTD::instance();
        case Peripheral::ATmega2560::USART2::ADDRESS:
            return Peripheral::ATmega2560::PORTH::instance();
        case Peripheral::ATmega2560::USART3::ADDRESS:
            return Peripheral::ATmega2560::PORTJ::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup a USART peripheral's XCK pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_pin_number().
 *
 * \param[in] usart The USART peripheral whose XCK pin number is to be looked up.
 *
 * \return The USART peripheral's XCK pin number.
 */
inline auto xck_pin_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::USART0::ADDRESS: return 2;
        case Peripheral::ATmega2560::USART1::ADDRESS: return 5;
        case Peripheral::ATmega2560::USART2::ADDRESS: return 2;
        case Peripheral::ATmega2560::USART3::ADDRESS: return 2;
    } // switch

    return 0;
}

/**
 * \brief Lookup a USART peripheral's XCK pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_pin_mask().
 *
 * \param[in] usart The USART peripheral whose XCK pin mask is to be looked up.
 *
 * \return The USART peripheral's XCK pin mask.
 */
inline auto xck_pin_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return 1 << xck_pin_number( usart );
}

/**
 * \brief Lookup a USART peripheral's TXD pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_pin_port().
 *
 * \param[in] usart The USART peripheral whose TXD pin port is to be looked up.
 *
 * \return The USART peripheral's TXD pin port.
 */
inline auto txd_pin_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::USART0::ADDRESS:
            return Peripheral::ATmega2560::PORTE::instance();
        case Peripheral::ATmega2560::USART1::ADDRESS:
            return Peripheral::ATmega2560::PORTD::instance();
        case Peripheral::ATmega2560::USART2::ADDRESS:
            return Peripheral::ATmega2560::PORTH::instance();
        case Peripheral::ATmega2560::USART3::ADDRESS:
            return Peripheral::ATmega2560::PORTJ::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup a USART peripheral's TXD pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_pin_number().
 *
 * \param[in] usart The USART peripheral whose TXD pin number is to be looked up.
 *
 * \return The USART peripheral's TXD pin number.
 */
inline auto txd_pin_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::USART0::ADDRESS: return 1;
        case Peripheral::ATmega2560::USART1::ADDRESS: return 3;
        case Peripheral::ATmega2560::USART2::ADDRESS: return 1;
        case Peripheral::ATmega2560::USART3::ADDRESS: return 1;
    } // switch

    return 0;
}

/**
 * \brief Lookup a USART peripheral's TXD pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_pin_mask().
 *
 * \param[in] usart The USART peripheral whose TXD pin mask is to be looked up.
 *
 * \return The USART peripheral's TXD pin mask.
 */
inline auto txd_pin_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return 1 << txd_pin_number( usart );
}

/**
 * \brief Lookup a USART peripheral's RXD pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_pin_port().
 *
 * \param[in] usart The USART peripheral whose RXD pin port is to be looked up.
 *
 * \return The USART peripheral's RXD pin port.
 */
inline auto rxd_pin_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::USART0::ADDRESS:
            return Peripheral::ATmega2560::PORTE::instance();
        case Peripheral::ATmega2560::USART1::ADDRESS:
            return Peripheral::ATmega2560::PORTD::instance();
        case Peripheral::ATmega2560::USART2::ADDRESS:
            return Peripheral::ATmega2560::PORTH::instance();
        case Peripheral::ATmega2560::USART3::ADDRESS:
            return Peripheral::ATmega2560::PORTJ::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup a USART peripheral's RXD pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_pin_number().
 *
 * \param[in] usart The USART peripheral whose RXD pin number is to be looked up.
 *
 * \return The USART peripheral's RXD pin number.
 */
inline auto rxd_pin_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::USART0::ADDRESS: return 0;
        case Peripheral::ATmega2560::USART1::ADDRESS: return 2;
        case Peripheral::ATmega2560::USART2::ADDRESS: return 0;
        case Peripheral::ATmega2560::USART3::ADDRESS: return 0;
    } // switch

    return 0;
}

/**
 * \brief Lookup a USART peripheral's RXD pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_pin_mask().
 *
 * \param[in] usart The USART peripheral whose RXD pin mask is to be looked up.
 *
 * \return The USART peripheral's RXD pin mask.
 */
inline auto rxd_pin_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return 1 << rxd_pin_number( usart );
}

} // namespace USART

} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560

namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals {

#ifdef __AVR_ATmega2560__
using namespace ATmega2560;
#endif // __AVR_ATmega2560__

} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_H
