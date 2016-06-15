#ifndef HUM_PLUGIN_HPP
#define HUM_PLUGIN_HPP

namespace hum
{
class Game;
class Plugin
{
    friend Game;
public:
    Plugin();
    virtual ~Plugin();

    /*!
     * \brief Function called once on game start.
     */
    virtual void gameStart();

    /*!
     * \brief Function called before each update.
     */
    virtual void preUpdate();

    /*!
     * \brief Function called before each fixed update.
     */
    virtual void preFixedUpdate();

    /*!
     * \brief Function called after each fixed update.
     */
    virtual void postFixedUpdate();

    /*!
     * \brief Function called after each update.
     */
    virtual void postUpdate();

    /*!
     * \brief Function called once on game end.
     */
    virtual void gameEnd();

protected:
    /*!
     * Get the Plugin's Game.
     *
     * \return The Plugin's Game
     */
    Game& game();

    /*!
     * Get the Plugin's Game.
     *
     * \return The Plugin's Game
     */
    const Game& game() const;

private:
    Game* p_game;
};

/*!
  \class hum::Plugin
  \brief Class from which inherit to implement and give a Plugin for the Game.

  A Plugin always lives inside the Game. The Game takes care of the lifecycle
  of the Plugin.

  For creating a custom Plugin you may inherit from this class and override
  the methods you need to implement the wanted functionality.

  For more information on the lifecycle of a Game see that page.

  Usage example:
  \code
  class DeltaTimePlugin : public hum::Plugin
  {
    void gameStart() override {
      hum::log("Game just started");
    }

    void preUpdate() override {
      hum::log(game().deltaTime());
    }

    void preFixedUpdate() override {
      hum::log(game().fixedUpdateLag());
    }

    void postFixedUpdate() override {
      hum::log(game().fixedUpdateLag());
    }

    void postUpdate() override {
      hum::log(game().deltaTime());
    }

    void gameEnd() override {
      hum::log("Game just finished");
    }
  }
  \endcode
*/
}
#endif
