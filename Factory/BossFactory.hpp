#ifndef BOSSFACTORY_HPP_
#define BOSSFACTORY_HPP_

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <dirent.h>

#include "Factory.hpp"
#include "Boss.hpp"
#include "PNJFactory.hpp"
#include "MonsterFactory.hpp"

class BossFactory : public Factory{
	private:
		PNJFactory* pnjFact;
		MonsterFactory* monsterFact;
	public:
		BossFactory(CommandManager *);
		virtual ~BossFactory();

		void createAllRandom(Character*);
		void createPersonnalize(Character*);
		Character* createCharacterSaved();
		Character* createCharacter();

		void setCharacter(Character*);
		Character* getCharacter();
};

#endif