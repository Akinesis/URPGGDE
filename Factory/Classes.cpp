/*
 * Classes.cpp
 *
 *  Created on: 7 oct. 2015
 *      Author: E139824H
 */

#include "Classes.hpp"

Classes::Classes(){}

Classes::~Classes(){}

void Classes::createPaladin(){
	className = "Paladin";
	modifStrength = 1;
	modifConstitution = 2;
	modifDexterity = -2;
	modifIntelligence = 0;
	modifWisdom = -1;
	modifCharisma = 1;

}

void Classes::createWarrior(){
	className = "Guerrier";
	modifStrength = 2;
	modifConstitution = 1;
	modifDexterity = 1;
	modifIntelligence = -2;
	modifWisdom = -1;
	modifCharisma = 0;
}

void Classes::createMage(){
	className = "Mage";
	modifStrength = -2;
	modifConstitution = -1;
	modifDexterity = 0;
	modifIntelligence = 2;
	modifWisdom = 2;
	modifCharisma = 0;
}

void Classes::createHunter(){
	className = "Ranger";
	modifStrength = 1;
	modifConstitution = -1;
	modifDexterity = 2;
	modifIntelligence = 0;
	modifWisdom = -1;
	modifCharisma = 0;
}

void Classes::createThief(){
	className = "Roublard";
	modifStrength = 1;
	modifConstitution = -1;
	modifDexterity = 2;
	modifIntelligence = -1;
	modifWisdom = 0;
	modifCharisma = 1;
}

void Classes::createPriest(){
	className = "Pretre";
	modifStrength = -2;
	modifConstitution = -1;
	modifDexterity = 0;
	modifIntelligence = 1;
	modifWisdom = 3;
	modifCharisma = 0;
}

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
	else if(rdmVar == 5{
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
