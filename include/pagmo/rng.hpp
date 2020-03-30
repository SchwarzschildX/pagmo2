/* Copyright 2017-2020 PaGMO development team

This file is part of the PaGMO library.

The PaGMO library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 3 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The PaGMO library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the PaGMO library.  If not,
see https://www.gnu.org/licenses/. */

#ifndef PAGMO_RNG_HPP
#define PAGMO_RNG_HPP

#include <random>

#include <pagmo/detail/visibility.hpp>

namespace pagmo
{

namespace detail
{

// PaGMO makes use of the 32-bit Mersenne Twister by Matsumoto and Nishimura, 1998.
using random_engine_type = std::mt19937;

} // namespace detail

/// Thread-safe random device
/**
 * This class intends to be a thread-safe substitute for std::random_device,
 * allowing, at the same time, precise global seed control throughout PaGMO.
 * It offers the user access to a global Pseudo Random Sequence generated by the
 * 32-bit Mersenne Twister by Matsumoto and Nishimura, 1998.
 * Such a PRS can be accessed by all PaGMO classes via the static method
 * random_device::next(). The seed of this global Pseudo Random Sequence can
 * be set by the method random_device::set_seed(), else by default is initialized
 * once at run-time using std::random_device.
 */
struct PAGMO_DLL_PUBLIC random_device {
    static unsigned next();

#if !defined(PAGMO_DOXYGEN_INVOKED)
    // Sets the seed for the PRS.
    static void set_seed(unsigned seed);
#endif
};

} // namespace pagmo

#endif
