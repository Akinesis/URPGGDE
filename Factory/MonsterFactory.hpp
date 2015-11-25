#ifndef MONSTERFACTORY_HPP_
#define MONSTERFACTORY_HPP_

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <dirent.h>

#include "Factory.hpp"
#include "Monster.hpp"

class MonsterFactory : public Factory{
	private:
		void createPersonnalizeMonster(Character*);
		void createBestiaryMonster(Character*);
	public:
		MonsterFactory(CommandManager *);
		virtual ~MonsterFactory();

		void createAllRandom(Character*);
		void createPersonnalize(Character*);
		Character* createCharacterSaved();
		Character* createCharacter();	

		void save(Character*, std::string, bool);

		//Getters Setters
		Character* getCharacter();
		void setCharacter(Character*);

};

#endif /* MONSTERFACTORY_HPP_ */
