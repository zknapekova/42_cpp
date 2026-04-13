#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1(Bureaucrat("test", -10));
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat b2(Bureaucrat("test", 1000));
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}