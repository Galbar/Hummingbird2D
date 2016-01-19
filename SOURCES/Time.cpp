#include "Time.hpp"

using namespace h2d;

Time::Time():
m_microseconds(0)
{}

Time::~Time()
{}

double Time::asSeconds() const
{
    return (double)m_microseconds/1e6;
}

double Time::asMilliseconds() const
{
    return (double)m_microseconds/1000.0;
}

long long Time::asMicroseconds() const
{
    return m_microseconds;
}

Time Time::seconds(double seconds)
{
    Time t;
    t.m_microseconds = (long long)(seconds * 1e6);
    return t;
}

Time Time::milliseconds(double milliseconds)
{
    Time t;
    t.m_microseconds = milliseconds * 1000.0;
    return t;
}

Time Time::microseconds(long long microseconds)
{
    Time t;
    t.m_microseconds = microseconds;
    return t;
}


Time& Time::operator+=(const Time& other)
{
    m_microseconds += other.m_microseconds;
    return *this;
}

Time& Time::operator-=(const Time& other)
{
    m_microseconds -= other.m_microseconds;
    return *this;
}

Time& Time::operator*=(double other)
{
    m_microseconds *= other;
    return *this;
}

Time& Time::operator*=(long long other)
{
    m_microseconds *= other;
    return *this;
}

Time& Time::operator/=(double other)
{
    m_microseconds /= other;
    return *this;
}

Time& Time::operator/=(long long other)
{
    m_microseconds /= other;
    return *this;
}

Time& Time::operator%=(const Time& other)
{
    m_microseconds %= other.m_microseconds;
    return *this;
}

Time operator-(Time right)
{
    return Time::microseconds(-right.asMicroseconds());
}

bool operator==(const Time& left, const Time& right)
{
    return left.asMicroseconds() == right.asMicroseconds();
}

bool operator!=(const Time& left, const Time& right)
{
    return left.asMicroseconds() != right.asMicroseconds();
}

bool operator<(const Time& left, const Time& right)
{
    return left.asMicroseconds() < right.asMicroseconds();
}

bool operator>(const Time& left, const Time& right)
{
    return left.asMicroseconds() > right.asMicroseconds();
}

bool operator<=(const Time& left, const Time& right)
{
    return left.asMicroseconds() <= right.asMicroseconds();
}

bool operator>=(const Time& left, const Time& right)
{
    return left.asMicroseconds() >= right.asMicroseconds();
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

Time operator*(Time left, long long right)
{
    return left *= right;
}

Time operator*(double left, Time right)
{
    return right *= left;
}

Time operator*(long long left, Time right)
{
    return right *= left;
}

Time operator/(Time left, double right)
{
    return left /= right;
}

Time operator/(Time left, long long right)
{
    return left /= right;
}

double operator/(const Time& left, const Time& right)
{
    return (double)left.asMicroseconds() / (double)right.asMicroseconds();
}

Time operator%(Time left, const Time& right)
{
    return left %= right;
}
