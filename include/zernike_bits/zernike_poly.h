/*! ------------------------------------------------------------------------- *
 * This file is part of the Zernike library. It is thus freely available and  *
 * infinitely modifiable and copyable. As it is with such products, it comes  *
 * with absolutely no warranty. It might even have bugs (!). If so, feel free *
 * to drop a line at the email address above, or visit:                       *
 * https://github.com/valandil/zernike                                        *
 * -------------------------------------------------------------------------- */

#ifndef ZERNIKE_POLY_H
#define ZERNIKE_POLY_H

#include <cmath>
#include <vector>

#include <zernike_bits/zernike_indices.h>
#include <zernike_bits/zernike_radial_poly.h>

namespace Zernike {

/// Computes the value of a given Zernike polynomial
/// at a given position in polar coordinates.
ZERNIKE_API
double ZernikePolynomial(unsigned int n,
                         int          m,
                         double       r,
                         double       theta);

/// Computes the sum of the Zernike polynomials up to
/// order j.size with coefficients stored in j,
/// in whatever linear index convention is specified.
typedef enum e_IndexConventions {Natural, Noll, Phasics, OSA} IndexConvention;
typedef void (*LinearToQuantumIndexConversionFunction)(int,int&,int&);
ZERNIKE_API
double ZernikeAberrations(std::vector<double> j,
                          double              r,
                          double              theta,
                          IndexConvention     convention = Phasics);

} // namespace Zernike

#endif // ZERNIKE_POLY_H
