#include "Plugin.hpp"

using namespace hum;

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
