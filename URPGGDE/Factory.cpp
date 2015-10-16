/*
 * Factory.cpp
 *
 *  Created on: 12 oct. 2015
 *      Author: E139824H
 */


#include "Factory.hpp"

Factory::Factory(){}

Factory::~Factory(){}

Factory::Factory(Character ch){
	chara = ch;
}

void Factory::setCharacter(Character charac){
	chara = charac;
}
int Factory::getCharacter(){
	return chara;
}
