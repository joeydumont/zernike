#include <iostream>

#include <zernike_bits/zernike_radial_poly.h>

int main(int argc, char* argv[])
{
  std::cout << Zernike::ZernikeRadialPolynomial(6,4,0.5) << std::endl;
  return 0;
}