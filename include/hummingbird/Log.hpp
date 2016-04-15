#ifndef HUM_LOG_HPP
#define HUM_LOG_HPP
#include <string>
#include <iostream>

namespace hum
{
inline void assert_msg(bool condition, const char* message)
{
#ifndef NDEBUG
    if (!condition)
    {
        std::cerr << "Assertion failed in " << __FILE__
                    << " line " << __LINE__ << ": " << message << std::endl;
        std::exit(EXIT_FAILURE);
    }
#endif
}

inline void assert_msg(bool condition, const std::string& message)
{
#ifndef NDEBUG
    if (!condition)
    {
        std::cerr << "Assertion failed in " << __FILE__
                    << " line " << __LINE__ << ": " << message << std::endl;
        std::exit(EXIT_FAILURE);
    }
#endif
}

inline void log_d(const char* message)
{
#ifndef NDEBUG
    std::cout << message << std::endl;
#endif
}

inline void log_d(const std::string& message)
{
#ifndef NDEBUG
    std::cout << message << std::endl;
#endif
}

inline void log(const char* message)
{
    std::cout << message << std::endl;
}

inline void log(const std::string& message)
{
    std::cout << message << std::endl;
}

inline void log_e(const char* message)
{
    std::cerr << message << std::endl;
}

inline void log_e(const std::string& message)
{
    std::cerr << message << std::endl;
}
}
#endif
