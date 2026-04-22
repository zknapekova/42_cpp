#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
    AForm(),
    _target("None")
{ }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
    AForm("ShrubberyCreationForm", _req_sign_grade, _req_exec_grade),
    _target(target)
{ }

ShrubberyCreationForm::~ShrubberyCreationForm()
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& orig):
    AForm("ShrubberyCreationForm", _req_sign_grade, _req_exec_grade),
    _target(orig._target)
{ }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& orig)
{ 
    if (this != &orig)
    {
        AForm::operator=(orig);
    }
    return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{    
    try
    {
        checkBeforeExec(executor, _target, _req_exec_grade);
    }
    catch(const std::exception& e)
    {
        std::cerr << "ShrubberyCreationForm check failed\n";
        throw ;
    }
    
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "File " << filename << "failed to open\n";
        return ;
    }
    file << "  *\n";
    file << " ***\n";
    file << "*****\n";
    file << "  #\n";

    file.close();
}
