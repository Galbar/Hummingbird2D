#ifndef H2D_BEHAVIOUR_HPP
#define H2D_BEHAVIOUR_HPP

namespace h2d
{
class Actor;
class Behaviour
{
	friend Actor;
public:
	virtual ~Behaviour()
	{}

	virtual void init()
	{}
	virtual void preUpdate()
	{}
	virtual void fixedUpdate()
	{}
	virtual void update()
	{}
	virtual void postUpdate()
	{}
	virtual void onDestroy()
	{}

	Actor& actor()
	{
		return *p_actor;
	}

	const Actor& actor() const
	{
		return *p_actor;
	}

protected:
	Behaviour():
	p_actor(nullptr)
	{}

private:
	Actor* p_actor;
};
}
#endif
