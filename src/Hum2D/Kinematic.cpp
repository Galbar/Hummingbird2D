#include "Game.hpp"
#include "Actor.hpp"
#include "Kinematic.hpp"
#include "KinematicWorld.hpp"
#include "Time.hpp"
using namespace h2d;

Kinematic::Kinematic():
p_kinematic_world(nullptr)
{
    p_velocity.scale_x = 0;
    p_velocity.scale_y = 0;
    p_acceleration.scale_x = 0;
    p_acceleration.scale_y = 0;
}

Kinematic::~Kinematic()
{}

void Kinematic::init()
{
    p_kinematic_world = actor().game().getPlugin<KinematicWorld>();
    p_kinematic_world->add(this);
}

void Kinematic::onDestroy()
{
    p_kinematic_world->remove(this);
}

const char* Kinematic::behaviourName()
{
    return "h2d::Kinematic";
}

Transformation Kinematic::simulate(const Time& delta_time) const
{
    Transformation transform = actor().transform();
    double ms = delta_time.asMilliseconds() / 1000.0;
    transform.x += p_velocity.x * ms + p_acceleration.x * ms * ms / 2;
    transform.y += p_velocity.y * ms + p_acceleration.y * ms * ms / 2;
    transform.z += p_velocity.z * ms + p_acceleration.z * ms * ms / 2;
    transform.rotation += p_velocity.rotation * ms + p_acceleration.rotation * ms * ms / 2;
    transform.scale_x += p_velocity.scale_x * ms + p_velocity.scale_x * ms * ms / 2;
    transform.scale_y += p_velocity.scale_y * ms + p_velocity.scale_y * ms * ms / 2;
    return transform;
}

Transformation& Kinematic::velocity()
{
    return p_velocity;
}

const Transformation& Kinematic::velocity() const
{
    return p_velocity;
}

Transformation& Kinematic::acceleration()
{
    return p_acceleration;
}

const Transformation& Kinematic::acceleration() const
{
    return p_acceleration;
}
