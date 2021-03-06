/**
* @file Character.cpp
* @brief Classe abstraite du personnage.
* @author HERAUD Xavier 
* 
* Classe abstraite du personnage possédant des variables et méthodes communes utilisés par tous les autres
* types de personnages.
*/

#include "Character.hpp"
#include "Race.hpp"
#include "Classes.hpp"
#include "Inventory.hpp"

/**
* @fn Character()
* @brief Constructeur de @class Character Character.hpp 
*
* @param
* @return
*/
Character::Character() : race(new Race()), classe(new Classes()), bag(new Inventory()){
}

/**
* @fn ~Character()
* @brief Destructeur de @class Character Character.hpp
*
* @param 
* @return
*/
Character::~Character(){}

/**
* @fn void applyMinStat()
* @brief Applique aux attributs de @class Character Character.hpp le nombre de points minimums authorisé par la race.
*
* @param
* @return 
*/
void Character::applyMinStat(){
	strength = race->getRangeStrengthMin();
	constitution = race->getRangeConstitutionMin();
	dexterity = race->getRangeDexterityMin();
	intelligence = race->getRangeIntelligenceMin();
	wisdom = race->getRangeWisdomMin();
	charisma = race->getRangeCharismaMin();
}

/**
* @fn void applyModifications()
* @brief Applique aux attributs de @class Character Character.hpp les changements du nombre de points en rapport avec la classe.
*
* @param
* @return
*/
void Character::applyModifications(){
	strength = strength + classe->getModifStrength();
	constitution = constitution + classe->getModifConstitution();
	dexterity = dexterity + classe->getModifDexterity();
	intelligence = intelligence + classe->getModifIntelligence();
	wisdom = wisdom + classe->getModifWisdom();
	charisma = charisma + classe->getModifCharisma();
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
Race* Character::getRace(){
	return race;
}
Classes* Character::getClasse(){
	return classe;
}
Inventory* Character::getBag(){
	return bag;
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
void Character::setProtection(int p){
	protection = p;
}
int Character::getProtection(){
	return protection;
}
//GETTERS SETTERS END
///////////////////////////////////////////////////////