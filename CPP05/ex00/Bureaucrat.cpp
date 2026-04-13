#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat():
    _name("Default bureaucrati name"),
    _grade(150)
{ }


Bureaucrat::Bureaucrat(const std::string& name, int grade):
    _name(name),
    _grade(grade)
{ 
    if (_grade < Bureaucrat::_min_grade)
        throw Bureaucrat::GradeTooLowException();
    if (_grade > Bureaucrat::_min_grade)
        throw Bureaucrat::GradeTooHighException();
}


Bureaucrat::~Bureaucrat()
{ }


Bureaucrat::Bureaucrat(const Bureaucrat& orig):
	_name(orig._name),
    _grade(orig._grade)
{ }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& orig)
{
    if (this != &orig)
        _grade = orig._grade;
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "The grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "The grade is too low.";
}