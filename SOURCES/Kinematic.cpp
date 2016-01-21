#include "Kinematic.hpp"
#include "Transformation.hpp"
#include "Actor.hpp"
#include "Game.hpp"
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

void Kinematic::fixedUpdate()
{
    double delta_time = actor().game().fixedUpdateTime().asMilliseconds() / 1000.0;

    actor().transform().x += velocity_x * delta_time + acceleration_x * delta_time * delta_time / 2;
    velocity_x += acceleration_x * delta_time;

    actor().transform().y += velocity_y * delta_time + acceleration_y * delta_time * delta_time / 2;
    velocity_y += acceleration_y * delta_time;

    actor().transform().z += velocity_z * delta_time + acceleration_z * delta_time * delta_time / 2;
    velocity_z += acceleration_z * delta_time;

    actor().transform().rotation += rotation_velocity * delta_time + rotation_acceleration * delta_time * delta_time / 2;
    rotation_velocity += rotation_acceleration * delta_time;

    actor().transform().scale_x += scale_velocity_x * delta_time + scale_acceleration_x * delta_time * delta_time / 2;
    scale_velocity_x += scale_acceleration_x * delta_time;

    actor().transform().scale_y += scale_velocity_y * delta_time + scale_acceleration_y * delta_time * delta_time / 2;
    scale_velocity_y += scale_acceleration_y * delta_time;
}

const char* Kinematic::behaviourName()
{
    return "h2d::Kinematic";
}
