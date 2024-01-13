#ifndef BALROG_H
#define BALROG_H
#include "Creature.h"


class Balrog : public Creature
{
public:

	std::string getSpeciesType() const override;

	int getDamage() const override;

	Balrog();

	Balrog(std::string new_ID, int new_health, int new_strength);

	Balrog(const Balrog& duplic_balrog);

	Balrog operator=(const Balrog& duplic_balrog);

	~Balrog();
};


#endif
