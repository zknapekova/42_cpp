#include "Bureaucrat.hpp"

int main()
{
    //check throwing exceptions in constructor
    try
    {
        Bureaucrat b1("test", -10);
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat b2("test", 1000);
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //check throwing another std::exception:
    try
    {
        Bureaucrat b3("test", 11);
        throw std::runtime_error("Another bureaucratic error");
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //check throwing non-standard exception:
    try
    {
        Bureaucrat b4("test", 11);
        throw 42;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Something went really wrong" << '\n';
        //throw; 
    }


    //check throwing exceptions in increment and decrement methods
    try
    {
        Bureaucrat b5(Bureaucrat("alpha", 2));
        std::cout << b5 << std::endl;
        b5.increment_grade();
        std::cout << b5 << std::endl;
        b5.increment_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat b5(Bureaucrat("beta", 149));
        std::cout << b5 << std::endl;
        b5.decrement_grade();
        std::cout << b5 << std::endl;
        b5.decrement_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}