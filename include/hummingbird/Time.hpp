#ifndef HUM_TIME_HPP
#define HUM_TIME_HPP
namespace hum
{
class Time
{
public:
    Time();
    Time(const Time& other);
    ~Time();
    float asSeconds() const;
    float asMilliseconds() const;
    float asMicroseconds() const;
    long asNanoseconds() const;
    static Time seconds(float seconds);
    static Time milliseconds(float milliseconds);
    static Time microseconds(float microseconds);
    static Time nanoseconds(long nanoseconds);

    Time& operator+=(const Time& other);
    Time& operator-=(const Time& other);
    Time& operator*=(float other);
    Time& operator*=(long other);
    Time& operator/=(float other);
    Time& operator/=(long other);
    Time& operator%=(const Time& other);

private:
    long m_nanoseconds;
};
}

hum::Time operator-(hum::Time right);
bool operator==(const hum::Time& left, const hum::Time& right);
bool operator!=(const hum::Time& left, const hum::Time& right);
bool operator<(const hum::Time& left, const hum::Time& right);
bool operator>(const hum::Time& left, const hum::Time& right);
bool operator<=(const hum::Time& left, const hum::Time& right);
bool operator>=(const hum::Time& left, const hum::Time& right);
hum::Time operator+(hum::Time left, hum::Time& right);
hum::Time operator-(hum::Time left, hum::Time& right);
hum::Time operator*(hum::Time left, float right);
hum::Time operator*(hum::Time left, long right);
hum::Time operator*(float left, hum::Time right);
hum::Time operator*(long left, hum::Time right);
hum::Time operator/(hum::Time left, float right);
hum::Time operator/(hum::Time left, long right);
float operator/(hum::Time& left, hum::Time& right);
hum::Time operator%(hum::Time left, hum::Time& right);
#endif
