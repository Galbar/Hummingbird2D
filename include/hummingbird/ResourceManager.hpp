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

/**
 * Loads a resource from <data>, if not already loaded.
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

    virtual T* get(const Key& key)
    {
        auto it = p_resources.find(key);
        if (it != p_resources.end())
            return it->second;
        return nullptr;
    }

    virtual const T* get(const Key& key) const
    {
        auto it = p_resources.find(key);
        if (it != p_resources.end())
            return it->second;
        return nullptr;
    }

    virtual void free(const Key& key)
    {
        auto it = p_resources.find(key);
        if (it != p_resources.end())
        {
            p_resources.erase(key);
        }
    }

protected:
    virtual T* loadResource(const Data& data) =0;

    std::unordered_map<Key, T*> p_resources;
};
}
#endif
