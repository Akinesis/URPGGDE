#ifndef PNJ_HPP_
#define PNJ_HPP_

#include <string>;

#include <ctime>;
#include <cstdlib>;
#include <iostream>;

class PNJ : public Character {
	private:
		std::string lastName;

	public:
		PNJ(std::string, std::string, std::string, int, int, int, int, int, int, int, int, int, int, int, int, int, Inventory, std::string);
		std::string performAttack();
		std::string defend();


		std::string getLastName();
		void setLastName(std::string);
};



#endif
