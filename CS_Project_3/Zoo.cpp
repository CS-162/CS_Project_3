/**
**	Program: Zoo Object
**	Author: Austin Chayka
**	Date: 11.7.2019
**	Description: Implementation of the zoo object
**/
#include "Zoo.h"

#include <iostream>
#include "util.h"

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: none
**/
Zoo::Zoo() {

	num_seaLions = 0;
	seaLions = nullptr;
	num_tigers = 0;
	tigers = nullptr;
	num_blackBears = 0;
	blackBears = nullptr;

	money = 100000;

	increased_vists = false;

	food_type = 0;

}

/**
**	Function: copy constructor
**	Description: sets default variable values to those of an existing object
**	Parameters: object to copy from
**/
Zoo::Zoo(const Zoo &copy_zoo) {

	num_seaLions = copy_zoo.num_seaLions;
	seaLions = new SeaLion[num_seaLions];
	for(int i = 0; i < num_seaLions; i++) seaLions[i] = copy_zoo.seaLions[i];
	num_tigers = copy_zoo.num_tigers;
	tigers = new Tiger[num_tigers];
	for(int i = 0; i < num_tigers; i++) tigers[i] = copy_zoo.tigers[i];
	num_blackBears = copy_zoo.num_blackBears;
	blackBears = new BlackBear[num_blackBears];
	for(int i = 0; i < num_blackBears; i++) blackBears[i] = copy_zoo.blackBears[i];

	money = copy_zoo.money;

	increased_vists = copy_zoo.increased_vists;

	food_type = copy_zoo.food_type;

}

/**
**	Function: destructor
**	Description: deallocates memory
**	Parameters: none
**/
Zoo::~Zoo() {

	if(seaLions != nullptr) delete[] seaLions;
	if(tigers != nullptr) delete[] tigers;
	if(blackBears != nullptr) delete[] blackBears;

}

/**
**	Function: assignment opperator overload
**	Description: sets variable values to those of an existing object
**	Parameters: object to copy from
**/
Zoo & Zoo::operator=(const Zoo &copy_zoo) {
	
	num_seaLions = copy_zoo.num_seaLions;
	delete[] seaLions;
	seaLions = new SeaLion[num_seaLions];
	for(int i = 0; i < num_seaLions; i++) seaLions[i] = copy_zoo.seaLions[i];
	num_tigers = copy_zoo.num_tigers;
	delete[] tigers;
	tigers = new Tiger[num_tigers];
	for(int i = 0; i < num_tigers; i++) tigers[i] = copy_zoo.tigers[i];
	num_blackBears = copy_zoo.num_blackBears;
	delete[] blackBears;
	blackBears = new BlackBear[num_blackBears];
	for(int i = 0; i < num_blackBears; i++) blackBears[i] = copy_zoo.blackBears[i];

	money = copy_zoo.money;

}

/**
**	Function: get money
**	Description: gets money amount
**	Parameters: none
**/
int Zoo::get_money() {

	return money;

}

/**
**	Function: set money
**	Description: sets money amount
**	Parameters: new money amount
**/
void Zoo::set_money(int money) {

	this->money = money;

}

/**
**	Function: get food type
**	Description: gets food type
**	Parameters: none
**/
int Zoo::get_food_type() {

	return food_type;

}

/**
**	Function: set food type
**	Description: sets food type
**	Parameters: new food type
**/
void Zoo::set_food_type(int food_type) {

	this->food_type = food_type;

}

/**
**	Function: update
**	Description: runs events and updates animals
**	Parameters: none
**/
void Zoo::update() {

	increased_vists = false;

	run_event();

	update_seaLions();
	update_tigers();
	update_blackBears();
	
}

/**
**	Function: run event
**	Description: runs a random event
**	Parameters: none
**/
void Zoo::run_event() {

	int n = 0;
	if(food_type == 1) n = get_rad_num(0, 7);
	else if(food_type == 2) n = get_rad_num(0, 6);
	else if(food_type == 3) n = get_rad_num(0, 9);

	std::cout << std:: endl;
	if(n <= 1) {
		birth_animal();
	} else if(n > 1 && n <= 3) {
		increased_vists = true;
		std::cout << "There was an increase in zoo visits this month" << std::endl;
	} else if(n > 3 && n <= 5) {
		std::cout << "Nothing happened this month" << std::endl;
	} else {
		spread_illness();
	}

}

