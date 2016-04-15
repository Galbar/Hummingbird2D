#include "Time.hpp"

using namespace hum;

Time::Time():
m_nanoseconds(0)
{}

Time::Time(const Time& other):
m_nanoseconds(other.m_nanoseconds)
{}

Time::~Time()
{}

float Time::asSeconds() const
{
    return (float)m_nanoseconds/1e9;
}

float Time::asMilliseconds() const
{
    return (float)m_nanoseconds/1e6;
}

float Time::asMicroseconds() const
{
    return (float)m_nanoseconds/1e3;
}

long Time::asNanoseconds() const
{
    return m_nanoseconds;
}

Time Time::seconds(float seconds)
{
    Time t;
    t.m_nanoseconds = (long)(seconds * 1e9);
    return t;
}

Time Time::milliseconds(float milliseconds)
{
    Time t;
    t.m_nanoseconds = milliseconds * 1e6;
    return t;
}

Time Time::microseconds(float microseconds)
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

Time& Time::operator*=(float other)
{
    m_nanoseconds *= other;
    return *this;
}

Time& Time::operator*=(long other)
{
    m_nanoseconds *= other;
    return *this;
}

Time& Time::operator/=(float other)
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

Time operator*(Time left, float right)
{
    return left *= right;
}

Time operator*(Time left, long right)
{
    return left *= right;
}

Time operator*(float left, Time right)
{
    return right *= left;
}

Time operator*(long left, Time right)
{
    return right *= left;
}

Time operator/(Time left, float right)
{
    return left /= right;
}

Time operator/(Time left, long right)
{
    return left /= right;
}

float operator/(const Time& left, const Time& right)
{
    return (float)left.asNanoseconds() / (float)right.asNanoseconds();
}

Time operator%(Time left, const Time& right)
{
    return left %= right;
}
