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

}