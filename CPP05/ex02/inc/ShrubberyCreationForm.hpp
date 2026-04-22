#ifndef SHRUBBERY_CREATION_FROM
#define SHRUBBERY_CREATION_FROM

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
    const std::string _target;
    static const int    _req_sign_grade = 145;
    static const int    _req_exec_grade = 137;


    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& orig);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& orig);

        void    execute(Bureaucrat const& executor) const;


};

#endif