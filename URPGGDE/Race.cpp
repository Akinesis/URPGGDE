#include "Race.hpp"
#include "Character.hpp"

Race::Race(std::string ra){
	std::string race = ra;
}

//Méthodes de création de race


void Race::applyMinStats(Character chara){
	chara.setStrength(rangeStrength.min);
	chara.setConstitution(rangeConstitution.min);
	chara.setDexterity(rangeDexterity.min);
	chara.setIntelligence(rangeIntelligence.min);
	chara.setWisdom(rangeWisdom.min);
	chara.setCharisma(rangeCharisma.min);
}


void Race::createHuman(Character chara){
	race = "Human";
	rangeStrength.min = 8;
	rangeStrength.max = 12;
	rangeConstitution.min = 8;
	rangeConstitution.max = 12;
	rangeDexterity.min = 8;
	rangeDexterity.max = 12;
	rangeIntelligence.min = 8;
	rangeIntelligence.max = 12;
	rangeWisdom.max = 8;
	rangeWisdom.min = 12;
	rangeCharisma.min = 8;
	rangeCharisma.max = 12;

	applyMinStats(chara);
}

void Race::createOrc(Character chara){
	race = "Orc";
	rangeStrength.min = 11;
	rangeStrength.max = 15;
	rangeConstitution.min = 10;
	rangeConstitution.max = 14;
	rangeDexterity.min = 8;
	rangeDexterity.max = 12;
	rangeIntelligence.min = 5;
	rangeIntelligence.max = 9;
	rangeWisdom.max = 6;
	rangeWisdom.min = 10;
	rangeCharisma.min = 8;
	rangeCharisma.max = 12;

	applyMinStats(chara);
}

void Race::createElf(Character chara){
	race = "Elf";
	rangeStrength.min = 5;
	rangeStrength.max = 9;
	rangeConstitution.min = 5;
	rangeConstitution.max = 9;
	rangeDexterity.min = 11;
	rangeDexterity.max = 15;
	rangeIntelligence.min = 8;
	rangeIntelligence.max = 12;
	rangeWisdom.max = 9;
	rangeWisdom.min = 13;
	rangeCharisma.min = 10;
	rangeCharisma.max = 14;

	applyMinStats(chara);
}

void Race::createDwarf(Character chara){
	race = "Dwarf";
	rangeStrength.min = 9;
	rangeStrength.max = 13;
	rangeConstitution.min = 11;
	rangeConstitution.max = 15;
	rangeDexterity.min = 9;
	rangeDexterity.max = 13;
	rangeIntelligence.min = 8;
	rangeIntelligence.max = 12;
	rangeWisdom.max = 5;
	rangeWisdom.min = 9;
	rangeCharisma.min = 6;
	rangeCharisma.max = 10;

	applyMinStats(chara);
}

void Race::createRandomRace(Character chara){
	std::srand(std::time(0));
	int rdmVar = (std::rand() % 4) + 1;

	if(rdmVar == 1){
		createHuman(chara);
	}
	else if(rdmVar == 2){
		createOrc(chara);
	}
	else if(rdmVar == 3){
		createElf(chara);
	}
	else{
		createDwarf(chara);
	}
}
////////////////////////////////////////////////////////////////////////////////
// Getters Setters START

std::string Race::getRaceName(){
	return race;
}

void Race::setRace(std::string ra){
	race = ra;
}

int Race::getRangeStrengthMin(){
	return rangeStrength.min;
}

int Race::getRangeStrengthMax(){
	return rangeStrength.max;
}

int Race::getRangeConstitutionMin(){
	return rangeConstitution.min;
}

int Race::getRangeConstitutionMax(){
	return rangeConstitution.max;
}

int Race::getRangeDexterityMin(){
	return rangeDexterity.min;
}

int Race::getRangeDexterityMax(){
	return rangeDexterity.max;
}

int Race::getRangeIntelligenceMin(){
	return rangeIntelligence.min;
}

int Race::getRangeIntelligenceMax(){
	return rangeIntelligence.max;
}

int Race::getRangeWisdomMin(){
	return rangeWisdom.min;
}

int Race::getRangeWisdomMax(){
	return rangeWisdom.max;
}

int Race::getRangeCharismaMin(){
	return rangeCharisma.min;
}

int Race::getRangeCharismaMax(){
	return rangeCharisma.max;
}
