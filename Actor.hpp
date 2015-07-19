#ifndef H2D_ACTOR_HPP
#define H2D_ACTOR_HPP
#include <memory>
#include <list>
#include <cassert>
#include "Behaviour.hpp"
#include "Transformation.hpp"

namespace h2d
{
class Game;
class Actor
{
	friend Game;
public:
	Transformation transform;
	~Actor()
	{}

	void preUpdate()
	{
		if (not p_asleep_behaviours.empty())
		{
			std::list<Behaviour*> to_init;
			while (not p_asleep_behaviours.empty())
			{
				std::list<std::unique_ptr<Behaviour>>::iterator b = p_asleep_behaviours.begin();
				to_init.push_back((*b).get());
				p_behaviours.emplace_back(std::move(*b));
				p_asleep_behaviours.pop_front();
			}
			for (Behaviour* b : to_init)
				b->init();
		}
		for (std::unique_ptr<Behaviour>& b : p_behaviours)
			b->preUpdate();
	}

	void fixedUpdate()
	{
		for (std::unique_ptr<Behaviour>& b : p_behaviours)
			b->fixedUpdate();
	}

	void update()
	{
		for (std::unique_ptr<Behaviour>& b : p_behaviours)
			b->update();
	}

	void postUpdate()
	{
		for (std::unique_ptr<Behaviour>& b : p_behaviours)
			b->postUpdate();
	}

	void onDestroy()
	{
		for (std::unique_ptr<Behaviour>& b : p_behaviours)
			b->onDestroy();
	}

	Game& game()
	{
		return *p_game;
	}

	const Game& game() const
	{
		return *p_game;
	}

	template <typename B, class... Args>
	B& addBehaviour(Args&& ... args)
	{
		B* b = new B(args...);
		b->p_actor = this;
		p_asleep_behaviours.push_back(std::unique_ptr<Behaviour>(b));
		return *b;
	}

	unsigned int id() const
	{
		return p_id;
	}

	template <typename T>
	T* getBehaviour()
	{
		for (std::unique_ptr<Behaviour>& b : p_behaviours)
			if (dynamic_cast<T*>(b.get()))
				return dynamic_cast<T*>(b.get());
		return nullptr;
	}

	template <typename T>
	const T* getBehaviour() const
	{
		for (const std::unique_ptr<Behaviour>& b : p_behaviours)
			if (dynamic_cast<T*>(b.get()))
				return dynamic_cast<T*>(b.get());
		return nullptr;
	}

	template <typename T>
	std::list<T*> getBehaviours()
	{
		std::list<T*> v;
		for (std::unique_ptr<Behaviour>& b : p_behaviours)
			if (dynamic_cast<T*>(b.get()))
				v.push_back(dynamic_cast<T*>(b.get()));
		return v;
	}

	template <typename T>
	std::list<const T*> getBehaviours() const
	{
		std::list<const T*> v;
		for (const std::unique_ptr<Behaviour>& b : p_behaviours)
			if (dynamic_cast<T*>(b.get()))
				v.push_back(dynamic_cast<T*>(b.get()));
		return v;
	}


private:
	Game* p_game;
	const unsigned int p_id;
	std::list<std::unique_ptr<Behaviour>> p_behaviours;
	std::list<std::unique_ptr<Behaviour>> p_asleep_behaviours;

	Actor(Game& game, unsigned int id):
	p_game(&game),
	p_id(id)
	{}
};
}
#endif
