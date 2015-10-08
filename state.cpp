#include "state.hpp"

State::State(){

}

State::~State(){

}

int State::help(){
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
	std::cout << "Liste des commandes disponible :" << std::endl;
	std::cout << "help, oui, non, personnage, monstre, boss, creation, jouer, hote,"<< std::endl;
	std::cout << "rejoindre, homme, femme, aleatoire, attaquer, elfe, orc,"<< std::endl;
	std::cout << "huamin, nain, guerrier, mage, pretre, paladin, chasseur,"<< std::endl;
	std::cout << "roublard"<< std::endl;
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;

	return 0;
}

int State::oui(){
	return 1;
}

int State::non(){
	return 0;
}

int State::personnage(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::monstre(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::boss(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::creation(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::jouer(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::hote(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::rejoindre(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::homme(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::femme(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::aleatoire(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::attaquer(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::elfe(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::orc(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::huamin(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::nain(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::guerrier(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::mage(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::pretre(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::paladin(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::chasseur(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::roublard(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}