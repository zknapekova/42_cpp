#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form f1("F1", 11, 12);
    std::cout << f1 << std::endl;

    //grade_to_sign exception
    try
    {
        Form f2("F1", 1500, 12);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //grade_to_exec exception
    try
    {
        Form f3("F1", 10, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //signForm check:
    try
    {
        Bureaucrat b1("B1", 1);
        b1.signForm(f1);
        std::cout << "_is_signed: " << f1.get_is_signed() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //signForm exception:
    Form f4("F1", 11, 12);
    try
    {
        Bureaucrat b2("B2", 150);
        b2.signForm(f4);
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught" << std::endl;
        std::cout << "_is_signed: " << f4.get_is_signed() << std::endl;
    }

}