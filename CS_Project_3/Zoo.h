#ifndef ZOO_H
#define ZOO_H

#include "SeaLion.h"
#include "Tiger.h"
#include "BlackBear.h"

class Zoo {

	private:

		SeaLion *seaLions;
		int num_seaLions;
		Tiger *tigers;
		int num_tigers;
		BlackBear *blackBears;
		int num_blackBears;

		int money;

		bool increased_vists;

		int food_type;

	public:

		Zoo();
		Zoo(const Zoo&);

		~Zoo();

		Zoo& operator=(const Zoo&);
		
		int get_money();
		void set_money(int);

		int get_food_type();
		void set_food_type(int);

		void update();
		void run_event();

		void spread_illness();
		void birth_animal();

		int get_num_adult_seaLions();
		int get_num_adult_tigers();
		int get_num_adult_blackBears();

		void update_seaLions();
		void update_tigers();
		void update_blackBears();

		int get_revenue();
		int get_costs();

		void add_seaLion();
		void remove_seaLion(int);
		void add_tiger();
		void remover_tiger(int);
		void add_blackBear();
		void remove_blackBear(int);

		void print_seaLion_count();
		void print_tiger_count();
		void print_blackBear_count();
		
};

#endif