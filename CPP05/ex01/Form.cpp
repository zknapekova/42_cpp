#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form():
    _name("Default name"),
    _is_signed(false),
    _grade_to_sign(150),
    _grade_to_exec(150)
{ }


Form::~Form()
{ }

Form::Form(std::string name, int grade_to_sign, int grade_to_exec):
    _name(name),
    _is_signed(false),
    _grade_to_sign(grade_to_sign),
    _grade_to_exec(grade_to_exec)
{
    if (_grade_to_exec > Bureaucrat::_lowest_grade)
        throw GradeTooLowException("The grade_to_exec is too low");
    if (_grade_to_sign > Bureaucrat::_lowest_grade)
        throw GradeTooLowException("The grade_to_sign is too low");
    if (_grade_to_exec < Bureaucrat::_highest_grade)
        throw GradeTooHighException("The grade_to_exec is too high");
    if (_grade_to_sign < Bureaucrat::_highest_grade)
        throw GradeTooHighException("The grade_to_sign is too high");
}

Form::GradeTooLowException::GradeTooLowException(std::string msg):
    _msg(msg)
{ }

Form::GradeTooLowException::GradeTooLowException():
    _msg("GradeTooLowException: The grade is too high.")
{ }

const char* Form::GradeTooLowException::what() const throw()
{
    return _msg.c_str();
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{ }

Form::GradeTooHighException::GradeTooHighException(std::string msg):
    _msg(msg)
{ }

Form::GradeTooHighException::GradeTooHighException():
    _msg("GradeTooLowException: The grade is too high.")
{ }

const char* Form::GradeTooHighException::what() const throw()
{
    return _msg.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{ }

Form::Form(const Form& orig):
    _name(orig._name),
    _is_signed(orig._is_signed),
    _grade_to_sign(orig._grade_to_sign),
    _grade_to_exec(orig._grade_to_exec)
{ }

Form& Form::operator=(const Form& orig)
{
     if (this != &orig)
        _is_signed = orig._is_signed;
    return *this;
}

const std::string& Form::getName() const
{
    return _name;
}

int Form::getGradeToSign() const
{
    return _grade_to_sign;
}

int Form::getGradeToExec() const
{
    return _grade_to_exec;
}

bool Form::getIsSigned() const
{
    return _is_signed;
}

std::ostream &operator<<(std::ostream &o, const Form &f)
{
    o << "Form " << f.getName() << ", is_signed: " << f.getIsSigned() << ", grade_to_sign: " << f.getGradeToSign() << ", grade_to_exec: " << f.getGradeToExec();
    return o;
}

void    Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= _grade_to_sign)
        _is_signed = true;
    else
        throw GradeTooLowException("Bureaucrat's grade is too low for signing");
}
