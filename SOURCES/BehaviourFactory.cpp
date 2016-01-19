#include "BehaviourFactory.hpp"
#include "Exceptions.hpp"
using namespace h2d;

typedef std::function<Behaviour*()> Builder;

std::map<std::string, Builder> BehaviourFactory::s_map = std::map<std::string, Builder>();

bool BehaviourFactory::Register(const std::string& key, const Builder& builder)
{
    return s_map.insert(std::make_pair(key, builder)).second;
}

Behaviour* BehaviourFactory::Build(const std::string& key)
{
    auto it = s_map.find(key);
    if (it == s_map.end())
    {
        throw exception::BehaviourNotRegistered(key);
    }
    return (it->second)();
}
