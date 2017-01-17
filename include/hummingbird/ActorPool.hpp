#ifndef ACTORPOOL_H
#define ACTORPOOL_H
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include "Actor.hpp"


namespace hum
{
class Game;
class ActorPool
{
public:
    ActorPool(Game* game);
    virtual ~ActorPool();

    Actor* create();
    void destroy(Actor* actor);
    void destroy(Actor& actor);
    void clear();
    void postUpdate();
    /*!
      \brief Get Actor instance given its id.
      \param id Actor id.
      \return Pointer to Actor instance.
      */
    Actor* getById(unsigned int id) const;
    /*!
      \brief Get vector of Actor%s with the given name.
      \param name Name of the Actor%s.
      \return Vector of pointers to the Actor%s matching the given name.
      */
    const std::list<Actor*>& getActorsByTag(const std::string& tag);

    /*!
      \brief Add tag to the Actor.
      */
    void addTag(Actor* actor, const std::string& tag);

    /*!
      \brief Remove tag to the Actor.
      */
    void removeTag(Actor* actor, const std::string& tag);

    std::unordered_map<unsigned int, Actor*>::const_iterator begin() const;
    std::unordered_map<unsigned int, Actor*>::const_iterator end() const;

private:
    Game* game;
    unsigned int p_actor_id_counter;
    std::unordered_map<unsigned int, Actor*> p_actor_by_id;
    std::unordered_map<unsigned int, std::list<std::string>> p_actor_id_to_tags;
    std::unordered_map<std::string, std::list<Actor*>> p_actor_by_tag;
    std::unordered_set<Actor*> p_actors_to_destroy;
};
} /* hum */

#endif /* ACTORPOOL_H */
