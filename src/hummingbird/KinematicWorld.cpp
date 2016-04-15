#include "Game.hpp"
#include "Actor.hpp"
#include "Transformation.hpp"
#include "KinematicWorld.hpp"
#include "Kinematic.hpp"

using namespace hum;

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
        float ms = game().fixedUpdateTime().asMilliseconds() / 1000.0;
        Actor& actor = kinematic->actor();

        actor.transform() = kinematic->simulate(game().fixedUpdateTime());

        kinematic->velocity().position += kinematic->acceleration().position * ms;
        kinematic->velocity().rotation += kinematic->acceleration().rotation * ms;
        kinematic->velocity().scale += kinematic->acceleration().scale * ms;
    }
}
