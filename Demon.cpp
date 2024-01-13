#include "Demon.h"


std::string Demon::getSpeciesType() const 
{
	return "Demon";
}

int Demon::getDamage() const
{
	if ((rand() % (DAMAGE * DAMAGE)) < HALF_DAMAGE)
	{
		return Creature::getDamage() + (DAMAGE * HALF_DAMAGE);
	}

	else
	{
		return Creature::getDamage();
	}
}


Demon::Demon() : Creature() { };

Demon::Demon(std::string new_ID, int new_health, int new_strength) : Creature(new_ID, new_health, new_strength) { };

Demon::Demon(const Demon& duplic_demon) : Creature(duplic_demon) { };

Demon Demon::operator=(const Demon& duplic_demon)
{
	if (this != &duplic_demon)
	{
		this->ID = duplic_demon.ID;
		this->health = duplic_demon.health;
		this->strength = duplic_demon.strength;
	}

	return *this;
}

Demon::~Demon() { };