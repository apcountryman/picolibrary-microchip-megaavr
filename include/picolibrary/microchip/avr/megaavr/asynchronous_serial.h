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
 * \brief picolibrary::Microchip::AVR::megaAVR::Asynchronous_Serial interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_ASYNCHRONOUS_SERIAL_H
#define PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_ASYNCHRONOUS_SERIAL_H

#include <cstdint>

#include "picolibrary/algorithm.h"
#include "picolibrary/microchip/avr/megaavr/peripheral/usart.h"
#include "picolibrary/result.h"
#include "picolibrary/utility.h"

/**
 * \brief Microchip AVR megaAVR asynchronous serial facilities.
 */
namespace picolibrary::Microchip::AVR::megaAVR::Asynchronous_Serial {

/**
 * \brief Microchip AVR megaAVR asynchronous serial clock configuration.
 */
struct Clock_Configuration {
    /**
     * \brief The clock generator operating speed.
     */
    Peripheral::USART::Operating_Speed operating_speed;

    /**
     * \brief The clock generator scaling factor.
     */
    std::uint16_t scaling_factor;
};

/**
 * \brief Microchip AVR megaAVR asynchronous serial transmitter.
 *
 * \tparam Data_Type The integral type used to hold the data to be transmitted.
 */
template<typename Data_Type>
class Transmitter {
  public:
    /**
     * \brief The integral type used to hold the data to be transmitted.
     */
    using Data = Data_Type;

    /**
     * \brief Constructor.
     */
    constexpr Transmitter() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] usart The USART to be used by the transmitter.
     * \param[in] data_bits The desired number of data bits.
     * \param[in] parity The desired parity mode.
     * \param[in] stop_bits The desired number of stop bits.
     * \param[in] clock_configuration The desired clock generator configuration.
     */
    Transmitter(
        Peripheral::USART &          usart,
        Peripheral::USART::Data_Bits data_bits,
        Peripheral::USART::Parity    parity,
        Peripheral::USART::Stop_Bits stop_bits,
        Clock_Configuration const &  clock_configuration ) noexcept :
        m_usart{ &usart }
    {
        m_usart->disable();

        m_usart->configure(
            data_bits,
            parity,
            stop_bits,
            clock_configuration.operating_speed,
            clock_configuration.scaling_factor );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Transmitter( Transmitter && source ) noexcept : m_usart{ source.m_usart }
    {
        source.m_usart = nullptr;
    }

    /**
     * \todo #27
     */
    Transmitter( Transmitter const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Transmitter() noexcept
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
    auto & operator=( Transmitter && expression ) noexcept
    {
        disable();

        m_usart = expression.m_usart;

        return *this;
    }

    /**
     * \todo #27
     *
     * \return
     */
    auto operator=( Transmitter const & ) = delete;

    /**
     * \brief Initialize the transmitter's hardware.
     *
     * \return Success.
     */
    auto initialize() noexcept -> Result<Void, Void>
    {
        m_usart->enable_transmitter();

        return {};
    }

    /**
     * \brief Transmit data.
     *
     * \param[in] data The data to transmit.
     *
     * \return Success.
     */
    auto transmit( Data data ) noexcept -> Result<Void, Void>
    {
        while ( not m_usart->transmit_buffer_empty() ) {}

        m_usart->transmit( data );

        return {};
    }

    /**
     * \brief Transmit a block of data.
     *
     * \param[in] begin The beginning of the block of data to transmit.
     * \param[in] end The end of the block of data to transmit.
     *
     * \return Success.
     */
    auto transmit( Data const * begin, Data const * end ) noexcept
    {
        return for_each<Discard_Functor>(
            begin, end, [this]( auto data ) noexcept { return transmit( data ); } );
    }

  private:
    /**
     * \brief The USART used by the transmitter.
     */
    Peripheral::USART * m_usart{};

    /**
     * \brief Disable the transmitter.
     */
    void disable() noexcept
    {
        if ( m_usart ) { m_usart->disable_transmitter(); }
    }
};

/**
 * \brief Microchip AVR megaAVR asynchronous serial 8 data bits, no parity bit, 1 stop bit
 *        (8-N-1) transmitter.
 */
class Transmitter_8_N_1 : private Transmitter<std::uint8_t> {
  public:
    using Transmitter<std::uint8_t>::Data;

    /**
     * \brief Constructor.
     */
    constexpr Transmitter_8_N_1() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] usart The USART to be used by the transmitter.
     * \param[in] clock_configuration The desired clock generator configuration.
     */
    Transmitter_8_N_1( Peripheral::USART & usart, Clock_Configuration const & clock_configuration ) noexcept :
        Transmitter<std::uint8_t>{ usart,
                                   Peripheral::USART::Data_Bits::_8,
                                   Peripheral::USART::Parity::NONE,
                                   Peripheral::USART::Stop_Bits::_1,
                                   clock_configuration }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Transmitter_8_N_1( Transmitter_8_N_1 && source ) noexcept = default;

    /**
     * \todo #27
     */
    Transmitter_8_N_1( Transmitter_8_N_1 const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Transmitter_8_N_1() noexcept = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    auto operator=( Transmitter_8_N_1 && expression ) noexcept -> Transmitter_8_N_1 & = default;

    /**
     * \todo #27
     *
     * \return
     */
    auto operator=( Transmitter_8_N_1 const & ) = delete;

    using Transmitter<std::uint8_t>::initialize;
    using Transmitter<std::uint8_t>::transmit;
};

} // namespace picolibrary::Microchip::AVR::megaAVR::Asynchronous_Serial

#endif // PICOLIBRARY_MICROCHIP_AVR_MEGAAVR_PERIPHERAL_ASYNCHRONOUS_SERIAL_H
