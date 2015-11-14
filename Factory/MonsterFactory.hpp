#ifndef MONSTERFACTORY_HPP_
#define MONSTERFACTORY_HPP_

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "Factory.hpp"
#include "Monster.hpp"

class MonsterFactory : public Factory{
	public:
		MonsterFactory();
		virtual ~MonsterFactory();

		Character* createAllRandom();
		Character* createPersonnalize();
		Character* createCharacterSaved();
		Character* createCharacter();

		void createBestiaryMonster(Character*);
		void createPersonnalizeMonster(Character*);

		//Getters Setters
		Character* getCharacter();
		void setCharacter(Character*);

};

#endif /* MONSTERFACTORY_HPP_ */
