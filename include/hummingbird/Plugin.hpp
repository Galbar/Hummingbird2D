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
    virtual void gameStart();
    virtual void preUpdate();
    virtual void preFixedUpdate();
    virtual void postFixedUpdate();
    virtual void postUpdate();
    virtual void gameEnd();

protected:
    Game& game();
    const Game& game() const;

private:
    Game* p_game;
};
}
#endif
