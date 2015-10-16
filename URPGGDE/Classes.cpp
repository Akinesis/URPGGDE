/*
 * Classes.cpp
 *
 *  Created on: 7 oct. 2015
 *      Author: E139824H
 */

#include "Classes.hpp"
#include "Character.hpp"
/*
void Classes::applyModifications(Character chara){
	chara.setStrength(chara.getStrength()+modifStrength);
	chara.setConstitution(chara.getConstitution()+modifConstitution);
	chara.setDexterity(chara.getDexterity()+modifDexterity);
	chara.setIntelligence(chara.getIntelligence()+modifIntelligence);
	chara.setWisdom(chara.getWisdom()+modifWisdom);
	chara.setCharisma(chara.getCharisma()+modifCharisma);
}
*/
void Classes::createPaladin(Character chara){
	modifStrength = 1;
	modifConstitution = 2;
	modifDexterity = -2;
	modifIntelligence = 0;
	modifWisdom = -1;
	modifCharisma = 1;
	applyModifications(chara);

}

void Classes::createWarrior(Character chara){
	modifStrength = 2;
	modifConstitution = 1;
	modifDexterity = 1;
	modifIntelligence = -2;
	modifWisdom = -1;
	modifCharisma = 0;
	applyModifications(chara);
}

void Classes::createMage(Character chara){
	modifStrength = -2;
	modifConstitution = -1;
	modifDexterity = 0;
	modifIntelligence = 2;
	modifWisdom = 2;
	modifCharisma = 0;
	applyModifications(chara);
}

void Classes::createHunter(Character chara){
	modifStrength = 1;
	modifConstitution = -1;
	modifDexterity = 2;
	modifIntelligence = 0;
	modifWisdom = -1;
	modifCharisma = 0;
	applyModifications(chara);
}

void Classes::createThief(Character chara){
	modifStrength = 1;
	modifConstitution = -1;
	modifDexterity = 2;
	modifIntelligence = -1;
	modifWisdom = 0;
	modifCharisma = 1;
	applyModifications(chara);
}

void Classes::createRandomClass(Character chara){
	std::srand(std::time(0));
	int rdmVar = (std::rand() % 5) + 1;

	if(rdmVar == 1){
		createPaladin(chara);
	}
	else if(rdmVar == 2){
		createWarrior(chara);
	}
	else if(rdmVar == 3){
		createMage(chara);
	}
	else if(rdmVar == 4){
		createHunter(chara);
	}
	else{
		createThief(chara);
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
