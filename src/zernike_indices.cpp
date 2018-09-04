/*! ------------------------------------------------------------------------- *
 * This file is part of the Zernike library. It is thus freely available and  *
 * infinitely modifiable and copyable. As it is with such products, it comes  *
 * with absolutely no warranty. It might even have bugs (!). If so, feel free *
 * to drop a line at the email address above, or visit:                       *
 * https://github.com/valandil/zernike                                        *
 * -------------------------------------------------------------------------- */

#include <zernike_bits/zernike_indices.h>

#include <cmath>
#include <vector>
#include <algorithm>

namespace Zernike {

void NaturalToQuantum(const int   j,
                            int & n,
                            int & m)
{
  // The natural indices run from j=1 to j=inf.
  if (j<1)
  {
    std::cout << "Zernike::NaturalToQuantum: The Noll indices run from j=1 to j=inf." << std::endl;
    std::cerr << "Zernike::NaturalToQuantum: Argument error: The natural indices run from j=1 to j=inf." << std::endl;
    return;
  }

  if (j==0)
  {
    n=m=0;
    return;
  }

  int r=1;
  while (j > (r*(r+1))/2)
    r++;

  n=r-1;
  m=r-1-2*(r*(r+1)/2-j);
}

int QuantumToNatural(const int n,
                     const int m)
{
  return (n*(n+1)/2+(m+n)/2+1);
}

/// Since the Noll and Phasics conventions are almost identical, except in their
/// handling of the sign of m, they share quite a lot of code, hence we define a
/// preamble function that does most of the work.
typedef enum e_SignConvention {Noll, Phasics} SignConvention;
static void PreambleToTriangularIndices(const int               j,
                                              int             & n,
                                              int             & m,
                                              SignConvention    method)
{
  // Compute the smallest triangular number larger than j.
  unsigned int triangular_number_idx = std::ceil((1+std::sqrt(1+8*j))/2)-1;
  unsigned int triangular_number     = (int)triangular_number_idx*(triangular_number_idx+1)/2;

  // n is basically the index, but as if started from 0.
  n                         = triangular_number_idx-1;

  // The remainder serves as an index to the value of m in the range
  // of all possible values of m.
  int remainder             = j - triangular_number;
  int remainderpn           = remainder + n;

  std::vector<int> m_vec(n+1);

  for (int i=-n,idx=0; i<=n; i+=2,idx++)
  {
    m_vec[idx] = std::abs(i);
  }

  std::sort(m_vec.begin(), m_vec.end());

  m = std::pow(-1,j%2)*m_vec[remainderpn];

  if (method == Phasics)
    m *= std::pow(-1,triangular_number%2+1);
}

void NollToQuantum(const int    j,
                         int  & n,
                         int  & m)
{
  PreambleToTriangularIndices(j,n,m,Noll);
}

void PhasicsToQuantum(const int j,
                            int &n,
                            int &m)
{
  PreambleToTriangularIndices(j,n,m,Phasics);
}

void OSAToQuantum(const int    j,
                        int  & n,
                        int  & m)
{
  n = (int)std::ceil((-3.0+std::sqrt(9.0+8.0*j))/2.0);
  m = 2*j-n*(n+2);
}

} // namespace Zernike