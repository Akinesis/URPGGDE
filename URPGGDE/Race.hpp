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
		std::vector<std::string> humanNames;
		std::vector<int>humanStats;

		std::vector<std::string> orcNames;
		std::vector<int> orcStats;

		std::vector<std::string> elfNames;
		std::vector<int> elfStats[18];


	public:
		Race();
		void CreateVector(std::vector<std::string>, std::vector<std::string>);

		int randomVariable(int, int);

		std::string randomName(std::string, std::string);
		std::string randomLastName(std::string);


	// Getters Setters START
		std::string getHumanNames();
		void setHumanNames(std::string, std::string);
		void setRandomHumanNames(std::string);




	// Getters Setters END

};




#endif /* RACE_HPP_ */
