#ifndef HUM_EXCEPTIONS_HPP
#define HUM_EXCEPTIONS_HPP
#include <exception>
#include <string>

namespace hum
{
    namespace exception
    {
        /*!
          \class BehaviorNotFound
          \brief Exception thrown when getting a Behavior from an Actor that
          does not contain it. (see Actor::getBehavior())
        */
        class BehaviorNotFound : public std::exception
        {
        public:
            BehaviorNotFound(const char* type_name);
            virtual const char* what() const noexcept override;

        private:
            const char* p_type_name;
        };

        /*!
          \class PluginNotFound
          \brief Exception thrown when getting a Plugin from a Game that
          does not contain it. (see Game::getPlugin())
        */
        class PluginNotFound : public std::exception
        {
        public:
            virtual const char* what() const noexcept override;
        };
    }
}
#endif
