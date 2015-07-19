#ifndef H2D_TIME_HPP
#define H2D_TIME_HPP

namespace h2d
{
class Time
{
public:
	Time():
	m_microseconds(0)
	{}

	~Time()
	{}

	double asSeconds() const
	{
		return (double)m_microseconds/1e6;
	}

	double asMilliseconds() const
	{
		return (double)m_microseconds/1000.0;
	}

	long long asMicroseconds() const
	{
		return m_microseconds;
	}

	static Time seconds(double seconds)
	{
		Time t;
		t.m_microseconds = (long long)(seconds * 1e6);
		return t;
	}

	static Time milliseconds(double milliseconds)
	{
		Time t;
		t.m_microseconds = milliseconds * 1000.0;
		return t;
	}

	static Time microseconds(long long microseconds)
	{
		Time t;
		t.m_microseconds = microseconds;
		return t;
	}

private:
	long long m_microseconds;
};

bool operator ==(Time left, Time right)
{
	return left.asMicroseconds() == right.asMicroseconds();
}

bool operator !=(Time left, Time right)
{
	return left.asMicroseconds() != right.asMicroseconds();
}

bool operator <(Time left, Time right)
{
	return left.asMicroseconds() < right.asMicroseconds();
}

bool operator >(Time left, Time right)
{
	return left.asMicroseconds() > right.asMicroseconds();
}

bool operator <=(Time left, Time right)
{
	return left.asMicroseconds() <= right.asMicroseconds();
}

bool operator >=(Time left, Time right)
{
	return left.asMicroseconds() >= right.asMicroseconds();
}

Time operator -(Time right)
{
	return Time::microseconds(-right.asMicroseconds());
}

Time operator +(Time left, Time right)
{
	return Time::microseconds(left.asMicroseconds() + right.asMicroseconds());
}

Time & operator +=(Time &left, Time right)
{
	left = left + right;
	return left;
}

Time operator -(Time left, Time right)
{
	return Time::microseconds(left.asMicroseconds() - right.asMicroseconds());
}

Time & operator -=(Time &left, Time right)
{
	left = left - right;
	return left;
}

Time operator *(Time left, double right)
{
	return Time::microseconds(left.asMicroseconds() * right);
}

Time operator *(Time left, long long right)
{
	return Time::microseconds(left.asMicroseconds() * right);
}

Time operator *(double left, Time right)
{
	return Time::microseconds(left * right.asMicroseconds());
}

Time operator *(long long left, Time right)
{
	return Time::microseconds(left * right.asMicroseconds());
}

Time & operator *=(Time &left, double right)
{
	left = left * right;
	return left;
}

Time & operator *=(Time &left, long long right)
{
	left = left * right;
	return left;
}

Time operator /(Time left, double right)
{
	return Time::microseconds(left.asMicroseconds() / right);
}

Time operator /(Time left, long long right)
{
	return Time::microseconds(left.asMicroseconds() / right);
}

Time & operator /=(Time &left, double right)
{
	left = left / right;
	return left;
}

Time & operator /=(Time &left, long long right)
{
	left = left / right;
	return left;
}

double operator /(Time left, Time right)
{
	return (double)left.asMicroseconds() / (double)right.asMicroseconds();
}

Time operator %(Time left, Time right)
{
	return Time::microseconds(left.asMicroseconds() % right.asMicroseconds());
}

Time & operator %=(Time &left, Time right)
{
	left = left % right;
	return left;
}
}
#endif
