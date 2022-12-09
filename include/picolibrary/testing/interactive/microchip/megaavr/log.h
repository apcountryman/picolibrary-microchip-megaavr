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
 * \brief picolibrary::Testing::Interactive::Microchip::megaAVR::Log interface.
 */

#ifndef PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_H
#define PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_H

#include <cstdint>

#include "picolibrary/algorithm.h"
#include "picolibrary/error.h"
#include "picolibrary/microchip/megaavr/peripheral.h"
#include "picolibrary/microchip/megaavr/peripheral/usart.h"
#include "picolibrary/precondition.h"
#include "picolibrary/rom.h"
#include "picolibrary/stream.h"
#include "picolibrary/utility.h"

namespace picolibrary::Testing::Interactive::Microchip::megaAVR {

/**
 * \brief Log.
 */
class Log : public Reliable_Output_Stream {
  public:
    /**
     * \brief USART peripheral clock generator operating speed.
     */
    enum class USART_Clock_Generator_Operating_Speed : std::uint8_t {
        NORMAL = 0b0 << ::picolibrary::Microchip::megaAVR::Peripheral::USART::Normal::UCSRA::Bit::U2X, ///< Normal.
        DOUBLE = 0b1 << ::picolibrary::Microchip::megaAVR::Peripheral::USART::Normal::UCSRA::Bit::U2X, ///< Double.
    };

    /**
     * \brief Check if the log has been initialized.
     *
     * \return true if the log has been initialized.
     * \return false if the log has not been initialized.
     */
    static auto is_initialized() noexcept -> bool
    {
        return USART;
    }

    /**
     * \brief Initialize the log.
     *
     * \pre not picolibrary::Testing::Interactive::Microchip::megaAVR::Log::is_initialized()
     *
     * \param[in] usart The USART peripheral to be used by the log.
     * \param[in] usart_clock_generator_operating_speed The desired USART peripheral clock
     *            generator operating speed.
     * \param[in] usart_clock_generator_scaling_factor The desired USART peripheral clock
     *            generator scaling factor.
     */
    static void initialize(
        ::picolibrary::Microchip::megaAVR::Peripheral::USART & usart,
        USART_Clock_Generator_Operating_Speed usart_clock_generator_operating_speed,
        std::uint16_t usart_clock_generator_scaling_factor ) noexcept
    {
        PICOLIBRARY_EXPECT( not is_initialized(), Generic_Error::LOGIC_ERROR );

        usart.normal.ucsrb = ::picolibrary::Microchip::megaAVR::Peripheral::USART::Normal::UCSRB::UCSZ_8_BIT;
        usart.normal.ucsrc =
            ::picolibrary::Microchip::megaAVR::Peripheral::USART::Normal::UCSRC::UMSEL_ASYNCHRONOUS_USART
            | ::picolibrary::Microchip::megaAVR::Peripheral::USART::Normal::UCSRC::UPM_DISABLED
            | ::picolibrary::Microchip::megaAVR::Peripheral::USART::Normal::UCSRC::USBS_1_BIT
            | ::picolibrary::Microchip::megaAVR::Peripheral::USART::Normal::UCSRC::UCSZ_8_BIT;
        usart.normal.ucsra = to_underlying( usart_clock_generator_operating_speed );
        usart.normal.ubrr  = usart_clock_generator_scaling_factor;

        usart.normal.ucsrb |= ::picolibrary::Microchip::megaAVR::Peripheral::USART::Normal::UCSRB::Mask::TXEN;

        USART = &usart;
    }

#if defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART )                                    \
    && defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED ) \
    && defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR )
    /**
     * \brief Initialize the log.
     *
     * \pre not picolibrary::Testing::Interactive::Microchip::megaAVR::Log::is_initialized()
     */
    static void initialize() noexcept
    {
        initialize(
            ::picolibrary::Microchip::megaAVR::Peripheral::PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART::instance(),
            USART_Clock_Generator_Operating_Speed::PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED,
            PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR );
    }
