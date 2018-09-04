/*! ------------------------------------------------------------------------- *
 * Author:       Joey Dumont                   <joey.dumont@gmail.com>        *
 * Date:         2015-09-11                                                   *
 * Description:  Conversions between double-index and single-index schemes.   *
 * License:      CC0 - Public Domain.                                         *
 *                                                                            *
 * This file is part of the Zernike library. It is thus freely available and  *
 * infinitely modifiable and copyable. As it is with such products, it comes  *
 * with absolutely no warranty. It might even have bugs (!). If so, feel free *
 * to drop a line at the email address above, or visit:                       *
 * https://github.com/valandil/zernike                                        *
 * -------------------------------------------------------------------------- */

#ifndef ZERNIKE_INDICES_H
#define ZERNIKE_INDICES_H

#include <iostream>

namespace Zernike {

/*! @name Natural Single-Index Scheme
 * These functions implement a "natural" way to enumerate the Zernike
 * polynomials. For a given n value, the m index is in the range [-n,n], in
 * steps of 2. A natural single-index enumeration is thus monotonic in n, and
 * monotonic in m for each n. On a triangle, we would place the nth polynomials
 * in the nth row, and the columns would start at m=-n to m=n.
 */
///@{
/// Implements the single-index to double-index ("quantum") conversion.
///   @param[in]  j  Natural single-index.
///   @param[out] n  Principal quantum number converted from natural.
///   @param[out] m  Angular momentum quantum number converted from natural.
void          NaturalToQuantum(const int     j,
                                     int   & n,
                                     int   & m);

/// Implements the double-index ("quantum") to single-index conversion.
///   @param[in]  n  Principal quantum number to be converted.
///   @param[in]  m  Angular momentum quantum number to be converted.
///   @retval     j  Natural single-index.
int           QuantumToNatural(const int n,
                               const int m);
///@}


/*! name Noll Single-Index Scheme
 * These functions implement a standard way to enumerate the Zernike polynomials
 * with a single index: the Noll scheme. This scheme, as the natural scheme, is
 * monotonic in n, but monotonic in |m|. In a given row, the relative order of
 * positive and negative m polynomials is decided by the rule that negative m
 * polynomials must be given odd single indices. This leads to slightly more
 * complicated conversion formulas.
 */
///@{
/// Implements the Noll single-index to double-index conversion.
///   @param[in]  j  Noll single-index.
///   @param[out] n  Principal quantum number converted from Noll.
///   @param[out] m  Angular momentum quantum number converted from Noll.
void         NollToQuantum    (const int   j,
                                     int & n,
                                     int & m);
///@}

/// Implements the double-index ("quantum") to single-index (Noll) conversion.
///   @param[in]  n  Principal quantum number to be converted.
///   @param[in]  m  Angular momentum quantum number to be converted.
///   @retval     j  Natural single-index.
//unsigned int QuantumToNoll   (unsigned int n,
//                              int m);

void         PhasicsToQuantum(const int    j,
                                    int  & n,
                                    int  & m);

/// Converts from the OSA/ANSI standard to the quantum values.
/// http://voi.opt.uh.edu/2000-JRS-standardsforrepotingtheopticalaberrationsofeyes.pdf
void         OSAToQuantum     (const int    j,
                                     int  & n,
                                     int  & m);


} // namespace Zernike

#endif // ZERNIKE_INDICES_H
