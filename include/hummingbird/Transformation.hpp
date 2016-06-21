#ifndef HUM_TRANSFORMATION_HPP
#define HUM_TRANSFORMATION_HPP
#include "Vector3.hpp"

namespace hum
{
class Transformation
{
public:
    /*!
      \brief Class constructor.

      Initializes its members as follows:
      \code
      position = hum::Vector3f(0.f);
      rotation = hum::Vector3f(0.f);
      scale = hum::Vector3f(1.f);
      \endcode
    */
    Transformation();
    //! position vector.
    Vector3f position;
    //! rotation degrees around each axis.
    Vector3f rotation;
    //! scale for each axis.
    Vector3f scale;

    /*!
      \brief Transform this Transformation by applying t.

      This does the equivalent of the following:
      \code
      hum::Transformation t1, t2, result;
      result.position = t1.position + t2.position;
      result.rotation = t1.rotation + t2.rotation;
      result.scale.x = t1.scale.x * t2.scale.x;
      result.scale.y = t1.scale.y * t2.scale.y;
      result.scale.z = t1.scale.z * t2.scale.z;
      \endcode

      \return The accumulated transformation of `this` and `t`.
    */
    Transformation transform(const Transformation& t) const;
};
}
#endif

/*!
  \class hum::Transformation
  \brief Class represeting 3D spacial transformation of an object.

  hum::Tranformation is a simple class that defines a spacial tranformation
  of an object. That is it defines a 3D translation, rotation and scale, using
  hum::Vector3.

  The hum::Transformation class has a small and simple interface, its
  position, rotation and scale members can be accessed directly
  (there are no accessors like setPosition(), getPosition()) and it
  contains no mathematical function other than the method transform(), which
  accumulates transformations.

  Usage example:
  \code
  hum::Transformation t, t2;
  t.position.x = 10.f;
  t.rotation.z = 90.f;
  t.scale.x = 0.5f;

  t2.position.x = 5.f;
  t2.rotation.z = -25.f;
  t2.scale.x = 0.2f;

  t = t.transform(t2);
  hum::log(t); // hum::Transformation ( position=hum::Vector3( 15, 0, 0 ); rotation=hum::Vector3( 0, 0, 65 ); scale=hum::Vector3( 0.1, 1, 1 ) )
  \endcode
*/
