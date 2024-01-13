#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <fstream>  
#include <sstream>
#include <string>
#ifndef CREATURE_H
#define CREATURE_H


const int DAMAGE = 10;
const int HALF_DAMAGE = DAMAGE / 2;
const int STAT_MIN = 75;
const int UPDATED_MAX = 200;
const int UPDATED_MIN = 100;

class Creature
{
protected:

	std::string ID = "";
	int health = 0;
	int strength = 0;
	friend class Creature_Inventory;


public:

	Creature();

	Creature(std::string mon_ID, int mon_health, int mon_strength);

	Creature(const Creature& duplic_mon);

	Creature operator=(const Creature& duplic_mon);

	virtual ~Creature();

	//Mutator function to set stats to one creature.
	void setCreature(std::string n_ID, int n_health, int n_hitPower);

	//Accessor functions to retrieve stats.
	std::string getID() const;

	int getHealth() const;

	int getStrength() const;

	//pure virtual function
	virtual std::string getSpeciesType() const = 0;

	virtual int getDamage() const;

	std::string ToString() const;
};


#endif



