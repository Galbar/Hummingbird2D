#include "Game.hpp"
#include "Actor.hpp"
#include "Transformation.hpp"
#include "KinematicWorld.hpp"
#include "Kinematic.hpp"

using namespace h2d;

KinematicWorld::KinematicWorld()
{}

KinematicWorld::~KinematicWorld()
{}

void KinematicWorld::add(Kinematic* kinematic)
{
    p_kinematics.insert(kinematic);
}

void KinematicWorld::remove(Kinematic* kinematic)
{
    p_kinematics.erase(kinematic);
}

void KinematicWorld::preFixedUpdate()
{
    for (auto kinematic : p_kinematics)
    {
        double ms = game().fixedUpdateTime().asMilliseconds() / 1000.0;
        Actor& actor = kinematic->actor();
        actor.transform().x += kinematic->velocity_x * ms + kinematic->acceleration_x * ms * ms / 2;
        kinematic->velocity_x += kinematic->acceleration_x * ms;
        actor.transform().y += kinematic->velocity_y * ms + kinematic->acceleration_y * ms * ms / 2;
        kinematic->velocity_y += kinematic->acceleration_y * ms;
        actor.transform().z += kinematic->velocity_z * ms + kinematic->acceleration_z * ms * ms / 2;
        kinematic->velocity_z += kinematic->acceleration_z * ms;
        actor.transform().rotation += kinematic->rotation_velocity * ms + kinematic->rotation_acceleration * ms * ms / 2;
        kinematic->rotation_velocity += kinematic->rotation_acceleration * ms;
        actor.transform().scale_x += kinematic->scale_velocity_x * ms + kinematic->scale_acceleration_x * ms * ms / 2;
        kinematic->scale_velocity_x += kinematic->scale_acceleration_x * ms;
        actor.transform().scale_y += kinematic->scale_velocity_y * ms + kinematic->scale_acceleration_y * ms * ms / 2;
        kinematic->scale_velocity_y += kinematic->scale_acceleration_y * ms;
    }
}
