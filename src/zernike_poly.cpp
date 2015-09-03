#include <zernike_bits/zernike_poly.h>

namespace Zernike {

double ZernikePolynomial(unsigned int n,
                         int m,
                         double r,
                         double theta)
{
  unsigned int m_abs   = std::abs(m);
  double normalization = std::sqrt(2.0*(n+1.0)/(1+(m==0 ? 1.0 : 0.0)));
  double radial_poly   = ZernikeRadialPolynomial(n,m_abs,r);
  double angular_poly  = (m < 0 ? std::sin(m_abs*theta) : std::cos(m_abs*theta))  ;

    return normalization*radial_poly*angular_poly;
}

}
