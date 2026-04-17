#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    const std::string   _name;
    bool                _is_signed;
    const int           _grade_to_sign;
    const int           _grade_to_exec;

    public:
        Form();
        Form(std::string name, int grade_to_sign, int grade_to_exec);
        ~Form();
        Form(const Form& orig);
        Form& operator=(const Form& orig);

        const std::string& get_name() const;
        int get_grade_to_sign() const ;
        int get_grade_to_exec() const;
        bool get_is_signed() const;

        void    beSigned(Bureaucrat& b);

        class GradeTooHighException: public std::exception
        {   
            const std::string _msg;

            public:
                GradeTooHighException(std::string msg);
                GradeTooHighException();
                ~GradeTooHighException() throw();
                const char* what() const throw();
        };

        class GradeTooLowException: public std::exception
        {              
            const std::string _msg;
            
            public:
                GradeTooLowException(std::string msg);
                GradeTooLowException();
                ~GradeTooLowException() throw();
                const char* what() const throw();
        };

};

std::ostream &operator<<(std::ostream &o, const Form &f);

#endif