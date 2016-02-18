#include "Actor.hpp"
#include "Behaviour.hpp"

using namespace h2d;

Actor::Actor(Game& game):
p_game(&game)
{}

Actor::~Actor()
{
    for (Behaviour* b : p_asleep_behaviours)
        delete b;
    for (Behaviour* b : p_behaviours)
        delete b;
}

void Actor::preUpdate()
{
    if (not p_asleep_behaviours.empty())
    {
        std::list<Behaviour*> to_init;
        while (not p_asleep_behaviours.empty())
        {
            std::list<Behaviour*>::iterator b = p_asleep_behaviours.begin();
            to_init.push_back(*b);
            p_behaviours.push_back(*b);
            p_asleep_behaviours.pop_front();
        }
        for (Behaviour* b : to_init)
            b->init();
    }
}

void Actor::fixedUpdate()
{
    for (Behaviour* b : p_behaviours)
        b->fixedUpdate();
}

void Actor::onDestroy()
{
    for (Behaviour* b : p_behaviours)
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
