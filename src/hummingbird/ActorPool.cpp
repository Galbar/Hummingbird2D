#include "ActorPool.hpp"
#include "Log.hpp"

using namespace hum;

ActorPool::ActorPool(Game* game):
game(game),
p_actor_id_counter(0)
{}

ActorPool::~ActorPool()
{
    clear();
}

Actor* ActorPool::create()
{
    Actor* actor = new Actor(*game, p_actor_id_counter);
    p_actor_by_id.insert(std::make_pair(p_actor_id_counter, actor));
    ++p_actor_id_counter;
    return actor;
}

void ActorPool::destroy(Actor* actor)
{
    if (p_actor_by_id.find(actor->id()) != p_actor_by_id.end())
    {
        p_actors_to_destroy.insert(actor);
    }
    else
    {
        hum::log("Trying to delete an non-existent Actor.");
    }
}

void ActorPool::destroy(Actor& actor)
{
    destroy(&actor);
}


void ActorPool::clear()
{
    for (auto it = begin(); it != end(); ++it)
    {
        destroy(it->second);
    }
    postUpdate();
}


void ActorPool::postUpdate()
{
    for (Actor* actor : p_actors_to_destroy)
    {
        unsigned int id = actor->id();
        auto tags_it = p_actor_id_to_tags.find(id);
        if (tags_it != p_actor_id_to_tags.end())
        {
            std::list<std::string>& tags = tags_it->second;
            for (const std::string& tag : tags)
            {
                p_actor_by_tag[tag].remove(actor);
            }
            tags.clear();
        }
        p_actor_id_to_tags.erase(id);
        p_actor_by_id.erase(id);
        actor->onDestroy();
        delete actor;
    }
    p_actors_to_destroy.clear();
}

Actor* ActorPool::getById(unsigned int id) const
{
    Actor* actor = nullptr;
    auto it = p_actor_by_id.find(id);
    if (it != p_actor_by_id.end())
    {
        actor = it->second;
    }
    return actor;
}


const std::list<Actor*>& ActorPool::getActorsByTag(const std::string& tag)
{
    return p_actor_by_tag[tag];
}

void ActorPool::addTag(Actor* actor, const std::string& tag)
{
    p_actor_by_tag[tag].push_back(actor);
    p_actor_id_to_tags[actor->id()].push_back(tag);
}

void ActorPool::removeTag(Actor* actor, const std::string& tag)
{
    p_actor_by_tag[tag].remove(actor);
    p_actor_id_to_tags[actor->id()].remove(tag);
}

std::unordered_map<unsigned int, Actor*>::const_iterator ActorPool::begin() const
{
    return p_actor_by_id.begin();
}

std::unordered_map<unsigned int, Actor*>::const_iterator ActorPool::end() const
{
    return p_actor_by_id.end();
}
