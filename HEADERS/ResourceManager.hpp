#ifndef H2D_RESOURCE_MANAGER_HPP
#define H2D_RESOURCE_MANAGER_HPP
#include <list>
#include <unordered_map>

namespace h2d
{
template <typename T>
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
 * Loads a resource from <filename>, if not already loaded.
 * Returns true if resource is loaded and can be accessed
 * and returns false otherwise.
 * Sets <filename> as the name of the resource.
 */
	virtual bool load(const std::string& filename)
	{
		auto it = p_resources.find(filename);
		if (it != p_resources.end())
			return true;

		T* resource = loadResource(filename);
		if (resource == nullptr)
			return false;
		p_resource_names.push_back(filename);
		p_resources.insert(std::make_pair (filename, resource));
		return true;
	}

/**
 * Loads a resource from <filename>, if not already loaded.
 * Returns true if resource is loaded and can be accessed
 * and returns false otherwise.
 * Sets <name> as the name of the resource.
 */
	virtual bool load(const std::string& name, const std::string& filename)
	{
		auto it = p_resources.find(name);
		if (it != p_resources.end())
			return true;

		T* resource = loadResource(filename);
		if (resource == nullptr)
			return false;
		p_resource_names.push_back(name);
		p_resources.insert(std::make_pair (name, resource));
		return true;
	}

	virtual T* get(const std::string& name)
	{
		auto it = p_resources.find(name);
		if (it != p_resources.end())
			return it->second;
		return nullptr;
	}

	virtual const T* get(const std::string& name) const
	{
		auto it = p_resources.find(name);
		if (it != p_resources.end())
			return it->second;
		return nullptr;
	}

	virtual void free(const std::string& name)
	{
		auto it = p_resources.find(name);
		if (it != p_resources.end())
		{
			p_resource_names.remove(name);
			p_resources.erase(name);
		}
	}

	virtual const std::list<std::string>& list() const
	{
		return p_resource_names;
	}

protected:
	virtual T* loadResource(const std::string& name) =0;

	std::list<std::string> p_resource_names;
	std::unordered_map<std::string, T*> p_resources;
};
}
#endif
