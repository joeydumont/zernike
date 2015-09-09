#include <zernike_bits/zernike_indices.h>

namespace Zernike {

void NaturalToQuantum(unsigned int j,
                      unsigned int & n,
                      int & m)
{
  // The Noll indices run from j=1 to j=inf.
  if (j<1)
  {
    std::cout << "Zernike::NollToQuantum: The Noll indices run from j=1 to j=inf." << std::endl;
    std::cerr << "Zernike::NollToQuantum: Argument error: The Noll indices run from j=1 to j=inf." << std::endl;
    return;
  }

  if (j==0)
  {
    n=m=0;
    return;
  }

  unsigned int r=1;
  while (j > (r*(r+1))/2)
    r++;

  n=r-1;
  m=r-1-2*(r*(r+1)/2-j);
}

unsigned int QuantumToNatural(unsigned int n,
                              int m)
{
  return (n*(n+1)/2+(m+n)/2+1);
}

} // namespace Zernike