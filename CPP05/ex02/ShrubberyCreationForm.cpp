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
    if (!AForm::getIsSigned())
    {
        std::cout << "The form is not signed\n";
        return ;
    }  
    
    if (executor.getGrade() > _req_exec_grade)
    {
        AForm::GradeTooLowException("The Bureaucrat's grade is too low for signing ShrubberyCreationForm");
        return ;
    }
    
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    //TODO: add check
    file << "  *\n";
    file << " ***\n";
    file << "*****\n";
    file << "  ##\n";
}
