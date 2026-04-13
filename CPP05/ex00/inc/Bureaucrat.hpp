#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    const std::string   _name;
    int                 _grade;
    static const int    _max_grade = 150;
    static const int    _min_grade = 1;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& orig);
		Bureaucrat& operator=(const Bureaucrat& orig);

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



#endif