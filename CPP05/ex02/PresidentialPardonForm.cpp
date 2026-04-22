#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():
    AForm(),
    _target("None")
{ }

PresidentialPardonForm::PresidentialPardonForm(std::string target):
    AForm("PresidentialPardonForm", _req_sign_grade, _req_exec_grade),
    _target(target)
{ }

PresidentialPardonForm::~PresidentialPardonForm()
{ }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& orig):
    AForm("PresidentialPardonForm", _req_sign_grade, _req_exec_grade),
    _target(orig._target)
{ }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& orig)
{ 
    if (this != &orig)
        AForm::operator=(orig);
    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
{    
    try
    {
        checkBeforeExec(executor, _target, _req_exec_grade);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Robotomy failed\n";
        throw ;
    }
    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
