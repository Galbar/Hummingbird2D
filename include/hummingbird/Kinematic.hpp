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
    //! Class constructor
    Kinematic();
    //! Class destructor
    virtual ~Kinematic();

    virtual void init() override;
    virtual void onDestroy() override;

    /*!
     * \brief Get the transformation of the Actor after applying the kinematic movement
     * during a given time (<delta_time>).
     */
    virtual Transformation simulate(const Time& delta_time) const;

    /*!
     * \brief Get the velocity of the Kinematic Transformation.
     */
    Transformation& velocity();

    /*!
     * \brief Get the velocity of the Kinematic Transformation.
     */
    const Transformation& velocity() const;

    /*!
     * \brief Get the acceleration of the Kinematic Transformation.
     */
    Transformation& acceleration();

    /*!
     * \brief Get the acceleration of the Kinematic Transformation.
     */
    const Transformation& acceleration() const;

    static const char* behaviorName();

private:
    KinematicWorld* p_kinematic_world;
    Transformation p_velocity;
    Transformation p_acceleration;
};

/*!
  \class hum::Kinematic
  \brief Add Kinematic properties to the Actor. (Requires KinematicWorld).

  This Behavior allows to give a velocity and an acceleration to an Actor. This way
  the Actor's Transformation will change automatically overtime following a
  kinematic movement.

  Usage example:
  \code
  hum::Game game;
  game.addPlugin<hum::KinematicWorld>();

  hum:Actor* actor = game.makeActor();
  hum::Kinematic* k = actor->addBehavior<hum::Kinematic>();
  k->velocity().position.x = 5;
  k->acceleration().rotation.z = 2;
  \endcode
*/
}
#endif
