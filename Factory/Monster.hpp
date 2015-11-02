#ifndef MONSTER_HPP_
#define MONSTER_HPP_

#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iostream>

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

};



#endif
