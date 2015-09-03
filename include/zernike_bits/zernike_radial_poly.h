#ifndef ZERNIKE_RADIAL_POLY_H
#define ZERNIKE_RADIAL_POLY_H

#include <cmath>
#include <iostream>
#include <vector>

namespace Zernike {

double ZernikeRadialPolynomial(unsigned int n,
                               unsigned int m,
                               double r);

} // namespace Zernike

#endif // ZERNIKE_POLY_H