#include "Monster.hpp"

std::string Monster::performAttack(){
	std::srand(std::time(0));
		int random_variable = (std::rand() % 20) + 1;
		if (random_variable <= attack()){
			std::cout << name << " a lancé son attaque en faisant un " << random_variable << ". C'est une réussite!";
			return name+" a réussi sa vil attaque grâce à un "+random_variable;
		}
		else {
			std::cout << name << " a lancé une attaque avec un dé de " << random_variable << ". C'est un échec!";
			return name+" a bien raté son attaque avec un "+random_variable;
		}
}

std::string Monster::defend(){
	std::srand(std::time(0));
		int random_variable = (std::rand() % 20) + 1;
		if (random_variable <= attack()){
			std::cout << name << " c'est défendu en faisant un " << random_variable << ". C'est une réussite!";
			return name+" effectué une parade réussit grâce à un "+random_variable;
		}
		else {
			std::cout << name << " c'est défendu en faisant un " << random_variable << ". C'est un échec!";
			return name+" a bien raté sa parade avec un "+random_variable;
		}
}
