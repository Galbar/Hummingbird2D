#ifndef H2D_ACTOR_HPP
#define H2D_ACTOR_HPP
#include <memory>
#include <list>
#include "Exceptions.hpp"

namespace h2d
{
class Game;
class Behaviour;
class Transformation;
class Actor
{
    friend Game;
public:
    ~Actor();
    void preUpdate();
    void fixedUpdate();
    void onDestroy();
    Game& game();
    const Game& game() const;
    Transformation& transform();
    const Transformation& transform() const;
    template <typename B, class... Args>
    B* addBehaviour(Args&& ... args)
    {
        B* b = new B(args...);
        b->p_actor = this;
        p_asleep_behaviours.push_back(b);
        return b;
    }
    template <typename T>
    T* getBehaviour() throw(exception::BehaviourNotFound)
    {
        for (Behaviour* b : p_behaviours)
            if (dynamic_cast<T*>(b))
                return dynamic_cast<T*>(b);
        throw exception::BehaviourNotFound(T::behaviourName());
    }
    template <typename T>
    const T* getBehaviour() const throw(exception::BehaviourNotFound)
    {
        for (const Behaviour* b : p_behaviours)
            if (dynamic_cast<T*>(b))
                return dynamic_cast<T*>(b);
        throw exception::BehaviourNotFound(T::behaviourName());
    }
    template <typename T>
    std::list<T*> getBehaviours()
    {
        std::list<T*> v;
        for (Behaviour* b : p_behaviours)
            if (dynamic_cast<T*>(b))
                v.push_back(dynamic_cast<T*>(b));
        return v;
    }
    template <typename T>
    std::list<const T*> getBehaviours() const
    {
        std::list<const T*> v;
        for (const Behaviour* b : p_behaviours)
            if (dynamic_cast<T*>(b))
                v.push_back(dynamic_cast<T*>(b));
        return v;
    }

private:
    Actor(Game& game);

    Game* p_game;
    Transformation* p_transform;
    std::list<Behaviour*> p_behaviours;
    std::list<Behaviour*> p_asleep_behaviours;
};
}
#endif
