#ifndef BOSS_HPP_
#define BOSS_HPP_


#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Character.hpp"

class Boss : public Character{
	private:
		std::string lastName;


	public:
		Boss();
		virtual ~Boss() = 0;
		std::string performAttack();
		std::string defend();

		std::string getLastName();
		void setLastName(std::string);
		void setRandomName();
		void setRandomLastName();
};


#endif /* BOSS_HPP_ */
