#include "Exceptions.hpp"
using namespace h2d::exception;

BehaviourNotFound::BehaviourNotFound(const char* type_name)
{
    p_type_name = type_name;
}

const char* BehaviourNotFound::what() const noexcept
{
    return p_type_name;
}

const char* PluginNotFound::what() const noexcept
{
    return "Plugin not found in game.";
}

BehaviourNotRegistered::BehaviourNotRegistered(const char* name)
{
    p_name = name;
}

const char* BehaviourNotRegistered::what() const noexcept
{
    return p_name;
}
