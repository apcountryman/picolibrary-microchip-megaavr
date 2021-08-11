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

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr/peripheral/instance.h"
#include "picolibrary/microchip/megaavr/register.h"

namespace picolibrary::Microchip::megaAVR::Peripheral {

/**
 * \brief Microchip megaAVR Serial Peripheral Interface (SPI) peripheral.
 */
class SPI {
  public:
    enum class Clock_Rate : std::uint8_t;

    enum class Clock_Polarity : std::uint8_t;

    enum class Clock_Phase : std::uint8_t;

    enum class Bit_Order : std::uint8_t;

    /**
     * \brief SPI Control Register (SPCR).
     *
     * This register has the following fields:
     * - SPI Clock Rate Select (SPR)
     * - Clock Phase (CPHA)
     * - Clock Polarity (CPOL)
     * - Host/Client Select (HOST)
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
            static constexpr auto HOST = std::uint_fast8_t{ 1 }; ///< HOST.
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
            static constexpr auto HOST = std::uint_fast8_t{ CPOL + Size::CPOL }; ///< HOST.
            static constexpr auto DORD = std::uint_fast8_t{ HOST + Size::HOST }; ///< DORD.
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
            static constexpr auto HOST = mask<std::uint8_t>( Size::HOST, Bit::HOST ); ///< HOST.
            static constexpr auto DORD = mask<std::uint8_t>( Size::DORD, Bit::DORD ); ///< DORD.
            static constexpr auto SPE = mask<std::uint8_t>( Size::SPE, Bit::SPE ); ///< SPE.
            static constexpr auto SPIE = mask<std::uint8_t>( Size::SPIE, Bit::SPIE ); ///< SPIE.
        };

        /**
         * \brief enum class field offset.
         */
        struct Offset {
            static constexpr auto SPR = std::uint_fast8_t{ 1 }; ///< SPR.
        };

        SPCR() = delete;

        SPCR( SPCR && ) = delete;

        SPCR( SPCR const & ) = delete;

        ~SPCR() = delete;

        auto operator=( SPCR && ) = delete;

        auto operator=( SPCR const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Configure the SPI for use as an SPI controller.
         */
        void configure_as_spi_controller() noexcept
        {
            *this = Mask::HOST;
        }

        /**
         * \brief Configure the SPI for use as an SPI device.
         */
        void configure_as_spi_device() noexcept
        {
            *this = 0;
        }

        /**
         * \brief Enable the SPI.
         */
        void enable() noexcept
        {
            *this |= Mask::SPE;
        }

        /**
         * \brief Disable the SPI.
         */
        void disable() noexcept
        {
            *this &= ~Mask::SPE;
        }

        /**
         * \brief Enable the SPI interrupt.
         */
        void enable_interrupt() noexcept
        {
            *this |= Mask::SPIE;
        }

        /**
         * \brief Disable the SPI interrupt.
         */
        void disable_interrupt() noexcept
        {
            *this &= static_cast<std::uint8_t>( ~Mask::SPIE );
        }

        /**
         * \brief Configure SPI data exchange.
         *
         * \param[in] clock_rate The desired clock rate.
         * \param[in] clock_polarity The desired clock polarity.
         * \param[in] clock_phase The desired clock phase.
         * \param[in] bit_order The desired data exchange bit order.
         */
        void configure( Clock_Rate clock_rate, Clock_Polarity clock_polarity, Clock_Phase clock_phase, Bit_Order bit_order ) noexcept;
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
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SPI2X    = std::uint_fast8_t{ 1 }; ///< SPI2X.
            static constexpr auto RESERVED = std::uint_fast8_t{ 5 }; ///< Reserved.
            static constexpr auto WCOL     = std::uint_fast8_t{ 1 }; ///< WCOL.
            static constexpr auto SPIF     = std::uint_fast8_t{ 1 }; ///< SPIF.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SPI2X = std::uint_fast8_t{}; ///< SPI2X.
            static constexpr auto RESERVED = std::uint_fast8_t{ SPI2X + Size::SPI2X }; ///< Reserved.
            static constexpr auto WCOL = std::uint_fast8_t{ RESERVED + Size::RESERVED }; ///< WCOL.
            static constexpr auto SPIF = std::uint_fast8_t{ WCOL + Size::WCOL }; ///< WCOL.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SPI2X = mask<std::uint8_t>( Size::SPI2X, Bit::SPI2X ); ///< SPI2X.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
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

        /**
         * \brief Configure the SPI for use as an SPI controller.
         */
        void configure_as_spi_controller() noexcept
        {
            *this = 0;
        }

        /**
         * \brief Configure the SPI for use as an SPI device.
         */
        void configure_as_spi_device() noexcept
        {
            *this = 0;
        }

        /**
         * \brief Configure SPI data exchange.
         *
         * \param[in] clock_rate The desired clock rate.
         */
        void configure( Clock_Rate clock_rate ) noexcept;

        /**
         * \brief Check if data exchange is complete.
         *
         * \return true if data exchange is complete.
         * \return false if data exchange is not complete.
         */
        auto data_exchange_complete() const noexcept -> bool
        {
            return *this & Mask::SPIF;
        }

        /**
         * \brief Check if a write collision occurred.
         *
         * \return true if a write collision occurred.
         * \return false if a write collision did not occur.
         */
        auto write_collision() const noexcept -> bool
        {
            return *this & Mask::WCOL;
        }
    };

