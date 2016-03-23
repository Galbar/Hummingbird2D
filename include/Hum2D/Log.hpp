#ifndef H2D_LOG_HPP
#define H2D_LOG_HPP
#include <iostream>

#ifndef NDEBUG
    #define h2d_assert(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                        << " line " << __LINE__ << ": " << message << std::endl; \
            std::exit(EXIT_FAILURE); \
        } \
    } while (false)
#else
    #define h2d_assert(condition, message) do { } while (false)
#endif

#ifndef NDEBUG
    #define h2d_log_d(message) \
    do { \
        std::cout << message << std::endl; \
    } while (false)
#else
    #define h2d_log_d(message) do { } while (false)
#endif

#define h2d_log(message) \
do { \
    std::cout << message << std::endl; \
} while (false)

#define h2d_log_e(message) \
do { \
    std::cerr << message << std::endl; \
} while (false)

#endif
