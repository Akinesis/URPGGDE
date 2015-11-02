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
	public:
		PNJFactory();
		virtual ~PNJFactory();

		Character* createAllRandom();
		Character* createPersonalize();
		Character* createCharacterSaved();

		// Getters Setters
		void setCharacter(Character*);
		Character* getCharacter();
};

#endif /* PNJFACTORY_HPP_ */
