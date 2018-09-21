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

#include <zernike_bits/zernike_indices.h>

class NollToQuantumTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        // Source: https://oeis.org/A176988
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(1, {0,0}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(2, {1,1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(3, {1,-1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(4, {2,0}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(5, {2,-2}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(6, {2,2}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(7, {3,-1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(8, {3,1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(9, {3,-3}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(10, {3,3}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(11, {4,0}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(12, {4,2}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(13, {4,-2}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(14, {4,4}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(15, {4,-4}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(16, {5,1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(17, {5,-1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(18, {5,3}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(19, {5,-3}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(20, {5,5}));

    }

    const int j_max = 21;
    int n,m;

    std::map<int,std::pair<int,int>> ReferenceIndexValues;
};

TEST_F(NollToQuantumTest, IndexValuesAgainstReference)
{
    for (auto element : ReferenceIndexValues)
    {
        Zernike::NollToQuantum(element.first,n,m);

        EXPECT_EQ(element.second.first,n);
        EXPECT_EQ(element.second.second,m);
    }
}

class PhasicsToQuantumTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        // Source: Phasics Manual, p.124.
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(1, {0,0}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(2, {1,1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(3, {1,-1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(4, {2,0}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(5, {2,2}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(6, {2,-2}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(7, {3,1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(8, {3,-1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(9, {3,3}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(10, {3,-3}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(11, {4,0}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(12, {4,2}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(13, {4,-2}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(14, {4,4}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(15, {4,-4}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(16, {5,1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(17, {5,-1}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(18, {5,3}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(19, {5,-3}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(20, {5,5}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(21, {5,-5}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(22, {6,0}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(23, {6,2}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(24, {6,-2}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(25, {6,4}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(26, {6,-4}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(27, {6,6}));
        ReferenceIndexValues.insert ( std::pair<int, std::pair<int,int>>(28, {6,-6}));

    }

    std::map<int,std::pair<int,int>> ReferenceIndexValues;
    int n,m;
};

TEST_F(PhasicsToQuantumTest, IndexValuesAgainstReference)
{
    for (auto&& element : ReferenceIndexValues)
    {
        Zernike::PhasicsToQuantum(element.first, n,m);

        EXPECT_EQ(element.second.first, n);
        EXPECT_EQ(element.second.second,m);
    }

    int n_noll,m_noll;
    for (int j=1; j<50; j++)
    {
        Zernike::NollToQuantum(j,n,m);
        n_noll = n;
        m_noll = m;

        Zernike::PhasicsToQuantum(j,n,m);

        std::cout << "Noll: "    << j << " " << n_noll << " " << m_noll << "\t";
        std::cout << "Phasics: " << j << " " << n      << " " << m << "\n";

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
