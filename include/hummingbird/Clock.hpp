#ifndef HUM_CLOCK_H
#define HUM_CLOCK_H
#include <chrono>

namespace hum
{
class Time;
class Clock
{
public:
    /*!
      \brief Class constructor.
      Initializes a new instance of Clock which starts measuring
      the time as it is created.
    */
    Clock();

    /*!
      \brief Class destructor.
      Destroys the instance of Clock.
    */
    ~Clock();

    /*!
      \brief Returns the Time elapsed since creation or last reset.
      \return Time since instance creation or last reset().
    */
    Time getTime() const;

    /*!
      \brief Restarts the Time counter.

      This function also returns the Time since instance creation or last reset().
      This is usefull for getting precise delta times without having
      time overhead for having to call two methods:
      \code
      hum::Clock clk;
      while(game_is_running)
      {
          hum::Time deltaTime = clk.reset();
          ... // Game code
      }
      \endcode
      \return Time since instance creation or last reset().
    */
    Time reset();

private:
    std::chrono::high_resolution_clock::time_point m_time_point;
};

/*!
  \class hum::Clock
  \brief Class for measuring intervals of time.
*/
}
#endif
