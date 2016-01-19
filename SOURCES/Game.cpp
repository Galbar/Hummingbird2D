#include "Game.hpp"
#include "Actor.hpp"
#include "Plugin.hpp"
#include "Time.hpp"
#include "Clock.hpp"

using namespace h2d;

Game::Game(unsigned int fixed_tickrate):
p_running(false),
c_ms_per_fixed_update(1000.0 / (double)fixed_tickrate),
p_fixed_update_lag(0.0)
{};

Game::~Game()
{};

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
        p_fixed_update_lag += p_delta_time.asMilliseconds();

        for (Actor* a : p_actors)
            a->preUpdate();
        for (Plugin* p : p_plugins)
            p->preUpdate();

        while (p_fixed_update_lag >= c_ms_per_fixed_update)
        {
            for (Actor* a : p_actors)
                a->fixedUpdate();
            for (Plugin* p : p_plugins)
                p->fixedUpdate();
            p_fixed_update_lag -= c_ms_per_fixed_update;
        }

        for (Plugin* p : p_plugins)
            p->postUpdate();

        while (not p_actors_to_destroy.empty())
        {
            unsigned int id = *p_actors_to_destroy.begin();
            const std::list<Actor*>::iterator it = p_actor_pool[id];
            p_actors_to_destroy.erase(p_actors_to_destroy.begin());
            p_actors.erase(it);
        }
    }

    for (Plugin* p : p_plugins)
        p->gameEnd();

    while (not p_actors.empty())
    {
        Actor* a = p_actors.front();
        p_actors.pop_front();
        delete a;
    }
}

void Game::destroy(const Actor& actor)
{
    p_actors_to_destroy.insert(actor.id());
}

Actor& Game::makeActor()
{
    Actor* a = new Actor(*this, p_actor_pool.size());
    p_actors.push_back(a);
    p_actor_pool[a->p_id] = --p_actors.end();
    return *a;
}

void Game::addPlugin(Plugin& plugin)
{
    plugin.setGame(*this);
    p_plugins.push_back(&plugin);
}

const std::list<Actor*>& Game::actors() const
{
    return p_actors;
}

const Time& Game::deltaTime() const
{
    return p_delta_time;
}

double Game::fixedUpdateMilliseconds() const
{
    return c_ms_per_fixed_update;
}

double Game::fixedUpdateLag() const
{
    return p_fixed_update_lag;
}

void Game::setRunning(bool running)
{
    p_running = running;
}

const Actor& Game::getActorById(unsigned int id) const
{
    return *(*(p_actor_pool.find(id)->second));
}

Actor& Game::getActorById(unsigned int id)
{
    return *(*(p_actor_pool.find(id)->second));
}

template <typename P>
const P* Game::getPlugin() const
{
    for (Plugin* p : p_plugins)
        if (dynamic_cast<P*>(p))
            return dynamic_cast<P*>(p);
    return nullptr;
}

template <typename P>
P* Game::getPlugin()
{
    for (Plugin* p : p_plugins)
        if (dynamic_cast<P*>(p))
            return dynamic_cast<P*>(p);
    return nullptr;
}
