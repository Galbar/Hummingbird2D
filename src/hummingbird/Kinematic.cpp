#include "Game.hpp"
#include "Actor.hpp"
#include "Kinematic.hpp"
#include "KinematicWorld.hpp"
#include "Time.hpp"
using namespace hum;

Kinematic::Kinematic():
p_kinematic_world(nullptr)
{
    p_velocity.scale.x = 0;
    p_velocity.scale.y = 0;
    p_velocity.scale.z = 0;
    p_acceleration.scale.x = 0;
    p_acceleration.scale.y = 0;
    p_acceleration.scale.z = 0;
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

const char* Kinematic::behaviorName()
{
    return "hum::Kinematic";
}

Transformation Kinematic::simulate(const Time& delta_time) const
{
    Transformation transform = actor().transform();
    float ms = delta_time.asMilliseconds() / 1000.f;
    transform.position += p_velocity.position * ms + p_acceleration.position * ms * ms / 2.f;
    transform.rotation += p_velocity.rotation * ms + p_acceleration.rotation * ms * ms / 2.f;
    transform.scale += p_velocity.scale * ms + p_velocity.scale * ms * ms / 2.f;
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
