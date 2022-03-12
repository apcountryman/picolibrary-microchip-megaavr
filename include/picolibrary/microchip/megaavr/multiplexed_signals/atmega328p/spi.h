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
 * \brief picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_SPI_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/microchip/megaavr/peripheral/atmega328p.h"
#include "picolibrary/microchip/megaavr/peripheral/port.h"
#include "picolibrary/microchip/megaavr/peripheral/spi.h"
#include "picolibrary/precondition.h"

namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P {

/**
 * \brief Lookup an SPI peripheral's pins PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::spi_port_address().
 *
 * \param[in] spi_address The address of the SPI peripheral whose pins PORT peripheral
 *            address is to be looked up.
 *
 * \return The SPI peripheral's pins PORT peripheral address.
 */
constexpr auto spi_port_address( std::uintptr_t spi_address ) noexcept -> std::uintptr_t
{
    switch ( spi_address ) {
        case Peripheral::ATmega328P::SPI0::ADDRESS:
            return Peripheral::ATmega328P::PORTB::ADDRESS;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup an SPI peripheral's pins PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::spi_port().
 *
 * \param[in] spi The SPI peripheral whose pins PORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's pins PORT peripheral.
 */
inline auto & spi_port( Peripheral::SPI const & spi ) noexcept
{
    return *reinterpret_cast<Peripheral::PORT *>(
        spi_port_address( reinterpret_cast<std::uintptr_t>( &spi ) ) );
}

/**
 * \brief Lookup an SPI peripheral's SS pin PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ss_port_address().
 *
 * \param[in] spi_address The address of the SPI peripheral whose SS pin PORT peripheral
 *            address is to be looked up.
 *
 * \return The SPI peripheral's SS pin PORT peripheral address.
 */
constexpr auto ss_port_address( std::uintptr_t spi_address ) noexcept
{
    return spi_port_address( spi_address );
}

/**
 * \brief Lookup an SPI peripheral's SS pin PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ss_port().
 *
 * \param[in] spi The SPI peripheral whose SS pin PORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's SS pin PORT peripheral.
 */
inline auto & ss_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's SS pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ss_number().
 *
 * \param[in] spi_address The address of the SPI peripheral whose SS pin number is to be
 *            looked up.
 *
 * \return The SPI peripheral's SS pin number.
 */
constexpr auto ss_number( std::uintptr_t spi_address ) noexcept -> std::uint_fast8_t
{
    switch ( spi_address ) {
        case Peripheral::ATmega328P::SPI0::ADDRESS: return 2;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup an SPI peripheral's SS pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ss_number().
 *
 * \param[in] spi The SPI peripheral whose SS pin number is to be looked up.
 *
 * \return The SPI peripheral's SS pin number.
 */
inline auto ss_number( Peripheral::SPI const & spi ) noexcept
{
    return ss_number( reinterpret_cast<std::uintptr_t>( &spi ) );
}

/**
 * \brief Lookup an SPI peripheral's SS pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ss_mask().
 *
 * \param[in] spi_address The address of the SPI peripheral whose SS pin mask is to be
 *            looked up.
 *
 * \return The SPI peripheral's SS pin mask.
 */
constexpr auto ss_mask( std::uintptr_t spi_address ) noexcept -> std::uint8_t
{
    return 1 << ss_number( spi_address );
}

/**
 * \brief Lookup an SPI peripheral's SS pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::ss_mask().
 *
 * \param[in] spi The SPI peripheral whose SS pin mask is to be looked up.
 *
 * \return The SPI peripheral's SS pin mask.
 */
inline auto ss_mask( Peripheral::SPI const & spi ) noexcept
{
    return ss_mask( reinterpret_cast<std::uintptr_t>( &spi ) );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_port_address().
 *
 * \param[in] spi_address The address of the SPI peripheral whose SCK pin PORT peripheral
 *            address is to be looked up.
 *
 * \return The SPI peripheral's SCK pin PORT peripheral address.
 */
constexpr auto sck_port_address( std::uintptr_t spi_address ) noexcept
{
    return spi_port_address( spi_address );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_port().
 *
 * \param[in] spi The SPI peripheral whose SCK pin PORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's SCK pin PORT peripheral.
 */
inline auto & sck_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_number().
 *
 * \param[in] spi_address The address of the SPI peripheral whose SCK pin number is to be
 *            looked up.
 *
 * \return The SPI peripheral's SCK pin number.
 */
constexpr auto sck_number( std::uintptr_t spi_address ) noexcept -> std::uint_fast8_t
{
    switch ( spi_address ) {
        case Peripheral::ATmega328P::SPI0::ADDRESS: return 5;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup an SPI peripheral's SCK pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_number().
 *
 * \param[in] spi The SPI peripheral whose SCK pin number is to be looked up.
 *
 * \return The SPI peripheral's SCK pin number.
 */
inline auto sck_number( Peripheral::SPI const & spi ) noexcept
{
    return sck_number( reinterpret_cast<std::uintptr_t>( &spi ) );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_mask().
 *
 * \param[in] spi_address The address of the SPI peripheral whose SCK pin mask is to be
 *            looked up.
 *
 * \return The SPI peripheral's SCK pin mask.
 */
constexpr auto sck_mask( std::uintptr_t spi_address ) noexcept -> std::uint8_t
{
    return 1 << sck_number( spi_address );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::sck_mask().
 *
 * \param[in] spi The SPI peripheral whose SCK pin mask is to be looked up.
 *
 * \return The SPI peripheral's SCK pin mask.
 */
inline auto sck_mask( Peripheral::SPI const & spi ) noexcept
{
    return sck_mask( reinterpret_cast<std::uintptr_t>( &spi ) );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::mosi_port_address().
 *
 * \param[in] spi_address The address of the SPI peripheral whose MOSI pin PORT peripheral
 *            address is to be looked up.
 *
 * \return The SPI peripheral's MOSI pin PORT peripheral address.
 */
constexpr auto mosi_port_address( std::uintptr_t spi_address ) noexcept
{
    return spi_port_address( spi_address );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::mosi_port().
 *
 * \param[in] spi The SPI peripheral whose MOSI pin PORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's MOSI pin PORT peripheral.
 */
inline auto & mosi_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::mosi_number().
 *
 * \param[in] spi_address The address of the SPI peripheral whose MOSI pin number is to be
 *            looked up.
 *
 * \return The SPI peripheral's MOSI pin number.
 */
constexpr auto mosi_number( std::uintptr_t spi_address ) noexcept -> std::uint_fast8_t
{
    switch ( spi_address ) {
        case Peripheral::ATmega328P::SPI0::ADDRESS: return 3;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::mosi_number().
 *
 * \param[in] spi The SPI peripheral whose MOSI pin number is to be looked up.
 *
 * \return The SPI peripheral's MOSI pin number.
 */
inline auto mosi_number( Peripheral::SPI const & spi ) noexcept
{
    return mosi_number( reinterpret_cast<std::uintptr_t>( &spi ) );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::mosi_mask().
 *
 * \param[in] spi_address The address of the SPI peripheral whose MOSI pin mask is to be
 *            looked up.
 *
 * \return The SPI peripheral's MOSI pin mask.
 */
constexpr auto mosi_mask( std::uintptr_t spi_address ) noexcept -> std::uint8_t
{
    return 1 << mosi_number( spi_address );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::mosi_mask().
 *
 * \param[in] spi The SPI peripheral whose MOSI pin mask is to be looked up.
 *
 * \return The SPI peripheral's MOSI pin mask.
 */
inline auto mosi_mask( Peripheral::SPI const & spi ) noexcept
{
    return mosi_mask( reinterpret_cast<std::uintptr_t>( &spi ) );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin PORT peripheral address.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::miso_port_address().
 *
 * \param[in] spi_address The address of the SPI peripheral whose MISO pin PORT peripheral
 *            address is to be looked up.
 *
 * \return The SPI peripheral's MISO pin PORT peripheral address.
 */
constexpr auto miso_port_address( std::uintptr_t spi_address ) noexcept
{
    return spi_port_address( spi_address );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin PORT peripheral.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::miso_port().
 *
 * \param[in] spi The SPI peripheral whose MISO pin PORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's MISO pin PORT peripheral.
 */
inline auto & miso_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::miso_number().
 *
 * \param[in] spi_address The address of the SPI peripheral whose MISO pin number is to be
 *            looked up.
 *
 * \return The SPI peripheral's MISO pin number.
 */
constexpr auto miso_number( std::uintptr_t spi_address ) noexcept -> std::uint_fast8_t
{
    switch ( spi_address ) {
        case Peripheral::ATmega328P::SPI0::ADDRESS: return 4;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup an SPI peripheral's MISO pin number.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::miso_number().
 *
 * \param[in] spi The SPI peripheral whose MISO pin number is to be looked up.
 *
 * \return The SPI peripheral's MISO pin number.
 */
inline auto miso_number( Peripheral::SPI const & spi ) noexcept
{
    return miso_number( reinterpret_cast<std::uintptr_t>( &spi ) );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::miso_mask().
 *
 * \param[in] spi_address The address of the SPI peripheral whose MISO pin mask is to be
 *            looked up.
 *
 * \return The SPI peripheral's MISO pin mask.
 */
constexpr auto miso_mask( std::uintptr_t spi_address ) noexcept -> std::uint8_t
{
    return 1 << miso_number( spi_address );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin mask.
 *
 * \attention This function should not be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega328p` and call
 *            picolibrary::Microchip::megaAVR::Multiplexed_Signals::miso_mask().
 *
 * \param[in] spi The SPI peripheral whose MISO pin mask is to be looked up.
 *
 * \return The SPI peripheral's MISO pin mask.
 */
inline auto miso_mask( Peripheral::SPI const & spi ) noexcept
{
    return miso_mask( reinterpret_cast<std::uintptr_t>( &spi ) );
}

} // namespace picolibrary::Microchip::megaAVR::Multiplexed_Signals::ATmega328P

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_MULTIPLEXED_SIGNALS_ATMEGA328P_SPI_H
