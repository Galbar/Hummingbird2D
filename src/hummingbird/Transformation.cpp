#include "Transformation.hpp"

namespace hum
{
Transformation::Transformation():
position(0.f),
rotation(0.f),
scale(1.f)
{}

Transformation Transformation::transform(const Transformation& t) const
{
    Transformation new_t = t;
    new_t.position += position;
    new_t.rotation += rotation;
    new_t.scale.x *= scale.x;
    new_t.scale.y *= scale.y;
    new_t.scale.z *= scale.z;
    return new_t;
}
}
