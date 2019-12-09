#include "util.h"

#include <iostream>

/**
**	Function: is number
**	Description: checks if string contains only numeric digits
**	Parameters: string to check
**/
bool is_num(std::string s) {

	for(int i = (s[0] == '-' ? 1 : 0); s[i] != '\0'; i++) if(s[i] < '0' || s[i] > '9') return false;

	return true;

}

/**
**	Function: get number choice
**	Description: gets a number choice from the user
**	Parameters: minimum valid choice, maximum valid choice
**/
int get_number_choice(int min, int max) {

	std::cout << "Enter choice:";
	std::string input;
	std::cin >> input;

	bool valid = false;
	while(!valid) {
		if(!is_num(input)) {
			std::cout << "Error: input was not a number. Enter again:";
			std::cin >> input;
		} else if(stoi(input) < min || stoi(input) > max) {
			std::cout << "Error: not a valid option. Enter again:";
			std::cin >> input;
		} else valid = true;
	}

	return stoi(input);

}

/**
**	Function: get random number
**	Description: gets a random number within the specified range
**	Parameters: minimum bounds (inclusive), maximum bounds (inclusive)
**/
int get_rad_num(int min, int max) {

	if(min == max) return min;
	
	return rand() % (max - min + 1) + min;

}
