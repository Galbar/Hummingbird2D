#ifndef H2D_TIME_HPP
#define H2D_TIME_HPP
namespace h2d
{
class Time
{
public:
    Time();
    Time(const Time& other);
    ~Time();
    double asSeconds() const;
    double asMilliseconds() const;
    double asMicroseconds() const;
    long asNanoseconds() const;
    static Time seconds(double seconds);
    static Time milliseconds(double milliseconds);
    static Time microseconds(double microseconds);
    static Time nanoseconds(long nanoseconds);

    Time& operator+=(const Time& other);
    Time& operator-=(const Time& other);
    Time& operator*=(double other);
    Time& operator*=(long other);
    Time& operator/=(double other);
    Time& operator/=(long other);
    Time& operator%=(const Time& other);

private:
    long m_nanoseconds;
};
}

h2d::Time operator-(h2d::Time right);
bool operator==(const h2d::Time& left, const h2d::Time& right);
bool operator!=(const h2d::Time& left, const h2d::Time& right);
bool operator<(const h2d::Time& left, const h2d::Time& right);
bool operator>(const h2d::Time& left, const h2d::Time& right);
bool operator<=(const h2d::Time& left, const h2d::Time& right);
bool operator>=(const h2d::Time& left, const h2d::Time& right);
h2d::Time operator+(h2d::Time left, h2d::Time right);
h2d::Time operator-(h2d::Time left, h2d::Time right);
h2d::Time operator*(h2d::Time left, double right);
h2d::Time operator*(h2d::Time left, long right);
h2d::Time operator*(double left, h2d::Time right);
h2d::Time operator*(long left, h2d::Time right);
h2d::Time operator/(h2d::Time left, double right);
h2d::Time operator/(h2d::Time left, long right);
double operator/(h2d::Time left, h2d::Time right);
h2d::Time operator%(h2d::Time left, h2d::Time right);
#endif
