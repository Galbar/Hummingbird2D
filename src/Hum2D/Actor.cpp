#include "Actor.hpp"
#include "Behavior.hpp"

using namespace h2d;

Actor::Actor(Game& game):
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
        std::list<Behavior*> to_init;
        while (!p_asleep_behaviors.empty())
        {
            std::list<Behavior*>::iterator b = p_asleep_behaviors.begin();
            to_init.push_back(*b);
            p_behaviors.push_back(*b);
            p_asleep_behaviors.pop_front();
        }
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
