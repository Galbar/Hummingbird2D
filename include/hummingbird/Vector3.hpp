#ifndef HUM_VECTOR3_HPP
#define HUM_VECTOR3_HPP
#include "Vector2.hpp"
namespace hum
{
template <typename T>
class Vector3
{
public:
    /*!
      \brief Class constructor. All components are initialized with the given value.
    */
    explicit Vector3(T x): x(x), y(x), z(x) {}

    /*!
      \brief Class constructor by specifying each component's value.
    */
    Vector3(T x, T y, T z): x(x), y(y), z(z) {}

    /*!
      \brief Class constructor from a Vector2 and a third component
    */
    explicit Vector3(const Vector2<T>& xy, T z): x(xy.x), y(xy.y), z(z) {}

    /*!
      \brief Cast constructor from other Vector3 of different type.

      It will work always that there is a defined cast from U to T.
    */
    template<typename U>
    Vector3(const Vector3<U>& v): x(v.x), y(v.y), z(v.z) {}

    /*!
      \brief Indexed accessor for the components of the vector.

      Gets the corresponding component as if the vector was an array like
      [x, y].
      \return The corresponding component.
    */
    T& operator[](unsigned int position)
    {
        position = position % 3;
        if (position == 0) return x;
        if (position == 1) return y;
        return z;
    }

    /*!
      \brief Indexed accessor for the components of the vector.

      Gets the corresponding component as if the vector was an array like
      [x, y].
      \return The corresponding component.
    */
    const T& operator[](unsigned int position) const
    {
        position = position % 3;
        if (position == 0) return x;
        if (position == 1) return y;
        return z;
    }

    T x, y, z;
};

/*!
   \relates Vector3
   \brief A 3D vector of floats.
 */
typedef Vector3<float> Vector3f;

/*!
   \relates Vector3
   \brief A 3D vector of int.
 */
typedef Vector3<int> Vector3i;
} /* hum */

// Operators

/*!
   \relates hum::Vector3

   \brief Overload of unary negative operator.

   \param right Vector to negate.

   \return A copy of the input vector with all its components negated.
 */
template<typename T>
hum::Vector3<T> operator-(const hum::Vector3<T>& right)
{
    return hum::Vector3<T>(-right.x, -right.y, -right.z);
}

/*!
   \relates hum::Vector3

   \brief Overload of binary plus-equal operator.

   \param left Vector that will be added the value of right.
   \param right Value to be added to left.

   \return A reference to left after having added right to it.
 */
template<typename T>
hum::Vector3<T>& operator+=(hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}

/*!
   \relates hum::Vector3

   \brief Overload of binary minus-equal operator.

   \param left Vector that will be substracted the value of right.
   \param right Value to be substracted to left.

   \return A reference to left after having substracted right to it.
 */
template<typename T>
hum::Vector3<T>& operator-=(hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}

/*!
   \relates hum::Vector3

   \brief Overload of binary plus operator.

   \param left Left addend.
   \param right Right addend

   \return The result of adding both addends, component by component.
 */
template<typename T>
hum::Vector3<T> operator+(const hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    return hum::Vector3<T>(left.x + right.x, left.y + right.y, left.z + right.z);
}

/*!
   \relates hum::Vector3

   \brief Overload of binary minus operator.

   \param left Left addend.
   \param right Right addend.

   \return The result of substracting both addends, component by component.
 */
template<typename T>
hum::Vector3<T> operator-(const hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    return hum::Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z);
}

/*!
   \relates hum::Vector3

   \brief Overload of binary multiply-equal operator.

   \param left Left factor and receiver of the result.
   \param right Right factor.

   \return A reference to left after having multiplied both factors,
   component by component, and assigned the result to left.
 */
template<typename T>
hum::Vector3<T>& operator*=(hum::Vector3<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    return left;
}

/*!
   \relates hum::Vector3

   \brief Overload of binary divide-equal operator.

   \param left Dividend.
   \param right Divisor.

   \return A reference to left after having been divided,
   component by component, by right.
 */
template<typename T>
hum::Vector3<T>& operator/=(hum::Vector3<T>& left, T right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    return left;
}

/*!
   \relates hum::Vector3

   \brief Overload of binary multiplication operator.

   \param left Left factor.
   \param right Right factor.

   \return The result of multiplying both factors, component by component.
 */
template<typename T>
hum::Vector3<T> operator*(const hum::Vector3<T>& left, T right)
{
    return hum::Vector3<T>(left.x * right, left.y * right, left.z * right);
}

/*!
   \relates hum::Vector3

   \brief Overload of binary multiplication operator.

   \param left Dividend.
   \param right Divisor.

   \return The quotient of the division, component by component.
 */
template<typename T>
hum::Vector3<T> operator/(const hum::Vector3<T>& left, T right)
{
    return hum::Vector3<T>(left.x / right, left.y / right, left.z / right);
}

/*!
   \relates hum::Vector3

   \brief Overload of binary multiplication operator.

   \param left Left factor.
   \param right Right factor.

   \return The result of multiplying both factors, component by component.
 */
template<typename T>
hum::Vector3<T> operator*(T left, const hum::Vector3<T>& right)
{
    return hum::Vector3<T>(left * right.x, left * right.y, left + right.z);
}

/*!
   \relates hum::Vector3

   \brief Overload of binary equal operator.

   \param left Left vector.
   \param right Right vector.

   \return Whether left and right are equal, component by component.
 */
template<typename T>
bool operator==(const hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}

/*!
   \relates hum::Vector3

   \brief Overload of binary different operator.

   \param left Left vector.
   \param right Right vector.

   \return Whether there is a difference between left and right's components.
 */
template<typename T>
bool operator!=(const hum::Vector3<T>& left, const hum::Vector3<T>& right)
{
    return (left.x != right.x || left.y != right.y || left.z != right.z);
}
#endif

/*!
  \class hum::Vector3
  \brief Class representing a 3D vector.

  hum::Vector3 is a simple class that defines a mathematical
  vector with two coordinates (x, y and z). It can be used to
  represent anything that has two dimensions: a size, a point,
  a velocity, etc.

  The template parameter T is the type of the coordinates. It
  can be any type that supports arithmetic operations (+, -, /, *)
  and comparisons (==, !=), for example int or float.

  You generally don't have to care about the templated form (hum::Vector3<T>),
  the most common specializations have special typedefs:
  \li hum::Vector3<float> is hum::Vector3f
  \li hum::Vector3<int> is hum::Vector3i

  The hum::Vector3 class has a small and simple interface, its x, y and z members
  can be accessed directly (there are no accessors like setX(), getX()) and it
  contains no mathematical function like dot product, cross product, length, etc.

  Usage example:
  \code
  hum::Vector3f v1(16.5f, 24.f, 13.f);
  v1.x = 18.2f;
  float y = v1.y;

  hum::Vector3f v2 = v1 * 5.f;
  hum::Vector3f v3;
  v3 = v1 + v2;

  bool different = (v2 != v3);
  \endcode

  Note: for 2-dimensional vectors, see hum::Vector2
*/
