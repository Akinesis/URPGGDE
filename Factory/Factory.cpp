/*
 * Factory.cpp
 *
 *  Created on: 12 oct. 2015
 *      Author: E139824H
 */


#include "Factory.hpp"

Factory::Factory(CommandManager* man) : commandManager(man){}

Factory::~Factory(){}


void Factory::setCharacter(Character* charac){
	chara = charac;
}
Character* Factory::getCharacter(){
	return chara;
}