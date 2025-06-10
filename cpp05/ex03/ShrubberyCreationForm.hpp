#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;
	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat &other) const;
};