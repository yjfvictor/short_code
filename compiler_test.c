#if defined _MSC_VER
#if   _MSC_VER == 800 // [
#error "Microsoft Visual C++ 1.0"
#elif _MSC_VER == 900
#error "Microsoft Visual C++ 3.0"
#elif _MSC_VER == 1000
#error "Microsoft Visual C++ 4.0"
#elif _MSC_VER == 1020
#error "Microsoft Visual C++ 4.2"
#elif _MSC_VER == 1100
#error "Microsoft Visual C++ 5.0"
#elif _MSC_VER == 1200
#error "Microsoft Visual C++ 6.0"
#elif _MSC_VER == 1300
#error "Microsoft Visual C++ 7.0 (Microsoft Visual Studio 2002)"
#elif _MSC_VER == 1310
#error "Microsoft Visual C++ 7.1 (Microsoft Visual Studio 2003)"
#elif _MSC_VER == 1400
#error "Microsoft Visual C++ 8.0 (Microsoft Visual Studio 2005)"
#elif _MSC_VER == 1500
#error "Microsoft Visual C++ 9.0 (Microsoft Visual Studio 2008)"
#elif _MSC_VER == 1600
#error "Microsoft Visual C++ 10.0 (Microsoft Visual Studio 2010)"
#elif _MSC_VER == 1700
#error "Microsoft Visual C++ 11.0 (Microsoft Visual Studio 2012)"
#elif _MSC_VER == 1800
#error "Microsoft Visual C++ 12.0 (Microsoft Visual Studio 2013)"
#else
#error "Microsoft Visual C++ unknown version"
#endif // _MSC_VER ]
#elif defined __GNUC__
#if   __GNUC__ == 1 // [
#error "GCC 1.x"
#elif __GNUC__ == 2
#error "GCC 2.x"
#elif __GNUC__ == 3
#error "GCC 3.x"
#elif __GNUC__ == 4
#if     __GNUC_MINOR__ == 1 // [
#error "GCC 4.1"
#elif   __GNUC_MINOR__ == 2
#error "GCC 4.2"
#elif   __GNUC_MINOR__ == 3
#error "GCC 4.3"
#elif   __GNUC_MINOR__ == 4
#error "GCC 4.4"
#elif   __GNUC_MINOR__ == 5
#error "GCC 4.5"
#elif   __GNUC_MINOR__ == 6
#error "GCC 4.6"
#elif   __GNUC_MINOR__ == 7
#error "GCC 4.7"
#elif   __GNUC_MINOR__ == 8
#error "GCC 4.8"
#elif   __GNUC_MINOR__ == 9
#error "GCC 4.9"
#else
#error "GCC 4.x"
#endif // __GNUC_MINOR__ ]
#elif __GNUC__ == 5
#error "GCC 5.x"
#else
#error "GCC unknown version"
#endif // __GNUC__ ]
#elif defined __clang__
#if   __clang_major__ == 1  // [
#error "Clang 1.x"
#elif __clang_major__ == 2
#error "Clang 2.x"
#elif __clang_major__ == 3
#if   __clang_minor__ == 1 // [
#error "Clang 3.1"
#elif __clang_minor__ == 2
#error "Clang 3.2"
#elif __clang_minor__ == 3
#error "Clang 3.3"
#elif __clang_minor__ == 4
#error "Clang 3.4"
#elif __clang_minor__ == 5
#error "Clang 3.5"
#elif __clang_minor__ == 6
#error "Clang 3.6"
#elif __clang_minor__ == 7
#error "Clang 3.7"
#elif __clang_minor__ == 8
#error "Clang 3.8"
#elif __clang_minor__ == 9
#error "Clang 3.9"
#else
#error "Clang 3.x"
#endif // __clang_minor__ ]
#else
#error "Clang unknown version"
#endif  // __clang_major__ ]
#else
#error "Other Compiler"
#endif
