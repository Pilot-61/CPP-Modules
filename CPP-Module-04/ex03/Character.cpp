#include "Character.hpp"


Character::Character() : name("default"), inventoryCount(0) {
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

Character::Character(const std::string &name) : name(name), inventoryCount(0) {
    std::cout << "Character parameterized constructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character &src) : name(src.name), inventoryCount(src.inventoryCount) {
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (src.inventory[i]) {
            inventory[i] = src.inventory[i]->clone();
        } else {
            inventory[i] = NULL;
        }
    }
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < inventoryCount; ++i) {
        delete inventory[i];
    }
}

Character &Character::operator=(const Character &rhs) {
    if (this != &rhs) {
        name = rhs.name;
        inventoryCount = rhs.inventoryCount;
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            if (rhs.inventory[i]) {
                inventory[i] = rhs.inventory[i]->clone();
            } else {
                inventory[i] = NULL;
            }
        }
    }
    std::cout << "Character assignment operator called" << std::endl;
    return *this;
}

const std::string &Character::getName() const {
    return name;
}

void Character::equip(AMateria *m) {
    if (inventoryCount < 4 && m) {
        inventory[inventoryCount++] = m;
        std::cout << "Equipped " << m->getType() << " to " << name << std::endl;
    } else {
        std::cout << "Inventory is full or materia is null" << std::endl;
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < inventoryCount) {
        std::cout << "Unequipped " << inventory[idx]->getType() << " from " << name << std::endl;
        delete inventory[idx];
        for (int i = idx; i < inventoryCount - 1; ++i) {
            inventory[i] = inventory[i + 1];
        }
        inventory[inventoryCount - 1] = NULL;
        --inventoryCount;
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < inventoryCount && inventory[idx]) {
        std::cout << name << " uses " << inventory[idx]->getType() << " on " << target.getName() << std::endl;
        inventory[idx]->use();
    } else {
        std::cout << "Invalid index or materia is null" << std::endl;
    }
}
