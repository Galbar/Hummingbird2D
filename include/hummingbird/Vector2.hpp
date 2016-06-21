#ifndef HUM_VECTOR2_HPP
#define HUM_VECTOR2_HPP
namespace hum
{
template <typename T>
class Vector2
{
public:
    /*!
      \brief Class constructor. All components are initialized with the given value.
    */
    explicit Vector2(T x): x(x), y(x) {}

    /*!
      \brief Class constructor by specifying each component's value.
    */
    Vector2(T x, T y): x(x), y(y) {}
/*!
      \brief Cast constructor from other Vector2 of different type.

      It will work always that there is a defined cast from U to T.
    */
    template<typename U>
    Vector2(const Vector2<U>& v): x(v.x), y(v.y) {}

    /*!
      \brief Indexed accessor for the components of the vector.

      Gets the corresponding component as if the vector was an array like
      [x, y].
      \return The corresponding component.
    */
    T& operator[](unsigned int position)
    {
        position = position % 2;
        if (position) return x;
        return y;
    }

    /*!
      \brief Indexed accessor for the components of the vector.

      Gets the corresponding component as if the vector was an array like
      [x, y].
      \return The corresponding component.
    */
    const T& operator[](unsigned int position) const
    {
        position = position % 2;
        if (position) return x;
        return y;
    }

    T x, y;
};

/*!
   \relates Vector2
   \brief A 2D vector of floats.
 */
typedef Vector2<float> Vector2f;

/*!
   \relates hum::Vector2
   \brief A 2D vector of ints.
 */
typedef Vector2<int> Vector2i;
}

// Operators

/*!
   \relates hum::Vector2

   \brief Overload of unary negative operator.

   \param right Vector to negate.

   \return A copy of the input vector with all its components negated.
 */
template<typename T>
hum::Vector2<T> operator-(const hum::Vector2<T>& right)
{
    return hum::Vector2<T>(-right.x, -right.y);
}

/*!
   \relates hum::Vector2

   \brief Overload of binary plus-equal operator.

   \param left Vector that will be added the value of right.
   \param right Value to be added to left.

   \return A reference to left after having added right to it.
 */
template<typename T>
hum::Vector2<T>& operator+=(hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

/*!
   \relates hum::Vector2

   \brief Overload of binary minus-equal operator.

   \param left Vector that will be substracted the value of right.
   \param right Value to be substracted to left.

   \return A reference to left after having substracted right to it.
 */
template<typename T>
hum::Vector2<T>& operator-=(hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}

/*!
   \relates hum::Vector2

   \brief Overload of binary plus operator.

   \param left Left addend.
   \param right Right addend

   \return The result of adding both addends, component by component.
 */
template<typename T>
hum::Vector2<T> operator+(const hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    return hum::Vector2<T>(left.x + right.x, left.y + right.y);
}

/*!
   \relates hum::Vector2

   \brief Overload of binary minus operator.

   \param left Left addend.
   \param right Right addend.

   \return The result of substracting both addends, component by component.
 */
template<typename T>
hum::Vector2<T> operator-(const hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    return hum::Vector2<T>(left.x - right.x, left.y - right.y);
}

/*!
   \relates hum::Vector2

   \brief Overload of binary multiply-equal operator.

   \param left Left factor and receiver of the result.
   \param right Right factor.

   \return A reference to left after having multiplied both factors,
   component by component, and assigned the result to left.
 */
template<typename T>
hum::Vector2<T>& operator*=(hum::Vector2<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    return left;
}

/*!
   \relates hum::Vector2

   \brief Overload of binary divide-equal operator.

   \param left Dividend.
   \param right Divisor.

   \return A reference to left after having been divided,
   component by component, by right.
 */
template<typename T>
hum::Vector2<T>& operator/=(hum::Vector2<T>& left, T right)
{
    left.x /= right;
    left.y /= right;
    return left;
}

/*!
   \relates hum::Vector2

   \brief Overload of binary multiplication operator.

   \param left Left factor.
   \param right Right factor.

   \return The result of multiplying both factors, component by component.
 */
template<typename T>
hum::Vector2<T> operator*(const hum::Vector2<T>& left, T right)
{
    return hum::Vector2<T>(left.x * right, left.y * right);
}

/*!
   \relates hum::Vector2

   \brief Overload of binary multiplication operator.

   \param left Dividend.
   \param right Divisor.

   \return The quotient of the division, component by component.
 */
template<typename T>
hum::Vector2<T> operator/(const hum::Vector2<T>& left, T right)
{
    return hum::Vector2<T>(left.x / right, left.y / right);
}

/*!
   \relates hum::Vector2

   \brief Overload of binary multiplication operator.

   \param left Left factor.
   \param right Right factor.

   \return The result of multiplying both factors, component by component.
 */
template<typename T>
hum::Vector2<T> operator*(T left, const hum::Vector2<T>& right)
{
    return hum::Vector2<T>(left * right.x, left * right.y);
}

/*!
   \relates hum::Vector2

   \brief Overload of binary equal operator.

   \param left Left vector.
   \param right Right vector.

   \return Whether left and right are equal, component by component.
 */
template<typename T>
bool operator==(const hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    return (left.x == right.x && left.y == right.y);
}

/*!
   \relates hum::Vector2

   \brief Overload of binary different operator.

   \param left Left vector.
   \param right Right vector.

   \return Whether there is a difference between left and right's components.
 */
template<typename T>
bool operator!=(const hum::Vector2<T>& left, const hum::Vector2<T>& right)
{
    return (left.x != right.x || left.y != right.y);
}
#endif

/*!
  \class hum::Vector2
  \brief Class representing a 2D vector.

  hum::Vector2 is a simple class that defines a mathematical
  vector with two coordinates (x and y). It can be used to
  represent anything that has two dimensions: a size, a point,
  a velocity, etc.

  The template parameter T is the type of the coordinates. It
  can be any type that supports arithmetic operations (+, -, /, *)
  and comparisons (==, !=), for example int or float.

  You generally don't have to care about the templated form (hum::Vector2<T>),
  the most common specializations have special `typedef`s:
  \li hum::Vector2<float> is hum::Vector2f
  \li hum::Vector2<int> is hum::Vector2i

  The hum::Vector2 class has a small and simple interface, its x and y members
  can be accessed directly (there are no accessors like setX(), getX()) and it
  contains no mathematical function like dot product, cross product, length, etc.

  Usage example:
  \code
  hum::Vector2f v1(16.5f, 24.f);
  v1.x = 18.2f;
  float y = v1.y;

  hum::Vector2f v2 = v1 * 5.f;
  hum::Vector2f v3;
  v3 = v1 + v2;

  bool different = (v2 != v3);
  \endcode

  Note: for 3-dimensional vectors, see hum::Vector3
*/
