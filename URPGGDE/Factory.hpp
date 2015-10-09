/*
 * CharacterFactory.hpp
 *
 *  Created on: 30 sept. 2015
 *      Author: E139824H
 */

#ifndef FACTORY_HPP_
#define FACTORY_HPP_


/**
 * @param
 *
 **/
class Factory{
	public:
		Factory();
		virtual ~Factory();
		virtual Character createAllRandom(std::string);
		virtual Character createPersonalize(std::string);
};


#endif /* FACTORY_HPP_ */
