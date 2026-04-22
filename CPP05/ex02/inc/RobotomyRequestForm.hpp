#ifndef ROBOTOMY_REQUEST_FROM
#define ROBOTOMY_REQUEST_FROM

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    const std::string _target;
    static const int    _req_sign_grade = 72;
    static const int    _req_exec_grade = 45;


    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& orig);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& orig);

        void    execute(Bureaucrat const& executor) const;
};

#endif