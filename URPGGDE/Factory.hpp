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
		virtual void createAllRandom();
		virtual void createPersonalize(std::string);
	protected:
		Character chara;
		static int num = 000;
};


#endif /* FACTORY_HPP_ */
