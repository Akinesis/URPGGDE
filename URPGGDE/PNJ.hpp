#ifndef PNJ_HPP_
#define PNJ_HPP_

#include <string>

#include <ctime>
#include <cstdlib>
#include <iostream>

class PNJ : public Character {
	private:
		std::string lastName;

	public:
		PNJ(std::string);
		std::string performAttack();
		std::string defend();


		std::string getLastName();
		void setLasteName(std::string);
};



#endif