/**
**	Function: spread illness
**	Description: makes a random animal sick
**	Parameters: none
**/
void Zoo::spread_illness() {
	
	switch(get_rad_num(0, 2)) {
		case 0:
			if(num_seaLions == 0) {
				std::cout << "Nothing happened this month" << std::endl;
				break;
			}
			seaLions[get_rad_num(0, num_seaLions - 1)].set_sick(true);
			std::cout << "A sea lion has gotten sick" << std::endl;
			break;
		case 1:
			if(num_tigers == 0) {
				std::cout << "Nothing happened this month" << std::endl;
				break;
			}
			tigers[get_rad_num(0, num_tigers - 1)].set_sick(true);
			std::cout << "A tiger has gotten sick" << std::endl;
			break;
		case 2:
			if(num_blackBears == 0) {
				std::cout << "Nothing happened this month" << std::endl;
				break;
			}
			blackBears[get_rad_num(0, num_blackBears - 1)].set_sick(true);
			std::cout << "A black bear has gotten sick" << std::endl;
			break;
	}

}

/**
**	Function: birth animal
**	Description: makes a random animal give birth
**	Parameters: none
**/
void Zoo::birth_animal() {
	
	switch(get_rad_num(0, 2)) {
		case 0:
			if(get_num_adult_seaLions() < 2) {
				std::cout << "Nothing happened this month" << std::endl;
				break;
			}
			std::cout << "A sea lion has given birth" << std::endl;
			add_seaLion();
			break;
		case 1:
			if(get_num_adult_tigers() < 2) {
				std::cout << "Nothing happened this month" << std::endl;
				break;
			}
			std::cout << "A tiger has given birth" << std::endl;
			for(int i = 0; i < 3; i++) add_tiger();
			break;
		case 2:
			if(get_num_adult_blackBears() < 2) {
				std::cout << "Nothing happened this month" << std::endl;
				break;
			}
			std::cout << "A black bear has given birth" << std::endl;
			for(int i = 0; i < 2; i++) add_blackBear();
			break;
	}

}

/**
**	Function: get number of adult sea lions
**	Description: gets the number of adult sea lions
**	Parameters: none
**/
int Zoo::get_num_adult_seaLions() {

	int adults = 0;
	for(int i = 0; i < num_seaLions; i++) if(seaLions[i].get_growth_stage() == 2) adults++;

	return adults;

}

/**
**	Function: get number of adult tiger
**	Description: gets the number of adult tigers
**	Parameters: none
**/
int Zoo::get_num_adult_tigers() {

	int adults = 0;
	for(int i = 0; i < num_tigers; i++) if(tigers[i].get_growth_stage() == 2) adults++;

	return adults;

}

/**
**	Function: get number of adult black bears
**	Description: gets the number of adult black bears
**	Parameters: none
**/
int Zoo::get_num_adult_blackBears() {

	int adults = 0;
	for(int i = 0; i < num_blackBears; i++) if(blackBears[i].get_growth_stage() == 2) adults++;

	return adults;

}

/**
**	Function: update sea lions
**	Description: get costs for illness and increases age
**	Parameters: none
**/
void Zoo::update_seaLions() {

	for(int i = 0; i < num_seaLions; i++)
		if(seaLions[i].is_sick()) {
			double care_cost = seaLions[i].get_purchase_cost() * (seaLions[i].get_growth_stage() == 0 ? 1 : .5);
			if(money > care_cost) {
				money -= (int)care_cost;
				std::cout << "$" << care_cost << " has been deducted to treat the sick sea lion." << std::endl;
			}
			else {
				remove_seaLion(i);
				i--;
				std::cout << "A sea lion has died." << std::endl;
			}
			seaLions[i].set_sick(false);
		}
	for(int i = 0; i < num_seaLions; i++) {
		seaLions[i].increase_age(1);
		seaLions[i].set_base_feeding_cost(
			(int)(seaLions[i].get_base_feeding_cost() * ((100.0 + get_rad_num(-20, 20)) / 100))
		);
	}

}

