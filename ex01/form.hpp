#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Form{
    private:
        const std::string name;
        bool isSigned;
        const int gradeTosign;
        const int gradeToExecute;
    public:
        Form();
        Form(std::string _name, const int _gradeTosign, const int _gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        std::string getname()const;
        bool getisSigned()const;
        int getgradeTosign()const;
        int getgradeToExecute()const;
		class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    	class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif