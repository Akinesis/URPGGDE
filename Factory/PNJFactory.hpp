#ifndef PNJFACTORY_HPP_
#define PNJFACTORY_HPP_

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <dirent.h>

#include "Factory.hpp"
#include "PNJ.hpp"

class PNJFactory : public Factory{
	private:
		void randomSex(Character*);
		void randomSkillPoints(Character*);
		
	public:
		PNJFactory(CommandManager *);
		virtual ~PNJFactory();

		void createAllRandom(Character*);
		void createPersonnalize(Character*);
		Character* createCharacterSaved();
		Character* createCharacter();

		
		void applySkillPoints(Character*);
		void save(Character*, std::string, bool);

		// Getters Setters
		void setCharacter(Character*);
		Character* getCharacter();
};

#endif /* PNJFACTORY_HPP_ */
