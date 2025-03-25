#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype>

bool isValid(const std::string &str) {
    bool hasNonWhitespace = false;
    
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isprint(str[i]) && str[i] != '\t')
            return false;
        if (!std::isspace(str[i]))
            hasNonWhitespace = true;
    }
    
    return hasNonWhitespace;
}

bool isNumber(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

Contact createContact()
{
    Contact contact;
    std::string input;
    
    while (true)
    {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, input)) {
            return contact;
        }
        if (isValid(input))
        {
            contact.setFirstName(input);
            break;
        }
        std::cout << "Field cannot be empty, contain unprintable characters, or consist of only whitespace. Please try again." << std::endl;
    }
    
    while (true)
    {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, input)) {
            return contact;
        }
        if (isValid(input))
        {
            contact.setLastName(input);
            break;
        }
        std::cout << "Field cannot be empty, contain unprintable characters, or consist of only whitespace. Please try again." << std::endl;
    }
    
    while (true)
    {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, input)) {
            return contact;
        }
        if (isValid(input))
        {
            contact.setNickname(input);
            break;
        }
        std::cout << "Field cannot be empty, contain unprintable characters, or consist of only whitespace. Please try again." << std::endl;
    }
    
    while (true)
    {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, input)) {
            return contact;
        }
        if (isValid(input) && isNumber(input))
        {
            contact.setPhoneNumber(input);
            break;
        }
        std::cout << "Field cannot be empty, contain unprintable characters, or consist of only whitespace, and it should be composed of numbers only. Please try again." << std::endl;
    }
    
    while (true)
    {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, input)) {
            return contact;
        }
        if (isValid(input))
        {
            contact.setDarkestSecret(input);
            break;
        }
        std::cout << "Field cannot be empty, contain unprintable characters, or consist of only whitespace. Please try again." << std::endl;
    }
    
    return contact;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << "\nEOF detected. Exiting safely...\n";
            break;
        }
        if (command == "ADD")
        {
            Contact contact = createContact();
            phoneBook.addCont(contact);
            if (contact.getFirstName().empty() || contact.getLastName().empty() || contact.getNickname().empty() || contact.getPhoneNumber().empty() || contact.getDarkestSecret().empty())
            {
                std::cout << "\nEoF detected. Exiting safely...\n";
                break;
            }
            std::cout << "Contact added successfully." << std::endl;
        }
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}