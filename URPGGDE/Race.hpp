/*
 * Race.hpp
 *
 *  Created on: 1 oct. 2015
 *      Author: Xavier
 */

#ifndef RACE_HPP_
#define RACE_HPP_

#include <string>
#include <stdlib.h>
#include <vector>
#include <cstddef>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>

class Race{
	private:
		std::string raceName;

		struct range{
			int min;
			int max;
		};
		range rangeStrength;
		range rangeConstitution;
		range rangeDexterity;
		range rangeIntelligence;
		range rangeWisdom;
		range rangeCharisma;

	public:

		//Constructor, Destructor, Getters, Setters
		Race();
		~Race();
		
		//Methodes de création de race
		void createRandomRace();
		void createHuman();
		void createOrc();
		void createElf();
		void createDwarf();

		std::string getRaceName();
		void setRace(std::string);

		// Getters Setters
		int getRangeStrengthMin();
		int getRangeStrengthMax();
		int getRangeConstitutionMin();
		int getRangeConstitutionMax();
		int getRangeDexterityMin();
		int getRangeDexterityMax();
		int getRangeIntelligenceMin();
		int getRangeIntelligenceMax();
		int getRangeWisdomMin();
		int getRangeWisdomMax();
		int getRangeCharismaMin();
		int getRangeCharismaMax();



	// Getters Setters END

};




#endif /* RACE_HPP_ */
