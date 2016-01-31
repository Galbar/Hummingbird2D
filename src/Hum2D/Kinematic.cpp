#include "Game.hpp"
#include "Actor.hpp"
#include "Kinematic.hpp"
#include "KinematicWorld.hpp"
#include "Transformation.hpp"
#include "Time.hpp"
using namespace h2d;

Kinematic::Kinematic():
velocity_x(0),
velocity_y(0),
velocity_z(0),
acceleration_x(0),
acceleration_y(0),
acceleration_z(0),
rotation_velocity(0),
rotation_acceleration(0),
scale_velocity_x(0),
scale_velocity_y(0),
scale_acceleration_x(0),
scale_acceleration_y(0)
{}

Kinematic::~Kinematic()
{}

void Kinematic::init()
{
    actor().game().getPlugin<KinematicWorld>()->add(this);
}

void Kinematic::onDestroy()
{
    actor().game().getPlugin<KinematicWorld>()->remove(this);
}

const char* Kinematic::behaviourName()
{
    return "h2d::Kinematic";
}

Transformation Kinematic::simulate(const Time& delta_time) const
{
    Transformation transform = actor().transform();
    double ms = delta_time.asMilliseconds() / 1000.0;
    transform.x += this->velocity_x * ms + this->acceleration_x * ms * ms / 2;
    transform.y += this->velocity_y * ms + this->acceleration_y * ms * ms / 2;
    transform.z += this->velocity_z * ms + this->acceleration_z * ms * ms / 2;
    transform.rotation += this->rotation_velocity * ms + this->rotation_acceleration * ms * ms / 2;
    transform.scale_x += this->scale_velocity_x * ms + this->scale_acceleration_x * ms * ms / 2;
    transform.scale_y += this->scale_velocity_y * ms + this->scale_acceleration_y * ms * ms / 2;
    return transform;
}
