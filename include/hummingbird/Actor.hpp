#ifndef HUM_ACTOR_HPP
#define HUM_ACTOR_HPP
#include <memory>
#include <vector>
#include "Exceptions.hpp"
#include "Transformation.hpp"

namespace hum
{
class Game;
class Behavior;
class Actor
{
    friend Game;
public:
    //! Class destructor
    ~Actor();

    /*!
      \brief Pre update

      In this method are initialized the actor's Behavior%s that haven't been
      initialized up to this point.
    */
    void preUpdate();

    /*!
      \brief Fixed update

      This method is called every Game's fixed update. It call all its Behaviors'
      fixedUpdate().
    */
    void fixedUpdate();

    /*!
      \brief Called just before destroying the Actor.

      It call its Behavior%s' onDestroy() method.
    */
    void onDestroy();

    /*!
      \brief Get the Actor's Game.

      \return The Game this Actor belongs.
    */
    Game& game();

    /*!
      \brief Get the Actor's Game.

      \return The Game this Actor belongs.
    */
    const Game& game() const;

    /*!
      \brief Get the Actor's Transformation.

      \return This Actor's Transformation.
    */
    Transformation& transform();

    /*!
      \brief Get the Actor's Transformation.

      \return This Actor's Transformation.
    */
    const Transformation& transform() const;

    /*!
      \brief Check if the Actor is active.

      If an Actor is not active, it is not updated

      \return true if the Actor is active, false otherwise.
    */
    bool isActive();

    //! Set the Actor active.
    void activate();

    //! Set the Actor inactive.
    void deactivate();

    /*!
      \brief Add a new Behavior to the Actor.
      \tparam B The Behavior's type.
      \tparam Args The parameters for B's constructor.

      This method will create a new instance of the given type B, add it to the
      Actor.

      \return A pointer to the new instance of the given Behavior type.
    */
    template <typename B, class... Args>
    B* addBehavior(Args&& ... args)
    {
        B* b = new B(args...);
        b->p_actor = this;
        p_asleep_behaviors.push_back(b);
        return b;
    }

    /*!
      \brief Get a Behavior of the given type in the Actor.
      \tparam T The Behavior's type.

      if the Actor doesn't have a Behavior of type T it will throw a
      exception::BehaviorNotFound.

      \return A pointer to the first Behavior of type T in the Actor.
    */
    template <typename T>
    T* getBehavior() throw(exception::BehaviorNotFound)
    {
        T* behavior;
        for (Behavior* b : p_behaviors)
            if ((behavior = dynamic_cast<T*>(b)) != nullptr)
                return behavior;
        throw exception::BehaviorNotFound(T::behaviorName());
    }

    /*!
      \brief Get a Behavior of the given type in the Actor.
      \tparam T The Behavior's type.

      if the Actor doesn't have a Behavior of type T it will throw a
      exception::BehaviorNotFound.

      \return A pointer to the first Behavior of type T in the Actor.
    */
    template <typename T>
    const T* getBehavior() const throw(exception::BehaviorNotFound)
    {
        T* behavior;
        for (const Behavior* b : p_behaviors)
            if ((behavior = dynamic_cast<T*>(b)) != nullptr)
                return behavior;
        throw exception::BehaviorNotFound(T::behaviorName());
    }

    /*!
      \brief Get all Behavior%s of a type in the Actor.
      \tparam T The Behavior's type.

      \return A std::vector<T*> with all the Behaviors of type T, if any.
    */
    template <typename T>
    std::vector<T*> getBehaviors()
    {
        std::vector<T*> v;
        T* behavior;
        for (Behavior* b : p_behaviors)
            if ((behavior = dynamic_cast<T*>(b)) != nullptr)
                v.push_back(behavior);
        return v;
    }

    /*!
      \brief Get all Behavior%s of a type in the Actor.
      \tparam T The Behavior's type.

      \return A std::vector<T*> with all the Behaviors of type T, if any.
    */
    template <typename T>
    std::vector<const T*> getBehaviors() const
    {
        std::vector<const T*> v;
        T* behavior;
        for (const Behavior* b : p_behaviors)
            if ((behavior = dynamic_cast<T*>(b)) != nullptr)
                v.push_back(behavior);
        return v;
    }

private:
    Actor(Game& game);

    bool p_is_active;
    Game* p_game;
    Transformation p_transform;
    std::vector<Behavior*> p_behaviors;
    std::vector<Behavior*> p_asleep_behaviors;
};

/*!
  \class hum::Actor
  \brief Actor (also known as GameObject).

  This class represents an object in the Game. You can create a new Actor by calling
  Game::makeActor(). This method will create a new Actor and return it. The Game owns
  the Actor and it controls its lifetime.

  To __destroy__ an Actor you __must__ call Game::destroy(), not its destructor.
  The Actor then, will be marked to be destroyed and after the next update step
  it'll be deleted. Just before being deleted, the Actor will call its
  Behavior%s onDestroy() method.

  An Actor, by default, doesn't have any behaviour and __you should not inherit
  from it__.  Instead Actor%s are composed by Behavior%s. These Behavior%s are
  the ones that must implement the behaviour of the Actor composed by them.

  On the other hand, Actor%s do have a Transformation, accessible through transform()
  and a reference to its Game, accessible through game().

  A Actor can be __active__ or __inactive__. If a Actor is __inactive__ it exists,
  all its Behavior%s also exist and have been instantiated; but it __won't__
  be updated. Same applies to its Behavior%s.

  Usage example. The Actor will be destroyed after 10 fixed updates:
  \code
  // We define two Behaviors: A and B.
  class B : public hum::Behavior
  {
  public:
      B(int x): value(x)
      {}

      int value;
  }

  class A : public hum::Behavior
  {
  public:
      A(int x): current(x)
      {}

      void init() override
      {
          last = actor().getBehavior<B>()->value;
      }

      void fixedUpdate() override
      {
          current++;
          if (current > last)
          {
              actor().game().destroy(actor());
          }
          hum::log(current);
      }

  private:
      int last, current;
  }

  int main()
  {
      hum::Game g;
      hum::Actor* a = g.makeActor();
      // here we add the A and B to the Actor.
      A* t = a->addBehavior<A>(1);
      a->addBehavior<B>(10);
      g.run();
      return 0;
  }
      \endcode
*/
}
#endif
