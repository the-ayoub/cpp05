#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Form invalidForm("Invalid", 0, 50);
	}
	catch (std::exception& e) {
		std::cout << "Exception creating form: " << e.what() << std::endl;
	}

	std::cout << "-------------------" << std::endl;

	Bureaucrat intern("Intern", 120);
	Bureaucrat director("Director", 10);
	Form contract("Contract", 50, 20);

	std::cout << contract << std::endl;
	intern.signForm(contract);
	std::cout << contract << std::endl;

	std::cout << "-------------------" << std::endl;

	director.signForm(contract);
	std::cout << contract << std::endl;

	return 0;
}