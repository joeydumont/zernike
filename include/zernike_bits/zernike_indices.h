#ifndef ZERNIKE_INDICES_H
#define ZERNIKE_INDICES_H

#include <iostream>

namespace Zernike {

void          NaturalToQuantum(unsigned int   j,
                               unsigned int & n,
                               int          & m);


unsigned int QuantumToNatural(unsigned int n,
                              int          m);

//void         NollToQuantum   (unsigned int   j,
//                              unsigned int & n,
//                              int          & m);
//
//unsigned int QuantumToNoll   (unsigned int n,
//                              int m);

} // namespace Zernike

#endif // ZERNIKE_INDICES_H
