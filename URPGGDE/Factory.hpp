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
		Factory(Character);
		virtual ~Factory();
		virtual Character createAllRandom(std::string);
		virtual Character createPersonalize(std::string);
	protected:
		Character chara;
};


#endif /* FACTORY_HPP_ */
