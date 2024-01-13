#ifndef ELF_H
#define ELF_H
#include "Creature.h"
#include "Demon.h"


class Elf : public Creature
{
public:

	std::string getSpeciesType() const override;

	int getDamage() const override;

	Elf();

	Elf(std::string new_ID, int new_health, int new_strength);

	Elf(const Demon& duplic_elf);

	Elf operator=(const Elf& duplic_elf);

	~Elf();
};


#endif