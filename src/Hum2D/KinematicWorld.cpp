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

        actor.transform().x += kinematic->velocity().x * ms + kinematic->acceleration().x * ms * ms / 2;
        kinematic->velocity().x += kinematic->acceleration().x * ms;

        actor.transform().y += kinematic->velocity().y * ms + kinematic->acceleration().y * ms * ms / 2;
        kinematic->velocity().y += kinematic->acceleration().y * ms;

        actor.transform().z += kinematic->velocity().z * ms + kinematic->acceleration().z * ms * ms / 2;
        kinematic->velocity().z += kinematic->acceleration().z * ms;

        actor.transform().rotation += kinematic->velocity().rotation * ms + kinematic->acceleration().rotation * ms * ms / 2;
        kinematic->velocity().rotation += kinematic->acceleration().rotation * ms;

        actor.transform().scale_x += kinematic->velocity().scale_x * ms + kinematic->acceleration().scale_x * ms * ms / 2;
        kinematic->velocity().scale_x += kinematic->acceleration().scale_x * ms;

        actor.transform().scale_y += kinematic->velocity().scale_y * ms + kinematic->acceleration().scale_y * ms * ms / 2;
        kinematic->velocity().scale_y += kinematic->acceleration().scale_y * ms;
    }
}
