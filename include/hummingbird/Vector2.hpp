#ifndef HUM_VECTOR2_HPP
#define HUM_VECTOR2_HPP
namespace hum
{
template <typename T>
class Vector2
{
public:
    explicit Vector2(T x): x(x), y(x) {}
    Vector2(T x, T y): x(x), y(y) {}

    T& operator[](unsigned int position)
    {
        position = position % 2;
        if (position) return x;
        return y;
    }

    const T& operator[](unsigned int position) const
    {
        position = position % 2;
        if (position) return x;
        return y;
    }

    T x, y;
};

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;
}

// Operators

template<typename T>
hum::Vector2<T> operator-(const hum::Vector2<T>& right)
{
    return hum::Vector2<T>(-right.x, -right.y);
}

template<typename T>
hum::Vector2<T>& operator+=(hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

template<typename T>
hum::Vector2<T>& operator-=(hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}

template<typename T>
hum::Vector2<T> operator+(const hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    return hum::Vector2<T>(left.x + right.x, left.y + right.y);
}

template<typename T>
hum::Vector2<T> operator-(const hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    return hum::Vector2<T>(left.x - right.x, left.y - right.y);
}

template<typename T>
hum::Vector2<T>& operator*=(hum::Vector2<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    return left;
}

template<typename T>
hum::Vector2<T>& operator/=(hum::Vector2<T>& left, T right)
{
    left.x /= right;
    left.y /= right;
    return left;
}

template<typename T>
hum::Vector2<T> operator*(const hum::Vector2<T>& left, T right)
{
    return hum::Vector2<T>(left.x * right, left.y * right);
}

template<typename T>
hum::Vector2<T> operator/(const hum::Vector2<T>& left, T right)
{
    return hum::Vector2<T>(left.x / right, left.y / right);
}

template<typename T>
hum::Vector2<T> operator*(T left, const hum::Vector2<T>& right)
{
    return hum::Vector2<T>(left * right.x, left * right.y);
}

template<typename T>
bool operator==(const hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    return (left.x == right.x && left.y == right.y);
}

template<typename T>
bool operator!=(const hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    return (left.x != right.x || left.y != right.y);
}
#endif
