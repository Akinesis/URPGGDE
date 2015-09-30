/*
 * CharacterFactory.hpp
 *
 *  Created on: 30 sept. 2015
 *      Author: E139824H
 */

#ifndef CHARACTERFACTORY_HPP_
#define CHARACTERFACTORY_HPP_

/**
 * @param
 *
 **/
class CharacterFactory{
	public:
		Character createAllRandomCharacter(std::string);
		Character createStatRandomCharacter(std::string);
		Character createRaceRandomCharacter(std::string);
		Character createPersonalizeCharacter(std::string);
};


#endif /* CHARACTERFACTORY_HPP_ */
