#ifndef HUM_BEHAVIOR_HPP
#define HUM_BEHAVIOR_HPP

namespace hum
{
class Actor;
class Behavior
{
    friend Actor;
public:
    virtual ~Behavior();
    virtual void init();
    virtual void fixedUpdate();
    virtual void onActivate();
    virtual void onDeactivate();
    virtual void onDestroy();
    Actor& actor();
    const Actor& actor() const;

protected:
    Behavior();

private:
    Actor* p_actor;
};
}
#endif
