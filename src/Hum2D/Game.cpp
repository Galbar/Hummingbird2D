#include "Game.hpp"
#include "Plugin.hpp"
#include "Actor.hpp"
#include "Clock.hpp"
#include "Log.hpp"

using namespace h2d;

Game::Game(unsigned int fixed_tickrate):
p_running(false),
c_nanoseconds_per_fixed_update(1e9 / (double)fixed_tickrate),
p_fixed_update_lag(0.0)
{};

Game::~Game()
{
    for (Actor* a : p_actor_pool)
        delete a;

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

        for (Actor* a : p_actor_pool)
        {
            if (a->isActive())
                a->preUpdate();
        }
        for (Plugin* p : p_plugins)
            p->preUpdate();

        while (p_fixed_update_lag >= c_nanoseconds_per_fixed_update)
        {
            for (Plugin* p : p_plugins)
                p->preFixedUpdate();
            for (Actor* a : p_actor_pool)
            {
                if (a->isActive())
                    a->fixedUpdate();
            }
            for (Plugin* p : p_plugins)
                p->postFixedUpdate();
            p_fixed_update_lag -= c_nanoseconds_per_fixed_update;
        }

        for (Plugin* p : p_plugins)
            p->postUpdate();

        for (Actor* a : p_actors_to_destroy)
        {
            a->onDestroy();
            p_actor_pool.erase(a);
            delete a;
        }
        p_actors_to_destroy.clear();
    }

    for (Plugin* p : p_plugins)
        p->gameEnd();

    for (Actor* a : p_actor_pool)
    {
        a->onDestroy();
        delete a;
    }
    p_actor_pool.clear();
}

void Game::destroy(Actor* actor)
{
    if (p_actor_pool.find(actor) != p_actor_pool.end())
    {
        p_actors_to_destroy.insert(actor);
    }
    else
    {
        h2d_log("Intentando eliminar un actor inexistente");
    }
}

void Game::destroy(Actor& actor)
{
    destroy(&actor);
}

Actor* Game::makeActor()
{
    Actor* a = new Actor(*this);
    p_actor_pool.insert(a);
    return a;
}

const std::unordered_set<Actor*>& Game::actors() const
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
