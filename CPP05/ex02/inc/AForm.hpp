#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
        const std::string   _name;
        bool                _is_signed;
        const int           _grade_to_sign;
        const int           _grade_to_exec;

    public:
        AForm();
        AForm(std::string name, int grade_to_sign, int grade_to_exec);
        virtual ~AForm();
        AForm(const AForm& orig);
        AForm& operator=(const AForm& orig);

        const std::string& getName() const;
        int getGradeToSign() const ;
        int getGradeToExec() const;
        bool getIsSigned() const;

        void            beSigned(Bureaucrat& b);
        virtual void    execute(Bureaucrat const& executor) const = 0;
        void            checkBeforeExec(Bureaucrat const& executor, std::string target, int req_exec_grade) const;

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

std::ostream &operator<<(std::ostream &o, const AForm &f);

#endif