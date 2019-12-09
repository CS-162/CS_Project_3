/**
**	Program: Sea Lion Object
**	Author: Austin Chayka
**	Date: 11.7.2019
**	Description: Implementation of the sea lion object
**/
#include "SeaLion.h"

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: none
**/
SeaLion::SeaLion() : Animal() {

	purchase_cost = 700;
	feeding_cost_multiplier = 1;
	revenue_percentage = 0.2;

}
