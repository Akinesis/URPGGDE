/**
* @file Monster.cpp
* @brief Classe de personnage monstre.
* @author HERAUD Xavier 
* 
* Classe fille de Character qui possèdes les variables et méthodes propres aux monstres.
*/
#include "Monster.hpp"

/**
* @fn Monster()
* @brief Constructeur de @class Monster Monster.hpp
*
* @param
* @return
*/
Monster::Monster(){}

/**
* @fn ~Monster()
* @brief Destructeur de @class Monster Monster.hpp
*
* @param
* @return
*/
Monster::~Monster(){}

/**
* @fn std::string performAttack()
* @brief Lance un d20 et compare le résultat à l'attribut attack.
*
* @param
* @return std::string indiquant si l'attack est réussi ou non.
*/
std::string Monster::performAttack(){
	std::srand(std::time(0));
	int random_variable = (std::rand() % 20) + 1;
	if (random_variable <= attack){
		std::cout << name << " a lance son attaque en faisant un " << random_variable << ". C'est une r�ussite!";
		std::string rdm = std::to_string(random_variable);
		return name+" a reussi sa vil attaque grace a un "+rdm;
	}
	else {
		std::cout << name << " a lance une attaque avec un de de " << random_variable << ". C'est un �chec!";
		std::string rdm = std::to_string(random_variable);
		return name+" a bien rate son attaque avec un "+rdm;
	}
}

/**
* @fn std::string defend()
* @brief Lance un d20 et compare le résultat à l'attribut defense.
*
* @param
* @return std::string indiquant si l'attaque est réussi ou non.
*/
std::string Monster::defend(){
	std::srand(std::time(0));
	int random_variable = (std::rand() % 20) + 1;
	if (random_variable <= attack){
		std::cout << name << " c'est defendu en faisant un " << random_variable << ". C'est une reussite!";
		std::string rdm = std::to_string(random_variable);
		return name+" effectue une parade reussit grace a un "+rdm;
	}
	else {
		std::cout << name << " c'est defendu en faisant un " << random_variable << ". C'est un echec!";
		std::string rdm = std::to_string(random_variable);
		return name+" a bien rate sa parade avec un "+rdm;
	}
}

//////////////////////////////////////////////////////////////////::
//	GETTERS SETTERS
int Monster::getDommagesDe(){
	return dommagesDe;
}
int Monster::getDommagesAdditionnels(){
	return dommagesAdditionnels;
}
void Monster::setDommagesDe(int dd){
	dommagesDe = dd;
}
void Monster::setDommagesAdditionnels(int da){
	dommagesAdditionnels = da;
}



void Monster::setRandomName(){}
void Monster::setRandomLastName(){}
void Monster::setLastName(std::string a){a = a;}
std::string Monster::getLastName(){std::string a = "a"; return a;}
