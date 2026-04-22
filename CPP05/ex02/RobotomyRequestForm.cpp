#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm():
    AForm(),
    _target("None")
{ }

RobotomyRequestForm::RobotomyRequestForm(std::string target):
    AForm("RobotomyRequestForm", _req_sign_grade, _req_exec_grade),
    _target(target)
{ }

RobotomyRequestForm::~RobotomyRequestForm()
{ }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& orig):
    AForm("RobotomyRequestForm", _req_sign_grade, _req_exec_grade),
    _target(orig._target)
{ }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& orig)
{ 
    if (this != &orig)
        AForm::operator=(orig);
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
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
    
    std::cout << _target << " has been robotomized successfully 50\% of the time" << std::endl;
}
