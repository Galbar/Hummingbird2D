#ifndef H2D_ACTOR_HPP
#define H2D_ACTOR_HPP
#include <memory>
#include <list>
#include "Exceptions.hpp"
#include "Transformation.hpp"

namespace h2d
{
class Game;
class Behavior;
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
    B* addBehavior(Args&& ... args)
    {
        B* b = new B(args...);
        b->p_actor = this;
        p_asleep_behaviors.push_back(b);
        return b;
    }
    template <typename T>
    T* getBehavior() throw(exception::BehaviorNotFound)
    {
        T* behavior;
        for (Behavior* b : p_behaviors)
            if ((behavior = dynamic_cast<T*>(b)) != nullptr)
                return behavior;
        throw exception::BehaviorNotFound(T::behaviorName());
    }
    template <typename T>
    const T* getBehavior() const throw(exception::BehaviorNotFound)
    {
        T* behavior;
        for (const Behavior* b : p_behaviors)
            if ((behavior = dynamic_cast<T*>(b)) != nullptr)
                return behavior;
        throw exception::BehaviorNotFound(T::behaviorName());
    }
    template <typename T>
    std::list<T*> getBehaviors()
    {
        std::list<T*> v;
        T* behavior;
        for (Behavior* b : p_behaviors)
            if ((behavior = dynamic_cast<T*>(b)) != nullptr)
                v.push_back(behavior);
        return v;
    }
    template <typename T>
    std::list<const T*> getBehaviors() const
    {
        std::list<const T*> v;
        T* behavior;
        for (const Behavior* b : p_behaviors)
            if ((behavior = dynamic_cast<T*>(b)) != nullptr)
                v.push_back(behavior);
        return v;
    }

private:
    Actor(Game& game);

    Game* p_game;
    Transformation p_transform;
    std::list<Behavior*> p_behaviors;
    std::list<Behavior*> p_asleep_behaviors;
};
}
#endif
