#ifndef H2D_BEHAVIOUR_FACTORY_HPP
#define H2D_BEHAVIOUR_FACTORY_HPP
#include <functional>
#include <string>
#include <map>

namespace h2d
{
class Behaviour;
class BehaviourFactory
{
public:
    typedef std::function<Behaviour*()> Builder;

    static bool Register(const std::string& key, const Builder& builder);
    static Behaviour* Build(const std::string& key);

private:
    static std::map<std::string, Builder> s_map;
};

template <typename B>
Behaviour* behaviourBuilder()
{
    return new B();
}
}
#endif
