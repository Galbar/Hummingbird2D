#ifndef H2D_BEHAVIOUR_HPP
#define H2D_BEHAVIOUR_HPP

namespace h2d
{
class Actor;
class Behaviour
{
    friend Actor;
public:
    virtual ~Behaviour();
    virtual void init();
    virtual void fixedUpdate();
    virtual void onDestroy();
    Actor& actor();
    const Actor& actor() const;

protected:
    Behaviour();

private:
    Actor* p_actor;
};
}
#endif
