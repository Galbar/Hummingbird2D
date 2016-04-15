#ifndef HUM_TRANSFORMATION_HPP
#define HUM_TRANSFORMATION_HPP
#include "Vector3.hpp"

namespace hum
{
class Transformation
{
public:
    Transformation();

    Vector3f position, rotation, scale;

    Transformation transform(const Transformation& t) const;
};
}
#endif
