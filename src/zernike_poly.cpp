/*! ------------------------------------------------------------------------- *
 * This file is part of the Zernike library. It is thus freely available and  *
 * infinitely modifiable and copyable. As it is with such products, it comes  *
 * with absolutely no warranty. It might even have bugs (!). If so, feel free *
 * to drop a line at the email address above, or visit:                       *
 * https://github.com/valandil/zernike                                        *
 * -------------------------------------------------------------------------- */

#include <zernike_bits/zernike_poly.h>

namespace Zernike {

double ZernikePolynomial(unsigned int n,
			                   int          m,
			                   double       r,
			                   double       theta)
{
  unsigned int m_abs   = std::abs(m);
  double normalization = std::sqrt((2.0*n+2.0)/((1.0+(m==0 ? 1.0 : 0.0))));
  double radial_poly   = ZernikeRadialPolynomial(n,m_abs,r, recursion);
  double angular_poly  = (m < 0 ? std::sin(m_abs*theta) : std::cos(m_abs*theta));

  return normalization*radial_poly*angular_poly;
}


double ZernikeAberrations(std::vector<double> j,
			                    double              r,
			                    double              theta,
                          IndexConvention     idx_convention)
{
  // Initialization of quantum indices for Zernike polynomials.
  int n;
  int m;

  // Initialization of sum of Zernike polynomials with given coefficients.
  double       zernike_sum = 0.0;
  int          j_start;

  // Determine the function used to compute the indices.
  LinearToQuantumIndexConversionFunction f = NULL;

  switch (idx_convention)
  {
    case Natural:
    {
      f       = &NaturalToQuantum;
      j_start = 0;
      break;
    }

    case Noll:
    {
      f       = &NollToQuantum;
      j_start = 1;
      break;
    }

    case Phasics:
    {
      f       = &PhasicsToQuantum;
      j_start = 1;
      break;
    }

    case OSA:
    {
      f       = &OSAToQuantum;
      j_start = 0;
      break;
    }

    default:
    {
      f       = &PhasicsToQuantum;
      j_start = 1;
      break;
    }
  }

  for (unsigned int i=j_start; i<j.size()+j_start; i++)
  {
    // We compute the quantum indices from the OSA/ANSI indices.
    f(i,n,m);

    // We add their contribution to the sum.
    zernike_sum += j[i-j_start]*ZernikePolynomial(n,m,r,theta);

  }

  return zernike_sum;
}

} // namespace Zernike
