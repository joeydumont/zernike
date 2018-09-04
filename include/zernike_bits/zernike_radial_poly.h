/*! ------------------------------------------------------------------------- *
 * This file is part of the Zernike library. It is thus freely available and  *
 * infinitely modifiable and copyable. As it is with such products, it comes  *
 * with absolutely no warranty. It might even have bugs (!). If so, feel free *
 * to drop a line at the email address above, or visit:                       *
 * https://github.com/valandil/zernike                                        *
 * -------------------------------------------------------------------------- */

#ifndef ZERNIKE_RADIAL_POLY_H
#define ZERNIKE_RADIAL_POLY_H

#include <cmath>
#include <iostream>
#include <vector>

#include <zernike_bits/binomial_coefficient.h>

namespace Zernike {

/// Determines the algorithm used to evaluate the Zernike radial polynomial.
enum ZernikeEvaluationMethod {direct, recursion};

/// High-level function that serves as an interface to different evaluation
/// algorithms of the Zernike radial polynomial.
double ZernikeRadialPolynomial(unsigned int n,
                               unsigned int m,
                               double r,
                               ZernikeEvaluationMethod eval_method = recursion);
} // namespace Zernike

#endif // ZERNIKE_POLY_H
