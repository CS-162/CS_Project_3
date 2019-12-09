/**
**	Program: Driver File
**	Author: Austin Chayka
**	Date: 11.7.2019
**	Description: Main driver file
**/

#include <iostream>
#include <ctime>
#include "util.h"
#include "Zoo.h"

using namespace std;

/**
**	Function:  runs animal purchase
**	Description: gets animal purchase choice and adds that animal to the zoo 
**	Parameters: zoo to add animals to
**/
void run_animal_purchase(Zoo &zoo) {

	cout << "(1) $700 - purchase sea lion\n(2) $12,000 - purchase tiger"
		<< "\n(3) $5,000 - purchase black bear\n(4) never mind" << endl;
	int input = get_number_choice(1, 4);
	cout << endl;
	switch(input) {

	case 1:
		if(zoo.get_money() >= 700) {
			zoo.add_seaLion();
			zoo.set_money(zoo.get_money() - 700);
		}
		else cout << "Not enough money." << endl;
		break;

	case 2:
		if(zoo.get_money() >= 12000) {
			zoo.add_tiger();
			zoo.set_money(zoo.get_money() - 12000);
		}
		else cout << "Not enough money." << endl;
		break;

	case 3:
		if(zoo.get_money() >= 5000) {
			zoo.add_blackBear();
			zoo.set_money(zoo.get_money() - 5000);
		}
		else cout << "Not enough money." << endl;
		break;

	}

}

/**
**	Function:  runs monthly progression
**	Description: gets fodd type for the month, updates the zoo, and gets
**		the monthly revenue and upkeep costs
**	Parameters: zoo to progress
**/
void run_monthly_progression(Zoo& zoo) {

	cout << "(1) Regular Food\n(2) Premium Food\n(3) Cheap Food" << endl;
	int input = get_number_choice(1, 3);
	zoo.set_food_type(input);
	zoo.update();
	int revenue = zoo.get_revenue(), costs = zoo.get_costs();
	cout << "Revenue: $" << revenue << "\nCosts: $" << costs << endl;
	zoo.set_money(zoo.get_money() + revenue - costs);
	zoo.print_seaLion_count();
	zoo.print_tiger_count();
	zoo.print_blackBear_count();

}

/**
**	Function:  main
**	Description: driver funtion
**	Parameters: none required
**/
int main(int argc, char *argv[]) {

	srand(time(NULL));

	Zoo zoo;

	bool running = true;
	int input;
	do {

		cout << "Current funds: $" << zoo.get_money() << endl;

		cout << "\n(1) purchase animal\n(2) proceed to next month\n(3) quit" << endl;
		input = get_number_choice(1, 3);
		cout << endl;
		switch(input) {

			case 1:
				run_animal_purchase(zoo);
				break;

			case 2:
				run_monthly_progression(zoo);
				break;

			case 3:
				running = false;
				break;

		}

		if(zoo.get_money() < 0) {
			cout << "Out of money." << endl;
			running = false;
		}

	} while(running);
		
	cout << "Game ended sucessfully" << endl;

	return 0;

}