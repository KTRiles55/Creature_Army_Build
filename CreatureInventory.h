#ifndef CREATUREINVENTORY_H
#define CREATUREINVENTORY_H
#include "Creature.h"


//Options letting user choose which creature to create by user-typed input.
enum ChooseCreature { NOT_CHOSEN = 0, DEMON, CYBERDEMON, BALROG, ELF };

class Creature_Inventory
{
private:

	//Total size of dynamically-allocated array calculated by user input.
	int monsterArrSize = 0;

	//Total number of objects allocated into array by user.
	int num_alloc_mons = 0;
	bool arrisEmpty = true;

	//Dynamically-allocated array
	Creature** monsterArmy = nullptr;

public:

	Creature_Inventory();

	Creature_Inventory(const Creature_Inventory& creatureList_copy);

	Creature_Inventory& operator=(const Creature_Inventory& creatureList_copy);

	~Creature_Inventory();

	//Prompts user to enter number of creatures. 
	int inputMonsterCount(int& mon_tally);

	int inputNumberOfAllocations();

	void AddCreatures();

	bool getEmptyArrayStatus();

	void showCreatures();

	void updateCreatures();

	//De-allocates array and frees memory from the heap.
	void emptyInventory();

	std::string promptCreatureName(std::string n_name);
};


#endif