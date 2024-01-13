#include <iostream>
#include "Creature.h"
#include "CreatureInventory.h"
#include "Demon.h"
#include "CyberDemon.h"
#include "Balrog.h"
#include "Elf.h"



//Creates menuOptions by inputting a certain number.
enum mainMenu { MENU = 0, SHOW_MONSTERS, UPDATE, EXIT };


std::string convertToLowercase(std::string& input_creature_name);

void displayMainMenu();

void alertInvalidInput();



int main()
{
	int creature_count = 0;
	srand((unsigned int)time(0));
	int menuSelect = 0; 
	std::string name;

	Creature_Inventory Army;

	//Asks user to enter total size of array.
	Army.inputMonsterCount(creature_count);

	//Error checking to ensure data is allocated successfully.
	try
	{
		//Dynamically allocates creatures via user input.
		Army.AddCreatures();
	}

	catch (std::bad_alloc& error)
	{
		std::cout << error.what() << "\n\nCannot allocate corrupted data.\nPlease try again.\n\n";
		Army.emptyInventory();
	}

	catch (std::out_of_range& error)
	{
		std::cout << error.what() << "\nPlease try again.\n\n";
		Army.emptyInventory();
	}

	catch (...)
	{
		std::cout << "\nUnknown error caught.\nPlease fix any errors in the program.\n\n";
		Army.emptyInventory();
	}

	while (menuSelect != EXIT)
	{
		//Displays main menu.
		displayMainMenu();

		std::cin >> menuSelect;
		switch (menuSelect)
		{
		case SHOW_MONSTERS:

			//checks if array is empty.
			if (Army.getEmptyArrayStatus() == true)
			{
				std::cout << "\n\nThis array is empty.\nPlease try adding more Creatures while in main.\n";
				break;
			}

			else
			{
				//Prints creatures in table format.
				Army.showCreatures();
				break;
			}

		case UPDATE:

			if (Army.getEmptyArrayStatus() == true)
			{
				std::cout << "\n\nThere are no creatures to update.\nPlease try adding Creatures into the list.\n\n";
				break;
			}

			else
			{
				//Updates stats of all creatures in array.
				Army.updateCreatures();
				break;
			}


		case EXIT:

			std::cout << "\n\nExiting program...\n\n";
			break;

		default:

			alertInvalidInput();
		}
	}
	return 0;
}


//Converts all text to lowercased in case the user types in either uppercased or lowercased, or both.
std::string convertToLowercase(std::string& input_creature_name)
{
	int i;
	for (i = 0; i <= input_creature_name.length(); ++i)
	{
		input_creature_name[i] = tolower(input_creature_name[i]);
	}
	return input_creature_name;
}



void displayMainMenu()
{
	std::cout << "\n\n\n\n(" << SHOW_MONSTERS << ") Show creature(s) type and damage output.\n\n("
		<< UPDATE << ") Update creature stats.\n\n("
		<< EXIT << ") Exit the Program.\n\n\n"
		"Please type and enter a number [1-2] to select from the menu. ";
}



void alertInvalidInput()
{
	std::cout << "\n\nInput is invalid.\nAlphabetic/symbolic characters are not numbers!\nPlease try again.\n\n";
	std::cin.clear();
	std::cin.ignore(' ', '\n');
}





//TESTING OUTPUT:


/*
(Test #1):



*/