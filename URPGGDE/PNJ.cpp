#include "PNJ.hpp"

PNJ::PNJ(std::string lName){
	lastName = lName;
}


std::string PNJ::performAttack(){
	std::srand(std::time(0));
		int random_variable = (std::rand() % 20) + 1;
		if (random_variable <= attack()){
			std::cout << "Vous avez lancé le dé et obtenu " << random_variable << ". C'est une réussite!";
			return name+" a réussi son attaque grâce à un "+random_variable;
		}
		else {
			std::cout << "Vous avez lancé le dé et obtenu " << random_variable << ". C'est un échec!";
			return name+" a raté son attaque avec un "+random_variable;
		}
}

std::string PNJ::defend(){
	std::srand(std::time(0));
			int random_variable = (std::rand() % 20) + 1;
			if (random_variable <= defense()){
				std::cout << "Vous avez lancé le dé et obtenu " << random_variable << ". C'est une réussite!";
				return name+" a réussi sa défense grâce à un "+random_variable;
			}
			else {
				std::cout << "Vous avez lancé le dé et obtenu " << random_variable << ". C'est un échec!";
				return name+" a rat sa défense avec un "+random_variable;
			}
}

////////////////////////////////////////////////////////////////////////////////
// Getters Setters START

std::string PNJ::getLastName(){
	return lastName;
}
void PNJ::setLasteName(std::string lName){
	lastName = lName;
}

// Getters Setters END
