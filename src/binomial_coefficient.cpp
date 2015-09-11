/*! ------------------------------------------------------------------------- *
 * This file is part of the Zernike library. It is thus freely available and  *
 * infinitely modifiable and copyable. As it is with such products, it comes  *
 * with absolutely no warranty. It might even have bugs (!). If so, feel free *
 * to drop a line at the email address above, or visit:                       *
 * https://github.com/valandil/zernike                                        *
 * -------------------------------------------------------------------------- */

#include <zernike_bits/binomial_coefficient.h>

namespace Zernike {

unsigned int binomial_coefficient(unsigned int n,
                                  unsigned int k)
{
  double binom = 1;

  for (unsigned int i=1;i<=k;i++)
  {
    binom *= (double)(n-(k-i))/(double)i;
  }

  return (unsigned int)binom;
}

} // namespace Zernike