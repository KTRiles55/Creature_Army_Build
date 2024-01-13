#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include "Creature.h"

class CyberDemon : public Creature
{
public:

	std::string getSpeciesType() const override;
	
	CyberDemon();

	CyberDemon(std::string new_ID, int new_health, int new_strength);

	CyberDemon(const CyberDemon& duplic_cybDemon);

	CyberDemon operator=(const CyberDemon& duplic_cybDemon);

	~CyberDemon();
};


#endif