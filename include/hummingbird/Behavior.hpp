#ifndef HUM_BEHAVIOR_HPP
#define HUM_BEHAVIOR_HPP

namespace hum
{
class Actor;
class Behavior
{
    friend Actor;
public:
    //! Class destructor
    virtual ~Behavior();

    /*!
     * \brief Behavior initialization function.
     *
     * This method is called only once, the first preUpdate of the behavior
     * in the Actor.
     *
     * This method is useful for initializing values that require accessing
     * other Behavior%s in the Actor, as it guarantees that they are accessible
     * from this point on.
     *
     * It also guarantees that the Game is running and all Plugin%s' gameStart()
     * have been called at this point, therefore the Game has been initialized.
     */
    virtual void init();

    /*!
     * \brief Fixed update.
     *
     * The main method for updating the logic of the game.
     *
     * This method is called every fixed update. The frequency of the fixed
     * update depends on the settings of the Game that contains this Behavior's
     * Actor.
     */
    virtual void fixedUpdate();

    /*!
     * \brief Called when the Actor is activated.
     *
     * This method is not called when the Behavior is initialized as it is
     * assumed that a Behavior is only initialized if it's Actor is active.
     */
    virtual void onActivate();

    /*!
     * \brief Called when the Actor is deactivated.
     */
    virtual void onDeactivate();

    /*!
     * \brief Called when the Actor is about to be destroyed.
     */
    virtual void onDestroy();

    /*!
     * \brief Get the Behavior's Actor.
     *
     * \return The Behavior's Actor
     */
    Actor& actor();

    /*!
     * \brief Get the Behavior's Actor.
     *
     * \return The Behavior's Actor
     */
    const Actor& actor() const;

protected:
    Behavior();

private:
    Actor* p_actor;
};

/*!
  \class hum::Behavior
  \brief Class from which inherit to implement and give an Actor behavior.

  A Behavior always lives inside an Actor. Said actor takes care of the lifecycle
  of the Behavior.

  For creating a custom Behavior you may inherit from this class and override
  the methods you need to implement the wanted functionality.

  Behaviors must also implement a <code>static const char* behaviorName()</code> method that,
  as the name hints, returns the class name. This is used for error reporting.

  Usage example:
  \code
  class PrintTransform : public hum::Behavior
  {
  public:
      void init() override
      {
          hum::log("Behavior initialized");
      }

      void fixedUpdate() override
      {
          hum::log("Actor transformation: ", actor().transform());
      }

      void onDestroy() override
      {
          hum::log("Actor destroyed");
      }

      static const char* behaviorName()
      {
          return "PrintTransform";
      }
  }
  \endcode
*/
}
#endif
