/**
**	Program: Black Bear Object
**	Author: Austin Chayka
**	Date: 11.7.2019
**	Description: Implementation of the black bear object
**/
#include "BlackBear.h"

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: none
**/
BlackBear::BlackBear() : Animal() {

	purchase_cost = 5000;
	feeding_cost_multiplier = 3;
	revenue_percentage = 0.1;

}
