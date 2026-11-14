#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try 
	{
        Bureaucrat david("David", 0);
        std::cout << david << std::endl;
    } 
	catch(std::exception& e)
	{
        std::cout << "David: " << e.what() << std::endl;
    }
    
    try
	{
        Bureaucrat john("John", 151);
        std::cout << john << std::endl;
    }
	catch(std::exception& e)
	{
        std::cout << "John: " << e.what() << std::endl;
    }
    
    try
	{
        Bureaucrat roger("Roger", 70);
        std::cout << "Initial state: " << roger << std::endl;
        roger.decrementGrade();
        std::cout << "After decrementing: " << roger << std::endl;
    }
	catch(std::exception& e)
	{
        std::cout << "Roger: " << e.what() << std::endl;
    }
    
    try
	{
        Bureaucrat xenia("Xenia", 1);
        std::cout << "Initial state: " << xenia << std::endl;
        xenia.incrementGrade();
        std::cout << xenia << std::endl;
    }
	catch(std::exception& e)
	{
        std::cout << "Xenia tried to increment: " << e.what() << std::endl;
    }
    
    try 
	{
        Bureaucrat marta("Marta", 150);
        std::cout << "Inicio: " << marta << std::endl;
        marta.decrementGrade();
        std::cout << marta << std::endl;
    }
	catch(std::exception& e)
	{
        std::cout << "Marta tried to decrement: " << e.what() << std::endl;
    }

    return 0;
}