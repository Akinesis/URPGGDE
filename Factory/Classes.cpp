/**
* @file Classes.cpp
* @brief Classe de classes
* @author HERAUD Xavier 
* 
* Classes qui gères les classes jouables par les personnages.
*/
#include "Classes.hpp"

/**
* @fn Classes()
* @brief Constructeur de @class Classes Classes.hpp
*
* @param
* @return
*/
Classes::Classes(){}

/**
* @fn ~Classes()
* @brief Destructeur de @class Classes Classes.hpp
*
* @param
* @return
*/
Classes::~Classes(){}

/**
* @fn void createPaladin().
* @brief Attribut aux variables de la @class Classes Classes.hpp les points correspondant à la classe paladin.
*
* @param
* @return
*/
void Classes::createPaladin(){
	className = "Paladin";
	modifStrength = 1;
	modifConstitution = 2;
	modifDexterity = -2;
	modifIntelligence = 0;
	modifWisdom = -1;
	modifCharisma = 1;

}

/**
* @fn void createWarrior().
* @brief Attribut aux variables de la @class Classes Classes.hpp les points correspondant à la classe guerrier.
*
* @param
* @return
*/
void Classes::createWarrior(){
	className = "Guerrier";
	modifStrength = 2;
	modifConstitution = 1;
	modifDexterity = 1;
	modifIntelligence = -2;
	modifWisdom = -1;
	modifCharisma = 0;
}

/**
* @fn void createMage().
* @brief Attribut aux variables de la @class Classes Classes.hpp les points correspondant à la classe mage.
*
* @param
* @return
*/
void Classes::createMage(){
	className = "Mage";
	modifStrength = -2;
	modifConstitution = -1;
	modifDexterity = 0;
	modifIntelligence = 2;
	modifWisdom = 2;
	modifCharisma = 0;
}

/**
* @fn void createHunter().
* @brief Attribut aux variables de la @class Classes Classes.hpp les points correspondant à la classe ranger.
*
* @param
* @return
*/
void Classes::createHunter(){
	className = "Ranger";
	modifStrength = 1;
	modifConstitution = -1;
	modifDexterity = 2;
	modifIntelligence = 0;
	modifWisdom = -1;
	modifCharisma = 0;
}

/**
* @fn void createThief().
* @brief Attribut aux variables de la @class Classes Classes.hpp les points correspondant à la classe roublard.
*
* @param
* @return
*/
void Classes::createThief(){
	className = "Roublard";
	modifStrength = 1;
	modifConstitution = -1;
	modifDexterity = 2;
	modifIntelligence = -1;
	modifWisdom = 0;
	modifCharisma = 1;
}

/**
* @fn void createPriest().
* @brief Attribut aux variables de la @class Classes Classes.hpp les points correspondant à la classe prêtre.
*
* @param
* @return
*/
void Classes::createPriest(){
	className = "Pretre";
	modifStrength = -2;
	modifConstitution = -1;
	modifDexterity = 0;
	modifIntelligence = 1;
	modifWisdom = 3;
	modifCharisma = 0;
}

/**
* @fn void createRandomClass().
* @brief Attribut aux variables de la @class Classes Classes.hpp les points correspondant à une classe aléatoire.
*
* @param
* @return
*/
void Classes::createRandomClass(){
	std::srand((unsigned int)std::time(0));
	int rdmVar = (std::rand() % 6) + 1;

	if(rdmVar == 1){
		createPaladin();
	}
	else if(rdmVar == 2){
		createWarrior();
	}
	else if(rdmVar == 3){
		createMage();
	}
	else if(rdmVar == 4){
		createHunter();
	}
	else if(rdmVar == 5){
		createThief();
	}
	else{
		createPriest();
	}
}

////////////////////////////////////////
//Getters Setters START

int Classes::getModifStrength(){
	return modifStrength;
}

int Classes::getModifConstitution(){
	return modifConstitution;
}

int Classes::getModifDexterity(){
	return modifDexterity;
}

int Classes::getModifIntelligence(){
	return modifIntelligence;
}

int Classes::getModifWisdom(){
	return modifWisdom;
}

int Classes::getModifCharisma(){
	return modifCharisma;
}

std::string Classes::getClassName(){
	return className;
}

void Classes::setClassName(std::string n){
	className = n;
}