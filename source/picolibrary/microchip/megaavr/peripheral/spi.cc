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
 * \brief picolibrary::Microchip::megaAVR::Peripheral::SPI implementation.
 */

#include "picolibrary/microchip/megaavr/peripheral/spi.h"

namespace picolibrary::Microchip::megaAVR::Peripheral {

static_assert( sizeof( SPI ) == 3 );
static_assert( SPI::SPCR::Bit::SPIE == 7 );
static_assert( SPI::SPSR::Bit::SPIF == 7 );

} // namespace picolibrary::Microchip::megaAVR::Peripheral
