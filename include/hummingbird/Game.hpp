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
    /*!
      \brief Class constructor

      `fixed_tickrate` is the frequency of the `fixedUpdate`. By default 60Hz.
     */
    Game(unsigned int fixed_tickrate = 60);

    /*!
      \brief Class destructor

      Takes care of destroying any remaining Actor%s and Plugin%s.
     */
    ~Game();

    /*!
      \brief Run the Game

      Starts running the game loop. See the Game class description for the flow chart
      of the main loops steps.
     */
    void run();

    /*!
     \brief Get the delta Time of the game update.

     \return Time elapsed between previous update and current update.
     */
    const Time& deltaTime() const;

    /*!
     \brief Get the delta Time of the game fixedUpdate.

     \return Time elapsed between previous fixedUpdate and current fixedUpdate.
     */
    Time fixedUpdateTime() const;

    /*!
     \brief Get the Time since the last fixedUpdate.

     \return Time elapsed since the last fixedUpdate.
     */
    Time fixedUpdateLag() const;

    /*!
     \brief Set the Game's running status.
     */
    void setRunning(bool running);

    /*!
     \brief Create a new Actor instance.

     \return The new Actor instance's pointer.
     */
    Actor* makeActor();

    /*!
     \brief Mark an Actor to be destroyed.
     */
    void destroy(Actor* actor);

    /*!
     \brief Mark an Actor to be destroyed.
     */
    void destroy(Actor& actor);

    /*!
     \brief Get the Actor object pool.

     \return A set of pointers to all Actor%s.
     */
    const std::unordered_set<Actor*>& actors() const;

    /*!
     \brief Add a new Plugin to the Game.
      \tparam P The Plugin's type.
      \tparam Args The parameters for P's constructor.

     \return A `P` pointer to the new Plugin instance.
     */
    template <typename P, class... Args>
    P* addPlugin(Args&&... args)
    {
        P* p = new P(args...);
        p->p_game = this;
        p_plugins.push_back(p);
        return p;
    }

    /*!
     \brief Get and exisitng Plugin from the Game.
      \tparam P The Plugin's type.

     If the Game doesn't contain a Plugin of the given type it will throw a
     exception::PluginNotFound exception.

     \return A `P` pointer to the Plugin instance.
     */
    template <typename P>
    const P* getPlugin() const throw(exception::PluginNotFound)
    {
        P* plugin;
        for (Plugin* p : p_plugins)
            if ((plugin = dynamic_cast<P*>(p)) != nullptr)
                return plugin;
        throw exception::PluginNotFound();
    }

    /*!
     \brief Get and exisitng Plugin from the Game.
      \tparam P The Plugin's type.

     If the Game doesn't contain a Plugin of the given type it will throw a
     exception::PluginNotFound exception.

     \return A `P` pointer to the Plugin instance.
     */
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

/*!
  \class hum::Game
  \brief The class that runs the Game.

  The Game class handles the game loop and the lifecycle of the game. To start
  running a Game just call `Game::run()` and the Game instance will enter the
  following flow chart. The flow chart shows the lifecycle of a Game and the
  different steps that happen through it.

  \image html game_loop.png
  \image latex game_loop.png "Game loop"

  A Game instance can be queried for Time information at any step (when the
  Game is running). This information can be the deltaTime(), which is the Time
  that passed between the previous `update` and the current `update`; the fixedUpdateTime() which is
  the Time that passes between `fixedUpdate` and `fixedUpdate` and is calculated
  from the `fixed_tickrate` constructor parameter; and the
  fixedUpdateLag(), this last value is the Time since the last `fixedUpdate`.

  The running state of the Game can be controlled by using setRunning(). If set
  to `false` the game loop will exit and the Game will end. A Game instance
  should not be reused once the Game is done running, as the final state is not
  guaranteed in any way.

  The Game class also owns the Actor object pool and therefore handles the
  creation and destruction of Actors. Example code:
  \code
  hum::Game game;
  hum::Actor* new_actor = game.makeActor(); // creation of a new Actor;
  // ...
  game.destroy(new_actor); // mark the Actor to be destroyed.
  \endcode

  Actor%s are not destroyed right away, but marked to be destroyed and destroyed
  after `Plugin::postUpdate()`. All Actor%s are destroyed automatically after
  `Plugin:gameEnd()`.

  A Game instance can also contain Plugin%s. Plugin%s can implement functionality
  for the Game such as a rendering pipeline, scene management, etc. They can be
  added and queried by typename using addPlugin() and getPlugin() template methods
  respectively (example below).

  \code
  class MyPlugin : public hum::Plugin {...};

  hum::Game game;
  MyPlugin* mp = game.addPlugin<MyPlugin>();

  // somewhere else in the code (p.e. inside a Behavior)
  MyPlugin* mp = game().getPlugin<MyPlugin>();
  \endcode

  A Plugin shouldn't be added after calling run().
*/
}
#endif
