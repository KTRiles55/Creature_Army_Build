#include "CreatureInventory.h"
#include "Creature.h"
#include "Demon.h"
#include "CyberDemon.h"
#include "Balrog.h"
#include "Elf.h"



Creature_Inventory::Creature_Inventory() { }



Creature_Inventory::Creature_Inventory(const Creature_Inventory& creatureList_copy)
{
	monsterArmy = new Creature * [monsterArrSize];
	int i;
	for (i = 0; i < monsterArrSize; ++i)
	{
		this->monsterArmy[i] = creatureList_copy.monsterArmy[i];
	}
}


Creature_Inventory::~Creature_Inventory()
{
	emptyInventory();
	std::cout << "Objects destroyed.\n\n";
}


void Creature_Inventory::emptyInventory()
{
	std::cout << "\nDeallocating elements from memory...\n\n";
	delete[] monsterArmy;
	monsterArmy = nullptr;
	arrisEmpty = true;
}


Creature_Inventory& Creature_Inventory::operator=(const Creature_Inventory& creatureList_copy)
{
	if (this != &creatureList_copy)
	{
		monsterArmy = new Creature * [monsterArrSize];
		int i;
		for (i = 0; i < monsterArrSize; ++i)
		{
			*this = creatureList_copy;
		}
	}
	return *this;
}


int Creature_Inventory::inputMonsterCount(int& mon_tally)
{
	std::cout << "Please enter the total number of creatures to allocate.\n";
	std::cin >> mon_tally;
	if (std::cin.fail())
	{
		std::cout << "\nInvalid input. Please try again!\n\n";
		std::cin.clear();
		std::cin.ignore(' ', '\n');
		inputMonsterCount(mon_tally);
	}
	monsterArrSize = mon_tally;
	return monsterArrSize;
}



int Creature_Inventory::inputNumberOfAllocations()
{
	std::cout << "\nEnter how many creatures you would like to allocate. ";
	std::cin >> num_alloc_mons;
	if (std::cin.fail())
	{
		std::cout << "\nInvalid input. Please try again!\n\n";
		std::cin.clear();
		std::cin.ignore(' ', '\n');
		inputNumberOfAllocations();
	}

	else if ((num_alloc_mons > monsterArrSize) || (num_alloc_mons < 0))
	{
		throw std::out_of_range("\nAllocation is out of range!\n");
	}

	arrisEmpty = false;
}



bool Creature_Inventory::getEmptyArrayStatus()
{
	return arrisEmpty;
}



void Creature_Inventory::AddCreatures()
{
	monsterArmy = new Creature * [monsterArrSize];

	inputNumberOfAllocations();
	int user_monSelection = NOT_CHOSEN;
	std::string creature_alias;

	std::cout << "\nYou have allocated " << num_alloc_mons << " into the list.\n"
		<< "The total space in the list contains " << monsterArrSize << " creatures.\n\n";
	int i = 0;
	while (i < num_alloc_mons)
	{
		std::cout << "\n\n(" << DEMON << ") Demon\n(" << CYBERDEMON << ") CyberDemon\n("
			<< BALROG << ") Balrog\n(" << ELF << ") Elf\n\n"
			<< "Enter one of the cooresponding numbers to choose the creature type of Monster no. " << i + 1 << ". ";
		std::cin >> user_monSelection;
		switch (user_monSelection)
		{
		case DEMON:

			std::cout << "\n\nYou have selected a Demon!";
			creature_alias = promptCreatureName(creature_alias);
			monsterArmy[i] = new Demon(creature_alias, STAT_MIN + (rand() % STAT_MIN), STAT_MIN + (rand() % STAT_MIN));
			++i;
			break;

		case CYBERDEMON:

			std::cout << "\n\nYou have selected a CyberDemon!";
			creature_alias = promptCreatureName(creature_alias);
			monsterArmy[i] = new CyberDemon(creature_alias, STAT_MIN + (rand() % STAT_MIN), STAT_MIN + (rand() % STAT_MIN));
			++i;
			break;

		case BALROG:

			std::cout << "\n\nYou have selected a Balrog!";
			creature_alias = promptCreatureName(creature_alias);
			monsterArmy[i] = new Balrog(creature_alias, STAT_MIN + (rand() % STAT_MIN), STAT_MIN + (rand() % STAT_MIN));
			++i;
			break;


		case ELF:

			std::cout << "\n\nYou have selected an Elf!";
			creature_alias = promptCreatureName(creature_alias);
			monsterArmy[i] = new Elf(creature_alias, STAT_MIN + (rand() % STAT_MIN), STAT_MIN + (rand() % STAT_MIN));
			++i;
			break;

		default:

			std::cout << "\nInvalid input. Please try again!\n\n";
			std::cin.clear();
			std::cin.ignore(' ', '\n');

		}

	}
}



std::string Creature_Inventory::promptCreatureName(std::string n_name)
{
	std::cout << "\n\nWrite a name for the creature. ";
	std::cin.ignore();
	std::getline(std::cin, n_name);
	int maxNameLength = DAMAGE + HALF_DAMAGE;

	if (n_name.length() > maxNameLength)
	{
		n_name.resize(maxNameLength);
	}
	return n_name;
}



void Creature_Inventory::showCreatures()
{
	int i;
	std::cout << "\n\n" << std::left << std::setw(21) << "Species" << std::setw(18) << "ID" << std::setw(18) << "Health" << std::setw(18) << "Power level"
		<< std::setw(22) << "Damage Inflicted\n";
	for (i = 0; i < num_alloc_mons; ++i)
	{
		std::cout << monsterArmy[i]->ToString() << "\n";
	}
}



void Creature_Inventory::updateCreatures()
{
	int i = 0;
	for (i = 0; i < num_alloc_mons; ++i)
	{
		monsterArmy[i]->health = UPDATED_MAX + (rand() % UPDATED_MIN);
		monsterArmy[i]->strength = UPDATED_MAX + (rand() % UPDATED_MIN);
	}
	std::cout << "\n\nAll creature stats have been updated.\n\n";
}

