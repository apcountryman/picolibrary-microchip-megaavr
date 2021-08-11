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
 * \brief picolibrary::Microchip::megaAVR::Asynchronous_Serial interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_ASYNCHRONOUS_SERIAL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_ASYNCHRONOUS_SERIAL_H

#include <cstdint>

#include "picolibrary/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr/peripheral/usart.h"
#include "picolibrary/result.h"
#include "picolibrary/void.h"

/**
 * \brief Microchip megaAVR asynchronous serial facilities.
 */
namespace picolibrary::Microchip::megaAVR::Asynchronous_Serial {

/**
 * \brief Microchip megaAVR asynchronous serial clock configuration.
 */
struct Clock_Configuration {
    /**
     * \brief Clock generator operating speed.
     */
    using Operating_Speed = Peripheral::USART::Operating_Speed;

    /**
     * \brief The clock generator operating speed.
     */
    Operating_Speed operating_speed;

    /**
     * \brief The clock generator scaling factor.
     */
    std::uint16_t scaling_factor;
};

/**
 * \brief Microchip megaAVR asynchronous serial basic transmitter.
 *
 * \tparam Data_Type The integral type used to hold the data to be transmitted.
 */
template<typename Data_Type>
class Basic_Transmitter {
  public:
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
     * \param[in] data_bits The desired number of data bits.
     * \param[in] parity The desired parity mode.
     * \param[in] stop_bits The desired number of stop bits.
     * \param[in] clock_configuration The desired clock generator configuration.
     */
    Basic_Transmitter(
        Peripheral::USART &          usart,
        Peripheral::USART::Data_Bits data_bits,
        Peripheral::USART::Parity    parity,
        Peripheral::USART::Stop_Bits stop_bits,
        Clock_Configuration const &  clock_configuration ) noexcept :
        m_usart{ &usart }
    {
        m_usart->configure_as_asynchronous_serial_usart(
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
    auto & operator=( Basic_Transmitter && expression ) noexcept
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
        if ( m_usart ) {
            m_usart->disable_transmitter();
        } // if
    }
};

/**
 * \brief Microchip megaAVR asynchronous serial transmitter.
 *
 * \tparam Data_Type The integral type used to hold the data to be transmitted.
 */
template<typename Data_Type>
class Transmitter :
    public ::picolibrary::Asynchronous_Serial::Transmitter<Basic_Transmitter<Data_Type>> {
  public:
    using ::picolibrary::Asynchronous_Serial::Transmitter<Basic_Transmitter<Data_Type>>::Transmitter;
};

/**
 * \brief Microchip megaAVR asynchronous serial 8 data bits, no parity bit, 1 stop bit
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

    auto operator=( Transmitter_8_N_1 const & ) = delete;

    using Transmitter<std::uint8_t>::initialize;
    using Transmitter<std::uint8_t>::transmit;
};

} // namespace picolibrary::Microchip::megaAVR::Asynchronous_Serial

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_ASYNCHRONOUS_SERIAL_H
