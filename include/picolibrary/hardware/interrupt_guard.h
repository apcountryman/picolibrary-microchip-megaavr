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
 * \brief picolibrary::Interrupt_Guard interface.
 */

#ifndef PICOLIBRARY_HARDWARE_INTERRUPT_GUARD_H
#define PICOLIBRARY_HARDWARE_INTERRUPT_GUARD_H

#include <avr-libcpp/interrupt>
#include <cstdint>

namespace picolibrary {

/**
 * \brief Interrupt guard with restore interrupt enable state action on destruction.
 */
template<>
class Interrupt_Guard<Restore_Interrupt_Enable_State> {
  public:
    /**
     * \brief Constructor.
     */
    Interrupt_Guard() noexcept :
        m_sreg{ *reinterpret_cast<std::uint8_t volatile *>( SREG_ADDRESS ) }
    {
        cli();
    }

    Interrupt_Guard( Interrupt_Guard && ) = delete;

    Interrupt_Guard( Interrupt_Guard const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Interrupt_Guard() noexcept
    {
        *reinterpret_cast<std::uint8_t volatile *>( SREG_ADDRESS ) = m_sreg;

        asm volatile( "" ::: "memory" );
    }

    auto operator=( Interrupt_Guard && ) = delete;

    auto operator=( Interrupt_Guard const & ) = delete;

  private:
    /**
     * \brief SREG register address.
     */
    static constexpr auto SREG_ADDRESS = std::uintptr_t{ 0x005F };

    /**
     * \brief The state of the SREG register when the interrupt guard was constructed.
     */
    std::uint8_t m_sreg{};
};

/**
 * \brief Interrupt guard with enable interrupts action on destruction.
 */
template<>
class Interrupt_Guard<Enable_Interrupts> {
  public:
    /**
     * \brief Constructor.
     */
    Interrupt_Guard() noexcept
    {
        cli();
    }

    Interrupt_Guard( Interrupt_Guard && ) = delete;

    Interrupt_Guard( Interrupt_Guard const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Interrupt_Guard() noexcept
    {
        sei();
    }

    auto operator=( Interrupt_Guard && ) = delete;

    auto operator=( Interrupt_Guard const & ) = delete;
};

} // namespace picolibrary

#endif // PICOLIBRARY_HARDWARE_INTERRUPT_GUARD_H
