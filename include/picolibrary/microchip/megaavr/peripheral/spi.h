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
 * \brief picolibrary::Microchip::megaAVR::Peripheral::SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_SPI_H

#include <cstdint>

#include "picolibrary/microchip/megaavr/register.h"

namespace picolibrary::Microchip::megaAVR::Peripheral {

/**
 * \brief Microchip megaAVR Serial Peripheral Interface (SPI) peripheral.
 */
class SPI {
  public:
    /**
     * \brief SPI Control Register (SPCR).
     *
     * This register has the following fields:
     * - SPI Clock Rate Select (SPR)
     * - Clock Phase (CPHA)
     * - Clock Polarity (CPOL)
     * - Master/Slave Select (MSTR)
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
            static constexpr auto SPR  = std::uint8_t{ 0b11 << Bit::SPR }; ///< SPR.
            static constexpr auto CPHA = std::uint8_t{ 0b1 << Bit::CPHA }; ///< CPHA.
            static constexpr auto CPOL = std::uint8_t{ 0b1 << Bit::CPOL }; ///< CPOL.
            static constexpr auto MSTR = std::uint8_t{ 0b1 << Bit::MSTR }; ///< MSTR.
            static constexpr auto DORD = std::uint8_t{ 0b1 << Bit::DORD }; ///< DORD.
            static constexpr auto SPE  = std::uint8_t{ 0b1 << Bit::SPE };  ///< SPE.
            static constexpr auto SPIE = std::uint8_t{ 0b1 << Bit::SPIE }; ///< SPIE.
        };

        SPCR() = delete;

        /**
         * \todo #27
         */
        SPCR( SPCR && ) = delete;

        /**
         * \todo #27
         */
        SPCR( SPCR const & ) = delete;

        ~SPCR() = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( SPCR && ) = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( SPCR const & ) = delete;
    };

    /**
     * \brief SPI Status Register (SPSR).
     *
     * This register has the following fields:
     * - Double SPI Speed (SPI2X)
     * - Write Collision (WCOL)
     * - SPI Interrupt (SPIF)
     */
    class SPSR : public Register<std::uint8_t> {
      public:
        SPSR() = delete;

        /**
         * \todo #27
         */
        SPSR( SPSR && ) = delete;

        /**
         * \todo #27
         */
        SPSR( SPSR const & ) = delete;

        ~SPSR() = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( SPSR && ) = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( SPSR const & ) = delete;
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
     * \brief SPI Data Register (SPDR).
     */
    Register<std::uint8_t> spdr;
};

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_SPI_H
