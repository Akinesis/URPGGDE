#ifndef MONSTER_HPP_
#define MONSTER_HPP_

#include <string>;

#include <ctime>;
#include <cstdlib>;
#include <iostream>;

class Monster : public Character{
	private:

	public:
		Monster(std::string, std::string, std::string, int, int, int, int, int, int, int, int, int, int, int, int, int, Inventory);
		std::string performAttack();
		std::string defend();




};



#endif /* MONSTER_HPP_ */
