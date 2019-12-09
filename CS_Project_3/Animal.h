#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {

protected:

	int purchase_cost;
	int base_feeding_cost;
	int feeding_cost_multiplier;
	int age;
	double revenue_percentage;
	bool sick;

public:

	Animal();
	Animal(const Animal&);

	Animal& operator=(const Animal&);

	virtual ~Animal();

	void set_purchase_cost(int);
	int get_purchase_cost();
	void set_base_feeding_cost(int);
	int get_base_feeding_cost();
	void set_feeding_cost_multiplier(int);
	int get_feeding_cost_multiplier();
	void set_age(int);
	int get_age();
	void set_revenue_percentage(double);
	double get_revenue_percentage();
	void set_sick(bool);
	bool is_sick();

	double get_revenue();
	int get_monthly_cost();
	void increase_age(int);
	int get_growth_stage();

};

#endif 