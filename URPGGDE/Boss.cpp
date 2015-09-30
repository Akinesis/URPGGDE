#include "Boss.hpp"



Boss::Boss(std::string na, std::string ra, std::string sx, int lPoints, int mPoints, int stgth, int cons, int dex, int intel, int wisd, int chari, int att, int def, int pr, int lvl, int bcap, Inventory b, std::string lname){
	Character(na, sx, ra, lPoints, mPoints, stgth, cons, dex, intel, wisd, chari, att, def, pr, lvl, bcap, b);
	lastName = lname;
}

std::string Boss::performAttack(){
	std::srand(std::time(0));
	int random_variable = (std::rand() % 20) + 1;
	if (random_variable <= attack()){
		std::cout << name << " a lanc� une puissante attaque en faisant un " << random_variable << ". C'est une r�ussite!";
		return name+" a r�ussi sa vil attaque gr�ce � un "+random_variable;
	}
	else {
		std::cout << name << " a lanc� une attaque avec un d� de " << random_variable << ". C'est un �chec!";
		return name+" a bien rat� son attaque avec un "+random_variable;
	}
}


std::string Boss::defend(){
	std::srand(std::time(0));
	int random_variable = (std::rand() % 20) + 1;
	if (random_variable <= attack()){
		std::cout << name << " c'est aisément d�fendu en faisant un " << random_variable << ". C'est une r�ussite!";
		return name+" effectu� une parade r�ussit gr�ce � un "+random_variable;
	}
	else {
		std::cout << name << " c'est d�fendu en faisant un " << random_variable << ". C'est un �chec!";
		return name+" a bien rat� sa parade avec un "+random_variable;
	}
}

////////////////////////////////////////////////////////////////////////////////
// Getters Setters START
std::string Boss::getLastName(){
	return lastName;
}
void Boss::setLastName(std::string ln){
	lastName = ln;
}
// Getters Setters END
