/*
 * Classes.hpp
 *
 *  Created on: 7 oct. 2015
 *      Author: E139824H
 */

#ifndef CLASSES_HPP_
#define CLASSES_HPP_

#include <cstddef>
#include <ctime>
#include <cstdlib>
#include <string>

class Classes{
	private:
		std::string className;

		int modifStrength;
		int modifConstitution;
		int modifDexterity;
		int modifIntelligence;
		int modifWisdom;
		int modifCharisma;

	public:
		Classes();
		~Classes();

		void createPaladin();
		void createWarrior();
		void createMage();
		void createHunter();
		void createThief();

		void createRandomClass();

		//Getters Setters
		int getModifStrength();
		int getModifConstitution();
		int getModifDexterity();
		int getModifIntelligence();
		int getModifWisdom();
		int getModifCharisma();
		std::string getClassName();


};


#endif /* CLASSES_HPP_ */