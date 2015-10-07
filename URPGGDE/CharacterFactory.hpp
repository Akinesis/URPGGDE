/*
 * CharacterFactory.hpp
 *
 *  Created on: 30 sept. 2015
 *      Author: E139824H
 */

#ifndef CHARACTERFACTORY_HPP_
#define CHARACTERFACTORY_HPP_

#include <ctime>
#include <cstdlib>

/**
 * @param
 *
 **/
class CharacterFactory{
	public:
		CharacterFactory();
		virtual ~CharacterFactory();
		virtual Character createAllRandomCharacter(std::string);
		virtual Character createPersonalizeCharacter(std::string);
};


#endif /* CHARACTERFACTORY_HPP_ */
