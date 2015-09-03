#include <iostream>

#include <zernike_bits/zernike_poly.h>
#include <zernike_bits/zernike_radial_poly.h>
#include <zernike_bits/binomial_coefficient.h>

int main(int argc, char* argv[])
{
  enum Zernike::ZernikeEvaluationMethod method = Zernike::direct;
  std::cout << Zernike::ZernikeRadialPolynomial(6,4,0.5) << std::endl;
  std::cout << Zernike::ZernikeRadialPolynomial(6,4,0.5,method) << std::endl;
  std::cout << Zernike::binomial_coefficient(20,3) << std::endl;

  double dr     = 1.0/10000.0;
  double dtheta = (2.0*3.14159)/10000.0;
  double sum    = 0.0;

  for (unsigned int i=0; i<10000; i++)
  {
    for (unsigned int j=0; j<10000; j++)
    {
      sum += i*dr*Zernike::ZernikePolynomial(11,-1,i*dr,j*dtheta)
                 *Zernike::ZernikePolynomial(11,1,i*dr,j*dtheta)
                 *dr*dtheta;
    }
  }

  std::cout << sum << std::endl;
  return 0;
}
