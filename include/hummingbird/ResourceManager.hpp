#ifndef HUM_RESOURCE_MANAGER_HPP
#define HUM_RESOURCE_MANAGER_HPP
#include <string>
#include <list>
#include <unordered_map>

namespace hum
{
template <typename T, typename Key = std::string, typename Data = std::string>
class ResourceManager
{
public:
    ResourceManager()
    {}

    virtual ~ResourceManager()
    {
        for(auto e : p_resources)
            delete e.second;
    }

    /*!
     * \brief Loads a resource from <data>, if not already loaded.
     *
     * Returns true if resource is loaded and can be accessed
     * and returns false otherwise.
     * Sets <key> as the name of the resource.
     */
    virtual bool load(const Key& key, const Data& data)
    {
        auto it = p_resources.find(key);
        if (it != p_resources.end())
            return true;

        T* resource = loadResource(data);
        if (resource == nullptr)
            return false;
        p_resources.insert(std::make_pair (key, resource));
        return true;
    }

    /*!
     * \brief Get a pointer to the resource identified by <key>. If not loaded
     * returns <code>nullptr</code>.
     */
    virtual T* get(const Key& key)
    {
        auto it = p_resources.find(key);
        if (it != p_resources.end())
            return it->second;
        return nullptr;
    }

    /*!
     * \brief Get a pointer to the resource identified by <key>. If not loaded
     * returns <code>nullptr</code>.
     */
    virtual const T* get(const Key& key) const
    {
        auto it = p_resources.find(key);
        if (it != p_resources.end())
            return it->second;
        return nullptr;
    }

    /*!
     * \brief Free the resource identified by <key>. If not loaded it does nothing.
     */
    virtual void free(const Key& key)
    {
        auto it = p_resources.find(key);
        if (it != p_resources.end())
        {
            p_resources.erase(key);
        }
    }

protected:
    /*!
     * \brief Function to implement for loading the new instance of the resource type.
     *
     * It recieves a Data (by default <code>std::string</code>) with information
     * to load the new resource instance.
     *
     * If there is an error when loading the resource it must return <code>nullptr</code>.
     */
    virtual T* loadResource(const Data& data) =0;

    std::unordered_map<Key, T*> p_resources;
};

/*!
  \class hum::ResourceManager
  \brief Class that implements the generic functionality of a resource manager.

  This template class has three type parameters, two of which are optional. The
  first is the type of the data to manage. The second one is the type of the
  key to identify the managed data (<code>std::string</code> by default). The third is the data needed to load the
  resource (<code>std::string</code> by default).

  Usage example (SFML Texture manager):
  \code
  class TextureManager : public ResourceManager<sf::Texture>
  {
  protected:
    sf::Texture* loadResource(const std::string& name) override
    {
      sf::Texture* resource = new sf::Texture();
      if (not resource->loadFromFile(name))
        return nullptr;
      return resource;
    }
  };

  //...

  TextureManager tm;

  if (!tm.load("cat", "cat.jpg")) {
    hum::log_e("Error loading cat.jpg");
  }
  if (!tm.load("dog", "dog.jpg")) {
    hum::log_e("Error loading dog.jpg");
  }

  sf::Texture* cat = tm.get("cat"); // get the texture

  tm.free("cat"); // unload the cat texture manually

  // when destroyed the resource manager will free all loaded resources.

  \endcode
*/
}
#endif
