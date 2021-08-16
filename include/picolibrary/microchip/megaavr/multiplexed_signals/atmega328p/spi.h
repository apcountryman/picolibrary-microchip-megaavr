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
 * \brief picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P::SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_SPI_H

#include <cstdint>

#include "picolibrary/fatal_error.h"
#include "picolibrary/microchip/megaavr/peripheral/atmega328p.h"
#include "picolibrary/microchip/megaavr/peripheral/port.h"
#include "picolibrary/microchip/megaavr/peripheral/spi.h"

namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P {

/**
 * \brief Lookup an SPI peripheral's pins port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::spi_port().
 *
 * \param[in] spi The SPI peripheral whose pins port is to be looked up.
 *
 * \return The SPI peripheral's pins port.
 */
inline auto spi_port( Peripheral::SPI const & spi ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega328P::SPI0::ADDRESS:
            return Peripheral::ATmega328P::PORTB::instance();
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's DS pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ds_port().
 *
 * \param[in] spi The SPI peripheral whose DS pin port is to be looked up.
 *
 * \return The SPI peripheral's DS pin port.
 */
inline auto & ds_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's DS pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ds_number().
 *
 * \param[in] spi The SPI peripheral whose DS pin number is to be looked up.
 *
 * \return The SPI peripheral's DS pin number.
 */
inline auto ds_number( Peripheral::SPI const & spi ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega328P::SPI0::ADDRESS: return 2;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's DS pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ds_mask().
 *
 * \param[in] spi The SPI peripheral whose DS pin mask is to be looked up.
 *
 * \return The SPI peripheral's DS pin mask.
 */
inline auto ds_mask( Peripheral::SPI const & spi ) noexcept -> std::uint8_t
{
    return 1 << ds_number( spi );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_port().
 *
 * \param[in] spi The SPI peripheral whose SCK pin port is to be looked up.
 *
 * \return The SPI peripheral's SCK pin port.
 */
inline auto & sck_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_number().
 *
 * \param[in] spi The SPI peripheral whose SCK pin number is to be looked up.
 *
 * \return The SPI peripheral's SCK pin number.
 */
inline auto sck_number( Peripheral::SPI const & spi ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega328P::SPI0::ADDRESS: return 5;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's SCK pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_mask().
 *
 * \param[in] spi The SPI peripheral whose SCK pin mask is to be looked up.
 *
 * \return The SPI peripheral's SCK pin mask.
 */
inline auto sck_mask( Peripheral::SPI const & spi ) noexcept -> std::uint8_t
{
    return 1 << sck_number( spi );
}

/**
 * \brief Lookup an SPI peripheral's CODI pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::codi_port().
 *
 * \param[in] spi The SPI peripheral whose CODI pin port is to be looked up.
 *
 * \return The SPI peripheral's CODI pin port.
 */
inline auto & codi_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's CODI pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::codi_number().
 *
 * \param[in] spi The SPI peripheral whose CODI pin number is to be looked up.
 *
 * \return The SPI peripheral's CODI pin number.
 */
inline auto codi_number( Peripheral::SPI const & spi ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega328P::SPI0::ADDRESS: return 3;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's CODI pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::codi_mask().
 *
 * \param[in] spi The SPI peripheral whose CODI pin mask is to be looked up.
 *
 * \return The SPI peripheral's CODI pin mask.
 */
inline auto codi_mask( Peripheral::SPI const & spi ) noexcept -> std::uint8_t
{
    return 1 << codi_number( spi );
}

/**
 * \brief Lookup an SPI peripheral's CIDO pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::cido_port().
 *
 * \param[in] spi The SPI peripheral whose CIDO pin port is to be looked up.
 *
 * \return The SPI peripheral's CIDO pin port.
 */
inline auto & cido_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's CIDO pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::cido_number().
 *
 * \param[in] spi The SPI peripheral whose CIDO pin number is to be looked up.
 *
 * \return The SPI peripheral's CIDO pin number.
 */
inline auto cido_number( Peripheral::SPI const & spi ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega328P::SPI0::ADDRESS: return 4;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's CIDO pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::cido_mask().
 *
 * \param[in] spi The SPI peripheral whose CIDO pin mask is to be looked up.
 *
 * \return The SPI peripheral's CIDO pin mask.
 */
inline auto cido_mask( Peripheral::SPI const & spi ) noexcept -> std::uint8_t
{
    return 1 << cido_number( spi );
}

} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_SPI_H
