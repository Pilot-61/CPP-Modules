#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Basic tests
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    dog->makeSound();
    cat->makeSound();
    
    delete dog;
    delete cat;
    
    // Test array of animals
    Animal* animals[4];
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();
        
    for (int i = 0; i < 4; i++)
        delete animals[i];
        
    // Test deep copy
    Dog* originalDog = new Dog();
    Dog* copyDog = new Dog(*originalDog);
    
    delete originalDog;
    copyDog->makeSound(); // Should still work fine if deep copy is correct
    delete copyDog;
    
    return 0;
}