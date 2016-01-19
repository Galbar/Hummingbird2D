#include "Exceptions.hpp"
using namespace h2d::exception;

BehaviourNotFound::BehaviourNotFound(const std::string& type_name)
{
    p_type = type_name;
}

const char* BehaviourNotFound::what() const throw()
{
    return ("Behaviour of type " + p_type + " not found.").c_str();
}

BehaviourNotRegistered::BehaviourNotRegistered(const std::string& name)
{
    p_name = name;
}

const char* BehaviourNotRegistered::what() const throw()
{
    return ("Behaviour of type " + p_name + " not registered in BehaviourBuilder.").c_str();
}
