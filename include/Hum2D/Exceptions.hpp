#ifndef H2D_EXCEPTIONS_HPP
#define H2D_EXCEPTIONS_HPP
#include <exception>
#include <string>

namespace h2d
{
    namespace exception
    {
        class BehaviorNotFound : public std::exception
        {
        public:
            BehaviorNotFound(const char* type_name);
            virtual const char* what() const noexcept override;

        private:
            const char* p_type_name;
        };

        class PluginNotFound : public std::exception
        {
        public:
            virtual const char* what() const noexcept override;
        };

        class BehaviorNotRegistered : public std::exception
        {
        public:
            BehaviorNotRegistered(const char* name);
            virtual const char* what() const noexcept override;

        private:
            const char* p_name;
        };
    }
}
#endif
