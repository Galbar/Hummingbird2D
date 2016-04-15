#ifndef HUM_GAME_HPP
#define HUM_GAME_HPP
#include <vector>
#include <unordered_set>
#include "Exceptions.hpp"
#include "Time.hpp"

namespace hum
{
class Plugin;
class Actor;
class Game
{
public:
    Game(unsigned int fixed_tickrate = 60);
    ~Game();
    void run();
    void destroy(Actor* actor);
    void destroy(Actor& actor);
    Actor* makeActor();
    const std::unordered_set<Actor*>& actors() const;
    const Time& deltaTime() const;
    void setRunning(bool running);
    Time fixedUpdateTime() const;
    Time fixedUpdateLag() const;

    template <typename P, class... Args>
    P* addPlugin(Args&&... args)
    {
        P* p = new P(args...);
        p->p_game = this;
        p_plugins.push_back(p);
        return p;
    }

    template <typename P>
    const P* getPlugin() const throw(exception::PluginNotFound)
    {
        P* plugin;
        for (Plugin* p : p_plugins)
            if ((plugin = dynamic_cast<P*>(p)) != nullptr)
                return plugin;
        throw exception::PluginNotFound();
    }

    template <typename P>
    P* getPlugin() throw(exception::PluginNotFound)
    {
        P* plugin;
        for (Plugin* p : p_plugins)
            if ((plugin = dynamic_cast<P*>(p)) != nullptr)
                return plugin;
        throw exception::PluginNotFound();
    }

private:
    bool p_running;
    const long c_nanoseconds_per_fixed_update;
    long p_fixed_update_lag;
    Time p_delta_time;

    std::unordered_set<Actor*> p_actor_pool;
    std::unordered_set<Actor*> p_actors_to_destroy;
    std::vector<Plugin*> p_plugins;
};
}
#endif
