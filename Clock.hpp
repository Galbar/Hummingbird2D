#ifndef HB_CLOCK_H
#define HB_CLOCK_H
#include <chrono>
#include "Time.hpp"

namespace h2d
{
class Clock
{
public:
	Clock()
	{
		m_time_point = std::chrono::high_resolution_clock::now();
	}

	~Clock()
	{}

	Time getTime() const
	{
		auto elapsed = std::chrono::high_resolution_clock::now() - m_time_point;
		return Time::microseconds(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());
	}

	Time reset()
	{
		Time t = getTime();
		m_time_point = std::chrono::high_resolution_clock::now();
		return t;
	}

private:
	std::chrono::high_resolution_clock::time_point m_time_point;
};
}
#endif
