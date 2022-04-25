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
 * \brief picolibrary::Microchip::megaAVR::Asynchronous_Serial interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_H

#include <cstdint>
#include <type_traits>

#include "picolibrary/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr/peripheral/usart.h"
#include "picolibrary/utility.h"

/**
 * \brief Microchip megaAVR asynchronous serial facilities.
 */
namespace picolibrary::Microchip::megaAVR::Asynchronous_Serial {

/**
 * \brief USART data bits configuration UCSRB register UCSZ field offset.
 */
constexpr auto USART_DATA_BITS_UCSRB_UCSZ_OFFSET = std::uint_fast8_t{ 1 };

/**
 * \brief USART data bits configuration.
 */
enum class USART_Data_Bits : std::uint_fast8_t {
    _5 = ( Peripheral::USART::Normal::UCSRB::UCSZ_5_BIT << USART_DATA_BITS_UCSRB_UCSZ_OFFSET )
         | Peripheral::USART::Normal::UCSRC::UCSZ_5_BIT, ///< 5.
    _6 = ( Peripheral::USART::Normal::UCSRB::UCSZ_6_BIT << USART_DATA_BITS_UCSRB_UCSZ_OFFSET )
         | Peripheral::USART::Normal::UCSRC::UCSZ_6_BIT, ///< 6.
    _7 = ( Peripheral::USART::Normal::UCSRB::UCSZ_7_BIT << USART_DATA_BITS_UCSRB_UCSZ_OFFSET )
         | Peripheral::USART::Normal::UCSRC::UCSZ_7_BIT, ///< 7.
    _8 = ( Peripheral::USART::Normal::UCSRB::UCSZ_8_BIT << USART_DATA_BITS_UCSRB_UCSZ_OFFSET )
         | Peripheral::USART::Normal::UCSRC::UCSZ_8_BIT, ///< 8.
    _9 = ( Peripheral::USART::Normal::UCSRB::UCSZ_9_BIT << USART_DATA_BITS_UCSRB_UCSZ_OFFSET )
         | Peripheral::USART::Normal::UCSRC::UCSZ_9_BIT, ///< 9.
};

/**
 * \brief USART parity configuration.
 */
enum class USART_Parity : std::uint8_t {
    NONE = Peripheral::USART::Normal::UCSRC::UPM_DISABLED,            ///< None.
    EVEN = Peripheral::USART::Normal::UCSRC::UPM_ENABLED_EVEN_PARITY, ///< Even.
    ODD  = Peripheral::USART::Normal::UCSRC::UPM_ENABLED_ODD_PARITY,  ///< Odd.
};

/**
 * \brief USART stop bits.
 */
enum class USART_Stop_Bits : std::uint8_t {
    _1 = Peripheral::USART::Normal::UCSRC::USBS_1_BIT, ///< 1.
    _2 = Peripheral::USART::Normal::UCSRC::USBS_2_BIT, ///< 2.
};

/**
 * \brief USART clock generator operating speed.
 */
enum class USART_Clock_Generator_Operating_Speed : std::uint8_t {
    NORMAL = 0b0 << Peripheral::USART::Normal::UCSRA::Bit::U2X, ///< Normal.
    DOUBLE = 0b1 << Peripheral::USART::Normal::UCSRA::Bit::U2X, ///< Double.
};

/**
 * \brief Basic transmitter.
 *
 * \tparam Data_Type The integral type used to hold the data to be transmitted (must be
 *         std::uint8_t or std::uint16_t).
 */
template<typename Data_Type>
class Basic_Transmitter {
  public:
    static_assert( std::is_same_v<Data_Type, std::uint8_t> or std::is_same_v<Data_Type, std::uint16_t> );

    /**
     * \brief The integral type used to hold the data to be transmitted.
     */
    using Data = Data_Type;

