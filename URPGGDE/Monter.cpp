#include "Monster.hpp"

std::string Monster::performAttack(){
	std::srand(std::time(0));
		int random_variable = (std::rand() % 20) + 1;
		if (random_variable <= attack()){
			std::cout << name << " a lanc� son attaque en faisant un " << random_variable << ". C'est une r�ussite!";
			return name+" a r�ussi sa vil attaque gr�ce �un "+random_variable;
		}
		else {
			std::cout << name << " a lanc� une attaque avec un d� de " << random_variable << ". C'est un �chec!";
			return name+" a bien rat� son attaque avec un "+random_variable;
		}
}

std::string Monster::defend(){
	std::srand(std::time(0));
		int random_variable = (std::rand() % 20) + 1;
		if (random_variable <= attack()){
			std::cout << name << " c'est d�fendu en faisant un " << random_variable << ". C'est une r�ussite!";
			return name+" effectu� une parade r�ussit gr�ce �un "+random_variable;
		}
		else {
			std::cout << name << " c'est d�fendu en faisant un " << random_variable << ". C'est un �chec!";
			return name+" a bien rat� sa parade avec un "+random_variable;
		}
}
