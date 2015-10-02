#include "Character.hpp"


Character::Character(std::string na, std::string sx, int lPoints, int mPoints, int stgth, int cons, int dex, int intel, int wisd, int chari, int att, int def, int pr, int lvl, int bcap, Inventory b){
	name = na;
	sexe = sx;
	Race race = new Race();
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
	//Get Set bagCapacity
int Character::getBagCapacity(){
	return bagCapacity;
}
void Character::setBagCapacity(int cap){
	bagCapacity = cap;
}
// Getters Setters STOP
