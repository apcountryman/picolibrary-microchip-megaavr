/**
 * picolibrary-microchip-avr-megaavr
 *
 * Copyright 2020 Andrew Countryman <apcountryman@gmail.com>
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
 * \brief picolibrary::Microchip::AVR::megaAVR::Peripheral::USART interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_USART_H
#define PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_USART_H

#include <cstdint>

#include "picolibrary/microchip/avr/megaavr/register.h"

namespace picolibrary::Microchip::AVR::megaAVR::Peripheral {

/**
 * \brief Microchip AVR megaAVR Universal Synchronous Asynchronous Receiver Transciever
 *        (USART) peripheral.
 */
class USART {
  public:
    /**
     * \brief USART Control and Status Register A (UCSRA).
     *
     * This register has the following fields:
     * - Multi-Processor Communication Mode (MPCM)
     * - Double USART Speed (U2X)
     * - USART Parity Error (UPE)
     * - Data Overrun (DOR)
     * - Frame Error (FE)
     * - USART Data Register Empty (UDRE)
     * - USART Transmit Complete (TXC)
     * - USART Receive Complete (RXC)
     */
    class UCSRA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto MPCM = std::uint_fast8_t{ 1 }; ///< MPCM.
            static constexpr auto U2X  = std::uint_fast8_t{ 1 }; ///< U2X.
            static constexpr auto UPE  = std::uint_fast8_t{ 1 }; ///< UPE.
            static constexpr auto DOR  = std::uint_fast8_t{ 1 }; ///< DOR.
            static constexpr auto FE   = std::uint_fast8_t{ 1 }; ///< FE.
            static constexpr auto UDRE = std::uint_fast8_t{ 1 }; ///< UDRE.
            static constexpr auto TXC  = std::uint_fast8_t{ 1 }; ///< TXC.
            static constexpr auto RXC  = std::uint_fast8_t{ 1 }; ///< RXC.
        };

        UCSRA() = delete;

        /**
         * \todo #27
         */
        UCSRA( UCSRA && ) = delete;

        /**
         * \todo #27
         */
        UCSRA( UCSRA const & ) = delete;

        ~UCSRA() = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRA && ) = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRA const & ) = delete;
    };

    /**
     * \brief USART Control and Status Register B (UCSRB).
     *
     * This register has the following fields:
     * - Transmit Data Bit 8 (TXB8)
     * - Receive Data Bit 8 (RXB8)
     * - Character Size Bit 2 (UCSZ2) (referred to as UCSZ within this class)
     * - Transmitter Enable (TXEN)
     * - Receiver Enable (RXEN)
     * - USART Data Register Empty Interrupt Enable (UDRIE)
     * - Transmit Complete Interrupt Enable (TXCIE)
     * - Receive Complete Interrupt Enable (RXCIE)
     */
    class UCSRB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TXB8  = std::uint_fast8_t{ 1 }; ///< TXB8.
            static constexpr auto RXB8  = std::uint_fast8_t{ 1 }; ///< RXB8.
            static constexpr auto UCSZ  = std::uint_fast8_t{ 1 }; ///< UCSZ.
            static constexpr auto TXEN  = std::uint_fast8_t{ 1 }; ///< TXEN.
            static constexpr auto RXEN  = std::uint_fast8_t{ 1 }; ///< RXEN.
            static constexpr auto UDRIE = std::uint_fast8_t{ 1 }; ///< UDRIE.
            static constexpr auto TXCIE = std::uint_fast8_t{ 1 }; ///< TXCIE.
            static constexpr auto RXCIE = std::uint_fast8_t{ 1 }; ///< RXCIE.
        };

        UCSRB() = delete;

        /**
         * \todo #27
         */
        UCSRB( UCSRB && ) = delete;

        /**
         * \todo #27
         */
        UCSRB( UCSRB const & ) = delete;

        ~UCSRB() = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRB && ) = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRB const & ) = delete;
    };

    /**
     * \brief USART Control and Status Register A (UCSRC).
     *
     * This register has the following fields:
     * - USART Clock Polarity (UCPOL)
     * - USART Character Size Bits 0 and 1 (UCSZ)
     * - USART Clock Phase (UCPHA)
     * - USART Data Order (UDORD)
     * - USART Stop Bit Select (USBS)
     * - USART Parity Mode (UPM)
     * - USART Mode Select (UMSEL)
     */
    class UCSRC : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto UCPOL = std::uint_fast8_t{ 1 }; ///< UCPOL.
            static constexpr auto UCSZ  = std::uint_fast8_t{ 2 }; ///< UCSZ.
            static constexpr auto USBS  = std::uint_fast8_t{ 1 }; ///< USBS.
            static constexpr auto UPM   = std::uint_fast8_t{ 2 }; ///< UPM.
            static constexpr auto UMSEL = std::uint_fast8_t{ 2 }; ///< UMSEL.

            static constexpr auto UCPHA = std::uint_fast8_t{ 1 }; ///< UCPHA.
            static constexpr auto UDORD = std::uint_fast8_t{ 1 }; ///< UDORD.
        };

        UCSRC() = delete;

        /**
         * \todo #27
         */
        UCSRC( UCSRC && ) = delete;

        /**
         * \todo #27
         */
        UCSRC( UCSRC const & ) = delete;

        ~UCSRC() = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRC && ) = delete;

        /**
         * \todo #27
         *
         * \return
         */
        auto operator=( UCSRC const & ) = delete;
    };

    /**
     * \brief UCSRA.
     */
    UCSRA ucsra;

    /**
     * \brief UCSRB.
     */
    UCSRB ucsrb;

    /**
     * \brief UCSRC.
     */
    UCSRC ucsrc;

    /**
     * \brief Reserved register.
     */
    Reserved_Register<std::uint8_t> const reserved;

    /**
     * \brief USART Baud Rate Register (UBRR).
     */
    Register<std::uint16_t> ubrr;

    /**
     * \brief USART Data Register (UDR).
     */
    Register<std::uint8_t> udr;

    USART() = delete;

    /**
     * \todo #27
     */
    USART( USART && ) = delete;

    /**
     * \todo #27
     */
    USART( USART const & ) = delete;

    ~USART() = delete;

    /**
     * \todo #27
     *
     * \return
     */
    auto operator=( USART && ) = delete;

    /**
     * \todo #27
     *
     * \return
     */
    auto operator=( USART const & ) = delete;
};

} // namespace picolibrary::Microchip::AVR::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_USART_H
