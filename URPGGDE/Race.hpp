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
		struct range{
			int min;
			int max;
		};

		range rangeLife;
		range rangeMana;

		range rangeStrength;
		range rangeConstitution;
		range rangeDexterity;
		range rangeIntelligence;
		range rangeWisdom;
		range rangeCharisma;



	public:
		Race();




	// Getters Setters END

};




#endif /* RACE_HPP_ */
