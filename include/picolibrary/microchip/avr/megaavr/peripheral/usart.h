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
    enum class Mode : std::uint8_t;

    enum class Operating_Speed : std::uint8_t;

    enum class Data_Bits : std::uint8_t;

    enum class Parity : std::uint8_t;

    enum class Stop_Bits : std::uint8_t;

    enum class Clock_Polarity : std::uint8_t;

    enum class Clock_Phase : std::uint8_t;

    enum class Bit_Order : std::uint8_t;

    enum class Frame_Type : std::uint8_t;

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

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto MPCM = std::uint_fast8_t{}; ///< MPCM.
            static constexpr auto U2X  = std::uint_fast8_t{ MPCM + Size::MPCM }; ///< U2X.
            static constexpr auto UPE  = std::uint_fast8_t{ U2X + Size::U2X };   ///< UPE.
            static constexpr auto DOR  = std::uint_fast8_t{ UPE + Size::UPE };   ///< DOR.
            static constexpr auto FE   = std::uint_fast8_t{ DOR + Size::DOR };   ///< FE.
            static constexpr auto UDRE = std::uint_fast8_t{ FE + Size::FE }; ///< UDRE.
            static constexpr auto TXC  = std::uint_fast8_t{ UDRE + Size::UDRE }; ///< TXC.
            static constexpr auto RXC  = std::uint_fast8_t{ TXC + Size::TXC };   ///< TXC.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto MPCM = std::uint_fast8_t{ 0b1 << Bit::MPCM }; ///< MPCM.
            static constexpr auto U2X  = std::uint_fast8_t{ 0b1 << Bit::U2X };  ///< U2X.
            static constexpr auto UPE  = std::uint_fast8_t{ 0b1 << Bit::UPE };  ///< UPE.
            static constexpr auto DOR  = std::uint_fast8_t{ 0b1 << Bit::DOR };  ///< DOR.
            static constexpr auto FE   = std::uint_fast8_t{ 0b1 << Bit::FE };   ///< FE.
            static constexpr auto UDRE = std::uint_fast8_t{ 0b1 << Bit::UDRE }; ///< UDRE.
            static constexpr auto TXC  = std::uint_fast8_t{ 0b1 << Bit::TXC };  ///< TXC.
            static constexpr auto RXC  = std::uint_fast8_t{ 0b1 << Bit::RXC };  ///< RXC.
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

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Configure the USART for use as an asynchronous USART.
         *
         * \param[in] operating_speed The desired clock generator operating speed.
         */
        void configure( Operating_Speed operating_speed ) noexcept;

        /**
         * \brief Configure the USART for use as a synchronous USART or an SPI master.
         */
        void configure() noexcept
        {
            *this = 0;
        }

        /**
         * \brief Set the multi-processor communication mode frame type of the next
         *        incoming frame.
         *
         * \param[in] frame_type The frame type of the next incoming frame.
         */
        void set_incoming_frame_type( Frame_Type frame_type ) noexcept;

        /**
         * \brief Check if data is available in the receive buffer.
         *
         * \return true if data is available in the receive buffer.
         * \return false if no data is available in the receive buffer.
         */
        auto data_available() const noexcept -> bool
        {
            return *this & Mask::RXC;
        }

        /**
         * \brief Check if a framing error or parity error occurred during reception of
         *        the next data in the receive buffer, or the receive buffer has
         *        experienced a data overrun.
         *
         * \return true if a framing error or parity error occurred during reception of
         *         the next data in the receive buffer, or the receive buffer has
         *         experienced a data overrun.
         * \return false if neither a framing error nor a parity error occurred during
         *         reception of the next data in the receive buffer, and the receive
         *         buffer has not experienced a data overrun.
         */
        auto error() const noexcept -> bool
        {
            return *this & ( Mask::FE | Mask::UPE | Mask::DOR );
        }

        /**
         * \brief Check if a framing error occurred during reception of the next data in
         *        the receive buffer.
         *
         * \return true if a framing error occurred during reception of the next data in
         *         the receive buffer.
         * \return false if a framing error did not occur during reception of the next
         *         data in the receive buffer.
         */
        auto framing_error() const noexcept -> bool
        {
            return *this & Mask::FE;
        }

        /**
         * \brief Check if a parity error occurred during reception of the next data in
         *        the receive buffer.
         *
         * \return true if a parity error occurred during reception of the next data in
         *         the receive buffer.
         * \return false if a parity error did not occur during reception of the next data
         *         in the receive buffer.
         */
        auto parity_error() const noexcept -> bool
        {
            return *this & Mask::UPE;
        }

        /**
         * \brief Check if the receive buffer has experienced a data overrun.
         *
         * \return true if the receive buffer has experienced a data overrun.
         * \return false if the receive buffer has not experienced a data overrun.
         */
        auto overrun_error() const noexcept -> bool
        {
            return *this & Mask::UPE;
        }

        /**
         * \brief Check if the transmit buffer is empty.
         *
         * \return true if the transmit buffer is empty.
         * \return false if the transmit buffer is not empty.
         */
        auto transmit_buffer_empty() const noexcept -> bool
        {
            return *this & Mask::UDRE;
        }

        /**
         * \brief Check if transmission is complete
         *
         * \return true if transmission is complete.
         * \return false if transmission is not complete.
         */
        auto transmission_complete() const noexcept -> bool
        {
            return *this & Mask::TXC;
        }

        /**
         * \brief Clear the transmission complete flag.
         */
        void clear_transmission_complete() noexcept
        {
            *this |= Mask::TXC;
        }
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

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TXB8 = std::uint_fast8_t{}; ///< TXB8.
            static constexpr auto RXB8 = std::uint_fast8_t{ TXB8 + Size::TXB8 }; ///< RXB8.
            static constexpr auto UCSZ = std::uint_fast8_t{ RXB8 + Size::RXB8 }; ///< UCSZ.
            static constexpr auto TXEN = std::uint_fast8_t{ UCSZ + Size::UCSZ }; ///< TXEN.
            static constexpr auto RXEN = std::uint_fast8_t{ TXEN + Size::TXEN }; ///< TXEN.
            static constexpr auto UDRIE = std::uint_fast8_t{ RXEN + Size::RXEN }; ///< UDRIE.
            static constexpr auto TXCIE = std::uint_fast8_t{ UDRIE + Size::UDRIE }; ///< TXCIE.
            static constexpr auto RXCIE = std::uint_fast8_t{ TXCIE + Size::TXCIE }; ///< TXCIE.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TXB8 = std::uint_fast8_t{ 0b1 << Bit::TXB8 }; ///< TXB8.
            static constexpr auto RXB8 = std::uint_fast8_t{ 0b1 << Bit::RXB8 }; ///< RXB8.
            static constexpr auto UCSZ = std::uint_fast8_t{ 0b1 << Bit::UCSZ }; ///< UCSZ.
            static constexpr auto TXEN = std::uint_fast8_t{ 0b1 << Bit::TXEN }; ///< TXEN.
            static constexpr auto RXEN = std::uint_fast8_t{ 0b1 << Bit::RXEN }; ///< RXEN.
            static constexpr auto UDRIE = std::uint_fast8_t{ 0b1 << Bit::UDRIE }; ///< UDRIE.
            static constexpr auto TXCIE = std::uint_fast8_t{ 0b1 << Bit::TXCIE }; ///< TXCIE.
            static constexpr auto RXCIE = std::uint_fast8_t{ 0b1 << Bit::RXCIE }; ///< RXCIE.
        };

        /**
         * \brief enum class field offset.
         */
        struct Offset {
            static constexpr auto UCSZ = std::uint_fast8_t{ 1 }; ///< UCSZ.
        };

        /**
         * \brief Interrupt masks.
         */
        struct Interrupt {
            static constexpr auto RECEIVE_COMPLETE  = Mask::RXCIE; ///< Receive complete.
            static constexpr auto TRANSMIT_COMPLETE = Mask::TXCIE; ///< Transmit complete.
            static constexpr auto DATA_REGISTER_EMPTY = Mask::UDRIE; ///< Data register
                                                                     ///< empty.

            static constexpr auto ALL = std::uint8_t{ RECEIVE_COMPLETE | TRANSMIT_COMPLETE
                                                      | DATA_REGISTER_EMPTY }; ///< All.
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

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Configure the USART for use as an asynchronous or synchronous USART.
         *
         * \param[in] data_bits The desired number of data bits.
         */
        void configure( Data_Bits data_bits ) noexcept;

        /**
         * \brief Configure the USART for use as an SPI master.
         */
        void configure() noexcept
        {
            *this = Mask::RXEN | Mask::TXEN;
        }

        /**
         * \brief Enable the receiver.
         */
        void enable_receiver() noexcept
        {
            *this |= Mask::RXEN;
        }

        /**
         * \brief Enable the transmitter.
         */
        void enable_transmitter() noexcept
        {
            *this |= Mask::TXEN;
        }

        /**
         * \brief Enable the receiver and transmitter.
         */
        void enable() noexcept
        {
            *this |= Mask::RXEN | Mask::TXEN;
        }

        /**
         * \brief Disable the receiver.
         */
        void disable_receiver() noexcept
        {
            *this &= ~Mask::RXEN;
        }

        /**
         * \brief Disable the transmitter.
         */
        void disable_transmitter() noexcept
        {
            *this &= ~Mask::TXEN;
        }

        /**
         * \brief Disable the receiver and transmitter.
         */
        void disable() noexcept
        {
            *this &= ~( Mask::RXEN | Mask::TXEN );
        }

        /**
         * \brief Enable interrupts.
         *
         * \param[in] interrupts The mask identifying the interrupts to enable.
         */
        void enable_interrupts( std::uint8_t interrupts ) noexcept
        {
            *this |= interrupts;
        }

        /**
         * \brief Disable interrupts.
         *
         * \param[in] interrupts The mask identifying the interrupts to disable.
         */
        void disable_interrupts( std::uint8_t interrupts = Interrupt::ALL )
        {
            *this &= ~interrupts;
        }

        /**
         * \brief Extract bit 8 of 9-bit received data.
         *
         * \return 0x0100 if bit 8 of the 9-bit received data is set.
         * \return 0x0000 if bit 8 of the 9-bit received data is not set.
         */
        auto receive() const noexcept -> std::uint16_t
        {
            return *this & Mask::RXB8 ? 0x0100 : 0x0000;
        }

        /**
         * \brief Load bit 8 of 9-bit data for transmission.
         *
         * \param[in] data The data being transmitted.
         */
        void transmit( std::uint16_t data ) noexcept
        {
            *this = ( *this & ~Mask::TXB8 ) | ( data & 0x0100 ? Mask::TXB8 : 0 );
        }
    };

    /**
     * \brief USART Control and Status Register C (UCSRC).
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

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto UCPOL = std::uint_fast8_t{}; ///< UCPOL.
            static constexpr auto UCSZ = std::uint_fast8_t{ UCPOL + Size::UCPOL }; ///< UCSZ.
            static constexpr auto USBS = std::uint_fast8_t{ UCSZ + Size::UCSZ }; ///< USBS.
            static constexpr auto UPM  = std::uint_fast8_t{ USBS + Size::USBS }; ///< UPM.
            static constexpr auto UMSEL = std::uint_fast8_t{ UPM + Size::UPM }; ///< UMSEL.

            static constexpr auto UCPHA = std::uint_fast8_t{ UCPOL + Size::UCPOL }; ///< UCPHA.
            static constexpr auto UDORD = std::uint_fast8_t{ UCPHA + Size::UCPHA }; ///< UDORD.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto UCPOL = std::uint_fast8_t{ 0b1 << Bit::UCPOL }; ///< UCPOL.
            static constexpr auto UCSZ = std::uint_fast8_t{ 0b11 << Bit::UCSZ }; ///< UCSZ.
            static constexpr auto USBS = std::uint_fast8_t{ 0b1 << Bit::USBS }; ///< USBS.
            static constexpr auto UPM  = std::uint_fast8_t{ 0b11 << Bit::UPM }; ///< UPM.
            static constexpr auto UMSEL = std::uint_fast8_t{ 0b11 << Bit::UMSEL }; ///< UMSEL.

            static constexpr auto UCPHA = std::uint_fast8_t{ 0b1 << Bit::UCPHA }; ///< UCPHA.
            static constexpr auto UDORD = std::uint_fast8_t{ 0b1 << Bit::UDORD }; ///< UDORD.
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

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Configure the USART for use as an asynchronous USART.
         *
         * \param[in] data_bits The desired number of data bits.
         * \param[in] parity The desired parity mode.
         * \param[in] stop_bits The desired number of stop bits.
         */
        void configure( Data_Bits data_bits, Parity parity, Stop_Bits stop_bits ) noexcept;

        /**
         * \brief Configure the USART for use as a synchronous USART.
         *
         * \param[in] data_bits The desired number of data bits.
         * \param[in] parity The desired parity mode.
         * \param[in] stop_bits The desired number of stop bits.
         * \param[in] clock_polarity The desired clock polarity.
         */
        void configure( Data_Bits data_bits, Parity parity, Stop_Bits stop_bits, Clock_Polarity clock_polarity ) noexcept;

        /**
         * \brief Configure the USART for use as an SPI master.
         */
        void configure() noexcept;

        /**
         * \brief Configure SPI data exchange.
         *
         * \param[in] clock_polarity The desired clock polarity.
         * \param[in] clock_phase The desired clock phase.
         * \param[in] bit_order The desired data exchange bit order.
         */
        void configure( Clock_Polarity clock_polarity, Clock_Phase clock_phase, Bit_Order bit_order ) noexcept;
    };

    /**
     * \brief Interrupt masks.
     */
    struct Interrupt {
        static constexpr auto RECEIVE_COMPLETE = UCSRB::Interrupt::RECEIVE_COMPLETE; ///< Receive complete.
        static constexpr auto TRANSMIT_COMPLETE = UCSRB::Interrupt::TRANSMIT_COMPLETE; ///< Transmit complete.
        static constexpr auto DATA_REGISTER_EMPTY = UCSRB::Interrupt::DATA_REGISTER_EMPTY; ///< Data register empty.

        static constexpr auto ALL = UCSRB::Interrupt::ALL; ///< All.
    };

    /**
     * \brief USART mode.
     */
    enum class Mode : std::uint8_t {
        ASYNCHRONOUS_USART = 0b00 << UCSRC::Bit::UMSEL, ///< Asynchronous USART.
        SYNCHRONOUS_USART  = 0b01 << UCSRC::Bit::UMSEL, ///< Synchronous USART.
        SPI_MASTER         = 0b11 << UCSRC::Bit::UMSEL, ///< SPI master.
    };

    /**
     * \brief Clock generator operating speed.
     */
    enum class Operating_Speed : std::uint8_t {
        NORMAL = 0b0 << UCSRA::Bit::U2X, ///< Normal.
        DOUBLE = 0b1 << UCSRA::Bit::U2X, ///< Double.
    };

    /**
     * \brief Data bits.
     */
    enum class Data_Bits : std::uint8_t {
        _5 = ( 0b0 << ( UCSRB::Bit::UCSZ + UCSRB::Offset::UCSZ ) ) | ( 0b00 << UCSRC::Bit::UCSZ ), ///< 5.
        _6 = ( 0b0 << ( UCSRB::Bit::UCSZ + UCSRB::Offset::UCSZ ) ) | ( 0b01 << UCSRC::Bit::UCSZ ), ///< 6.
        _7 = ( 0b0 << ( UCSRB::Bit::UCSZ + UCSRB::Offset::UCSZ ) ) | ( 0b10 << UCSRC::Bit::UCSZ ), ///< 7.
        _8 = ( 0b0 << ( UCSRB::Bit::UCSZ + UCSRB::Offset::UCSZ ) ) | ( 0b11 << UCSRC::Bit::UCSZ ), ///< 8.
        _9 = ( 0b1 << ( UCSRB::Bit::UCSZ + UCSRB::Offset::UCSZ ) ) | ( 0b11 << UCSRC::Bit::UCSZ ), ///< 9.
    };

    /**
     * \brief Parity mode.
     */
    enum class Parity : std::uint8_t {
        NONE = 0b00 << UCSRC::Bit::UPM, ///< None.
        EVEN = 0b10 << UCSRC::Bit::UPM, ///< Even.
        ODD  = 0b11 << UCSRC::Bit::UPM, ///< Odd.
    };

    /**
     * \brief Stop bits.
     */
    enum class Stop_Bits : std::uint8_t {
        _1 = 0b0 << UCSRC::Bit::USBS, ///< 1.
        _2 = 0b1 << UCSRC::Bit::USBS, ///< 2.
    };

    /**
     * \brief Clock polarity.
     */
    enum class Clock_Polarity : std::uint8_t {
        IDLE_LOW  = 0b0 << UCSRC::Bit::UCPOL, ///< Idle low.
        IDLE_HIGH = 0b1 << UCSRC::Bit::UCPOL, ///< Idle high.
    };

    /**
     * \brief Clock phase.
     */
    enum class Clock_Phase : std::uint8_t {
        CAPTURE_IDLE_TO_ACTIVE = 0b0 << UCSRC::Bit::UCPHA, ///< Capture data on the
                                                           ///< idle-to-active clock
                                                           ///< transition.
        CAPTURE_ACTIVE_TO_IDLE = 0b1 << UCSRC::Bit::UCPHA, ///< Capture data on the
                                                           ///< active-to-idle clock
                                                           ///< transition.
    };

    /**
     * \brief Data exchange bit order.
     */
    enum class Bit_Order : std::uint8_t {
        MSB_FIRST = 0b0 << UCSRC::Bit::UDORD, ///< Exchange data MSB first.
        LSB_FIRST = 0b1 << UCSRC::Bit::UDORD, ///< Exchange data LSB first.
    };

    /**
     * \brief Multi-processor communication mode frame type.
     */
    enum class Frame_Type : std::uint8_t {
        DATA    = 0b0 << UCSRA::Bit::MPCM, ///< Data.
        ADDRESS = 0b1 << UCSRA::Bit::MPCM, ///< Address.
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

    /**
     * \brief Configure the USART for use as an asynchronous USART.
     *
     * \param[in] data_bits The desired number of data bits.
     * \param[in] parity The desired parity mode.
     * \param[in] stop_bits The desired number of stop bits.
     * \param[in] operating_speed The desired clock generator operating speed.
     * \param[in] scaling_factor The desired clock generator scaling factor.
     */
    void configure( Data_Bits data_bits, Parity parity, Stop_Bits stop_bits, Operating_Speed operating_speed, std::uint16_t scaling_factor ) noexcept
    {
        ucsrc.configure( data_bits, parity, stop_bits );
        ucsrb.configure( data_bits );
        ucsra.configure( operating_speed );

        ubrr = scaling_factor;
    }

    /**
     * \brief Configure the USART for use as a synchronous USART.
     *
     * \param[in] data_bits The desired number of data bits.
     * \param[in] parity The desired parity mode.
     * \param[in] stop_bits The desired number of stop bits.
     * \param[in] clock_polarity The desired clock polarity.
     * \param[in] scaling_factor The desired clock generator scaling factor.
     */
    void configure( Data_Bits data_bits, Parity parity, Stop_Bits stop_bits, Clock_Polarity clock_polarity, std::uint16_t scaling_factor ) noexcept
    {
        ucsrc.configure( data_bits, parity, stop_bits, clock_polarity );
        ucsrb.configure( data_bits );
        ucsra.configure();

        ubrr = scaling_factor;
    }

    /**
     * \brief Configure the USART for use as an SPI master.
     */
    void configure() noexcept
    {
        ubrr = 0;

        ucsrc.configure();
        ucsrb.configure();
        ucsra.configure();
    }

    /**
     * \brief Configure SPI data exchange.
     *
     * \param[in] clock_polarity The desired clock polarity.
     * \param[in] clock_phase The desired clock phase.
     * \param[in] bit_order The desired data exchange bit order.
     * \param[in] scaling_factor The desired clock generator scaling factor.
     */
    void configure( Clock_Polarity clock_polarity, Clock_Phase clock_phase, Bit_Order bit_order, std::uint16_t scaling_factor ) noexcept
    {
        ucsrc.configure( clock_polarity, clock_phase, bit_order );

        ubrr = scaling_factor;
    }

    /**
     * \brief Enable the receiver.
     */
    void enable_receiver() noexcept
    {
        ucsrb.enable_receiver();
    }

    /**
     * \brief Enable the transmitter.
     */
    void enable_transmitter() noexcept
    {
        ucsrb.enable_transmitter();
    }

    /**
     * \brief Enable the receiver and transmitter.
     */
    void enable() noexcept
    {
        ucsrb.enable();
    }

    /**
     * \brief Disable the receiver.
     */
    void disable_receiver() noexcept
    {
        ucsrb.disable_receiver();
    }

    /**
     * \brief Disable the transmitter.
     */
    void disable_transmitter() noexcept
    {
        ucsrb.disable_transmitter();
    }

    /**
     * \brief Disable the receiver and transmitter.
     */
    void disable() noexcept
    {
        ucsrb.disable();
    }

    /**
     * \brief Enable interrupts.
     *
     * \param[in] interrupts The mask identifying the interrupts to enable.
     */
    void enable_interrupts( std::uint8_t interrupts ) noexcept
    {
        ucsrb.enable_interrupts( interrupts );
    }

    /**
     * \brief Disable interrupts.
     *
     * \param[in] interrupts The mask identifying the interrupts to disable.
     */
    void disable_interrupts( std::uint8_t interrupts = Interrupt::ALL )
    {
        ucsrb.disable_interrupts( interrupts );
    }

    /**
     * \brief Set the multi-processor communication mode frame type of the next incoming
     *        frame.
     *
     * \param[in] frame_type The frame type of the next incoming frame.
     */
    void set_incoming_frame_type( Frame_Type frame_type ) noexcept
    {
        ucsra.set_incoming_frame_type( frame_type );
    }

    /**
     * \brief Check if data is available in the receive buffer.
     *
     * \return true if data is available in the receive buffer.
     * \return false if no data is available in the receive buffer.
     */
    auto data_available() const noexcept
    {
        return ucsra.data_available();
    }

    /**
     * \brief Check if a framing error or parity error occurred during reception of the
     *        next data in the receive buffer, or the receive buffer has experienced a
     *        data overrun.
     *
     * \return true if a framing error or parity error occurred during reception of the
     *         next data in the receive buffer, or the receive buffer has experienced a
     *         data overrun.
     * \return false if neither a framing error nor a parity error occurred during
     *         reception of the next data in the receive buffer, and the receive buffer
     *         has not experienced a data overrun.
     */
    auto error() const noexcept
    {
        return ucsra.error();
    }

    /**
     * \brief Check if a framing error occurred during reception of the next data in the
     *        receive buffer.
     *
     * \return true if a framing error occurred during reception of the next data in the
     *         receive buffer.
     * \return false if a framing error did not occur during reception of the next data in
     *         the receive buffer.
     */
    auto framing_error() const noexcept
    {
        return ucsra.framing_error();
    }

    /**
     * \brief Check if a parity error occurred during reception of the next data in the
     *        receive buffer.
     *
     * \return true if a parity error occurred during reception of the next data in the
     *         receive buffer.
     * \return false if a parity error did not occur during reception of the next data in
     *         the receive buffer.
     */
    auto parity_error() const noexcept
    {
        return ucsra.parity_error();
    }

    /**
     * \brief Check if the receive buffer has experienced a data overrun.
     *
     * \return true if the receive buffer has experienced a data overrun.
     * \return false if the receive buffer has not experienced a data overrun.
     */
    auto overrun_error() const noexcept
    {
        return ucsra.overrun_error();
    }

    /**
     * \brief Read data from the receive buffer.
     *
     * \tparam T The type of data to read from the receive buffer.
     *
     * \return The data read from the receive buffer.
     */
    template<typename T>
    auto receive() noexcept
    {
        return receive( T{} );
    }

    /**
     * \brief Check if the transmit buffer is empty.
     *
     * \return true if the transmit buffer is empty.
     * \return false if the transmit buffer is not empty.
     */
    auto transmit_buffer_empty() const noexcept
    {
        ucsra.transmit_buffer_empty();
    }

    /**
     * \brief Check if transmission is complete
     *
     * \return true if transmission is complete.
     * \return false if transmission is not complete.
     */
    auto transmission_complete() const noexcept
    {
        return ucsra.transmission_complete();
    }

    /**
     * \brief Clear the transmission complete flag.
     */
    void clear_transmission_complete() noexcept
    {
        ucsra.clear_transmission_complete();
    }

    /**
     * \brief Write data to the transmit buffer.
     *
     * \param[in] data The data to write to the transmit buffer.
     */
    void transmit( std::uint8_t data ) noexcept
    {
        udr = data;
    }

    /**
     * \brief Write data to the transmit buffer.
     *
     * \param[in] data The data to write to the transmit buffer.
     */
    void transmit( std::uint16_t data ) noexcept
    {
        ucsrb.transmit( data );
        udr = data;
    }

  private:
    /**
     * \brief Read data from the receive buffer.
     *
     * \return The data read from the receive buffer.
     */
    auto receive( std::uint8_t ) noexcept -> std::uint8_t
    {
        return udr;
    }

    /**
     * \brief Read data from the receive buffer.
     *
     * \return The data read from the receive buffer.
     */
    auto receive( std::uint16_t ) noexcept -> std::uint16_t
    {
        return ucsrb.receive() | udr;
    }
};

