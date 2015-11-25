/*
 * CharacterFactory.hpp
 *
 *  Created on: 30 sept. 2015
 *      Author: E139824H
 */

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "Character.hpp"
#include "Config.hpp"
#include "../state/commandManager.hpp"

/**
 * @param
 *
 **/
class Factory{
	protected:
		Character* chara;
		CommandManager* commandManager;
		Config* config;
	public:
		Factory(CommandManager*);
		virtual ~Factory()=0;
		virtual void createAllRandom(Character*)=0;
		virtual void createPersonnalize(Character*)=0;
		virtual Character* createCharacterSaved()=0;

		virtual Character* createCharacter()=0;
		
		void setCharacter(Character*);
		Character* getCharacter();
};


#endif /* FACTORY_HPP_ */
