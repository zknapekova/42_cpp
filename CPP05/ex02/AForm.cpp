#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm():
    _name("Default name"),
    _is_signed(false),
    _grade_to_sign(150),
    _grade_to_exec(150)
{ }


AForm::~AForm()
{ }

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec):
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

AForm::GradeTooLowException::GradeTooLowException(std::string msg):
    _msg(msg)
{ }

AForm::GradeTooLowException::GradeTooLowException():
    _msg("GradeTooLowException: The grade is too high.")
{ }

const char* AForm::GradeTooLowException::what() const throw()
{
    return _msg.c_str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{ }

AForm::GradeTooHighException::GradeTooHighException(std::string msg):
    _msg(msg)
{ }

AForm::GradeTooHighException::GradeTooHighException():
    _msg("GradeTooLowException: The grade is too high.")
{ }

const char* AForm::GradeTooHighException::what() const throw()
{
    return _msg.c_str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{ }

AForm::AForm(const AForm& orig):
    _name(orig._name),
    _is_signed(orig._is_signed),
    _grade_to_sign(orig._grade_to_sign),
    _grade_to_exec(orig._grade_to_exec)
{ }

AForm& AForm::operator=(const AForm& orig)
{
     if (this != &orig)
        _is_signed = orig._is_signed;
    return *this;
}

const std::string& AForm::getName() const
{
    return _name;
}

int AForm::getGradeToSign() const
{
    return _grade_to_sign;
}

int AForm::getGradeToExec() const
{
    return _grade_to_exec;
}

bool AForm::getIsSigned() const
{
    return _is_signed;
}

std::ostream &operator<<(std::ostream &o, const AForm &f)
{
    o << "AForm " << f.getName() << ", is_signed: " << f.getIsSigned() << ", grade_to_sign: " << f.getGradeToSign() << ", grade_to_exec: " << f.getGradeToExec();
    return o;
}

void    AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= _grade_to_sign)
        _is_signed = true;
    else
        throw GradeTooLowException("Bureaucrat's grade is too low for signing");
}

void    AForm::checkBeforeExec(Bureaucrat const& executor, std::string _target, int req_exec_grade) const
{
    if (!AForm::getIsSigned())
        throw std::invalid_argument("The form is not signed");
    
    if (executor.getGrade() > req_exec_grade)
        throw AForm::GradeTooLowException("The Bureaucrat's grade is too low for signing " +_target );

    return ;
}
