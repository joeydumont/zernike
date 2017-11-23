/*! ------------------------------------------------------------------------- *
 * This file is part of the Zernike library. It is thus freely available and  *
 * infinitely modifiable and copyable. As it is with such products, it comes  *
 * with absolutely no warranty. It might even have bugs (!). If so, feel free *
 * to drop a line at the email address above, or visit:                       *
 * https://github.com/valandil/zernike                                        *
 * -------------------------------------------------------------------------- */

#ifndef BINOMIAL_COEFFICIENT_H
#define BINOMIAL_COEFFICIENT_H

#include <cmath>

namespace Zernike {

/// Computes the binomial coefficient. The algorithm is stupid and this
/// should be removed in favour of a call to boost.
unsigned int binomial_coefficient(unsigned int n,
                                 unsigned int k);

} // namespace Zernike

#endif // BINOMIAL_COEFFICIENT_H
