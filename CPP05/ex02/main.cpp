#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        ShrubberyCreationForm shcf1("ShcF1");

        AForm* f = new ShrubberyCreationForm();
        std::cout << *f;

        Bureaucrat b("test_bureaucrat", 1);
        b.signForm(shcf1);

        shcf1.execute(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}