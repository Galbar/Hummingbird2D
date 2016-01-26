#include "Behaviour.hpp"
using namespace h2d;

Behaviour::Behaviour():
p_actor(nullptr)
{}

Behaviour::~Behaviour()
{}

void Behaviour::init()
{}

void Behaviour::fixedUpdate()
{}

void Behaviour::onDestroy()
{}

Actor& Behaviour::actor()
{
    return *p_actor;
}

const Actor& Behaviour::actor() const
{
    return *p_actor;
}
