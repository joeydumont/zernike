#ifndef ZERNIKE_RADIAL_POLY_H
#define ZERNIKE_RADIAL_POLY_H

#include <cmath>
#include <iostream>
#include <vector>

#include <zernike_bits/binomial_coefficient.h>

namespace Zernike {

enum ZernikeEvaluationMethod {direct, recursion};

double ZernikeRadialPolynomial(unsigned int n,
                               unsigned int m,
                               double r,
                               ZernikeEvaluationMethod eval_method = recursion);

double ZernikeRadialPolynomialLowOrder(unsigned int n,
                                       unsigned int m,
                                       double r);

double ZernikeRadialPolynomialDirect(unsigned int n,
                                     unsigned int m,
                                     double r);

double ZernikeRadialPolynomialRecursion(unsigned int n,
                                        unsigned int m,
                                        double r);

} // namespace Zernike

#endif // ZERNIKE_POLY_H
