#include "Plugin.hpp"

using namespace h2d;

Plugin::Plugin()
{}

Plugin::~Plugin()
{}

void Plugin::gameStart()
{}

void Plugin::preUpdate()
{}

void Plugin::preFixedUpdate()
{}

void Plugin::postFixedUpdate()
{}

void Plugin::postUpdate()
{}

void Plugin::gameEnd()
{}

Game& Plugin::game()
{
    return *p_game;
}

const Game& Plugin::game() const
{
    return *p_game;
}

void Plugin::setGame(Game& game)
{
    p_game = &game;
}
