#include "Behavior.hpp"
using namespace hum;

Behavior::Behavior():
p_actor(nullptr)
{}

Behavior::~Behavior()
{}

void Behavior::init()
{}

void Behavior::fixedUpdate()
{}

void Behavior::onActivate()
{}

void Behavior::onDeactivate()
{}

void Behavior::onDestroy()
{}

Actor& Behavior::actor()
{
    return *p_actor;
}

const Actor& Behavior::actor() const
{
    return *p_actor;
}
