#ifndef H2B_PLUGIN_HPP
#define H2B_PLUGIN_HPP

namespace h2d
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
    virtual void fixedUpdate();
    virtual void postUpdate();
    virtual void gameEnd();

protected:
    Game& game();
    const Game& game() const;

private:
    void setGame(Game& game);
    Game* p_game;
};
}
#endif
