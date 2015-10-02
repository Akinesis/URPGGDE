/*
 * Race.hpp
 *
 *  Created on: 1 oct. 2015
 *      Author: Xavier
 */

#ifndef RACE_HPP_
#define RACE_HPP_

#include <string>;
#include <stdlib.h>;
#include <vector>;
#include <cstddef>;
#include <ctime>;
#include <cstdlib>;

class Race{
	private:
		std::vector<std::string> humanNames;
		std::vector<int>humanStats;

		std::vector<std::string> orcNames;
		std::vector<std::string> orcStats;

		std::vector<std::string> elfNames;
		std::vector<std::string> elfStats;


	public:
		Race();
		void humanCreateVector(std::vector<std::string>, std::vector<std::string>);

		int randomVariable(int, int);

		std::string randomName(std::string);
		std::string randomLastName(std::string);

	// Getters Setters START

	// Getters Setters END

};




#endif /* RACE_HPP_ */
