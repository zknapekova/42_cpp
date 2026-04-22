#ifndef PRESIDENTIAL_PARDON_FROM
#define PRESIDENTIAL_PARDON_FROM

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    const std::string _target;
    static const int    _req_sign_grade = 25;
    static const int    _req_exec_grade = 5;


    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& orig);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& orig);

        void    execute(Bureaucrat const& executor) const;
};

#endif