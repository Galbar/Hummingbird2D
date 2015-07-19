#ifndef H2B_PLUGIN_HPP
#define H2B_PLUGIN_HPP

namespace h2d
{
class Game;
class Plugin
{
	friend Game;
public:
	Plugin()
	{}
	virtual ~Plugin()
	{}

	virtual void gameStart()
	{}
	virtual void preUpdate()
	{}
	virtual void fixedUpdate()
	{}
	virtual void postUpdate()
	{}
	virtual void gameEnd()
	{}


protected:
	Game& game()
	{
		return *p_game;
	}

	const Game& game() const
	{
		return *p_game;
	}

private:
	Game* p_game;

	void setGame(Game& game)
	{
		p_game = &game;
	}
};
}
#endif
