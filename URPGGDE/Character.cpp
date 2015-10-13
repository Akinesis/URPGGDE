#include "Character.hpp"

Character::Character(std::string na, std::string sx, Race ra, Classes cl, int cLPoints, int lPoints, int cMPoints, int mPoints, int stgth, int cons, int dex, int intel, int wisd, int chari, int att, int def, int pr, int lvl, int bcap, Inventory b){
	name = na;
	sexe = sx;
	race = new Race(ra);
	classe = new Classes(cl);
	currentLifePoints = cLPoints;
	lifePoints = lPoints;
	currentManaPoints = cMPoints;
	manaPoints = mPoints;
	strength = stgth;
	constitution = cons;
	dexterity = dex;
	intelligence = intel;
	wisdom = wisd;
	charisma = chari;
	attack = att;
	defense = def;
	protection = pr;
	level = lvl;
	bagCapacity = bcap;
	Inventory * bag = new Inventory[b];
}

//Méthodes de création de race


void Character::applyMinStats(){
	this->setStrength(race.rangeStrength.min);
	setStrength(race.rangeConstitution.min);
	setStrength(race.rangeDexterity.min);
	setStrength(race.rangeIntelligence.min);
	setStrength(race.rangeWisdom.min);
	setStrength(race.rangeCharisma.min);
}


void Character::createHuman(){
	race = "Human";
	race.rangeStrength.min = 8;
	race.rangeStrength.max = 12;
	race.rangeConstitution.min = 8;
	race.rangeConstitution.max = 12;
	race.rangeDexterity.min = 8;
	race.rangeDexterity.max = 12;
	race.rangeIntelligence.min = 8;
	race.rangeIntelligence.max = 12;
	race.rangeWisdom.max = 8;
	race.rangeWisdom.min = 12;
	race.rangeCharisma.min = 8;
	race.rangeCharisma.max = 12;

	applyMinStats();
}

void Character::createOrc(){
	race.race = "Orc";
	race.rangeStrength.min = 11;
	race.rangeStrength.max = 15;
	race.rangeConstitution.min = 10;
	race.rangeConstitution.max = 14;
	race.rangeDexterity.min = 8;
	race.rangeDexterity.max = 12;
	race.rangeIntelligence.min = 5;
	race.rangeIntelligence.max = 9;
	race.rangeWisdom.max = 6;
	race.rangeWisdom.min = 10;
	race.rangeCharisma.min = 8;
	race.rangeCharisma.max = 12;

	applyMinStats();
}

void Character::createElf(){
	race = "Elf";
	race.rangeStrength.min = 5;
	race.rangeStrength.max = 9;
	race.rangeConstitution.min = 5;
	race.rangeConstitution.max = 9;
	race.rangeDexterity.min = 11;
	race.rangeDexterity.max = 15;
	race.rangeIntelligence.min = 8;
	race.rangeIntelligence.max = 12;
	race.rangeWisdom.max = 9;
	race.rangeWisdom.min = 13;
	race.rangeCharisma.min = 10;
	race.rangeCharisma.max = 14;

	applyMinStats();
}

void Character::createDwarf(){
	race = "Dwarf";
	race.rangeStrength.min = 9;
	race.rangeStrength.max = 13;
	race.rangeConstitution.min = 11;
	race.rangeConstitution.max = 15;
	race.rangeDexterity.min = 9;
	race.rangeDexterity.max = 13;
	race.rangeIntelligence.min = 8;
	race.rangeIntelligence.max = 12;
	race.rangeWisdom.max = 5;
	race.rangeWisdom.min = 9;
	race.rangeCharisma.min = 6;
	race.rangeCharisma.max = 10;

	applyMinStats();
}
// A creer
void Character::createRandomRace(){
	std::srand(std::time(0));
	int rdmVar = (std::rand() % 4) + 1;

	if(rdmVar == 1){
		createHuman();
	}
	else if(rdmVar == 2){
		createOrc();
	}
	else if(rdmVar == 3){
		createElf();
	}
	else{
		createDwarf();
	}
}

////////////////////////////////////////////////////////////////////////////////

// Getters Setters START
	//Get Set name
std::string Character::getName() {
	return name;
}
void Character::setName(std::string n) {
	name = n;
}
std::string Character::getSexe(){
	return sexe;
}
void Character::setSexe(std::string sx){
	sexe = sx;
}
Race Character::getRace(){
	return race;
}
Classes Character::getClasse(){
	return classe;
}
	//Get Set lifePoints
void Character::setCurrentLifePoints(int clp){
	currentLifePoints = clp;
}
int Character::getCurrentLifePoints(){
	return currentLifePoints;
}
int Character::getLifePoints(){
	return lifePoints;
}
void Character::setLifePoints(int lPoints){
	lifePoints = lPoints;
}
	//Get Set manaPoints
void Character::setCurrentManaPoints(int cmp){
	currentManaPoints = cmp;
}
int Character::getCurrentManaPoints(){
	return currentManaPoints;
}
int Character::getManaPoints(){
	return manaPoints;
}
void Character::setManaPoint(int mPoints){
	manaPoints = mPoints;
}

	//Get Set strength
int Character::getStrength(){
	return strength;
}
void Character::setStrength(int str){
	strength = str;
}
	//Get Set constitution
int Character::getConstitution(){
	return constitution;
}
void Character::setConstitution(int cons){
	constitution = cons;
}
	//Get Set dexterity
int Character::getDexterity(){
	return dexterity;
}
void Character::setDexterity(int dex){
	dexterity = dex;
}
	//Get Set intelligence
int Character::getIntelligence(){
	return intelligence;
}
void Character::setIntelligence(int intel){
	intelligence = intel;
}
	//Get Set wisdom
int  Character::getWisdom(){
	return wisdom;
}
void Character::setWisdom(int wisd){
	wisdom = wisd;
}
int Character::getCharisma(){
	return charisma;
}
void Character::setCharisma(int cha){
	charisma = cha;
}
	//Get Set Attack Defense
void Character::setAttack(int att){
	attack = att;
}
int Character::getAttack(){
	return attack;
}
void Character::setDefense(int def){
	defense = def;
}
int Character::getDefense(){
	return defense;
}
