#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string& _name, int _gradeToSign, int _gradeToExecute)
	: name(_name), isSigned(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute) 
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other) 
{
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const 
{
	return this->isSigned;
}

int Form::getGradeToSign() const 
{
	return this->gradeToSign;
}

int Form::getGradeToExecute() const 
{
	return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) 
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() 
{
	return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) 
{
	os << "Form \"" << f.getName() << "\", signed: " << (f.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << f.getGradeToSign()
	   << ", grade to execute: " << f.getGradeToExecute();
	return os;
}