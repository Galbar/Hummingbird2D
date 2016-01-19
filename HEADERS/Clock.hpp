#ifndef HB_CLOCK_H
#define HB_CLOCK_H
#include <chrono>

namespace h2d
{
class Time;
class Clock
{
public:
    Clock();
    ~Clock();
    Time getTime() const;
    Time reset();

private:
    std::chrono::high_resolution_clock::time_point m_time_point;
};
}
#endif
