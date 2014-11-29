#if   defined __STDC_VERSION__ // [
#if   __STDC_VERSION__ == 199409L // [
#error "C 94"
#elif __STDC_VERSION__ == 199901L
#error "C 99"
#elif __STDC_VERSION__ == 201112L
#error "C 11"
#else
#error "unknown C version"
#endif // __STDC_VERSION__ ]
#elif __STDC_VERSION__ == 199901L
#elif defined __cplusplus // __STDC_VERSION__ ]  [
#if   __cplusplus == 1  // [
#error "pre-standard C++"
#elif __cplusplus == 199711L
#error "C++ 98"
#elif __cplusplus > 199711L && __cplusplus < 201103L
#error "C++ 0x"
#elif __cplusplus == 201103L
#error "C++ 11"
#elif __cplusplus > 201103L && __cplusplus < 201402L
#error "C++ 1y"
#elif __cplusplus == 201402L
#error "C++ 14"
#else
#error "unknown C++ version"
#endif // __cplusplus ]
#endif // __cplusplus ]