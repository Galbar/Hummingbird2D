#ifndef HUM_VECTOR3_HPP
#define HUM_VECTOR3_HPP
#include "Vector2.hpp"
namespace hum
{
template <typename T>
class Vector3
{
public:
    Vector3(T x): x(x), y(x), z(x) {}
    Vector3(T x, T y, T z): x(x), y(y), z(z) {}
    Vector3(const Vector2<T>& xy, T z): x(xy.x), y(xy.y), z(z) {}

    T& operator[](unsigned int position)
    {
        position = position % 3;
        if (position == 0) return x;
        if (position == 1) return y;
        return z;
    }

    const T& operator[](unsigned int position) const
    {
        position = position % 3;
        if (position == 0) return x;
        if (position == 1) return y;
        return z;
    }

    T x, y, z;
};
typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;
} /* hum */

// Operators

template<typename T>
hum::Vector3<T> operator-(const hum::Vector3<T>& right)
{
    return hum::Vector3<T>(-right.x, -right.y, -right.z);
}

template<typename T>
hum::Vector3<T>& operator+=(hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}

template<typename T>
hum::Vector3<T>& operator-=(hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}

template<typename T>
hum::Vector3<T> operator+(const hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    return hum::Vector3<T>(left.x + right.x, left.y + right.y, left.y + right.y);
}

template<typename T>
hum::Vector3<T> operator-(const hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    return hum::Vector3<T>(left.x - right.x, left.y - right.y, left.y - right.y);
}

template<typename T>
hum::Vector3<T>& operator*=(hum::Vector3<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    return left;
}

template<typename T>
hum::Vector3<T>& operator/=(hum::Vector3<T>& left, T right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    return left;
}

template<typename T>
hum::Vector3<T> operator*(const hum::Vector3<T>& left, T right)
{
    return hum::Vector3<T>(left.x * right, left.y * right, left.y * right);
}

template<typename T>
hum::Vector3<T> operator/(const hum::Vector3<T>& left, T right)
{
    return hum::Vector3<T>(left.x / right, left.y / right, left.y / right);
}

template<typename T>
hum::Vector3<T> operator*(T left, const hum::Vector3<T>& right)
{
    return hum::Vector3<T>(left * right.x, left * right.y, left + right.y);
}

template<typename T>
bool operator==(const hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}

template<typename T>
bool operator!=(const hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    return (left.x != right.x || left.y != right.y || left.z != right.z);
}
#endif
