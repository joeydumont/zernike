#include <zernike_bits/zernike_radial_poly.h>

namespace Zernike {

double ZernikeRadialPolynomial(unsigned int n,
                               unsigned int m,
                               double r,
                               ZernikeEvaluationMethod eval_method)
{

  if (n<m)
  {
    std::cout << "The Zernike polynomial is undefined if n<m or n-m"
                  "is not even."
              << std::endl;
    return 0.0;
  }

  // Evaluates the Zernike polynomials on the diagonal n=m.
  if (n==m)
  {
    return std::pow(r,n);
  }

  // If the order is low enough, we use hard-coded polynomials.
  if (n<=6)
    return ZernikeRadialPolynomialLowOrder(n,m,r);

  // Otherwise, we use the recursion relation, or the direct approach,
  // as chosen by the user.
  double zernike_value;
  switch (eval_method)
  {
    case direct:
    {
      zernike_value = ZernikeRadialPolynomialDirect(n,m,r);
      break;
    }

    case recursion:
    {
      zernike_value = ZernikeRadialPolynomialRecursion(n,m,r);
      break;
    }

    default:
    {
      std::cout << "ZernikeRadialPolynomial: Specified eval_method not implemented."
                << "Using the recursion method by default."
                << std::endl;
      zernike_value = ZernikeRadialPolynomialRecursion(n,m,r);
      break;
    }
  }

  return zernike_value;
}

double ZernikeRadialPolynomialLowOrder(unsigned int n,
                                       unsigned int m,
                                       double r)
{
  if (n>6)
  {
    std::cout << "ZernikeRadialPolynomialLowOrder: This function implements only polynomials with n < 6." << std::endl;
    std::cerr << "Order n > 6 given in ZernikeRadialPolynomialLowOrder." << std::endl;
    return 0.0;
  }

  if (n==2 && m==0)
    return 2.0*std::pow(r,2)-1.0;

  if (n==3 && m==1)
  {
    return 3.0*std::pow(r,3)-2*r;
  }

  if (n==4)
  {
    if (m==0)
      return 6.0*std::pow(r,4)-6.0*std::pow(r,2)+1.0;

   if (m==2)
      return 4.0*std::pow(r,4)-3.0*std::pow(r,2);
  }

  if (n==5)
  {
    if (m==1)
      return 10.0*std::pow(r,5)-12.0*std::pow(r,3)+3.0*r;

    if (m==3)
      return 5.0*std::pow(r,5)-4.0*std::pow(r,3);
  }

  if (n==6)
  {
    if (m==0)
      return 20.0*std::pow(r,6)-30.0*std::pow(r,4)+12.0*std::pow(r,2)-1.0;

    if (m==2)
      return 15.0*std::pow(r,6)-20.0*std::pow(r,4)+6.0*std::pow(r,2);

    if (m==4)
      return 6.0*std::pow(r,6)-5.0*std::pow(r,4);
  }
}

double ZernikeRadialPolynomialDirect(unsigned int n,
                                     unsigned int m,
                                     double r)
{
  // We set up the recursion relations between the terms in the summation
  // representation of the Zernike polynomials.
  // We compute the first term, which r^m/m!.
  double r_pow  = std::pow(r,m);
  unsigned int npm2      = (n+m)/2;
  unsigned int nmm2      = (n-m)/2;
  double a_k    = std::pow(-1.0,nmm2)*binomial_coefficient(npm2,nmm2);

  double zernike_value = a_k*r_pow;

  for (int k=nmm2-1;k>=0;k--)
  {
    std::cout << "Computing the coefficient for k=" << k << "." << std::endl;
    a_k   *= -(double)((k+1)*(n-k))/(double)((npm2-k)*(nmm2-k));
    r_pow *= std::pow(r,2);
    zernike_value += a_k*r_pow;
  }

  return zernike_value;
}

double ZernikeRadialPolynomialRecursion(unsigned int n,
                                        unsigned int m,
                                        double r)
{
  // We now compute the Zernike polynomials with the recursion relation.
  // We determine the number of diagonals that need to be computed.
  unsigned int ndiags    = (n-m)/2;

  // We determine the last element for which n=m.
  unsigned int nm        = n-(n-m)/2;
  unsigned int diag_size = nm+1;


  // We compute the initial diagonal.
  std::vector<double> zernike_values_old(diag_size,0.0);
  std::vector<double> zernike_values_new(diag_size,0.0);

  for (unsigned int i=0; i<diag_size; i++)
  {
    zernike_values_old[i] = std::pow(r,i);
  }

  --diag_size;

  for (unsigned int i=0; i<ndiags; i++)
  {
    for (unsigned int j=0; j<diag_size; j++)
    {
      if (j==0)
        zernike_values_new[0] = -zernike_values_old[0] + 2.0*r*zernike_values_old[1];

      else
        zernike_values_new[j] = -zernike_values_old[j] + r*(zernike_values_new[j-1]+zernike_values_old[j+1]);
    }

    zernike_values_old = zernike_values_new;
    --diag_size;
  }

  return zernike_values_new[diag_size];
}

} // namespace Zernike
