/**
 * picolibrary-microchip-megaavr
 *
 * Copyright 2020-2023, Andrew Countryman <apcountryman@gmail.com> and the
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
#include <utility>

#include "picolibrary/microchip/megaavr/gpio.h"
#include "picolibrary/microchip/megaavr/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr/peripheral/spi.h"
#include "picolibrary/microchip/megaavr/peripheral/usart.h"
#include "picolibrary/spi.h"
#include "picolibrary/utility.h"

/**
 * \brief Microchip megaAVR SPI facilities.
 */
namespace picolibrary::Microchip::megaAVR::SPI {

/**
 * \brief SPI clock rate SPCR register SPR field offset.
 */
constexpr auto SPI_CLOCK_RATE_SPCR_SPR_OFFSET = std::uint_fast8_t{ 1 };

/**
 * \brief SPI clock rate.
 */
enum class SPI_Clock_Rate : std::uint_fast8_t {
    FOSC_2 = ( 0b1 << Peripheral::SPI::SPSR::Bit::SPI2X )
             | ( 0b00 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/2
    FOSC_4 = ( 0b0 << Peripheral::SPI::SPSR::Bit::SPI2X )
             | ( 0b00 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/4
    FOSC_8 = ( 0b1 << Peripheral::SPI::SPSR::Bit::SPI2X )
             | ( 0b01 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/8
    FOSC_16 = ( 0b0 << Peripheral::SPI::SPSR::Bit::SPI2X )
              | ( 0b01 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/16
    FOSC_32 = ( 0b1 << Peripheral::SPI::SPSR::Bit::SPI2X )
              | ( 0b10 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/32
    FOSC_64 = ( 0b0 << Peripheral::SPI::SPSR::Bit::SPI2X )
              | ( 0b10 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/64
    FOSC_128 = ( 0b0 << Peripheral::SPI::SPSR::Bit::SPI2X )
               | ( 0b11 << ( Peripheral::SPI::SPCR::Bit::SPR + SPI_CLOCK_RATE_SPCR_SPR_OFFSET ) ), ///< fosc/128
};

/**
 * \brief SPI clock polarity.
 */
enum class SPI_Clock_Polarity : std::uint8_t {
    IDLE_LOW = Peripheral::SPI::SPCR::CPOL_LEADING_EDGE_RISING_TRAILING_EDGE_FALLING, ///< Idle low.
    IDLE_HIGH = Peripheral::SPI::SPCR::CPOL_LEADING_EDGE_FALLING_TRAILING_EDGE_RISING, ///< Idle high.
};

/**
 * \brief SPI clock phase.
 */
enum class SPI_Clock_Phase : std::uint8_t {
    CAPTURE_IDLE_TO_ACTIVE = Peripheral::SPI::SPCR::CPHA_LEADING_EDGE_SAMPLE_TRAILING_EDGE_SETUP, ///< Capture data on the idle-to-active clock transition.
    CAPTURE_ACTIVE_TO_IDLE = Peripheral::SPI::SPCR::CPHA_LEADING_EDGE_SETUP_TRAILING_EDGE_SAMPLE, ///< Capture data on the active-to-idle clock transition.
};

/**
 * \brief SPI bit order.
 */
enum class SPI_Bit_Order : std::uint8_t {
    MSB_FIRST = 0b0 << Peripheral::SPI::SPCR::Bit::DORD, ///< MSB first.
    LSB_FIRST = 0b1 << Peripheral::SPI::SPCR::Bit::DORD, ///< LSB first.
};

/**
 * \brief USART clock polarity.
 */
enum class USART_Clock_Polarity : std::uint8_t {
    IDLE_LOW  = 0b0 << Peripheral::USART::SPI_Host::UCSRC::Bit::UCPOL, ///< Idle low.
    IDLE_HIGH = 0b1 << Peripheral::USART::SPI_Host::UCSRC::Bit::UCPOL, ///< Idle high.
};

/**
 * \brief USART clock phase.
 */
enum class USART_Clock_Phase : std::uint8_t {
    CAPTURE_IDLE_TO_ACTIVE = 0b0 << Peripheral::USART::SPI_Host::UCSRC::Bit::UCPHA, ///< Capture data on the idle-to-active clock transition.
    CAPTURE_ACTIVE_TO_IDLE = 0b1 << Peripheral::USART::SPI_Host::UCSRC::Bit::UCPHA, ///< Capture data on the active-to-idle clock transition.
};

/**
 * \brief USART bit order.
 */
enum class USART_Bit_Order : std::uint8_t {
    MSB_FIRST = 0b0 << Peripheral::USART::SPI_Host::UCSRC::Bit::UDORD, ///< MSB first.
    LSB_FIRST = 0b1 << Peripheral::USART::SPI_Host::UCSRC::Bit::UDORD, ///< LSB first.
};

/**
 * \brief Fixed configuration basic controller.
 *
 * \tparam Peripheral The type of peripheral used to implement fixed configuration
 *         controller functionality.
 */
template<typename Peripheral>
class Fixed_Configuration_Basic_Controller;

/**
 * \brief Fixed configuration controller.
 *
 * \tparam Peripheral The type of peripheral used to implement fixed configuration
 *         controller functionality.
 */
template<typename Peripheral>
using Fixed_Configuration_Controller =
    ::picolibrary::SPI::Controller<Fixed_Configuration_Basic_Controller<Peripheral>>;

/**
 * \brief SPI peripheral based fixed configuration basic controller.
 */
template<>
class Fixed_Configuration_Basic_Controller<Peripheral::SPI> {
  public:
    /**
     * \brief Clock (frequency, polarity, and phase) and data exchange bit order
     *        configuration.
     */
    struct Configuration {
    };

    /**
     * \brief Constructor.
     */
    constexpr Fixed_Configuration_Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] spi The SPI to be used by the controller.
     * \param[in] spi_clock_rate The desired SPI clock rate.
     * \param[in] spi_clock_polarity The desired SPI clock polarity.
     * \param[in] spi_clock_phase The desired SPI clock phase.
     * \param[in] spi_bit_order The desired SPI bit order.
     */
    Fixed_Configuration_Basic_Controller(
        Peripheral::SPI &  spi,
        SPI_Clock_Rate     spi_clock_rate,
        SPI_Clock_Polarity spi_clock_polarity,
        SPI_Clock_Phase    spi_clock_phase,
        SPI_Bit_Order      spi_bit_order ) noexcept :
        m_spi{ &spi },
        m_spi_sck_mosi{ Multiplexed_Signals::spi_port( spi ),
                        static_cast<std::uint8_t>(
                            Multiplexed_Signals::sck_mask( spi ) | Multiplexed_Signals::mosi_mask( spi ) ) }
    {
        configure_controller( spi_clock_rate, spi_clock_polarity, spi_clock_phase, spi_bit_order );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Fixed_Configuration_Basic_Controller( Fixed_Configuration_Basic_Controller && source ) noexcept :
        m_spi{ source.m_spi },
        m_spi_sck_mosi{ std::move( source.m_spi_sck_mosi ) }
    {
        source.m_spi = nullptr;
    }

    Fixed_Configuration_Basic_Controller( Fixed_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Fixed_Configuration_Basic_Controller() noexcept
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
    constexpr auto operator=( Fixed_Configuration_Basic_Controller && expression ) noexcept
        -> Fixed_Configuration_Basic_Controller &
    {
        if ( &expression != this ) {
            disable();

            m_spi          = expression.m_spi;
            m_spi_sck_mosi = std::move( expression.m_spi_sck_mosi );

            expression.m_spi = nullptr;
        } // if

        return *this;
    }

    auto operator=( Fixed_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Initialize the controller's hardware.
     */
    void initialize() noexcept
    {
        m_spi_sck_mosi.initialize();

        enable_controller();
    }

    /**
     * \brief Configure the controller's clock and data exchange bit order to meet a
     *        specific device's communication requirements.
     *
     * \param[in] configuration The clock and data exchange bit order configuration that
     *            meets the device's communication requirements.
     */
    void configure( Configuration configuration ) noexcept
    {
        static_cast<void>( configuration );
    }

    /**
     * \brief Exchange data with a device.
     *
     * \param[in] data The data to transmit to the device.
     *
     * \return The data received from the device.
     */
    auto exchange( std::uint8_t data ) noexcept -> std::uint8_t
    {
        initiate_exchange( data );

        while ( not exchange_complete() ) {} // while

        return finish_exchange();
    }

  private:
    /**
     * \brief The SPI used by the controller.
     */
    Peripheral::SPI * m_spi{};

    /**
     * \brief The SPI's SCK and MOSI pins.
     */
    GPIO::Push_Pull_IO_Pin m_spi_sck_mosi{};

    /**
     * \brief Disable the controller.
     */
    constexpr void disable() noexcept
    {
        if ( m_spi ) {
            disable_controller();
        } // if
    }

    /**
     * \brief Configure the controller.
     *
     * \param[in] spi_clock_rate The desired SPI clock rate.
     * \param[in] spi_clock_polarity The desired SPI clock polarity.
     * \param[in] spi_clock_phase The desired SPI clock phase.
     * \param[in] spi_bit_order The desired SPI bit order.
     */
    void configure_controller(
        SPI_Clock_Rate     spi_clock_rate,
        SPI_Clock_Polarity spi_clock_polarity,
        SPI_Clock_Phase    spi_clock_phase,
        SPI_Bit_Order      spi_bit_order ) noexcept
    {
        m_spi->spcr = Peripheral::SPI::SPCR::Mask::MSTR
                      | ( to_underlying( spi_clock_rate ) >> SPI_CLOCK_RATE_SPCR_SPR_OFFSET )
                      | to_underlying( spi_clock_polarity )
                      | to_underlying( spi_clock_phase ) | to_underlying( spi_bit_order );
        m_spi->spsr = to_underlying( spi_clock_rate ) & Peripheral::SPI::SPSR::Mask::SPI2X;
    }

    /**
     * \brief Disable the controller.
     */
    void disable_controller() noexcept
    {
        m_spi->spcr = 0;
    }

    /**
     * \brief Enable the controller.
     */
    void enable_controller() noexcept
    {
        m_spi->spcr |= Peripheral::SPI::SPCR::Mask::SPE;
    }

    /**
     * \brief Initiate a data exchange.
     *
     * \param[in] data The data to transmit.
     */
    void initiate_exchange( std::uint8_t data ) noexcept
    {
        m_spi->spdr = data;
    }

    /**
     * \brief Check if a data exchange is complete.
     *
     * \return true if the data exchange is complete.
     * \return false if the data exchange is not complete.
     */
    auto exchange_complete() const noexcept -> bool
    {
        return m_spi->spsr & Peripheral::SPI::SPSR::Mask::SPIF;
    }

    /**
     * \brief Finish a data exchange.
     *
     * \return The received data.
     */
    auto finish_exchange() noexcept -> std::uint8_t
    {
        return m_spi->spdr;
    }
};

/**
 * \brief USART peripheral based fixed configuration basic controller.
 */
template<>
class Fixed_Configuration_Basic_Controller<Peripheral::USART> {
  public:
    /**
     * \brief Clock (frequency, polarity, and phase) and data exchange bit order
     *        configuration.
     */
    struct Configuration {
    };

    /**
     * \brief Constructor.
     */
    constexpr Fixed_Configuration_Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] usart The USART to be used by the controller.
     * \param[in] usart_clock_generator_scaling_factor The desired USART clock generator
     *            scaling factor (UBRR register value).
     * \param[in] usart_clock_polarity The desired USART clock polarity.
     * \param[in] usart_clock_phase The desired USART clock phase.
     * \param[in] usart_bit_order The desired USART bit order.
     */
    Fixed_Configuration_Basic_Controller(
        Peripheral::USART &  usart,
        std::uint16_t        usart_clock_generator_scaling_factor,
        USART_Clock_Polarity usart_clock_polarity,
        USART_Clock_Phase    usart_clock_phase,
        USART_Bit_Order      usart_bit_order ) noexcept :
        m_usart{ &usart },
        m_usart_xck{ Multiplexed_Signals::xck_port( usart ), Multiplexed_Signals::xck_mask( usart ) }
    {
        configure_controller(
            usart_clock_generator_scaling_factor, usart_clock_polarity, usart_clock_phase, usart_bit_order );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Fixed_Configuration_Basic_Controller( Fixed_Configuration_Basic_Controller && source ) noexcept :
        m_usart{ source.m_usart },
        m_usart_xck{ std::move( source.m_usart_xck ) }
    {
        source.m_usart = nullptr;
    }

    Fixed_Configuration_Basic_Controller( Fixed_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Fixed_Configuration_Basic_Controller() noexcept
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
    constexpr auto operator=( Fixed_Configuration_Basic_Controller && expression ) noexcept
        -> Fixed_Configuration_Basic_Controller &
    {
        if ( &expression != this ) {
            disable();

            m_usart     = expression.m_usart;
            m_usart_xck = std::move( expression.m_usart_xck );

            expression.m_usart = nullptr;
        } // if

        return *this;
    }

    auto operator=( Fixed_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Initialize the controller's hardware.
     */
    void initialize() noexcept
    {
        auto const usart_clock_generator_scaling_factor = clear_usart_clock_generator_scaling_factor();

        m_usart_xck.initialize();

        enable_controller();

        set_usart_clock_generator_scaling_factor( usart_clock_generator_scaling_factor );
    }

    /**
     * \brief Configure the controller's clock and data exchange bit order to meet a
     *        specific device's communication requirements.
     *
     * \param[in] configuration The clock and data exchange bit order configuration that
     *            meets the device's communication requirements.
     */
    void configure( Configuration configuration ) noexcept
    {
        static_cast<void>( configuration );
    }

    /**
     * \brief Exchange data with a device.
     *
     * \param[in] data The data to transmit to the device.
     *
     * \return The data received from the device.
     */
    auto exchange( std::uint8_t data ) noexcept -> std::uint8_t
    {
        while ( not transmit_buffer_is_empty() ) {} // while

        load_transmit_buffer( data );

        while ( not received_data_is_available() ) {} // while

        return read_receive_buffer();
    }

  private:
    /**
     * \brief The USART used by the controller.
     */
    Peripheral::USART * m_usart{};

    /**
     * \brief The USART's XCK pin.
     */
    GPIO::Push_Pull_IO_Pin m_usart_xck{};

    /**
     * \brief Disable the controller.
     */
    constexpr void disable() noexcept
    {
        if ( m_usart ) {
            disable_controller();
        } // if
    }

    /**
     * \brief Configure the controller.
     *
     * \param[in] usart_clock_generator_scaling_factor The desired USART clock generator
     *            scaling factor (UBRR register value).
     * \param[in] usart_clock_polarity The desired USART clock polarity.
     * \param[in] usart_clock_phase The desired USART clock phase.
     * \param[in] usart_bit_order The desired USART bit order.
     */
    void configure_controller(
        std::uint16_t        usart_clock_generator_scaling_factor,
        USART_Clock_Polarity usart_clock_polarity,
        USART_Clock_Phase    usart_clock_phase,
        USART_Bit_Order      usart_bit_order ) noexcept
    {
        m_usart->spi_host.ucsrb = 0;
        m_usart->spi_host.ucsrc = Peripheral::USART::SPI_Host::UCSRC::UMSEL_HOST_SPI
                                  | to_underlying( usart_clock_polarity )
                                  | to_underlying( usart_clock_phase )
                                  | to_underlying( usart_bit_order );
        m_usart->spi_host.ubrr = usart_clock_generator_scaling_factor;
    }

    /**
     * \brief Disable the controller.
     */
    void disable_controller() noexcept
    {
        m_usart->spi_host.ucsrb = 0;
    }

    /**
     * \brief Clear the USART's clock generator scaling factor (UBRR register value).
     *
     * \return The previous USART clock generator scaling factor (UBRR register value).
     */
    auto clear_usart_clock_generator_scaling_factor() noexcept -> std::uint16_t
    {
        auto const usart_clock_generator_scaling_factor = std::uint16_t{ m_usart->spi_host.ubrr };

        m_usart->spi_host.ubrr = 0;

        return usart_clock_generator_scaling_factor;
    }

    /**
     * \brief Enable the controller.
     */
    void enable_controller() noexcept
    {
        m_usart->spi_host.ucsrb = Peripheral::USART::SPI_Host::UCSRB::Mask::TXEN
                                  | Peripheral::USART::SPI_Host::UCSRB::Mask::RXEN;
    }

    /**
     * \brief Set the USART's clock generator scaling factor (UBRR register value).
     *
     * \param[in] usart_clock_generator_scaling_factor The desired USART clock generator
     *            scaling factor (UBRR register value).
     */
    void set_usart_clock_generator_scaling_factor( std::uint16_t usart_clock_generator_scaling_factor ) noexcept
    {
        m_usart->spi_host.ubrr = usart_clock_generator_scaling_factor;
    }

    /**
     * \brief Check if the transmit buffer is empty.
     *
     * \return true if the transmit buffer is empty.
     * \return false if the transmit buffer is not empty.
     */
    auto transmit_buffer_is_empty() const noexcept -> bool
    {
        return m_usart->spi_host.ucsra & Peripheral::USART::SPI_Host::UCSRA::Mask::UDRE;
    }

    /**
     * \brief Load data into the transmit buffer.
     *
     * \param[in] data The data to load into the transmit buffer.
     */
    void load_transmit_buffer( std::uint8_t data ) noexcept
    {
        m_usart->spi_host.udr = data;
    }

    /**
     * \brief Check if received data is available.
     *
     * \return true if received data is available.
     * \return false if received data is not available.
     */
    auto received_data_is_available() const noexcept -> bool
    {
        return m_usart->spi_host.ucsra & Peripheral::USART::SPI_Host::UCSRA::Mask::RXC;
    }

    /**
     * \brief Read data from the receive buffer.
     *
     * \return The data read from the receive buffer.
     */
    auto read_receive_buffer() noexcept -> std::uint8_t
    {
        return m_usart->spi_host.udr;
    }
};

/**
 * \brief Variable configuration basic controller.
 *
 * \tparam Peripheral The type of peripheral used to implement variable configuration
 *         controller functionality.
 */
template<typename Peripheral>
class Variable_Configuration_Basic_Controller;

/**
 * \brief Variable configuration controller.
 *
 * \tparam Peripheral The type of peripheral used to implement variable configuration
 *         controller functionality.
 */
template<typename Peripheral>
using Variable_Configuration_Controller =
    ::picolibrary::SPI::Controller<Variable_Configuration_Basic_Controller<Peripheral>>;

/**
 * \brief SPI peripheral based variable configuration basic controller.
 */
template<>
class Variable_Configuration_Basic_Controller<Peripheral::SPI> {
  public:
    /**
     * \brief Clock (frequency, polarity, and phase) and data exchange bit order
     *        configuration.
     */
    class Configuration {
      public:
        /**
         * \brief Constructor.
         */
        constexpr Configuration() noexcept :
            Configuration{ SPI_Clock_Rate::FOSC_2,
                           SPI_Clock_Polarity::IDLE_LOW,
                           SPI_Clock_Phase::CAPTURE_IDLE_TO_ACTIVE,
                           SPI_Bit_Order::MSB_FIRST }
        {
        }

        /**
         * \brief Constructor.
         *
         * \param[in] spi_clock_rate The desired SPI clock rate.
         * \param[in] spi_clock_polarity The desired SPI clock polarity.
         * \param[in] spi_clock_phase The desired SPI clock phase.
         * \param[in] spi_bit_order The desired SPI bit order.
         */
        constexpr Configuration(
            SPI_Clock_Rate     spi_clock_rate,
            SPI_Clock_Polarity spi_clock_polarity,
            SPI_Clock_Phase    spi_clock_phase,
            SPI_Bit_Order      spi_bit_order ) noexcept :
            m_spcr{ static_cast<std::uint8_t>(
                Peripheral::SPI::SPCR::Mask::SPE | Peripheral::SPI::SPCR::Mask::MSTR
                | ( to_underlying( spi_clock_rate ) >> SPI_CLOCK_RATE_SPCR_SPR_OFFSET )
                | to_underlying( spi_clock_polarity ) | to_underlying( spi_clock_phase )
                | to_underlying( spi_bit_order ) ) },
            m_spsr{ static_cast<std::uint8_t>(
                to_underlying( spi_clock_rate ) & Peripheral::SPI::SPSR::Mask::SPI2X ) }
        {
        }

        /**
         * \brief Constructor.
         *
         * \param[in] source The source of the move.
         */
        constexpr Configuration( Configuration && source ) noexcept = default;

        /**
         * \brief Constructor.
         *
         * \param[in] original The original to copy.
         */
        constexpr Configuration( Configuration const & original ) noexcept = default;

        /**
         * \brief Destructor.
         */
        ~Configuration() noexcept = default;

        /**
         * \brief Assignment operator.
         *
         * \param[in] expression The expression to be assigned.
         *
         * \return The assigned to object.
         */
        constexpr auto operator=( Configuration && expression ) noexcept -> Configuration & = default;

        /**
         * \brief Assignment operator.
         *
         * \param[in] expression The expression to be assigned.
         *
         * \return The assigned to object.
         */
        constexpr auto operator=( Configuration const & expression ) noexcept
            -> Configuration & = default;

        /**
         * \brief Get the configuration's SPCR register value.
         *
         * \return The configuration's SPCR register value.
         */
        constexpr auto spcr() const noexcept -> std::uint8_t
        {
            return m_spcr;
        }

        /**
         * \brief Get the configuration's SPSR register value.
         *
         * \return The configuration's SPSR register value.
         */
        constexpr auto spsr() const noexcept -> std::uint8_t
        {
            return m_spsr;
        }

      private:
        /**
         * \brief The configuration's SPCR register value.
         */
        std::uint8_t m_spcr{};

        /**
         * \brief The configuration's SPSR register value.
         */
        std::uint8_t m_spsr{};
    };

    /**
     * \brief Constructor.
     */
    constexpr Variable_Configuration_Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] spi The SPI to be used by the controller.
     */
    Variable_Configuration_Basic_Controller( Peripheral::SPI & spi ) noexcept :
        m_spi{ &spi },
        m_spi_sck_mosi{ Multiplexed_Signals::spi_port( spi ),
                        static_cast<std::uint8_t>(
                            Multiplexed_Signals::sck_mask( spi ) | Multiplexed_Signals::mosi_mask( spi ) ) }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Variable_Configuration_Basic_Controller( Variable_Configuration_Basic_Controller && source ) noexcept
        :
        m_spi{ source.m_spi },
        m_spi_sck_mosi{ std::move( source.m_spi_sck_mosi ) }
    {
        source.m_spi = nullptr;
    }

    Variable_Configuration_Basic_Controller( Variable_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Variable_Configuration_Basic_Controller() noexcept
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
    constexpr auto operator=( Variable_Configuration_Basic_Controller && expression ) noexcept
        -> Variable_Configuration_Basic_Controller &
    {
        if ( &expression != this ) {
            disable();

            m_spi          = expression.m_spi;
            m_spi_sck_mosi = std::move( expression.m_spi_sck_mosi );

            expression.m_spi = nullptr;
        } // if

        return *this;
    }

    auto operator=( Variable_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Initialize the controller's hardware.
     */
    void initialize() noexcept
    {
        m_spi_sck_mosi.initialize();

        enable_controller();
    }

    /**
     * \brief Configure the controller's clock and data exchange bit order to meet a
     *        specific device's communication requirements.
     *
     * \param[in] configuration The clock and data exchange bit order configuration that
     *            meets the device's communication requirements.
     */
    void configure( Configuration configuration ) noexcept
    {
        configure_controller( configuration.spcr(), configuration.spsr() );
    }

    /**
     * \brief Exchange data with a device.
     *
     * \param[in] data The data to transmit to the device.
     *
     * \return The data received from the device.
     */
    auto exchange( std::uint8_t data ) noexcept -> std::uint8_t
    {
        initiate_exchange( data );

        while ( not exchange_complete() ) {} // while

        return finish_exchange();
    }

  private:
    /**
     * \brief The SPI used by the controller.
     */
    Peripheral::SPI * m_spi{};

    /**
     * \brief The SPI's SCK and MOSI pins.
     */
    GPIO::Push_Pull_IO_Pin m_spi_sck_mosi{};

    /**
     * \brief Disable the controller.
     */
    constexpr void disable() noexcept
    {
        if ( m_spi ) {
            disable_controller();
        } // if
    }

    /**
     * \brief Disable the controller.
     */
    void disable_controller() noexcept
    {
        m_spi->spcr = 0;
    }

    /**
     * \brief Enable the controller.
     */
    void enable_controller() noexcept
    {
        m_spi->spsr = 0;
        m_spi->spcr = Peripheral::SPI::SPCR::Mask::SPE | Peripheral::SPI::SPCR::Mask::MSTR;
    }

    /**
     * \brief Configure the controller.
     *
     * \param[in] spcr The desired SPCR register value.
     * \param[in] spsr The desired SPSR register value.
     */
    void configure_controller( std::uint8_t spcr, std::uint8_t spsr ) noexcept
    {
        m_spi->spcr = spcr;
        m_spi->spsr = spsr;
    }

    /**
     * \brief Initiate a data exchange.
     *
     * \param[in] data The data to transmit.
     */
    void initiate_exchange( std::uint8_t data ) noexcept
    {
        m_spi->spdr = data;
    }

    /**
     * \brief Check if a data exchange is complete.
     *
     * \return true if the data exchange is complete.
     * \return false if the data exchange is not complete.
     */
    auto exchange_complete() const noexcept -> bool
    {
        return m_spi->spsr & Peripheral::SPI::SPSR::Mask::SPIF;
    }

    /**
     * \brief Finish a data exchange.
     *
     * \return The received data.
     */
    auto finish_exchange() noexcept -> std::uint8_t
    {
        return m_spi->spdr;
    }
};

/**
 * \brief USART peripheral based variable configuration basic controller.
 */
template<>
class Variable_Configuration_Basic_Controller<Peripheral::USART> {
  public:
    /**
     * \brief Clock (frequency, polarity, and phase) and data exchange bit order
     *        configuration.
     */
    class Configuration {
      public:
        /**
         * \brief Constructor.
         */
        constexpr Configuration() noexcept :
            Configuration{ 0,
                           USART_Clock_Polarity::IDLE_LOW,
                           USART_Clock_Phase::CAPTURE_IDLE_TO_ACTIVE,
                           USART_Bit_Order::MSB_FIRST }
        {
        }

        /**
         * \brief Constructor.
         *
         * \param[in] usart_clock_generator_scaling_factor The desired USART clock
         *            generator scaling factor (UBRR register value).
         * \param[in] usart_clock_polarity The desired USART clock polarity.
         * \param[in] usart_clock_phase The desired USART clock phase.
         * \param[in] usart_bit_order The desired USART bit order.
         */
        constexpr Configuration(
            std::uint16_t        usart_clock_generator_scaling_factor,
            USART_Clock_Polarity usart_clock_polarity,
            USART_Clock_Phase    usart_clock_phase,
            USART_Bit_Order      usart_bit_order ) noexcept :
            m_ucsrc{ static_cast<std::uint8_t>(
                Peripheral::USART::SPI_Host::UCSRC::UMSEL_HOST_SPI | to_underlying( usart_clock_polarity )
                | to_underlying( usart_clock_phase ) | to_underlying( usart_bit_order ) ) },
            m_ubrr{ usart_clock_generator_scaling_factor }
        {
        }

        /**
         * \brief Constructor.
         *
         * \param[in] source The source of the move.
         */
        constexpr Configuration( Configuration && source ) noexcept = default;

        /**
         * \brief Constructor.
         *
         * \param[in] original The original to copy.
         */
        constexpr Configuration( Configuration const & original ) noexcept = default;

        /**
         * \brief Destructor.
         */
        ~Configuration() noexcept = default;

        /**
         * \brief Assignment operator.
         *
         * \param[in] expression The expression to be assigned.
         *
         * \return The assigned to object.
         */
        constexpr auto operator=( Configuration && expression ) noexcept -> Configuration & = default;

        /**
         * \brief Assignment operator.
         *
         * \param[in] expression The expression to be assigned.
         *
         * \return The assigned to object.
         */
        constexpr auto operator=( Configuration const & expression ) noexcept
            -> Configuration & = default;

        /**
         * \brief Get the configuration's UCSRC register value.
         *
         * \return The configuration's UCSRC register value.
         */
        constexpr auto ucsrc() const noexcept -> std::uint8_t
        {
            return m_ucsrc;
        }

        /**
         * \brief Get the configuration's UBRR register value.
         *
         * \return The configuration's UBRR register value.
         */
        constexpr auto ubrr() const noexcept -> std::uint16_t
        {
            return m_ubrr;
        }

      private:
        /**
         * \brief The configuration's UCSRC register value.
         */
        std::uint8_t m_ucsrc{};

        /**
         * \brief The configuration's UBRR register value.
         */
        std::uint16_t m_ubrr{};
    };

    /**
     * \brief Constructor.
     */
    constexpr Variable_Configuration_Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] usart The USART to be used by the controller.
     */
    Variable_Configuration_Basic_Controller( Peripheral::USART & usart ) noexcept :
        m_usart{ &usart },
        m_usart_xck{ Multiplexed_Signals::xck_port( usart ), Multiplexed_Signals::xck_mask( usart ) }
    {
        configure_controller();
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Variable_Configuration_Basic_Controller( Variable_Configuration_Basic_Controller && source ) noexcept
        :
        m_usart{ source.m_usart },
        m_usart_xck{ std::move( source.m_usart_xck ) }
    {
        source.m_usart = nullptr;
    }

    Variable_Configuration_Basic_Controller( Variable_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Variable_Configuration_Basic_Controller() noexcept
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
    constexpr auto operator=( Variable_Configuration_Basic_Controller && expression ) noexcept
        -> Variable_Configuration_Basic_Controller &
    {
        if ( &expression != this ) {
            disable();

            m_usart     = expression.m_usart;
            m_usart_xck = std::move( expression.m_usart_xck );

            expression.m_usart = nullptr;
        } // if

        return *this;
    }

    auto operator=( Variable_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Initialize the controller's hardware.
     */
    void initialize() noexcept
    {
        m_usart_xck.initialize();

        enable_controller();
    }

    /**
     * \brief Configure the controller's clock and data exchange bit order to meet a
     *        specific device's communication requirements.
     *
     * \param[in] configuration The clock and data exchange bit order configuration that
     *            meets the device's communication requirements.
     */
    void configure( Configuration const & configuration ) noexcept
    {
        configure_controller( configuration.ucsrc(), configuration.ubrr() );
    }

    /**
     * \brief Exchange data with a device.
     *
     * \param[in] data The data to transmit to the device.
     *
     * \return The data received from the device.
     */
    auto exchange( std::uint8_t data ) noexcept -> std::uint8_t
    {
        while ( not transmit_buffer_is_empty() ) {} // while

        load_transmit_buffer( data );

        while ( not received_data_is_available() ) {} // while

        return read_receive_buffer();
    }

  private:
    /**
     * \brief The USART used by the controller.
     */
    Peripheral::USART * m_usart{};

    /**
     * \brief The USART's XCK pin.
     */
    GPIO::Push_Pull_IO_Pin m_usart_xck{};

    /**
     * \brief Disable the controller.
     */
    constexpr void disable() noexcept
    {
        if ( m_usart ) {
            disable_controller();
        } // if
    }

    /**
     * \brief Configure the controller.
     */
    void configure_controller() noexcept
    {
        m_usart->spi_host.ucsrb = 0;
        m_usart->spi_host.ucsrc = Peripheral::USART::SPI_Host::UCSRC::UMSEL_HOST_SPI;
        m_usart->spi_host.ubrr  = 0;
    }

    /**
     * \brief Disable the controller.
     */
    void disable_controller() noexcept
    {
        m_usart->spi_host.ucsrb = 0;
    }

    /**
     * \brief Enable the controller.
     */
    void enable_controller() noexcept
    {
        m_usart->spi_host.ucsrb = Peripheral::USART::SPI_Host::UCSRB::Mask::TXEN
                                  | Peripheral::USART::SPI_Host::UCSRB::Mask::RXEN;
    }

    /**
     * \brief Configure the controller.
     *
     * \param[in] ucsrc The desired UCSRC register value.
     * \param[in] ubrr The desired UBRR register value.
     */
    void configure_controller( std::uint8_t ucsrc, std::uint16_t ubrr ) noexcept
    {
        m_usart->spi_host.ucsrc = ucsrc;
        m_usart->spi_host.ubrr  = ubrr;
    }

    /**
     * \brief Check if the transmit buffer is empty.
     *
     * \return true if the transmit buffer is empty.
     * \return false if the transmit buffer is not empty.
     */
    auto transmit_buffer_is_empty() const noexcept -> bool
    {
        return m_usart->spi_host.ucsra & Peripheral::USART::SPI_Host::UCSRA::Mask::UDRE;
    }

    /**
     * \brief Load data into the transmit buffer.
     *
     * \param[in] data The data to load into the transmit buffer.
     */
    void load_transmit_buffer( std::uint8_t data ) noexcept
    {
        m_usart->spi_host.udr = data;
    }

    /**
     * \brief Check if received data is available.
     *
     * \return true if received data is available.
     * \return false if received data is not available.
     */
    auto received_data_is_available() const noexcept -> bool
    {
        return m_usart->spi_host.ucsra & Peripheral::USART::SPI_Host::UCSRA::Mask::RXC;
    }

    /**
     * \brief Read data from the receive buffer.
     *
     * \return The data read from the receive buffer.
     */
    auto read_receive_buffer() noexcept -> std::uint8_t
    {
        return m_usart->spi_host.udr;
    }
};

} // namespace picolibrary::Microchip::megaAVR::SPI

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_SPI_H
