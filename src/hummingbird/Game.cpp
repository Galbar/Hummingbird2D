#include "Game.hpp"
#include "Plugin.hpp"
#include "Actor.hpp"
#include "Clock.hpp"
#include "Log.hpp"

using namespace hum;

Game::Game(unsigned int fixed_tickrate):
p_running(false),
c_nanoseconds_per_fixed_update(1e9 / (float)fixed_tickrate),
p_fixed_update_lag(0.0),
p_actor_pool(this)
{};

Game::~Game()
{
    for (Plugin* p : p_plugins)
        delete p;
};

void Game::run()
{
    p_running = true;
    for (Plugin* p : p_plugins)
        p->gameStart();

    Clock clk;
    p_fixed_update_lag = 0.0;
    while (p_running)
    {
        p_delta_time = clk.reset();
        p_fixed_update_lag += p_delta_time.asNanoseconds();

        for (auto it : p_actor_pool)
        {
            Actor* actor = it.second;
            if (actor->isActive())
                actor->preUpdate();
        }
        for (Plugin* p : p_plugins)
            p->preUpdate();

        while (p_fixed_update_lag >= c_nanoseconds_per_fixed_update)
        {
            for (Plugin* p : p_plugins)
                p->preFixedUpdate();
            for (auto it : p_actor_pool)
            {
                Actor* actor = it.second;
                if (actor->isActive())
                    actor->fixedUpdate();
            }
            for (Plugin* p : p_plugins)
                p->postFixedUpdate();
            p_fixed_update_lag -= c_nanoseconds_per_fixed_update;
        }

        for (Plugin* p : p_plugins)
            p->postUpdate();

        p_actor_pool.postUpdate();
    }

    for (Plugin* p : p_plugins)
        p->gameEnd();

    p_actor_pool.clear();
}

const ActorPool& Game::actors() const
{
    return p_actor_pool;
}

ActorPool& Game::actors()
{
    return p_actor_pool;
}

const Time& Game::deltaTime() const
{
    return p_delta_time;
}

Time Game::fixedUpdateTime() const
{
    return Time::nanoseconds(c_nanoseconds_per_fixed_update);
}

Time Game::fixedUpdateLag() const
{
    return Time::nanoseconds(p_fixed_update_lag);
}

void Game::setRunning(bool running)
{
    p_running = running;
}
