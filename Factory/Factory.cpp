/**
* @file Factory.cpp
* @brief Classe abstraite de la Fabrique
* @author HERAUD Xavier 
* 
* Classe mère possédants les méthodes communes à toutes les fabriques.
*/
#include "Factory.hpp"

/**
* @fn Factory()
* @brief Constructeur de @class Factory Factory.hpp
*
* @param
* @return
*/
Factory::Factory() : commandManager(new CommandManager()){}

/**
* @fn ~Factory()
* @brief Destructeur de @class Factory Factory.hpp
*
* @param
* @return
*/
Factory::~Factory(){}


void Factory::setCharacter(Character* charac){
	chara = charac;
}
Character* Factory::getCharacter(){
	return chara;
}