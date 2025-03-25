#include <iostream>
#include <sstream>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *Zombies = new (std::nothrow) Zombie[N];
	if (!Zombies)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return NULL;
	}

	for (int i = 0; i < N; i++)
		Zombies[i].setName(name);
	return Zombies;
}