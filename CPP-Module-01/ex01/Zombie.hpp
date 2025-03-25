#ifndef ZOMBIE_HORDE_H
#define ZOMBIE_HORDE_H

#include <string>

class Zombie {
private:
    std::string m_name;

public:
    Zombie();
    Zombie(const std::string& name);
    ~Zombie();
    void announce() const;
    void setName(const std::string& name);
};

Zombie* zombieHorde(int N, const std::string& name);

#endif