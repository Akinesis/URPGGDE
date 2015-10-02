#ifndef BOSS_HPP_
#define BOSS_HPP_


#include <string>

#include <cstdlib>
#include <ctime>
#include <iostream>

class Boss : public Character{
	private:
		std::string lastName;


	public:
		Boss(std::string, std::string, int, int, int, int, int, int, int, int, int, int, int, int, int, Inventory b, std::string);
		std::string performAttack();
		std::string defend();

		std::string getLastName();
		void setLastName(std::string);
};


#endif /* BOSS_HPP_ */
