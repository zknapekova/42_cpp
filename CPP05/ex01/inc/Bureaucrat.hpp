#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
    const std::string   _name;
    int                 _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& orig);
		Bureaucrat& operator=(const Bureaucrat& orig);

        const std::string&  getName() const ;
        int                 getGrade() const;
        void                signForm(Form& f);

        void    incrementGrade();
        void    decrementGrade();

        static const int    _highest_grade = 1;
        static const int    _lowest_grade = 150;


        class GradeTooHighException: public std::exception
        {   
            public:
                const char* what() const throw(); //noexcept in C++11
        };

        class GradeTooLowException: public std::exception
        {              
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);


#endif