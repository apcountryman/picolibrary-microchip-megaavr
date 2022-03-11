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
 * \brief picolibrary::Microchip::megaAVR::Peripheral::SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_SPI_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr/register.h"

namespace picolibrary::Microchip::megaAVR::Peripheral {

/**
 * \brief Microchip megaAVR Serial Peripheral Interface (SPI) peripheral.
 */
class SPI {
  public:
    /**
     * \brief SPI Control Register (SPCR) register.
     *
     * This register has the following fields:
     * - SPI Clock Rate Select (SPR)
     * - Clock Phase (CPHA)
     * - Clock Polarity (CPOL)
     * - Host/Client Select (MSTR)
     * - Data Order (DORD)
     * - SPI Enable (SPE)
     * - SPI Interrupt Enable (SPIE)
     */
    class SPCR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SPR  = std::uint_fast8_t{ 2 }; ///< SPR.
            static constexpr auto CPHA = std::uint_fast8_t{ 1 }; ///< CPHA.
            static constexpr auto CPOL = std::uint_fast8_t{ 1 }; ///< CPOL.
            static constexpr auto MSTR = std::uint_fast8_t{ 1 }; ///< MSTR.
            static constexpr auto DORD = std::uint_fast8_t{ 1 }; ///< DORD.
            static constexpr auto SPE  = std::uint_fast8_t{ 1 }; ///< SPE.
            static constexpr auto SPIE = std::uint_fast8_t{ 1 }; ///< SPIE.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SPR  = std::uint_fast8_t{};                  ///< SPR.
            static constexpr auto CPHA = std::uint_fast8_t{ SPR + Size::SPR }; ///< CPHA.
            static constexpr auto CPOL = std::uint_fast8_t{ CPHA + Size::CPHA }; ///< CPOL.
            static constexpr auto MSTR = std::uint_fast8_t{ CPOL + Size::CPOL }; ///< MSTR.
            static constexpr auto DORD = std::uint_fast8_t{ MSTR + Size::MSTR }; ///< DORD.
            static constexpr auto SPE  = std::uint_fast8_t{ DORD + Size::DORD }; ///< SPE.
            static constexpr auto SPIE = std::uint_fast8_t{ SPE + Size::SPE }; ///< SPIE.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SPR = mask<std::uint8_t>( Size::SPR, Bit::SPR ); ///< SPR.
            static constexpr auto CPHA = mask<std::uint8_t>( Size::CPHA, Bit::CPHA ); ///< CPHA.
            static constexpr auto CPOL = mask<std::uint8_t>( Size::CPOL, Bit::CPOL ); ///< CPOL.
            static constexpr auto MSTR = mask<std::uint8_t>( Size::MSTR, Bit::MSTR ); ///< MSTR.
            static constexpr auto DORD = mask<std::uint8_t>( Size::DORD, Bit::DORD ); ///< DORD.
            static constexpr auto SPE = mask<std::uint8_t>( Size::SPE, Bit::SPE ); ///< SPE.
            static constexpr auto SPIE = mask<std::uint8_t>( Size::SPIE, Bit::SPIE ); ///< SPIE.
        };

        /**
         * \brief CPHA.
         */
        enum CPHA : std::uint8_t {
            CPHA_LEADING_EDGE_SAMPLE_TRAILING_EDGE_SETUP = 0b0 << Bit::CPHA, ///< Leading edge: sample, trailing edge: setup.
            CPHA_LEADING_EDGE_SETUP_TRAILING_EDGE_SAMPLE = 0b1 << Bit::CPHA, ///< Leading edge: setup, trailing edge: sample.
        };

        /**
         * \brief CPOL.
         */
        enum CPOL : std::uint8_t {
            CPOL_LEADING_EDGE_RISING_TRAILING_EDGE_FALLING = 0b0 << Bit::CPOL, ///< Leading edge: rising, trailing edge: falling.
            CPOL_LEADING_EDGE_FALLING_TRAILING_EDGE_RISING = 0b1 << Bit::CPOL, ///< Leading edge: falling, trailing edge: rising.
        };

        SPCR() = delete;

        SPCR( SPCR && ) = delete;

        SPCR( SPCR const & ) = delete;

        ~SPCR() = delete;

        auto operator=( SPCR && ) = delete;

        auto operator=( SPCR const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief SPI Status Register (SPSR) register.
     *
     * This register has the following fields:
     * - Double SPI Speed Bit (SPI2X)
     * - Write Collision Flag (WCOL)
     * - SPI Interrupt Flag (SPIF)
     */
    class SPSR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SPI2X     = std::uint_fast8_t{ 1 }; ///< SPI2X.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 5 }; ///< RESERVED1.
            static constexpr auto WCOL      = std::uint_fast8_t{ 1 }; ///< WCOL.
            static constexpr auto SPIF      = std::uint_fast8_t{ 1 }; ///< SPIF.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SPI2X = std::uint_fast8_t{}; ///< SPI2X.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ SPI2X + Size::SPI2X }; ///< RESERVED1.
            static constexpr auto WCOL = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< WCOL.
            static constexpr auto SPIF = std::uint_fast8_t{ WCOL + Size::WCOL }; ///< SPIF.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SPI2X = mask<std::uint8_t>( Size::SPI2X, Bit::SPI2X ); ///< SPI2X.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto WCOL = mask<std::uint8_t>( Size::WCOL, Bit::WCOL ); ///< WCOL.
            static constexpr auto SPIF = mask<std::uint8_t>( Size::SPIF, Bit::SPIF ); ///< SPIF.
        };

        SPSR() = delete;

        SPSR( SPSR && ) = delete;

        SPSR( SPSR const & ) = delete;

        ~SPSR() = delete;

        auto operator=( SPSR && ) = delete;

        auto operator=( SPSR const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief SPCR.
     */
    SPCR spcr;

    /**
     * \brief SPSR.
     */
    SPSR spsr;

    /**
     * \brief SPI Data Register (SPDR) register.
     */
    Register<std::uint8_t> spdr;

    SPI() = delete;

    SPI( SPI && ) = delete;

    SPI( SPI const & ) = delete;

    ~SPI() = delete;

    auto operator=( SPI && ) = delete;

    auto operator=( SPI const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_SPI_H
