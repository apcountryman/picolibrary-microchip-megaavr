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
 * \brief picolibrary::Microchip::megaAVR::SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_H

#include <cstdint>

#include "picolibrary/microchip/megaavr/gpio.h"
#include "picolibrary/microchip/megaavr/peripheral/spi.h"
#include "picolibrary/result.h"
#include "picolibrary/spi.h"
#include "picolibrary/utility.h"

/**
 * \brief Microchip megaAVR Serial Peripheral Interface (SPI) facilities.
 */
namespace picolibrary::Microchip::megaAVR::SPI {

/**
 * \brief SPI basic controller.
 *
 * \tparam Peripheral The type of peripheral used to implement SPI basic controller
 *         functionality.
 */
template<typename Peripheral>
class Basic_Controller;

/**
 * \brief SPI controller.
 *
 * \tparam Peripheral The type of peripheral used to implement SPI controller
 *         functionality.
 */
template<typename Peripheral>
using Controller = ::picolibrary::SPI::Controller<Basic_Controller<Peripheral>>;

/**
 * \brief SPI peripheral based SPI basic controller.
 */
template<>
class Basic_Controller<Peripheral::SPI> {
  public:
    /**
     * \brief Clock configuration (frequency, polarity, and phase), and data exchange
     *        bit order.
     */
    struct Configuration {
        /**
         * \brief Clock rate.
         */
        Peripheral::SPI::Clock_Rate clock_rate;

        /**
         * \brief Clock polarity.
         */
        Peripheral::SPI::Clock_Polarity clock_polarity;

        /**
         * \brief Clock phase.
         */
        Peripheral::SPI::Clock_Phase clock_phase;

        /**
         * \brief Data exchange bit order.
         */
        Peripheral::SPI::Bit_Order bit_order;
    };

    /**
     * \brief Constructor.
     */
    constexpr Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] sck The SCK pin.
     * \param[in] mosi The MOSI pin.
     * \param[in] spi The SPI peripheral used by the SPI controller.
     */
    Basic_Controller( GPIO::Push_Pull_IO_Pin sck, GPIO::Push_Pull_IO_Pin mosi, Peripheral::SPI & spi ) noexcept :
        m_sck{ std::move( sck ) },
        m_mosi{ std::move( mosi ) },
        m_spi{ &spi }
    {
        m_spi->configure_controller();
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Basic_Controller( Basic_Controller && source ) noexcept :
        m_sck{ std::move( source.m_sck ) },
        m_mosi{ std::move( source.m_mosi ) },
        m_spi{ source.m_spi }
    {
        source.m_spi = nullptr;
    }

    Basic_Controller( Basic_Controller const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Basic_Controller() noexcept
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
    auto & operator=( Basic_Controller && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_sck  = std::move( expression.m_sck );
            m_mosi = std::move( expression.m_mosi );
            m_spi  = expression.m_spi;

            expression.m_spi = nullptr;
        } // if

        return *this;
    }

    auto operator=( Basic_Controller const & ) = delete;

    /**
     * \brief Initialize the controller's hardware.
     *
     * \return Success.
     */
    auto initialize() noexcept -> Result<Void, Void>
    {
        static_cast<void>( m_sck.initialize() );
        static_cast<void>( m_mosi.initialize() );

        m_spi->configure_controller();
        m_spi->enable();

        return {};
    }

    /**
     * \brief Configure the controller's clock and data exchange bit order to meet a
     *        specific device's communication requirements.
     *
     * \param[in] configuration The clock and data exchange bit order configuration that
     *            meets the device's communication requirements.
     *
     * \return Success.
     */
    auto configure( Configuration const & configuration ) noexcept -> Result<Void, Void>
    {
        m_spi->configure(
            configuration.clock_rate,
            configuration.clock_polarity,
            configuration.clock_phase,
            configuration.bit_order );

        return {};
    }

    /**
     * \brief Exchange data with a device.
     *
     * \param[in] data The data to transmit.
     *
     * \return The received data.
     */
    auto exchange( std::uint8_t data ) noexcept -> Result<std::uint8_t, Void>
    {
        m_spi->transmit( data );

        while ( not m_spi->exchange_complete() ) {}

        return m_spi->receive();
    }

  private:
    /**
     * \brief The SCK pin.
     */
    GPIO::Push_Pull_IO_Pin m_sck{};

    /**
     * \brief The MOSI pin.
     */
    GPIO::Push_Pull_IO_Pin m_mosi{};

    /**
     * \brief The SPI peripheral used by the SPI controller.
     */
    Peripheral::SPI * m_spi{};

    /**
     * \brief Disable the SPI.
     */
    void disable() noexcept
    {
        if ( m_spi ) {
            m_spi->disable();
        } // if
    }
};

} // namespace picolibrary::Microchip::megaAVR::SPI

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_H
