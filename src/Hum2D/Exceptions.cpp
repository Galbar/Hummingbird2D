#include "Exceptions.hpp"
using namespace h2d::exception;

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

BehaviorNotRegistered::BehaviorNotRegistered(const char* name)
{
    p_name = name;
}

const char* BehaviorNotRegistered::what() const noexcept
{
    return p_name;
}
