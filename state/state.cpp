#include "state.hpp"
#include "commandManager.hpp"

State::State(CommandManager* commandManager): manager(commandManager){
}

State::~State(){

}

/*
int State::help(){
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
	std::cout << "Liste des commandes disponible :" << std::endl;
	std::cout << "help, oui, non, personnage, monstre, boss, creation, jouer, hote,"<< std::endl;
	std::cout << "rejoindre, homme, femme, aleatoire, attaquer, elfe, orc,"<< std::endl;
	std::cout << "huamin, nain, guerrier, mage, pretre, paladin, chasseur,"<< std::endl;
	std::cout << "roublard, annuler"<< std::endl;
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;

	return 0;
}*/

int State::exit(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::cancel(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::yes(){
	return 1;
}

int State::no(){
	return 2;
}

int State::character(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::monster(){
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

int State::play(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::host(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::join(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::man(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::woman(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::random(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::custom(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::attack(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::elf(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::orc(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::human(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::dwarf(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::warrior(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::mage(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::priest(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::paladin(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::hunter(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}

int State::rogue(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}


int State::what(){
	std::cout << "やめて ください 先生" << std::endl;

	return 0;
}

int State::error(){
	std::cout << "Commande invalide désoler !"<< std::endl;
	return -1;
}