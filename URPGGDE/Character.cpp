#include "Character.hpp"




//std::random_device rd;//nouvelle methode !
//std::mt19937 rng(rd());//nouvelle methode !
//rng();//nouvelle methode !

/*
std::string Character::attaquer(){
	std::srand(std::time(0)); //use current time as seed for random generator
		int random_variable = (std::rand() % 20) + 1;
		if (random_variable <= getAttack()){
			std::cout << "Vous avez lancé le dé et obtenu " << random_variable << ". C'est une réussite!";
			return name+" a réussi son attaque grâce à un "+random_variable;
		}
		else {
			std::cout << "Vous avez lancé le dé et obtenu " << random_variable << ". C'est un échec!";
			return name+" a raté son attaque avec un "+random_variable;
		}
}
*/

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
// Getters Setters STOP

