#ifndef PNJ_HPP_
#define PNJ_HPP_

#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Character.hpp"

class PNJ : public Character {
	private:
		std::string lastName;

	public:
		PNJ();
		virtual ~PNJ();
		std::string performAttack();
		std::string defend();


		std::string getLastName();
		void setLastName(std::string);
		void setRandomName();
		void setRandomLastName();
};



#endif
