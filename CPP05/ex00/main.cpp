#include "Bureaucrat.hpp"

int main()
{
    //check throwing exceptions in constructor
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

    //check throwing exceptions in increment and decrement methods
    try
    {
        Bureaucrat b3(Bureaucrat("alpha", 2));
        std::cout << b3 << std::endl;
        b3.decrement_grade();
        std::cout << b3 << std::endl;
        b3.decrement_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat b4(Bureaucrat("beta", 149));
        std::cout << b4 << std::endl;
        b4.increment_grade();
        std::cout << b4 << std::endl;
        b4.increment_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}