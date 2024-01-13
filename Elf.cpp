#include "Elf.h"


std::string Elf::getSpeciesType() const
{
	return "Elf";
};

int Elf::getDamage() const
{
	if ((rand() % DAMAGE) == 0)
	{
		return Creature::getDamage() * (DAMAGE / HALF_DAMAGE);
	}

	else
	{
		return Creature::getDamage();
	}
}

Elf::Elf() : Creature() { };

Elf::Elf(std::string new_ID, int new_health, int new_strength) : Creature(new_ID, new_health, new_strength) { };

Elf::Elf(const Demon& duplic_elf) : Creature(duplic_elf) { };

Elf Elf::operator=(const Elf& duplic_elf)
{
	if (this != &duplic_elf)
	{
		this->ID = duplic_elf.ID;
		this->health = duplic_elf.health;
		this->strength = duplic_elf.strength;
	}

	return *this;
}


Elf::~Elf() { };