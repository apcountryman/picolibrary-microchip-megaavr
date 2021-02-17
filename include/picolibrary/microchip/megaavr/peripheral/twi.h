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
 * \brief picolibrary::Microchip::megaAVR::Peripheral::TWI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_TWI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_TWI_H

#include <cstdint>

#include "picolibrary/microchip/megaavr/peripheral/instance.h"
#include "picolibrary/microchip/megaavr/register.h"

namespace picolibrary::Microchip::megaAVR::Peripheral {

/**
 * \brief Microchip megaAVR 2-wire Serial Interface (TWI) peripheral.
 */
class TWI {
  public:
    /**
     * \brief TWI Control Register (TWCR).
     *
     * This register has the following fields:
     * - TWI Interrupt Enable (TWIE)
     * - TWI Enable (TWEN)
     * - TWI Write Collision (TWWC)
     * - TWI Stop Condition (TWSTO)
     * - TWI Start Condition (TWSTA)
     * - TWI Enable Acknowledge (TWEA)
     * - TWI Interrupt (TWINT)
     */
    class TWCR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TWIE     = std::uint_fast8_t{ 1 }; ///< TWIE.
            static constexpr auto RESERVED = std::uint_fast8_t{ 1 }; ///< Reserved.
            static constexpr auto TWEN     = std::uint_fast8_t{ 1 }; ///< TWEN.
            static constexpr auto TWWC     = std::uint_fast8_t{ 1 }; ///< TWWC.
            static constexpr auto TWSTO    = std::uint_fast8_t{ 1 }; ///< TWSTO.
            static constexpr auto TWSTA    = std::uint_fast8_t{ 1 }; ///< TWSTA.
            static constexpr auto TWEA     = std::uint_fast8_t{ 1 }; ///< TWEA.
            static constexpr auto TWINT    = std::uint_fast8_t{ 1 }; ///< TWINT.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TWIE = std::uint_fast8_t{}; ///< TWIE.
            static constexpr auto RESERVED = std::uint_fast8_t{ TWIE + Size::TWIE }; ///< Reserved.
            static constexpr auto TWEN = std::uint_fast8_t{ RESERVED + Size::RESERVED }; ///< TWEN.
            static constexpr auto TWWC = std::uint_fast8_t{ TWEN + Size::TWEN }; ///< TWWC.
            static constexpr auto TWSTO = std::uint_fast8_t{ TWWC + Size::TWWC }; ///< TWSTO.
            static constexpr auto TWSTA = std::uint_fast8_t{ TWSTO + Size::TWSTO }; ///< TWSTA.
            static constexpr auto TWEA = std::uint_fast8_t{ TWSTA + Size::TWSTA }; ///< TWEA.
            static constexpr auto TWINT = std::uint_fast8_t{ TWEA + Size::TWEA }; ///< TWINT.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TWIE = std::uint8_t{ 0b1 << Bit::TWIE }; ///< TWIE.
            static constexpr auto RESERVED = std::uint8_t{ 0b1 << Bit::RESERVED }; ///< Reserved.
            static constexpr auto TWEN  = std::uint8_t{ 0b1 << Bit::TWEN };  ///< TWEN.
            static constexpr auto TWWC  = std::uint8_t{ 0b1 << Bit::TWWC };  ///< TWWC.
            static constexpr auto TWSTO = std::uint8_t{ 0b1 << Bit::TWSTO }; ///< TWSTO.
            static constexpr auto TWSTA = std::uint8_t{ 0b1 << Bit::TWSTA }; ///< TWSTA.
            static constexpr auto TWEA  = std::uint8_t{ 0b1 << Bit::TWEA };  ///< TWEA.
            static constexpr auto TWINT = std::uint8_t{ 0b1 << Bit::TWINT }; ///< TWINT.
        };

        TWCR() = delete;

        TWCR( TWCR && ) = delete;

        TWCR( TWCR const & ) = delete;

        ~TWCR() = delete;

        auto operator=( TWCR && ) = delete;

