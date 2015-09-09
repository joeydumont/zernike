#include <iostream>

#include <zernike_bits/zernike_noll.h>
#include <zernike_bits/zernike_poly.h>
#include <zernike_bits/zernike_radial_poly.h>
#include <zernike_bits/binomial_coefficient.h>

int main(int argc, char* argv[])
{
  enum Zernike::ZernikeEvaluationMethod method = Zernike::direct;
  std::cout << Zernike::ZernikeRadialPolynomial(6,4,0.5) << std::endl;
  std::cout << Zernike::ZernikeRadialPolynomial(6,4,0.5,method) << std::endl;
  std::cout << Zernike::binomial_coefficient(20,3) << std::endl;

  unsigned int n;
  int m;
  Zernike::NollToQuantum(11,n,m);
  std::cout << "[n, m]: " << n << ", " << m << std::endl;

  return 0;
}
