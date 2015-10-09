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
		std::string race;

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
		void createRandomRace();
		void createHuman();
		void createOrc();
		void createElf();
		void createDwarf();

		//Constructor, Destructor, Getters, Setters
		Race(std::string);
		~Race();
		std::string getRaceName();
		void setRace(std::string);

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
