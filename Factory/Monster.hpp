#ifndef MONSTER_HPP_
#define MONSTER_HPP_

#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>

#include "Character.hpp"

class Monster : public Character{
	private:
		int dommagesDe;
		int dommagesAdditionnels;
	public:
		Monster();
		virtual ~Monster();
		std::string performAttack();
		std::string defend();


		// Getters Setters
		int getDommagesDe();
		int getDommagesAdditionnels();
		void setDommagesDe(int);
		void setDommagesAdditionnels(int);

		//Getter Setters de Character non utilisé
		void setRandomName();
		void setRandomLastName();
		void setLastName(std::string);
		std::string getLastName();
};



#endif
