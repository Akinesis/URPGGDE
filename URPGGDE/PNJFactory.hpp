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

#include "Factory.hpp"
#include "PNJ.hpp"

class PNJFactory : public Factory{
	public:
		PNJFactory();
		virtual ~PNJFactory();

		Character* createAllRandom();
		//void createPersonalize();

		void setCharacter(Character*);
		Character* getCharacter();
	private:
		int num;

};

#endif /* PNJFACTORY_HPP_ */
