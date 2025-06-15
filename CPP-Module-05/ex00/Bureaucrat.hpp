#ifndef BUREACRAT_HPP
#define BUREACRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
private:
    const std::string name;
    int grade;
public:
    	Bureaucrat();
	    Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat	&operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string	&getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw() {
            return "Grade is too high!";
        }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw() {
            return "Grade is too low!";
        }
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif