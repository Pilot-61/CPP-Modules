#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int count;
    int oldestIndex;
    
    std::string trimStr(const std::string &str) const;
    void showDetails(int index);
    void showCont();

public:
    PhoneBook();
    void addCont(const Contact &contact);
    void searchContact();
};

#endif