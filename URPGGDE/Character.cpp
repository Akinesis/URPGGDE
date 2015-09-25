#include "Character.hpp"


Character::Character(std::string name, int lifePoints, int manaPoints, int strength, int constitution, int dexterity, int intelligence, int wisdom, int charisma, int attack, int defense, int protection, int level){
	this->name = name;
	this->lifePoints = lifePoints;
	this->manaPoints = manaPoints;
	this->strength = strength;
	this->constitution = constitution;
	this->dexterity = dexterity;
	this->intelligence = intelligence;
	this->wisdom = wisdom;
	this->charisma = charisma;
	this->attack = attack;
	this->defense = defense;
	this->protection = protection;
	this->level = level;
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
	//Get Set charisma
int Character::getCharisma(){
	return charisma;
}
void Character::setCharisma(int cha){
	charisma = cha;
}
	//Get Set attack
int Character::getAttack(){
	return attack;
}
void Character::setAttack(int att){
	attack = att;
}
	//Get Set defense
int Character::getDefense(){
	return defense;
}
void Character::setDefense(int def){
	defense = def;
}
	//Get Set protection
int Character::getProtection(){
	return protection;
}
void Character::setProtection(int pr){
	protection = pr;
}
	//Get Set level
int Character::getLevel(){
	return level;
}
void Character::setLevel(int l){
	level = l;
}
// Getters Setters STOP

