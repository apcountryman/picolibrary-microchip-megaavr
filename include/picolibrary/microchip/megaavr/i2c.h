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
 * \brief picolibrary::Microchip::megaAVR::I2C interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H

/**
 * \brief Microchip megaAVR Inter-Integrated Circuit (I2C) facilities.
 */
namespace picolibrary::Microchip::megaAVR::I2C {

/**
 * \brief I2C basic controller.
 */
class Basic_Controller {
  public:
    /**
     * \brief Constructor.
     */
    constexpr Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Basic_Controller( Basic_Controller && source ) noexcept = default;

    Basic_Controller( Basic_Controller const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Basic_Controller() noexcept = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto operator=( Basic_Controller && expression ) noexcept -> Basic_Controller & = default;

    auto operator=( Basic_Controller const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR::I2C

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR_I2C_H