    /**
     * \brief Constructor.
     */
    constexpr Basic_Transmitter() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] usart The USART to be used by the transmitter.
     * \param[in] usart_data_bits The desired USART data bits configuration.
     * \param[in] usart_parity The desired USART parity configuration.
     * \param[in] usart_stop_bits The desired USART stop bits configuration.
     * \param[in] usart_clock_generator_operating_speed The desired USART clock generator
     *            operating speed.
     * \param[in] usart_clock_generator_scaling_factor The desired USART clock generator
     *            scaling factor (UBRR register value).
     */
    Basic_Transmitter(
        Peripheral::USART &                   usart,
        USART_Data_Bits                       usart_data_bits,
        USART_Parity                          usart_parity,
        USART_Stop_Bits                       usart_stop_bits,
        USART_Clock_Generator_Operating_Speed usart_clock_generator_operating_speed,
        std::uint16_t usart_clock_generator_scaling_factor ) noexcept :
        m_usart{ &usart }
    {
        configure_transmitter(
            usart_data_bits, usart_parity, usart_stop_bits, usart_clock_generator_operating_speed, usart_clock_generator_scaling_factor );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Basic_Transmitter( Basic_Transmitter && source ) noexcept :
        m_usart{ source.m_usart }
    {
        source.m_usart = nullptr;
    }

    Basic_Transmitter( Basic_Transmitter const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Basic_Transmitter() noexcept
    {
        disable();
    }

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto & operator=( Basic_Transmitter && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_usart = expression.m_usart;

            expression.m_usart = nullptr;
        } // if

        return *this;
    }

    auto operator=( Basic_Transmitter const & ) = delete;

    /**
     * \brief Initialize the transmitter's hardware.
     */
    void initialize() noexcept
    {
        enable_transmitter();
    }

    /**
     * \brief Transmit data.
     *
     * \param[in] data The data to transmit.
     */
    void transmit( Data data ) noexcept
    {
        while ( not transmit_buffer_is_empty() ) {} // while

        load_transmit_buffer( data );
    }

  private:
    /**
     * \brief The USART used by the transmitter.
     */
    Peripheral::USART * m_usart{};

    /**
     * \brief Disable the transmitter.
     */
    constexpr void disable() noexcept
    {
        if ( m_usart ) {
            disable_transmitter();
        } // if
    }

    /**
     * \brief Configure the transmitter.
     *
     * \param[in] usart_data_bits The desired USART data bits configuration.
     * \param[in] usart_parity The desired USART parity configuration.
     * \param[in] usart_stop_bits The desired USART stop bits configuration.
     * \param[in] usart_clock_generator_operating_speed The desired USART clock generator
     *            operating speed.
     * \param[in] usart_clock_generator_scaling_factor The desired USART clock generator
     *            scaling factor (UBRR register value).
     */
    void configure_transmitter(
        USART_Data_Bits                       usart_data_bits,
        USART_Parity                          usart_parity,
        USART_Stop_Bits                       usart_stop_bits,
        USART_Clock_Generator_Operating_Speed usart_clock_generator_operating_speed,
        std::uint16_t usart_clock_generator_scaling_factor ) noexcept
    {
        m_usart->normal.ucsrb = ( to_underlying( usart_data_bits ) >> USART_DATA_BITS_UCSRB_UCSZ_OFFSET )
                                & Peripheral::USART::Normal::UCSRB::Mask::UCSZ;
        m_usart->normal.ucsrc = Peripheral::USART::Normal::UCSRC::UMSEL_ASYNCHRONOUS_USART
                                | ( to_underlying( usart_data_bits )
                                    & Peripheral::USART::Normal::UCSRC::Mask::UCSZ )
                                | to_underlying( usart_parity ) | to_underlying( usart_stop_bits );
        m_usart->normal.ucsra = to_underlying( usart_clock_generator_operating_speed );
        m_usart->normal.ubrr  = usart_clock_generator_scaling_factor;
    }

    /**
     * \brief Disable the transmitter.
     */
    void disable_transmitter() noexcept
    {
        m_usart->normal.ucsrb &= ~Peripheral::USART::Normal::UCSRB::Mask::TXEN;
    }

    /**
     * \brief Enable the transmitter.
     */
    void enable_transmitter() noexcept
    {
        m_usart->normal.ucsrb |= Peripheral::USART::Normal::UCSRB::Mask::TXEN;
    }

    /**
     * \brief Check if the transmit buffer is empty.
     *
     * \return true if the transmit buffer is empty.
     * \return false if the transmit buffer is not empty.
     */
    auto transmit_buffer_is_empty() const noexcept -> bool
    {
        return m_usart->normal.ucsra & Peripheral::USART::Normal::UCSRA::Mask::UDRE;
    }

    /**
     * \brief Load data into the transmit buffer.
     *
     * \param[in] data The data to load into the transmit buffer.
     */
    void load_transmit_buffer( std::uint8_t data ) noexcept
    {
        m_usart->normal.udr = data;
    }

    /**
     * \brief Load data into the transmit buffer.
     *
     * \param[in] data The data to load into the transmit buffer.
     */
    void load_transmit_buffer( std::uint16_t data ) noexcept
    {
        m_usart->normal.ucsrb = ( m_usart->normal.ucsrb & Peripheral::USART::Normal::UCSRB::Mask::TXB8 )
                                | ( data & 0x0100 ? Peripheral::USART::Normal::UCSRB::Mask::TXB8 : 0 );
        m_usart->normal.udr = data;
    }
};

/**
 * \brief Transmitter.
 *
 * \tparam Data_Type The integral type used to hold the data to be transmitted (must be
 *         std::uint8_t or std::uint16_t).
 */
template<typename Data_Type>
using Transmitter = ::picolibrary::Asynchronous_Serial::Transmitter<Basic_Transmitter<Data_Type>>;

} // namespace picolibrary::Microchip::megaAVR::Asynchronous_Serial

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_ASYNCHRONOUS_SERIAL_H
