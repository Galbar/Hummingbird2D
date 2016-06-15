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

    /*!
     * \brief Add a Kinematic Behavior to handle by the Plugin. (Internal use).
     */
    void add(Kinematic* kinematic);

    /*!
     * \brief Remove a Kinematic Behavior to handle by the Plugin. (Internal use).
     */
    void remove(Kinematic* kinematic);

    void preFixedUpdate() override;
protected:
    std::set<Kinematic*> p_kinematics;
};

/*!
  \class hum::KinematicWorld
  \brief Plugin that handles the transformation (movement, scale or rotation)
  of an Actor with a Kinematic behavior.


  Usage example:
  \code
  hum::Game game;
  game.addPlugin<hum::KinematicWorld>();
  \endcode
*/
}
#endif
