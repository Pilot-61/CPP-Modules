#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    Animal* animal = new Animal();
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    WrongAnimal* wrongAnimal = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();
    std::cout << "------------------------" << std::endl;
    std::cout << "Animal type: " << animal->getType() << std::endl;
    animal->makeSound();
    std::cout << "Dog type: " << dog->getType() << std::endl;
    dog->makeSound();
    std::cout << "Cat type: " << cat->getType() << std::endl;
    cat->makeSound();
    std::cout << "------------------------" << std::endl;
    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
    wrongAnimal->makeSound();
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    std::cout << "------------------------" << std::endl;
    delete animal;
    delete dog;
    delete cat;
    delete wrongAnimal;
    delete wrongCat;
    return 0;
}