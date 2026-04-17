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

}