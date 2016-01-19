#ifndef H2D_GAME_HPP
#define H2D_GAME_HPP
#include <unordered_map>
#include <list>
#include <set>
#include "Time.hpp"

namespace h2d
{
class Actor;
class Plugin;
class Game
{
public:
    Game(unsigned int fixed_tickrate = 60);
    ~Game();
    void run();
    void destroy(const Actor& actor);
    Actor& makeActor();
    void addPlugin(Plugin& plugin);
    const std::list<Actor*>& actors() const;
    const Time& deltaTime() const;
    void setRunning(bool running);
    const Actor& getActorById(unsigned int id) const;
    Actor& getActorById(unsigned int id);
    template <typename P>
    const P* getPlugin() const;
    template <typename P>
    P* getPlugin();
    double fixedUpdateMilliseconds() const;
    double fixedUpdateLag() const;

private:
    bool p_running;
    const double c_ms_per_fixed_update;
    double p_fixed_update_lag;
    Time p_delta_time;

    std::unordered_map<unsigned int, std::list<Actor*>::iterator> p_actor_pool;
    std::list<Actor*> p_actors;
    std::list<Plugin*> p_plugins;

    std::set<unsigned int> p_actors_to_destroy;
};
}
#endif
