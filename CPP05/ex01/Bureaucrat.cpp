#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():
    _name("Default bureaucratic name"),
    _grade(150)
{ }


Bureaucrat::Bureaucrat(const std::string& name, int grade):
    _name(name),
    _grade(grade)
{ 
    if (_grade > Bureaucrat::_lowest_grade)
        throw GradeTooLowException();
    if (_grade < Bureaucrat::_highest_grade)
        throw GradeTooHighException();
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
    return "GradeTooHighException: The grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException: The grade is too low.";
}

const std::string& Bureaucrat::get_name() const
{
    return _name;
}

int Bureaucrat::get_grade() const
{
    return _grade;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
    o << b.get_name() << ", bureaucrat grade " << b.get_grade();
    return o;
}

void    Bureaucrat::increment_grade()
{
    if (_grade <= _highest_grade)
        throw GradeTooHighException();
    _grade--;
}


void    Bureaucrat::decrement_grade()
{
    if (_grade >= _lowest_grade)
        throw GradeTooLowException();
    _grade++;
}

void    Bureaucrat::signForm(Form& f)
{
    
    if (f.get_is_signed())
    {
        std::cerr << get_name() << " couldn't sign " << f.get_name() << " because it's been already signed.\n";
        return ;
    }
    try
    {
        f.beSigned(*this);
        std::cout << get_name() << " signed " << f.get_name() << std::endl;
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << get_name() << " couldn't sign " << f.get_name() << " because: " << e.what() << std::endl;
        throw;
    }
    catch(...)
    {
        std::cerr << get_name() << " couldn't sign " << f.get_name() << " because of unexpected error\n";
        throw;
    }
}