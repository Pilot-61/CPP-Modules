#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &src);
    virtual ~Animal();
    Animal &operator=(const Animal &rhs);

    virtual void makeSound() const = 0; // Pure virtual function
    // This makes Animal an abstract class
    // and you cannot create an instance of it
    // You can only create instances of derived classes
    // that implement the pure virtual function
    // For example, Dog and Cat classes
    // that inherit from Animal class
    // and implement the makeSound() function
    // You can create an array of Animal pointers
    // and store Dog and Cat objects in it
    // and call the makeSound() function on them
    // and it will call the correct function
    // depending on the type of the object
    // This is called polymorphism
    // and it is one of the main features of OOP
    // and it allows you to write more flexible and reusable code
    // and it allows you to create more complex programs
    std::string getType() const;
};

#endif