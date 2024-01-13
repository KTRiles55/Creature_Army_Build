#include "CyberDemon.h"


std::string CyberDemon::getSpeciesType() const
{
	return "CyberDemon";
}

CyberDemon::CyberDemon() : Creature() { };

CyberDemon::CyberDemon(std::string new_ID, int new_health, int new_strength) : Creature(new_ID, new_health, new_strength) { };

CyberDemon::CyberDemon(const CyberDemon& duplic_cybDemon) : Creature(duplic_cybDemon) { };

CyberDemon CyberDemon::operator=(const CyberDemon& duplic_cybDemon)
{
	if (this != &duplic_cybDemon)
	{
		this->ID = duplic_cybDemon.ID;
		this->health = duplic_cybDemon.health;
		this->strength = duplic_cybDemon.strength;
	}

	return *this;
}

CyberDemon::~CyberDemon() { };