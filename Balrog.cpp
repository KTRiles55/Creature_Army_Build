#include "Balrog.h"



std::string Balrog::getSpeciesType() const
{
	return "Balrog";
};

int Balrog::getDamage() const
{
	return Creature::getDamage() + Creature::getDamage();
}

Balrog::Balrog() : Creature() { };

Balrog::Balrog(std::string new_ID, int new_health, int new_strength) : Creature(new_ID, new_health, new_strength) { };

Balrog::Balrog(const Balrog& duplic_balrog) : Creature(duplic_balrog) { };

Balrog Balrog::operator=(const Balrog& duplic_balrog)
{
	if (this != &duplic_balrog)
	{
		this->ID = duplic_balrog.ID;
		this->health = duplic_balrog.health;
		this->strength = duplic_balrog.strength;
	}

	return *this;
}

Balrog::~Balrog() { };