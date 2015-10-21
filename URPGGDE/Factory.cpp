/*
 * Factory.cpp
 *
 *  Created on: 12 oct. 2015
 *      Author: E139824H
 */


#include "Factory.hpp"

Factory::Factory(){}

Factory::~Factory(){}


void Factory::setCharacter(Character* charac){
	chara = charac;
}
Character* Factory::getCharacter(){
	return chara;
}

void Factory::setNum(int n){
	num = n;
}
int Factory::getNum(){
	return num;
}