/**
**	Function: update tigers
**	Description: get costs for illness and increases age
**	Parameters: none
**/
void Zoo::update_tigers() {

	for(int i = 0; i < num_tigers; i++)
		if(tigers[i].is_sick()) {
			double care_cost = tigers[i].get_purchase_cost() * (tigers[i].get_growth_stage() == 0 ? 1 : .5);
			if(money > care_cost) {
				money -= (int)care_cost;
				std::cout << "$" << care_cost << " has been deducted to treat the sick tiger." << std::endl;
			}
			else {
				remover_tiger(i);
				i--;
				std::cout << "A tiger has died." << std::endl;
			}
			tigers[i].set_sick(false);
		}
	for(int i = 0; i < num_tigers; i++) {
		tigers[i].increase_age(1);
		tigers[i].set_base_feeding_cost(
			(int)(tigers[i].get_base_feeding_cost() * ((100.0 + get_rad_num(-20, 20)) / 100))
		);
	}

}

/**
**	Function: update black bears
**	Description: get costs for illness and increases age
**	Parameters: none
**/
void Zoo::update_blackBears() {

	for(int i = 0; i < num_blackBears; i++)
		if(blackBears[i].is_sick()) {
			double care_cost = blackBears[i].get_purchase_cost() * (blackBears[i].get_growth_stage() == 0 ? 1 : .5);
			if(money > care_cost) {
				money -= (int)care_cost;
				std::cout << "$" << care_cost << " has been deducted to treat the sick black bear." << std::endl;
			}
			else {
				remove_blackBear(i);
				i--;
				std::cout << "A black bear has died." << std::endl;
			}
			blackBears[i].set_sick(false);
		}
	for(int i = 0; i < num_blackBears; i++) {
		blackBears[i].increase_age(1);
		blackBears[i].set_base_feeding_cost(
			(int)(blackBears[i].get_base_feeding_cost() * ((100.0 + get_rad_num(-20, 20)) / 100))
		);
	}

}

/**
**	Function: get revenue
**	Description: gets zoo revenue
**	Parameters: none
**/
int Zoo::get_revenue() {

	int revenue = 0;

	for(int i = 0; i < num_seaLions; i++) 
		revenue += (seaLions[i].get_revenue() + (increased_vists ? get_rad_num(150, 400) : 0));
	for(int i = 0; i < num_tigers; i++) revenue += tigers[i].get_revenue();
	for(int i = 0; i < num_blackBears; i++) revenue += blackBears[i].get_revenue();

	return revenue;

}

/**
**	Function: get costs
**	Description: gets zoo upkeep costs
**	Parameters: none
**/
int Zoo::get_costs() {

	int costs = 0;

	for(int i = 0; i < num_seaLions; i++) {
		if(food_type == 1) costs += seaLions[i].get_monthly_cost();
		else if(food_type == 2) costs += (seaLions[i].get_monthly_cost() * 2);
		else if(food_type == 3) costs += (seaLions[i].get_monthly_cost() / 2);
	}
	for(int i = 0; i < num_tigers; i++) {
		if(food_type == 1) costs += tigers[i].get_monthly_cost();
		else if(food_type == 2) costs += (tigers[i].get_monthly_cost() * 2);
		else if(food_type == 3) costs += (tigers[i].get_monthly_cost() / 2);
	}
	for(int i = 0; i < num_blackBears; i++) {
		if(food_type == 1) costs += blackBears[i].get_monthly_cost();
		else if(food_type == 2) costs += (blackBears[i].get_monthly_cost() * 2);
		else if(food_type == 3) costs += (blackBears[i].get_monthly_cost() / 2);
	}

	return costs;

}

/**
**	Function: add sea lion
**	Description: adds a baby sea lion to the zoo
**	Parameters: none
**/
void Zoo::add_seaLion() {
	
	if(seaLions != nullptr) {
		SeaLion *temp = new SeaLion[++num_seaLions];
		for(int i = 0; i < num_seaLions - 1; i++) temp[i] = seaLions[i];
		delete[] seaLions;
		seaLions = temp;
	} else seaLions = new SeaLion[++num_seaLions];
	
}

