#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;
	PresidentialPardonForm();

public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	void execute(const Bureaucrat &other) const;
};