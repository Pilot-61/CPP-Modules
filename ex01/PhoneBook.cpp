#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : count(0), oldestIndex(0) {}

std::string PhoneBook::trimStr(const std::string &str) {
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

void PhoneBook::showCont() {
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < this->count; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << trimStr(this->contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << trimStr(this->contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << trimStr(this->contacts[i].getNickname()) << std::endl;
    }
}


void PhoneBook::showDetails(int index){
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

void PhoneBook::searchContact(){
    if (this->count == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    
    this->showCont();
    
    std::cout << "Enter index to display: ";
    int index = 0;
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Invalid input." << std::endl;
        return;
    }
    char *end;
    index = std::strtol(input.c_str(), &end, 10);
    if (*end != '\0') {
        std::cout << "Invalid input." << std::endl;
        return;
    }
    this->showDetails(index);
}