/**
**	Function: remove sea lion
**	Description: removes the sea lion at a specified index
**	Parameters: index of sea lion
**/
void Zoo::remove_seaLion(int index) {

	if(seaLions == nullptr || num_seaLions < index) return;

	SeaLion *temp = new SeaLion[--num_seaLions];
	int counter = 0;
	for(int i = 0; i < num_seaLions; i++) if(i != index) temp[counter++] = seaLions[i];
	delete[] seaLions;
	seaLions = temp;

}

/**
**	Function: add tiger
**	Description: adds a baby tiger to the zoo
**	Parameters: none
**/
void Zoo::add_tiger() {

	if(tigers != nullptr) {
		Tiger* temp = new Tiger[++num_tigers];
		for(int i = 0; i < num_tigers - 1; i++) temp[i] = tigers[i];
		delete[] tigers;
		tigers = temp;
	} else tigers = new Tiger[++num_tigers];

}

/**
**	Function: remove tiger
**	Description: removes the tiger at a specified index
**	Parameters: index of tiger
**/
void Zoo::remover_tiger(int index) {

	if(tigers == nullptr || num_tigers < index) return;

	Tiger* temp = new Tiger[--num_tigers];
	int counter = 0;
	for(int i = 0; i < num_tigers; i++) if(i != index) temp[counter++] = tigers[i];
	delete[] tigers;
	tigers = temp;

}

/**
**	Function: add black bear
**	Description: adds a baby black bear to the zoo
**	Parameters: none
**/
void Zoo::add_blackBear() {

	if(blackBears != nullptr) {
		BlackBear* temp = new BlackBear[++num_blackBears];
		for(int i = 0; i < num_blackBears - 1; i++) temp[i] = blackBears[i];
		delete[] blackBears;
		blackBears = temp;
	} else blackBears = new BlackBear[++num_blackBears];

}

/**
**	Function: remove black bear
**	Description: removes the black bear at a specified index
**	Parameters: index of black bear
**/
void Zoo::remove_blackBear(int index) {

	if(blackBears == nullptr || num_blackBears < index) return;

	BlackBear* temp = new BlackBear[--num_blackBears];
	int counter = 0;
	for(int i = 0; i < num_blackBears; i++) if(i != index) temp[counter++] = blackBears[i];
	delete[] blackBears;
	blackBears = temp;

}

/**
**	Function: print sea lion count
**	Description: prints the numebr of baby, adolescent, and adult sea lions
**	Parameters: none
**/
void Zoo::print_seaLion_count() {

	int adults = 0, adolescents = 0, babies = 0;
	for(int i = 0; i < num_seaLions; i++) {

		switch(seaLions[i].get_growth_stage()) {

			case 0: 
				babies++; 
				break;

			case 1:
				adolescents++;
				break;

			case 2:
				adults++;
				break;

		}

	}

	std::cout << "Sea Lions: " << babies << " babies, " << adolescents << " adolescents, "
		<< adults << " adults." << std::endl;

}

/**
**	Function: print tiger count
**	Description: prints the numebr of baby, adolescent, and adult tigers
**	Parameters: none
**/
void Zoo::print_tiger_count() {

	int adults = 0, adolescents = 0, babies = 0;
	for(int i = 0; i < num_tigers; i++) {

		switch(tigers[i].get_growth_stage()) {

		case 0:
			babies++;
			break;

		case 1:
			adolescents++;
			break;

		case 2:
			adults++;
			break;

		}

	}

	std::cout << "Tigers: " << babies << " babies, " << adolescents << " adolescents, "
		<< adults << " adults." << std::endl;

}

/**
**	Function: print black bear count
**	Description: prints the numebr of baby, adolescent, and adult black bears
**	Parameters: none
**/
void Zoo::print_blackBear_count() {

	int adults = 0, adolescents = 0, babies = 0;
	for(int i = 0; i < num_blackBears; i++) {

		switch(blackBears[i].get_growth_stage()) {

		case 0:
			babies++;
			break;

		case 1:
			adolescents++;
			break;

		case 2:
			adults++;
			break;

		}

	}

	std::cout << "Black Bears: " << babies << " babies, " << adolescents << " adolescents, "
		<< adults << " adults." << std::endl;

}
