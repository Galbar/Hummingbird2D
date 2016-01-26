#ifndef H2D_KINEMATIC_HPP
#define H2D_KINEMATIC_HPP
#include "Behaviour.hpp"

namespace h2d
{
class Time;
class Transformation;
class Kinematic : public Behaviour
{
public:
    Kinematic();
    virtual ~Kinematic();

    virtual void init() override;
    virtual void onDestroy() override;
    virtual Transformation simulate(const Time& delta_time) const;

    static const char* behaviourName();

    double velocity_x;
    double velocity_y;
    double velocity_z;

    double acceleration_x;
    double acceleration_y;
    double acceleration_z;

    double rotation_velocity;
    double rotation_acceleration;

    double scale_velocity_x;
    double scale_velocity_y;

    double scale_acceleration_x;
    double scale_acceleration_y;
};
}
#endif
