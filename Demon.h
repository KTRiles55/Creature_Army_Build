#ifndef DEMON_H
#define DEMON_H
#include "Creature.h"

class Demon : public Creature
{
public:

	std::string getSpeciesType() const override;

	int getDamage() const override;

	Demon();

	Demon(std::string new_ID, int new_health, int new_strength);

	Demon(const Demon& duplic_demon);

	Demon operator=(const Demon& duplic_demon);

	~Demon();
};


#endif