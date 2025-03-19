#include "PhoneBook.hpp"
#include <iostream>
#include <string>

bool isEmptyOrWhitespace(const std::string &str)
{
    if (str.empty())
        return true;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isspace(str[i]))
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
            std::cout << "\nEOF detected. Exiting safely...\n";
            break;
        }
        if (!isEmptyOrWhitespace(input))
        {
            contact.setFirstName(input);
            break;
        }
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    
    while (true)
    {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF detected. Exiting safely...\n";
            break;
        }
        if (!isEmptyOrWhitespace(input))
        {
            contact.setLastName(input);
            break;
        }
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    
    while (true)
    {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF detected. Exiting safely...\n";
            break;
        }
        if (!isEmptyOrWhitespace(input))
        {
            contact.setNickname(input);
            break;
        }
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    
    while (true)
    {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF detected. Exiting safely...\n";
            break;
        }
        if (!isEmptyOrWhitespace(input))
        {
            contact.setPhoneNumber(input);
            break;
        }
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    
    while (true)
    {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF detected. Exiting safely...\n";
            break;
        }
        if (!isEmptyOrWhitespace(input))
        {
            contact.setDarkestSecret(input);
            break;
        }
        std::cout << "Field cannot be empty. Please try again." << std::endl;
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