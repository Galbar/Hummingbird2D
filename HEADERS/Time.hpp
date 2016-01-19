#ifndef H2D_TIME_HPP
#define H2D_TIME_HPP
namespace h2d
{
class Time
{
public:
    Time();
    ~Time();
    double asSeconds() const;
    double asMilliseconds() const;
    long long asMicroseconds() const;
    static Time seconds(double seconds);
    static Time milliseconds(double milliseconds);
    static Time microseconds(long long microseconds);

    Time& operator+=(const Time& other);
    Time& operator-=(const Time& other);
    Time& operator*=(double other);
    Time& operator*=(long long other);
    Time& operator/=(double other);
    Time& operator/=(long long other);
    Time& operator%=(const Time& other);

private:
    long long m_microseconds;
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
h2d::Time operator*(h2d::Time left, long long right);
h2d::Time operator*(double left, h2d::Time right);
h2d::Time operator*(long long left, h2d::Time right);
h2d::Time operator/(h2d::Time left, double right);
h2d::Time operator/(h2d::Time left, long long right);
double operator/(h2d::Time left, h2d::Time right);
h2d::Time operator%(h2d::Time left, h2d::Time right);
#endif
