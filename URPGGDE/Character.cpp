#include "Character.hpp"

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
	//Get Set Charisma
int Character::getCharisma(){
	return charisma;
}
void Character::setCharisma(int cha){
	charisma = cha;
}
// Getters Setters STOP

