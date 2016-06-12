#ifndef HUM_TIME_HPP
#define HUM_TIME_HPP
namespace hum
{
/*!
  \class Time
  \brief Class for representing intervals of time.
  This class has nanoseconds precision.
*/
class Time
{
public:
    /*!
      \brief Default constructor.
    */
    Time();

    /*!
      \brief Copy constructor.
    */
    Time(const Time& other);

    /*!
      \brief Class destructor.
    */
    ~Time();

    /*!
      \brief Get Time as seconds.
      \return Number of seconds represented.
    */
    float asSeconds() const;

    /*!
      \brief Get Time as milliseconds.
      \return Number of milliseconds represented.
    */
    float asMilliseconds() const;

    /*!
      \brief Get Time as microseconds.
      \return Number of microseconds represented.
    */
    float asMicroseconds() const;

    /*!
      \brief Get Time as nanoseconds.
      \return Number of nanoseconds represented.
    */
    long asNanoseconds() const;

    /*!
      \brief Construct Time from seconds.
    */
    static Time seconds(float seconds);

    /*!
      \brief Construct Time from milliseconds.
    */
    static Time milliseconds(float milliseconds);

    /*!
      \brief Construct Time from microseconds.
    */
    static Time microseconds(float microseconds);

    /*!
      \brief Construct Time from nanoseconds.
    */
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
