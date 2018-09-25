# ------------------------------- Information ------------------------------- #
# Author:       Joey Dumont                    <joey.dumont@gmail.com>        #
# Created:      Aug. 31st, 2018                                               #
# Description:  We try to compute the quantum indices from the Noll single    #
#               index convention for the Zernike polynomials.                 #
# --------------------------------------------------------------------------- #

import numpy as np
import time
import dis

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
    indices = np.array(np.array(np.ceil((1+np.sqrt(1+8*j))/2),dtype=int)-1,dtype=int)
    triangular_numbers = np.array(indices*(indices+1)/2).astype(int)
    n = np.array((indices - 1),dtype=int)

    r     = j - triangular_numbers
    rpn   = r+n
    m     = np.zeros_like(n)

    # -- Have to work value-per-value here.
    for i in range(n.size):
        m_vec = np.array([j for j in range(-n[i],n[i]+2,2)],dtype=int)
        m_vec = np.sort(np.abs(m_vec))
        m[i]  = (-1)**(j[i]%2)*m_vec[rpn[i]]

    return n, m

def PhasicsToQuantum(j):
    indices = np.array(np.array(np.ceil((1+np.sqrt(1+8*j))/2),dtype=int)-1,dtype=int)
    triangular_numbers = np.array(indices*(indices+1)/2).astype(int)
    n = np.array((indices - 1),dtype=int)

    r     = j - triangular_numbers
    rpn   = r+n
    m     = np.zeros_like(n)

    # -- Have to work value-per-value here.
    for i in range(n.size):
        m_vec = np.array([j for j in range(-n[i],n[i]+2,2)],dtype=int)
        m_vec = np.sort(np.abs(m_vec))
        m[i]  = (-1)**(triangular_numbers[i]%2+1)*(-1)**(j[i]%2)*m_vec[rpn[i]]

    return n, m

def NollToQuantumFaster(j):
    indices = np.array(np.ceil((1+np.sqrt(1+8*j))/2),dtype=int)-1
    triangular_numbers = np.array(indices*(indices+1)/2).astype(int)
    n = indices -1

    r = j - triangular_numbers
    r +=n
    m = (-1)**j * ((n % 2) + 2 * np.array((r + ((n+1)%2))/2).astype(int))

    return n,m

def NollToQuantumLoop(j):
    n = np.empty((j.size))
    m = np.empty((j.size))
    for i in range(j.size):
        n[i] = 0
        j1 = j[i]-1
        while (j1 > n[i]):
            n[i] += 1
            j1 -= n[i]

        m[i] = (-1)**j[i] * ((n[i] % 2) + 2 * int((j1+((n[i]+1)%2)) / 2.0 ))
    return n, m

#for j in range(1,21):
#    indices, triangular_numbers, n, r, m = NollToQuantumTest(j)
#    print(indices,triangular_numbers,j,n,m)

j_vec          = np.array([j for j in range(1,51)], dtype=int)
n_noll,m_noll           = NollToQuantumTest(j_vec)
n_phasics,m_phasics = PhasicsToQuantum(j_vec)
n_fast, m_fast = NollToQuantumFaster(j_vec)
n_loop, m_loop  = NollToQuantumLoop(j_vec)



time_start = time.perf_counter()

ntries = 1000
for i in range(ntries):
    n,m = NollToQuantumTest(j_vec)

time_end = time.perf_counter()

print("NollToQuantumTest time: {}", time_end-time_start)


for i in range(ntries):
    n,m = NollToQuantumFaster(j_vec)

time_end = time.perf_counter()

print("NollToQuantumFaster time: {}", time_end-time_start)

for i in range(ntries):
    n,m = NollToQuantumLoop(j_vec)

time_end = time.perf_counter()

print("NollToQuantumLoop time: {}", time_end-time_start)

# ------ Print markdown table.
print("| $$j$$ | Noll | Phasics |")

for i in range(j_vec.size):
    print("| $${}$$ | $$({:d},{:d})$$ | $$({:d},{:d})$$ |".format(i+1,n_noll[i],m_noll[i],n_phasics[i],m_phasics[i]))
