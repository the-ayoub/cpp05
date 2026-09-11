#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"),grade(150){}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade):name(_name),grade(_grade)
{
	if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name),grade(other.grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if(this->grade+1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Error: the grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Error: the grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
	return os <<other.getName() << ", bureaucrat grade " << other.getGrade() <<"." ;
}