        auto operator=( TWCR const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief TWI Status Register (TWSR).
     *
     * This register has the following fields:
     * - TWI Prescaler (TWPS)
     * - TWI Status (TWS)
     */
    class TWSR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TWPS     = std::uint_fast8_t{ 2 }; ///< TWPS.
            static constexpr auto RESERVED = std::uint_fast8_t{ 1 }; ///< Reserved.
            static constexpr auto TWS      = std::uint_fast8_t{ 5 }; ///< TWS.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TWPS = std::uint_fast8_t{}; ///< TWPS.
            static constexpr auto RESERVED = std::uint_fast8_t{ TWPS + Size::TWPS }; ///< Reserved.
            static constexpr auto TWS = std::uint_fast8_t{ RESERVED + Size::RESERVED }; ///< TWS.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TWPS = std::uint8_t{ 0b11 << Bit::TWPS }; ///< TWPS.
            static constexpr auto RESERVED = std::uint8_t{ 0b1 << Bit::RESERVED }; ///< Reserved.
            static constexpr auto TWS = std::uint8_t{ 0b1'1111 << Bit::TWS }; ///< TWS.
        };

        TWSR() = delete;

        TWSR( TWSR && ) = delete;

        TWSR( TWSR const & ) = delete;

        ~TWSR() = delete;

        auto operator=( TWSR && ) = delete;

        auto operator=( TWSR const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief TWI (Device) Address Register (TWAR).
     *
     * This register has the following fields:
     * - TWI General Call Recognition Enable (TWGCE)
     * - TWI (Device) Address (TWA)
     */
    class TWAR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TWGCE = std::uint_fast8_t{ 1 }; ///< TWGCE.
            static constexpr auto TWA   = std::uint_fast8_t{ 7 }; ///< TWA.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TWGCE = std::uint_fast8_t{}; ///< TWGCE.
            static constexpr auto TWA = std::uint_fast8_t{ TWGCE + Size::TWGCE }; ///< TWA.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TWGCE = std::uint8_t{ 0b1 << Bit::TWGCE }; ///< TWGCE.
            static constexpr auto TWA = std::uint8_t{ 0b111'1111 << Bit::TWA }; ///< TWA.
        };

        TWAR() = delete;

        TWAR( TWAR && ) = delete;

        TWAR( TWAR const & ) = delete;

        ~TWAR() = delete;

        auto operator=( TWAR && ) = delete;

        auto operator=( TWAR const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief TWI (Device) Address Mask Register (TWAMR).
     *
     * This register has the following fields:
     * - TWI (Device) Address Mask(TWAM)
     */
    class TWAMR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED = std::uint_fast8_t{ 1 }; ///< Reserved.
            static constexpr auto TWAM     = std::uint_fast8_t{ 7 }; ///< TWAM.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED = std::uint_fast8_t{}; ///< Reserved.
            static constexpr auto TWAM = std::uint_fast8_t{ RESERVED + Size::RESERVED }; ///< TWAM.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED = std::uint8_t{ 0b1 << Bit::RESERVED }; ///< Reserved.
            static constexpr auto TWAM = std::uint8_t{ 0b111'1111 << Bit::TWAM }; ///< TWAM.
        };

        TWAMR() = delete;

        TWAMR( TWAMR && ) = delete;

        TWAMR( TWAMR const & ) = delete;

        ~TWAMR() = delete;

        auto operator=( TWAMR && ) = delete;

        auto operator=( TWAMR const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief TWI Bit Rate Register (TWBR).
     */
    Register<std::uint8_t> twbr;

    /**
     * \brief TWSR.
     */
    TWSR twsr;

    /**
     * \brief TWAR.
     */
    TWAR twar;

    /**
     * \brief TWI Data Register (TWDR).
     */
    Register<std::uint8_t> twdr;

    /**
     * \brief TWCR.
     */
    TWCR twcr;

    /**
     * \brief TWAMR.
     */
    TWAMR twamr;
};

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_TWI_H
