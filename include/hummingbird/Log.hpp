#ifndef HUM_LOG_HPP
#define HUM_LOG_HPP
#include <string>
#include <sstream>
#include <iostream>
#include "hum.hpp"

namespace hum
{
namespace detail
{
// Declarations to allow for recursivity
template <typename T, typename... TT>
inline void log(std::ostream& out, const hum::Vector2<T>& vector, const TT&... tt);
template <typename T, typename... TT>
inline void log(std::ostream& out, const hum::Vector3<T>& vector, const TT&... tt);
template <typename... TT>
inline void log(std::ostream& out, const hum::Transformation& transform, const TT&... tt);
template <typename... TT>
inline void log(std::ostream& out, const hum::Time& time, const TT&... tt);
template <typename... TT>
inline void log(std::ostream& out, const hum::Clock& clock, const TT&... tt);


// Template recursion base case
inline void log(std::ostream& out)
{}

// The method that actually prints everything
template <typename T, typename... TT>
inline void log(std::ostream& out, const T& message, const TT&... tt)
{
    out << message;
    detail::log(out, tt...);
}

template <typename T, typename... TT>
inline void log(std::ostream& out, const hum::Vector2<T>& vector, const TT&... tt)
{
    detail::log(out, "hum::Vector2( ", vector.x, ", ", vector.y, " )", tt...);
}

template <typename T, typename... TT>
inline void log(std::ostream& out, const hum::Vector3<T>& vector, const TT&... tt)
{
    detail::log(out, "hum::Vector3( ", vector.x, ", ", vector.y, ", ", vector.z, " )", tt...);
}

template <typename... TT>
inline void log(std::ostream& out, const hum::Transformation& transform, const TT&... tt)
{
    detail::log(out, "hum::Transformation ( ", "position=", transform.position,
            "; rotation=", transform.rotation, "; scale=", transform.scale, " )", tt...);
}

template <typename... TT>
inline void log(std::ostream& out, const hum::Time& time, const TT&... tt)
{
    detail::log(out, "hum::Time ( ", time.asMilliseconds(), " ms )", tt...);
}

template <typename... TT>
inline void log(std::ostream& out, const hum::Clock& clock, const TT&... tt)
{
    detail::log(out, "hum::Clock ( ", clock.getTime().asMilliseconds(), " ms )", tt...);
}
} /* detail */

/*!
  \brief Check a condition and if it fails, exit the program and print the
  message.

  This method does nothing if NDEBUG is defined.

  Usage example:
  \code
  hum::assert_msg(player_x > 64, "Player is outside of the map! x=", player_x);
  \endcode
*/
template <typename... TT>
inline void assert_msg(bool condition, const TT&... tt)
{
#ifndef NDEBUG
    if (!condition)
    {
        detail::log(std::cerr, "Assertion failed in ", __FILE__, " line ", __LINE__, ": ", tt...);
        std::cerr << std::endl;
        std::exit(EXIT_FAILURE);
    }
#endif
}

/*!
  \brief Print a message to the standard output.

  T can be any type that has the operator << overloaded.
  It can also be any of the following classes:
  \li hum::Vector2
  \li hum::Vector3
  \li hum::Transformation
  \li hum::Time
  \li hum::Clock

  Usage example:
  \code
  hum::log("Player position: ", actor().transform().position);
  \endcode
*/
template <typename T, typename... TT>
inline void log(const T& message, const TT&... tt)
{
    detail::log(std::cout, message, tt...);
    std::cout << std::endl;
}

/*!
  \brief Print a message to the error output.

  T can be any type that has the operator << overloaded.
  It can also be any of the following classes:
  \li hum::Vector2
  \li hum::Vector3
  \li hum::Transformation
  \li hum::Time
  \li hum::Clock

  Usage example:
  \code
  hum::log_e("Player position: ", actor().transform().position);
  \endcode
*/
template <typename T, typename... TT>
inline void log_e(const T& message, const TT&... tt)
{
    detail::log(std::cerr, message, tt...);
    std::cerr << std::endl;
}

/*!
  \brief Print a message to the standard output.

  This method does nothing if NDEBUG is defined.

  T can be any type that has the operator << overloaded.
  It can also be any of the following classes:
  \li hum::Vector2
  \li hum::Vector3
  \li hum::Transformation
  \li hum::Time
  \li hum::Clock

  Usage example:
  \code
  hum::log_d("Player position: ", actor().transform().position);
  \endcode
*/
template <typename T, typename... TT>
inline void log_d(const T& message, const TT&... tt)
{
#ifndef NDEBUG
    log(message, tt...);
#endif
}
}
#endif
