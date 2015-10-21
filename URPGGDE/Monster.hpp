#ifndef MONSTER_HPP_
#define MONSTER_HPP_

#include <string>;

#include <ctime>;
#include <cstdlib>;
#include <iostream>;

#include "Character.hpp"

class Monster : public Character{
	private:

	public:
		Monster();
		virtual ~Monster();
		std::string performAttack();
		std::string defend();

};



#endif /* MONSTER_HPP_ */
