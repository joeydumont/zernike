#ifndef ZERNIKE_POLY_H
#define ZERNIKE_POLY_H

#include <cmath>

#include <zernike_bits/zernike_radial_poly.h>

namespace Zernike {

double ZernikePolynomial(unsigned int n,
                         int m,
                         double r,
                         double theta);

} // namespace Zernike

#endif // ZERNIKE_POLY_H
