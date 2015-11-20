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
		int dommagesDe;
		int dommagesAdditionnels;

	public:
		Boss();
		virtual ~Boss();
		std::string performAttack();
		std::string defend();

		std::string getLastName();
		void setLastName(std::string);
		void setRandomName();
		void setRandomLastName();

		//Getters Setters pour Monster
		int getDommagesDe();
		void setDommagesDe(int);
		int getDommagesAdditionnels();
		void setDommagesAdditionnels(int);
};


#endif /* BOSS_HPP_ */
