#include "Actor.hpp"
#include "Behavior.hpp"
#include "Game.hpp"

using namespace hum;

Actor::Actor(Game& game, unsigned int id):
p_is_active(true),
p_id(id),
p_game(&game)
{}

Actor::~Actor()
{
    for (Behavior* b : p_asleep_behaviors)
        delete b;
    for (Behavior* b : p_behaviors)
        delete b;
}

void Actor::preUpdate()
{
    if (!p_asleep_behaviors.empty())
    {
        std::vector<Behavior*> to_init;
        for (Behavior* b: p_asleep_behaviors)
        {
            to_init.push_back(b);
            p_behaviors.push_back(b);
        }
        p_asleep_behaviors.clear();
        for (Behavior* b : to_init)
            b->init();
    }
}

void Actor::fixedUpdate()
{
    for (Behavior* b : p_behaviors)
        b->fixedUpdate();
}

void Actor::onDestroy()
{
    for (Behavior* b : p_behaviors)
        b->onDestroy();
}

Game& Actor::game()
{
    return *p_game;
}

const Game& Actor::game() const
{
    return *p_game;
}

Transformation& Actor::transform()
{
    return p_transform;
}

const Transformation& Actor::transform() const
{
    return p_transform;
}

bool Actor::isActive()
{
    return p_is_active;
}

void Actor::activate()
{
    if (!p_is_active)
    {
        for (Behavior* b : p_behaviors)
            b->onActivate();
        p_is_active = true;
    }
}

void Actor::deactivate()
{
    if (p_is_active)
    {
        for (Behavior* b : p_behaviors)
            b->onDeactivate();
        p_is_active = false;
    }
}

void Actor::destroy()
{
    p_game->actors().destroy(this);
}

unsigned int Actor::id() const
{
    return p_id;
}
