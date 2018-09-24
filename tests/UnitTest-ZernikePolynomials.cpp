/*! ------------------------------------------------------------------------- *
 * This file is part of the Zernike library. It is thus freely available and  *
 * infinitely modifiable and copyable. As it is with such products, it comes  *
 * with absolutely no warranty. It might even have bugs (!). If so, feel free *
 * to drop a line at the email address above, or visit:                       *
 * https://github.com/valandil/zernike                                        *
 * -------------------------------------------------------------------------- */

#include <gtest/gtest.h>

#include <iostream>
#include <map>
#include <array>
#include <zernike>
#include <armadillo>
#include <sstream>

class ZernikePolynomialTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        rho = arma::linspace<arma::vec>(0.0,1.0,rho_size);
        theta = arma::linspace<arma::vec>(0.0,6.28,theta_size);
        zernike_polynomials.set_size(rho_size,theta_size,j_max+1);

        int n,m;

        for (int i=1; i<=j_max;i++)
        {
            Zernike::NollToQuantum(i,n,m);

            for (int rho_idx = 0; rho_idx < rho_size; rho_idx++)
            {
                for (int theta_idx = 0; theta_idx < theta_size; theta_idx++)
                {
                    zernike_polynomials(rho_idx,theta_idx,i-1) = Zernike::ZernikePolynomial(n,m,rho(rho_idx),theta(theta_idx));
                }
            }
        }

    }

    const int        j_max      = 30;          ///< Largest Zernike polynomial to plot.
    const int        rho_size   = 250;
    const int        theta_size = 250;
          arma::vec  rho;                 ///< Values of rho between 0 and 1.
          arma::vec  theta;               ///< Values of theta between 0 and 2*pi.
          arma::cube zernike_polynomials; /// Values of the Zernike polynomials.

};

TEST_F(ZernikePolynomialTest, UnitCirclePlot)
{
    // Compare then against manually inputed values.

    // Output the slices.
    for (int slice_idx = 0; slice_idx <= j_max; slice_idx++)
    {
        std::stringstream ss;
        ss << "zernike-" << slice_idx+1 << ".dat";
        zernike_polynomials.slice(slice_idx).save(ss.str(), arma::raw_ascii);

    }
}

class ZernikeAberrationsTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        rho   = arma::linspace<arma::vec>(0.0,1.0,rho_size);
        theta = arma::linspace<arma::vec>(0.0,6.28,theta_size);
        zernike_polynomials.set_size(rho_size,theta_size,j_max+1);

        for (int i = 0; i <= j_max; i++)
        {
            std::vector<double> j(j_max+1);
            j[i] = 1.0;

            for (int rho_idx = 0; rho_idx < rho_size; rho_idx++)
            {
                for (int theta_idx = 0; theta_idx < theta_size; theta_idx++)
                {
                    zernike_polynomials(rho_idx,theta_idx,i) = Zernike::ZernikeAberrations(j,rho(rho_idx),theta(theta_idx));
                }
            }
        }
    }

    const int        j_max                = 30;
    const int        rho_size             = 250;
    const int        theta_size           = 250;
          arma::vec  rho;
          arma::vec  theta;
          arma::cube zernike_polynomials;

};

TEST_F(ZernikeAberrationsTest, UnitCirclePlot)
{
    // Output the coordinates.
    rho.save("rho.dat",arma::raw_ascii);
    theta.save("theta.dat",arma::raw_ascii);

    // Output the slices.
    for (int slice_idx = 0; slice_idx <= j_max; slice_idx++)
    {
        std::stringstream ss;
        ss << "zernike-aberrations-" << slice_idx+1 << ".dat";
        zernike_polynomials.slice(slice_idx).save(ss.str(),arma::raw_ascii);
    }
}

GTEST_API_ int main (int argc, char* argv[])
{
 // Library initalization
 printf("Running %s .\n" , __FILE__);
 testing::InitGoogleTest(&argc, argv);
 auto result = RUN_ALL_TESTS();
 return result;
}
