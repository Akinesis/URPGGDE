#include "Character.hpp"

Character::Character(std::string na, std::string sx, Race ra, Classes cl, int lPoints, int mPoints, int stgth, int cons, int dex, int intel, int wisd, int chari, int att, int def, int pr, int lvl, int bcap, Inventory b){
	name = na;
	sexe = sx;
	race = new Race(ra);
	classe = new Classes(cl);
	lifePoints = lPoints;
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
int Character::getLifePoints(){
	return lifePoints;
}
void Character::setLifePoints(int lPoints){
	lifePoints = lPoints;
}
	//Get Set manaPoints
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