    /**
     * \brief Clock rate.
     */
    enum class Clock_Rate : std::uint8_t {
        FOSC_2   = ( 0b1 << SPSR::Bit::SPI2X ) | ( 0b00 << ( SPCR::Bit::SPR + SPCR::Offset::SPR ) ), ///< Oscillator Clock frequency / 2.
        FOSC_4   = ( 0b0 << SPSR::Bit::SPI2X ) | ( 0b00 << ( SPCR::Bit::SPR + SPCR::Offset::SPR ) ), ///< Oscillator Clock frequency / 4.
        FOSC_8   = ( 0b1 << SPSR::Bit::SPI2X ) | ( 0b01 << ( SPCR::Bit::SPR + SPCR::Offset::SPR ) ), ///< Oscillator Clock frequency / 8.
        FOSC_16  = ( 0b0 << SPSR::Bit::SPI2X ) | ( 0b01 << ( SPCR::Bit::SPR + SPCR::Offset::SPR ) ), ///< Oscillator Clock frequency / 16.
        FOSC_32  = ( 0b1 << SPSR::Bit::SPI2X ) | ( 0b10 << ( SPCR::Bit::SPR + SPCR::Offset::SPR ) ), ///< Oscillator Clock frequency / 32.
        FOSC_64  = ( 0b0 << SPSR::Bit::SPI2X ) | ( 0b10 << ( SPCR::Bit::SPR + SPCR::Offset::SPR ) ), ///< Oscillator Clock frequency / 64.
        FOSC_128 = ( 0b0 << SPSR::Bit::SPI2X ) | ( 0b11 << ( SPCR::Bit::SPR + SPCR::Offset::SPR ) ), ///< Oscillator Clock frequency / 128.
    };

    /**
     * \brief Clock polarity.
     */
    enum class Clock_Polarity : std::uint8_t {
        IDLE_LOW  = 0b0 << SPCR::Bit::CPOL, ///< Idle low.
        IDLE_HIGH = 0b1 << SPCR::Bit::CPOL, ///< Idle high.
    };

    /**
     * \brief Clock phase.
     */
    enum class Clock_Phase : std::uint8_t {
        CAPTURE_IDLE_TO_ACTIVE = 0b0 << SPCR::Bit::CPHA, ///< Capture data on the idle-to-active clock transition.
        CAPTURE_ACTIVE_TO_IDLE = 0b1 << SPCR::Bit::CPHA, ///< Capture data on the active-to-idle clock transition.
    };

    /**
     * \brief Data exchange bit order.
     */
    enum class Bit_Order : std::uint8_t {
        MSB_FIRST = 0b0 << SPCR::Bit::DORD, ///< Exchange data MSB first.
        LSB_FIRST = 0b1 << SPCR::Bit::DORD, ///< Exchange data LSB first.
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

    /**
     * \brief Configure the SPI for use as an SPI controller.
     */
    void configure_as_spi_controller() noexcept
    {
        spcr.configure_as_spi_controller();
        spsr.configure_as_spi_controller();
    }

    /**
     * \brief Configure the SPI for use as an SPI device.
     */
    void configure_as_spi_device() noexcept
    {
        spcr.configure_as_spi_device();
        spsr.configure_as_spi_device();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR::Peripheral::SPI::SPCR::enable()
     */
    void enable() noexcept
    {
        spcr.enable();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR::Peripheral::SPI::SPCR::disable()
     */
    void disable() noexcept
    {
        spcr.disable();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR::Peripheral::SPI::SPCR::enable_interrupt()
     */
    void enable_interrupt() noexcept
    {
        spcr.enable_interrupt();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR::Peripheral::SPI::SPCR::disable_interrupt()
     */
    void disable_interrupt() noexcept
    {
        spcr.disable_interrupt();
    }

    /**
     * \brief Configure SPI data exchange.
     *
     * \param[in] clock_rate The desired clock rate.
     * \param[in] clock_polarity The desired clock polarity.
     * \param[in] clock_phase The desired clock phase.
     * \param[in] bit_order The desired data exchange bit order.
     */
    void configure( Clock_Rate clock_rate, Clock_Polarity clock_polarity, Clock_Phase clock_phase, Bit_Order bit_order ) noexcept
    {
        spsr.configure( clock_rate );
        spcr.configure( clock_rate, clock_polarity, clock_phase, bit_order );
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR::Peripheral::SPI::SPSR::data_exchange_complete()
     */
    auto data_exchange_complete() const noexcept
    {
        return spsr.data_exchange_complete();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR::Peripheral::SPI::SPSR::write_collision()
     */
    auto write_collision() const noexcept
    {
        return spsr.write_collision();
    }

    /**
     * \brief Write data to the transmit buffer.
     *
     * \param[in] data The data to write to the transmit buffer.
     */
    void transmit( std::uint8_t data ) noexcept
    {
        spdr = data;
    }

    /**
     * \brief Read data from the receive buffer.
     *
     * \return The data read from the receive buffer.
     */
    auto receive() noexcept -> std::uint8_t
    {
        return spdr;
    }
};

inline void SPI::SPCR::configure( Clock_Rate clock_rate, Clock_Polarity clock_polarity, Clock_Phase clock_phase, Bit_Order bit_order ) noexcept
{
    *this = ( *this & ~( Mask::DORD | Mask::CPOL | Mask::CPHA | Mask::SPR ) )
            | ( ( static_cast<std::uint8_t>( clock_rate ) >> Offset::SPR ) & Mask::SPR )
            | static_cast<std::uint8_t>( clock_polarity )
            | static_cast<std::uint8_t>( clock_phase ) | static_cast<std::uint8_t>( bit_order );
}

inline void SPI::SPSR::configure( Clock_Rate clock_rate ) noexcept
{
    *this = static_cast<std::uint8_t>( clock_rate );
}

/**
 * \brief Microchip megaAVR Serial Peripheral Interface (SPI) peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the SPI instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using SPI_Instance = Instance<SPI, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_PERIPHERAL_SPI_H
