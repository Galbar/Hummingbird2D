#include "Time.hpp"
#include <iostream>

using namespace h2d;

Time::Time():
m_nanoseconds(0)
{}

Time::Time(const Time& other):
m_nanoseconds(other.m_nanoseconds)
{}

Time::~Time()
{}

double Time::asSeconds() const
{
    return (double)m_nanoseconds/1e9;
}

double Time::asMilliseconds() const
{
    return (double)m_nanoseconds/1e6;
}

double Time::asMicroseconds() const
{
    return (double)m_nanoseconds/1e3;
}

long Time::asNanoseconds() const
{
    return m_nanoseconds;
}

Time Time::seconds(double seconds)
{
    Time t;
    t.m_nanoseconds = (long)(seconds * 1e9);
    return t;
}

Time Time::milliseconds(double milliseconds)
{
    Time t;
    t.m_nanoseconds = milliseconds * 1e6;
    return t;
}

Time Time::microseconds(double microseconds)
{
    Time t;
    t.m_nanoseconds = microseconds * 1e3;
    return t;
}

Time Time::nanoseconds(long nanoseconds)
{
    Time t;
    t.m_nanoseconds = nanoseconds;
    return t;
}

Time& Time::operator+=(const Time& other)
{
    m_nanoseconds += other.m_nanoseconds;
    return *this;
}

Time& Time::operator-=(const Time& other)
{
    m_nanoseconds -= other.m_nanoseconds;
    return *this;
}

Time& Time::operator*=(double other)
{
    m_nanoseconds *= other;
    return *this;
}

Time& Time::operator*=(long other)
{
    m_nanoseconds *= other;
    return *this;
}

Time& Time::operator/=(double other)
{
    m_nanoseconds /= other;
    return *this;
}

Time& Time::operator/=(long other)
{
    m_nanoseconds /= other;
    return *this;
}

Time& Time::operator%=(const Time& other)
{
    m_nanoseconds %= other.m_nanoseconds;
    return *this;
}

Time operator-(Time right)
{
    return Time::microseconds(-right.asNanoseconds());
}

bool operator==(const Time& left, const Time& right)
{
    return left.asNanoseconds() == right.asNanoseconds();
}

bool operator!=(const Time& left, const Time& right)
{
    return left.asNanoseconds() != right.asNanoseconds();
}

bool operator<(const Time& left, const Time& right)
{
    return left.asNanoseconds() < right.asNanoseconds();
}

bool operator>(const Time& left, const Time& right)
{
    return left.asNanoseconds() > right.asNanoseconds();
}

bool operator<=(const Time& left, const Time& right)
{
    return left.asNanoseconds() <= right.asNanoseconds();
}

bool operator>=(const Time& left, const Time& right)
{
    return left.asNanoseconds() >= right.asNanoseconds();
}

Time operator+(Time left, const Time& right)
{
    return left += right;
}

Time operator-(Time left, const Time& right)
{
    return left -= right;
}

Time operator*(Time left, double right)
{
    return left *= right;
}

Time operator*(Time left, long right)
{
    return left *= right;
}

Time operator*(double left, Time right)
{
    return right *= left;
}

Time operator*(long left, Time right)
{
    return right *= left;
}

Time operator/(Time left, double right)
{
    return left /= right;
}

Time operator/(Time left, long right)
{
    return left /= right;
}

double operator/(const Time& left, const Time& right)
{
    return (double)left.asNanoseconds() / (double)right.asNanoseconds();
}

Time operator%(Time left, const Time& right)
{
    return left %= right;
}
