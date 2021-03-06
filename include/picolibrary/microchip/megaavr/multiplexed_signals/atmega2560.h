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
#include "picolibrary/microchip/megaavr/peripheral/spi.h"
#include "picolibrary/microchip/megaavr/peripheral/twi.h"
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
 * \brief SPI peripheral signals.
 */
inline namespace SPI {

/**
 * \brief Lookup an SPI peripheral's DS pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ds_port().
 *
 * \param[in] usart The SPI peripheral whose DS pin port is to be looked up.
 *
 * \return The SPI peripheral's DS pin port.
 */
inline auto ds_port( Peripheral::SPI const & usart ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::SPI0::ADDRESS:
            return Peripheral::ATmega2560::PORTB::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup an SPI peripheral's DS pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ds_number().
 *
 * \param[in] usart The SPI peripheral whose DS pin number is to be looked up.
 *
 * \return The SPI peripheral's DS pin number.
 */
inline auto ds_number( Peripheral::SPI const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::SPI0::ADDRESS: return 0;
    } // switch

    return 0;
}

/**
 * \brief Lookup an SPI peripheral's DS pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ds_mask().
 *
 * \param[in] usart The SPI peripheral whose DS pin mask is to be looked up.
 *
 * \return The SPI peripheral's DS pin mask.
 */
inline auto ds_mask( Peripheral::SPI const & usart ) noexcept -> std::uint8_t
{
    return 1 << ds_number( usart );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_port().
 *
 * \param[in] usart The SPI peripheral whose SCK pin port is to be looked up.
 *
 * \return The SPI peripheral's SCK pin port.
 */
inline auto sck_port( Peripheral::SPI const & usart ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::SPI0::ADDRESS:
            return Peripheral::ATmega2560::PORTB::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_number().
 *
 * \param[in] usart The SPI peripheral whose SCK pin number is to be looked up.
 *
 * \return The SPI peripheral's SCK pin number.
 */
inline auto sck_number( Peripheral::SPI const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::SPI0::ADDRESS: return 1;
    } // switch

    return 0;
}

/**
 * \brief Lookup an SPI peripheral's SCK pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_mask().
 *
 * \param[in] usart The SPI peripheral whose SCK pin mask is to be looked up.
 *
 * \return The SPI peripheral's SCK pin mask.
 */
inline auto sck_mask( Peripheral::SPI const & usart ) noexcept -> std::uint8_t
{
    return 1 << sck_number( usart );
}

/**
 * \brief Lookup an SPI peripheral's CODI pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::codi_port().
 *
 * \param[in] usart The SPI peripheral whose CODI pin port is to be looked up.
 *
 * \return The SPI peripheral's CODI pin port.
 */
inline auto codi_port( Peripheral::SPI const & usart ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::SPI0::ADDRESS:
            return Peripheral::ATmega2560::PORTB::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup an SPI peripheral's CODI pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::codi_number().
 *
 * \param[in] usart The SPI peripheral whose CODI pin number is to be looked up.
 *
 * \return The SPI peripheral's CODI pin number.
 */
inline auto codi_number( Peripheral::SPI const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::SPI0::ADDRESS: return 2;
    } // switch

    return 0;
}

/**
 * \brief Lookup an SPI peripheral's CODI pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::codi_mask().
 *
 * \param[in] usart The SPI peripheral whose CODI pin mask is to be looked up.
 *
 * \return The SPI peripheral's CODI pin mask.
 */
inline auto codi_mask( Peripheral::SPI const & usart ) noexcept -> std::uint8_t
{
    return 1 << codi_number( usart );
}

/**
 * \brief Lookup an SPI peripheral's CIDO pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::cido_port().
 *
 * \param[in] usart The SPI peripheral whose CIDO pin port is to be looked up.
 *
 * \return The SPI peripheral's CIDO pin port.
 */
inline auto cido_port( Peripheral::SPI const & usart ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::SPI0::ADDRESS:
            return Peripheral::ATmega2560::PORTB::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup an SPI peripheral's CIDO pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::cido_number().
 *
 * \param[in] usart The SPI peripheral whose CIDO pin number is to be looked up.
 *
 * \return The SPI peripheral's CIDO pin number.
 */
inline auto cido_number( Peripheral::SPI const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::SPI0::ADDRESS: return 3;
    } // switch

    return 0;
}

/**
 * \brief Lookup an SPI peripheral's CIDO pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::cido_mask().
 *
 * \param[in] usart The SPI peripheral whose CIDO pin mask is to be looked up.
 *
 * \return The SPI peripheral's CIDO pin mask.
 */
inline auto cido_mask( Peripheral::SPI const & usart ) noexcept -> std::uint8_t
{
    return 1 << cido_number( usart );
}

} // namespace SPI

/**
 * \brief TWI peripheral signals.
 */
inline namespace TWI {

/**
 * \brief Lookup a TWI peripheral's SCL pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_port().
 *
 * \param[in] usart The TWI peripheral whose SCL pin port is to be looked up.
 *
 * \return The TWI peripheral's SCL pin port.
 */
inline auto scl_port( Peripheral::TWI const & usart ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::TWI0::ADDRESS:
            return Peripheral::ATmega2560::PORTD::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_number().
 *
 * \param[in] usart The TWI peripheral whose SCL pin number is to be looked up.
 *
 * \return The TWI peripheral's SCL pin number.
 */
inline auto scl_number( Peripheral::TWI const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::TWI0::ADDRESS: return 0;
    } // switch

    return 0;
}

/**
 * \brief Lookup a TWI peripheral's SCL pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::scl_mask().
 *
 * \param[in] usart The TWI peripheral whose SCL pin mask is to be looked up.
 *
 * \return The TWI peripheral's SCL pin mask.
 */
inline auto scl_mask( Peripheral::TWI const & usart ) noexcept -> std::uint8_t
{
    return 1 << scl_number( usart );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_port().
 *
 * \param[in] usart The TWI peripheral whose SDA pin port is to be looked up.
 *
 * \return The TWI peripheral's SDA pin port.
 */
inline auto sda_port( Peripheral::TWI const & usart ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::TWI0::ADDRESS:
            return Peripheral::ATmega2560::PORTD::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_number().
 *
 * \param[in] usart The TWI peripheral whose SDA pin number is to be looked up.
 *
 * \return The TWI peripheral's SDA pin number.
 */
inline auto sda_number( Peripheral::TWI const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega2560::TWI0::ADDRESS: return 1;
    } // switch

    return 0;
}

/**
 * \brief Lookup a TWI peripheral's SDA pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sda_mask().
 *
 * \param[in] usart The TWI peripheral whose SDA pin mask is to be looked up.
 *
 * \return The TWI peripheral's SDA pin mask.
 */
inline auto sda_mask( Peripheral::TWI const & usart ) noexcept -> std::uint8_t
{
    return 1 << sda_number( usart );
}

} // namespace TWI

/**
 * \brief USART peripheral signals.
 */
inline namespace USART {

/**
 * \brief Lookup a USART peripheral's XCK pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_port().
 *
 * \param[in] usart The USART peripheral whose XCK pin port is to be looked up.
 *
 * \return The USART peripheral's XCK pin port.
 */
inline auto xck_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
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
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_number().
 *
 * \param[in] usart The USART peripheral whose XCK pin number is to be looked up.
 *
 * \return The USART peripheral's XCK pin number.
 */
inline auto xck_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
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
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::xck_mask().
 *
 * \param[in] usart The USART peripheral whose XCK pin mask is to be looked up.
 *
 * \return The USART peripheral's XCK pin mask.
 */
inline auto xck_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return 1 << xck_number( usart );
}

/**
 * \brief Lookup a USART peripheral's TXD pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_port().
 *
 * \param[in] usart The USART peripheral whose TXD pin port is to be looked up.
 *
 * \return The USART peripheral's TXD pin port.
 */
inline auto txd_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
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
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_number().
 *
 * \param[in] usart The USART peripheral whose TXD pin number is to be looked up.
 *
 * \return The USART peripheral's TXD pin number.
 */
inline auto txd_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
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
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::txd_mask().
 *
 * \param[in] usart The USART peripheral whose TXD pin mask is to be looked up.
 *
 * \return The USART peripheral's TXD pin mask.
 */
inline auto txd_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return 1 << txd_number( usart );
}

/**
 * \brief Lookup a USART peripheral's RXD pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega2560` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_port().
 *
 * \param[in] usart The USART peripheral whose RXD pin port is to be looked up.
 *
 * \return The USART peripheral's RXD pin port.
 */
inline auto rxd_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
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
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_number().
 *
 * \param[in] usart The USART peripheral whose RXD pin number is to be looked up.
 *
 * \return The USART peripheral's RXD pin number.
 */
inline auto rxd_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
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
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::rxd_mask().
 *
 * \param[in] usart The USART peripheral whose RXD pin mask is to be looked up.
 *
 * \return The USART peripheral's RXD pin mask.
 */
inline auto rxd_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return 1 << rxd_number( usart );
}

} // namespace USART

} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega2560

namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals {

#ifdef __AVR_ATmega2560__
using namespace ATmega2560;
#endif // __AVR_ATmega2560__

} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA2560_H
