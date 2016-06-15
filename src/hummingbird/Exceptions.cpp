#include "Exceptions.hpp"
using namespace hum::exception;

BehaviorNotFound::BehaviorNotFound(const char* type_name)
{
    p_type_name = type_name;
}

const char* BehaviorNotFound::what() const noexcept
{
    return p_type_name;
}

const char* PluginNotFound::what() const noexcept
{
    return "Plugin not found in game.";
}
