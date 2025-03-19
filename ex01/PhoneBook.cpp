#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::trimStr(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::addCont(const Contact &contact) {
    this->contacts[this->oldestIndex] = contact;
    this->oldestIndex = (this->oldestIndex + 1) % 8;
    if (this->count < 8)
        this->count++;
}

void PhoneBook::showCont() const {
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    
    for (int i = 0; i < this->count; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << trimStr(this->contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << trimStr(this->contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << trimStr(this->contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::showDetails(int index) const {
    if (index < 0 || index >= this->count) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    
    std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact() const {
    if (this->count == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    
    this->showCont();
    
    std::cout << "Enter index to display: ";
    int index;
    std::cin >> index;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input." << std::endl;
        return;
    }
    
    std::cin.ignore(10000, '\n');
    this->showDetails(index);
}