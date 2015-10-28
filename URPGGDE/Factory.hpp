/*
 * CharacterFactory.hpp
 *
 *  Created on: 30 sept. 2015
 *      Author: E139824H
 */

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "Character.hpp"
/**
 * @param
 *
 **/
class Factory{
	protected:
		Character* chara;
	public:
		Factory();
		virtual ~Factory()=0;
		virtual Character* createAllRandom()=0;
		virtual Character* createPersonalize()=0;
		virtual Character* createCharacterSaved()=0;
		
		void setCharacter(Character*);
		Character* getCharacter();
};


#endif /* FACTORY_HPP_ */
