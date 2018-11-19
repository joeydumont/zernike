/*! ------------------------------------------------------------------------- *
* This file is part of the Zernike library. It is thus freely available and  *
* infinitely modifiable and copyable. As it is with such products, it comes  *
* with absolutely no warranty. It might even have bugs (!). If so, feel free *
* to drop a line at the email address above, or visit:                       *
* https://github.com/valandil/zernike                                        *
* -------------------------------------------------------------------------- */

#ifndef ZERNIKE_GLOBAL_H
#define ZERNIKE_GLOBAL_H

#if defined(_WIN32)
#define ZERNIKE_DECL_EXPORT __declspec(dllexport)
#define ZERNIKE_DECL_IMPORT __declspec(dllimport)
#else
#define ZERNIKE_DECL_EXPORT __attribute__((visibility("default")))
#define ZERNIKE_DECL_IMPORT __attribute__((visibility("default")))
#endif
#ifdef ZERNIKE_EXPORTS
#define ZERNIKE_API ZERNIKE_DECL_EXPORT
#elif defined(ZERNIKE_STATIC)
#define ZERNIKE_API
#else
#define ZERNIKE_API ZERNIKE_DECL_IMPORT
#endif

#endif // ZERNIKE_GLOBAL_H