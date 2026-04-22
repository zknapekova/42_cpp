#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    //create test bureaucrats
    Bureaucrat* b = NULL;
    Bureaucrat* b2 = NULL;
    try
    {
        b = new Bureaucrat("highest_grade_bureaucrat", 1);
        std::cout << *b << std::endl;

        b2 = new Bureaucrat("lowest_grade_bureaucrat", 150);
        std::cout << *b2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Something went wrong when creating testing bureaucrats\n";
        return 0;
    }
    
    try
    {
        ShrubberyCreationForm shcf1("ShcF1");
        std::cout << shcf1 << std::endl;
        b->signForm(shcf1);

        shcf1.execute(*b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Something went wrong when creating test ShrubberyCreationForm\n";
        delete b;
        delete b2;
        return 0;
    }

    //ShrubberyCreationForm is not signed
    try
    {
        ShrubberyCreationForm shcf_not_signed("ShcF_not_signed");
        std::cout << shcf_not_signed << std::endl;

        shcf_not_signed.execute(*b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Something went wrong when creating test ShrubberyCreationForm\n";
        delete b;
        delete b2;
        return 0;
    }

     //Bureaucrat's grade is too low
    try
    {
        ShrubberyCreationForm shcf2("ShcF2");
        std::cout << shcf2 << std::endl;
        b2->signForm(shcf2);

        shcf2.execute(*b2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Something went wrong when creating test ShrubberyCreationForm\n";
        delete b;
        delete b2;
        return 0;
    }

    delete b;
    delete b2;
}