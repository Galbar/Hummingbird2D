#ifndef HUM_KINEMATIC_WORLD
#define HUM_KINEMATIC_WORLD
#include <set>
#include "Plugin.hpp"

namespace hum
{
class Kinematic;
class KinematicWorld : public Plugin
{
public:
    KinematicWorld();
    virtual ~KinematicWorld();

    void add(Kinematic* kinematic);
    void remove(Kinematic* kinematic);
    void preFixedUpdate() override;
protected:
    std::set<Kinematic*> p_kinematics;
};
}
#endif
