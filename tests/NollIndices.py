# ------------------------------- Information ------------------------------- #
# Author:       Joey Dumont                    <joey.dumont@gmail.com>        #
# Created:      Aug. 31st, 2018                                               #
# Description:  We try to compute the quantum indices from the Noll single    #
#               index convention for the Zernike polynomials.                 #
# --------------------------------------------------------------------------- #

import numpy as np

# The Noll indices are related to the A176988 OIES sequence. The rule is that
# odd j indices correspond to negative values of m, and even j to positive
# values of m, and larger values of j correspond to larger values of |m|
# within a row.

# The strategy is to find the smallest triangular number that is larger than
# the given index j, and identify the reminder r. In short, we write the index
# as
#       j = T_k - r
# where k is the smallest possible k such that T_k > j. We can use that to
# identity what cell oft the triangle of possible quantum indices (m,n) the
# index points to.

def NollToQuantumTest(j):
    """
    """
    indices = np.array(np.ceil((1+np.sqrt(1+8*j))/2),dtype=int)-1
    triangular_numbers = np.array(indices*(indices+1)/2).astype(int)
    n = indices - 1

    r     = j - triangular_numbers
    rpn   = r+n
    m     = np.zeros_like(n)

    # -- Have to work value-per-value here.
    for i in range(n.size):
        m_vec = np.array([j for j in range(-n[i],n[i]+2,2)])
        m_vec = np.sort(np.abs(m_vec))
        test     = (-1)**(j[i]%2)*m_vec[rpn[i]]
        print(test)
        m[i] = test

    #m = np.array([i for i in range(n,-n-2,-2)], dtype=int)
    #m_ind = np.argsort((m))
    #m = m[m_ind[::-1]]

    return indices, triangular_numbers, n, r,m#, (-1)**(n%2)*m[r]


#for j in range(1,21):
#    indices, triangular_numbers, n, r, m = NollToQuantumTest(j)
#    print(indices,triangular_numbers,j,n,m)

j_vec = np.array([j for j in range(1,21)], dtype=int)
indices, triangular_numbers, n,r,m = NollToQuantumTest(j_vec)

for i in range(j_vec.size):
    print(j_vec[i], n[i], m[i])

