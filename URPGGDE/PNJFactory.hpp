/*
 * PNJFactory.hpp
 *
 *  Created on: 9 oct. 2015
 *      Author: E139824H
 */

#ifndef PNJFACTORY_HPP_
#define PNJFACTORY_HPP_

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

class PNJFactory : public Factory{
	public:
		PNJFactory();
		PNJFactory(Character);
		~PNJFactory();
		void createAllRandom();
		void createPersonalize(std::string);
	private:

};

#endif /* PNJFACTORY_HPP_ */