#endif // defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART ) && defined(
       // PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED
       // ) && defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR )

    /**
     * \brief Report a fatal error.
     *
     * \param[in] error The fatal error.
     */
    static void report_fatal_error( Error_Code const & error ) noexcept
    {
        if ( is_initialized() ) {
            transmit( PICOLIBRARY_ROM_STRING( "fatal error: " ) );
            transmit( error.category().name() );
            transmit( PICOLIBRARY_ROM_STRING( "::" ) );
            transmit( error.description() );
            transmit( '\n' );
        } // if
    }

    /**
     * \brief Get the log instance.
     *
     * \pre picolibrary::Testing::Interactive::Microchip::megaAVR::Log::is_initialized()
     *
     * \return The log instance.
     */
    static auto instance() noexcept -> Log &
    {
        PICOLIBRARY_EXPECT( is_initialized(), Generic_Error::LOGIC_ERROR );

        static auto log = Log{};

        return log;
    }

    Log( Log && ) = delete;

    Log( Log const & ) = delete;

    auto operator=( Log && ) = delete;

    auto operator=( Log const & ) = delete;

  private:
    /**
     * \brief Buffer.
     */
    class Buffer final : public Reliable_Stream_Buffer {
      public:
        /**
         * \brief Constructor.
         */
        constexpr Buffer() noexcept = default;

        Buffer( Buffer && ) = delete;

        Buffer( Buffer const & ) = delete;

        /**
         * \brief Destructor.
         */
        ~Buffer() noexcept = default;

        auto operator=( Buffer && ) = delete;

        auto operator=( Buffer const & ) = delete;

        /**
         * \brief Transmit a character.
         *
         * \param[in] character The character to transmit.
         */
        void put( char character ) noexcept override final
        {
            transmit( character );
        }

        /**
         * \brief Transmit a block of characters.
         *
         * \param[in] begin The beginning of the block of characters to transmit.
         * \param[in] end The end of the block of characters to transmit.
         */
        void put( char const * begin, char const * end ) noexcept override final
        {
            for_each( begin, end, []( auto character ) noexcept { transmit( character ); } );
        }

        /**
         * \brief Transmit a null-terminated string.
         *
         * \param[in] string The null-terminated string to transmit.
         */
        void put( char const * string ) noexcept override final
        {
            transmit( string );
        }

        /**
         * \brief Transmit a null-terminated ROM string.
         *
         * \param[in] string The null-terminated ROM string to transmit.
         */
        void put( ROM::String string ) noexcept override final
        {
            transmit( string );
        }

        /**
         * \brief Transmit an unsigned byte.
         *
         * \param[in] value The unsigned byte to transmit.
         */
        void put( std::uint8_t value ) noexcept override final
        {
            transmit( value );
        }

        /**
         * \brief Transmit a block of unsigned bytes.
         *
         * \param[in] begin The beginning of the block of unsigned bytes to transmit.
         * \param[in] end The end of the block of unsigned bytes to transmit.
         */
        void put( std::uint8_t const * begin, std::uint8_t const * end ) noexcept override final
        {
            for_each( begin, end, []( auto value ) noexcept { transmit( value ); } );
        }

        /**
         * \brief Transmit a signed byte.
         *
         * \param[in] value The signed byte to transmit.
         */
        void put( std::int8_t value ) noexcept override final
        {
            transmit( value );
        }

        /**
         * \brief Transmit a block of signed bytes.
         *
         * \param[in] begin The beginning of the block of signed bytes to transmit.
         * \param[in] end The end of the block of signed bytes to transmit.
         */
        void put( std::int8_t const * begin, std::int8_t const * end ) noexcept override final
        {
            for_each( begin, end, []( auto value ) noexcept { transmit( value ); } );
        }

        /**
         * \brief Do nothing.
         */
        void flush() noexcept override final
        {
        }
    };

    /**
     * \brief The USART peripheral used by the log.
     */
    static inline auto USART = static_cast<::picolibrary::Microchip::megaAVR::Peripheral::USART *>( nullptr );

    /**
     * \brief The buffer.
     */
    static inline auto BUFFER = Buffer{};

    /**
     * \brief Transmit data.
     *
     * \param[in] data The data to transmit.
     */
    static void transmit( std::uint8_t data ) noexcept
    {
        while ( not(
            USART->normal.ucsra
            & ::picolibrary::Microchip::megaAVR::Peripheral::USART::Normal::UCSRA::Mask::UDRE ) ) {
        } // while

        USART->normal.udr = data;
    }

    /**
     * \brief Transmit a null-terminated string.
     *
     * \param[in] string The null-terminated string to transmit.
     */
    static void transmit( char const * string ) noexcept
    {
        while ( auto const character = *string++ ) { transmit( character ); } // while
    }

    /**
     * \brief Transmit a null-terminated ROM string.
     *
     * \param[in] string The null-terminated ROM string to transmit.
     */
    static void transmit( ROM::String string ) noexcept
    {
        while ( auto const character = *string++ ) { transmit( character ); } // while
    }

    /**
     * \brief Constructor.
     */
    Log() noexcept
    {
        set_buffer( &BUFFER );
    }

    /**
     * \brief Destructor.
     */
    ~Log() noexcept = default;
};

} // namespace picolibrary::Testing::Interactive::Microchip::megaAVR

#endif // PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR_LOG_H