inline void USART::UCSRA::configure( Operating_Speed operating_speed ) noexcept
{
    *this = static_cast<std::uint8_t>( operating_speed );
}

inline void USART::UCSRA::set_incoming_frame_type( Frame_Type frame_type ) noexcept
{
    *this = ( *this & ~( Mask::FE | Mask::DOR | Mask::UPE | Mask::MPCM ) )
            | static_cast<std::uint8_t>( frame_type );
}

inline void USART::UCSRB::configure( Data_Bits data_bits ) noexcept
{
    *this = ( static_cast<std::uint8_t>( data_bits ) >> Offset::UCSZ ) & Mask::UCSZ;
}

inline void USART::UCSRC::configure( Data_Bits data_bits, Parity parity, Stop_Bits stop_bits ) noexcept
{
    *this = static_cast<std::uint8_t>( Mode::ASYNCHRONOUS_USART )
            | static_cast<std::uint8_t>( data_bits ) | static_cast<std::uint8_t>( parity )
            | static_cast<std::uint8_t>( stop_bits );
}

inline void USART::UCSRC::configure( Data_Bits data_bits, Parity parity, Stop_Bits stop_bits, Clock_Polarity clock_polarity ) noexcept
{
    *this = static_cast<std::uint8_t>( Mode::SYNCHRONOUS_USART )
            | static_cast<std::uint8_t>( data_bits ) | static_cast<std::uint8_t>( parity )
            | static_cast<std::uint8_t>( stop_bits ) | static_cast<std::uint8_t>( clock_polarity );
}

inline void USART::UCSRC::configure() noexcept
{
    *this = static_cast<std::uint8_t>( Mode::SPI_MASTER );
}

inline void USART::UCSRC::configure( Clock_Polarity clock_polarity, Clock_Phase clock_phase, Bit_Order bit_order ) noexcept
{
    *this = static_cast<std::uint8_t>( Mode::SPI_MASTER ) | static_cast<std::uint8_t>( clock_polarity )
            | static_cast<std::uint8_t>( clock_phase ) | static_cast<std::uint8_t>( bit_order );
}

} // namespace picolibrary::Microchip::AVR::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_USART_H
