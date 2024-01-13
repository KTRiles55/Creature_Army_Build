#include "Creature.h"


Creature::Creature() { };

Creature::Creature(std::string mon_ID, int mon_health, int mon_strength) : ID(mon_ID), health(mon_health), strength(mon_strength) { };

Creature::Creature(const Creature& duplic_mon)
{
	this->ID = duplic_mon.ID;
	this->health = duplic_mon.health;
	this->strength = duplic_mon.strength;
}

Creature::~Creature() { };


void Creature::setCreature(std::string n_ID, int n_health, int n_hitPower)
{
	ID = n_ID;
	health = n_health;
	strength = n_hitPower;
}



std::string Creature::getID() const
{
	return ID;
}

int Creature::getHealth() const
{
	return health;
}

int Creature::getStrength() const
{
	return strength;
}


int Creature::getDamage() const
{
	return (rand() % strength) + 1;
}



std::string Creature::ToString() const
{
	std::ostringstream creature_stats;
	std::string creature_id = getID();
	creature_id[0] = toupper(creature_id[0]);

	creature_stats << "\n\n" << std::left << std::setw(20) << getSpeciesType() << std::setw(20) << creature_id << std::setw(21) << getHealth() << std::setw(21) << getStrength()
		<< std::setw(20) << getDamage();
	return creature_stats.str();
}