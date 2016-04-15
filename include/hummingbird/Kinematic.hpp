#ifndef HUM_KINEMATIC_HPP
#define HUM_KINEMATIC_HPP
#include "Behavior.hpp"
#include "Transformation.hpp"

namespace hum
{
class Time;
class KinematicWorld;
class Kinematic : public Behavior
{
public:
    Kinematic();
    virtual ~Kinematic();

    virtual void init() override;
    virtual void onDestroy() override;
    virtual Transformation simulate(const Time& delta_time) const;

    Transformation& velocity();
    const Transformation& velocity() const;
    Transformation& acceleration();
    const Transformation& acceleration() const;

    static const char* behaviorName();

private:
    KinematicWorld* p_kinematic_world;
    Transformation p_velocity;
    Transformation p_acceleration;
};
}
#endif
