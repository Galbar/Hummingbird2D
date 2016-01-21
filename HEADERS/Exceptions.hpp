#ifndef H2D_EXCEPTIONS_HPP
#define H2D_EXCEPTIONS_HPP
#include <exception>
#include <string>

namespace h2d
{
    namespace exception
    {
        class BehaviourNotFound : public std::exception
        {
        public:
            BehaviourNotFound(const char* type_name);
            virtual const char* what() const noexcept override;

        private:
            const char* p_type_name;
        };

        class BehaviourNotRegistered : public std::exception
        {
        public:
            BehaviourNotRegistered(const char* name);
            virtual const char* what() const noexcept override;

        private:
            const char* p_name;
        };
    }
}
#endif
