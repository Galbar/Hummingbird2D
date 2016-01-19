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
            BehaviourNotFound(const std::string& type_name);
            virtual const char* what() const throw();

        private:
            std::string p_type;
        };

        class BehaviourNotRegistered : public std::exception
        {
        public:
            BehaviourNotRegistered(const std::string& name);
            virtual const char* what() const throw();

        private:
            std::string p_name;
        };
    }
}
#endif
