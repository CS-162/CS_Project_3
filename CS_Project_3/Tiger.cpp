/**
**	Program: Tiger Object
**	Author: Austin Chayka
**	Date: 11.7.2019
**	Description: Implementation of the tiger object
**/
#include "Tiger.h"

/**
**	Function: constructor
**	Description: sets default variable values
**	Parameters: none
**/
Tiger::Tiger() : Animal() {
	
	purchase_cost = 12000;
	feeding_cost_multiplier = 5;
	revenue_percentage = 0.1;

}