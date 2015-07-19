#ifndef H2D_GAME_HPP
#define H2D_GAME_HPP
#include <unordered_map>
#include <list>
#include <set>
#include "Actor.hpp"
#include "Plugin.hpp"
#include "Clock.hpp"

namespace h2d
{
class Game
{
public:
	Game(unsigned int fixed_tickrate = 60):
	p_running(false),
	c_ms_per_fixed_update(1000.0 / (double)fixed_tickrate),
	p_fixed_update_lag(0.0)
	{};
	~Game()
	{};

	void run()
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

			for (Plugin* p : p_plugins)
				p->preUpdate();
			for (Actor* a : p_actors)
				a->preUpdate();

			while (p_fixed_update_lag >= c_ms_per_fixed_update)
			{
				for (Actor* a : p_actors)
					a->fixedUpdate();
				for (Plugin* p : p_plugins)
					p->fixedUpdate();
				p_fixed_update_lag -= c_ms_per_fixed_update;
			}

			for (Actor* a : p_actors)
				a->update();

			for (Actor* a : p_actors)
				a->postUpdate();
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

	void destroy(const Actor& actor)
	{
		p_actors_to_destroy.insert(actor.id());
	}

	Actor& makeActor()
	{
		Actor* a = new Actor(*this, p_actor_pool.size());
		p_actors.push_back(a);
		p_actor_pool[a->p_id] = --p_actors.end();
		return *a;
	}

	void addPlugin(Plugin& plugin)
	{
		plugin.setGame(*this);
		p_plugins.push_back(&plugin);
	}

	const std::list<Actor*>& actors() const
	{
		return p_actors;
	}

	const Time& deltaTime() const
	{
		return p_delta_time;
	}

	void setRunning(bool running)
	{
		p_running = running;
	}

	const Actor& getActorById(unsigned int id) const
	{
		return *(*(p_actor_pool.find(id)->second));
	}

	Actor& getActorById(unsigned int id)
	{
		return *(*(p_actor_pool.find(id)->second));
	}

	template <typename P>
	const P* getPlugin() const
	{
		for (Plugin* p : p_plugins)
			if (dynamic_cast<P*>(p))
				return dynamic_cast<P*>(p);
		return nullptr;
	}

	template <typename P>
	P* getPlugin()
	{
		for (Plugin* p : p_plugins)
			if (dynamic_cast<P*>(p))
				return dynamic_cast<P*>(p);
		return nullptr;
	}

	double fixedUpdateMilliseconds() const
	{
		return c_ms_per_fixed_update;
	}

	double fixedUpdateLag() const
	{
		return p_fixed_update_lag;
	}

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
