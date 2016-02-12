#include "Clock.hpp"
#include "Time.hpp"

using namespace h2d;

Clock::Clock()
{
    m_time_point = std::chrono::high_resolution_clock::now();
}

Clock::~Clock()
{}

Time Clock::getTime() const
{
    auto elapsed = std::chrono::high_resolution_clock::now() - m_time_point;
    return Time::nanoseconds(std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count());
}

Time Clock::reset()
{
    auto new_point = std::chrono::high_resolution_clock::now();
    auto elapsed = new_point - m_time_point;
    Time t = Time::nanoseconds(std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count());
    m_time_point = new_point;
    return t;
}
