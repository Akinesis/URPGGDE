#include "stateCreation.hpp"

StateCreate::StateCreate(CommandManager* commandManager) : State(commandManager){	

}

StateCreate::~StateCreate(){

}



void StateCreate::help(){
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
	std::cout << "Liste des commandes disponible :" << std::endl;
	std::cout << "help, oui, non, personnage, monstre, boss"<< std::endl;
	std::cout << "homme, femme, aleatoire, personaliser, elfe, orc"<< std::endl;
	std::cout << "humain, nain, guerrier, mage, pretre, paladin"<< std::endl;
	std::cout << "chasseur, roublard, exit"<< std::endl;
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;

}

int StateCreate::man(){

	return 2;
}

int StateCreate::woman(){
	return 3;
}

int StateCreate::random(){
	return 4;
}

int StateCreate::custom(){
	return 5;
}

int StateCreate::elf(){
	return 6;
}

int StateCreate::human(){
	return 7;
}

int StateCreate::orc(){
	return 8;
}

int StateCreate::dwarf(){
	return 9;
}

int StateCreate::warrior(){
	return 10;
}

int StateCreate::mage(){
	return 11;
}

int StateCreate::priest(){
	return 12;
}

int StateCreate::paladin(){
	return 13;
}

int StateCreate::hunter(){
	return 14;
}

int StateCreate::rogue(){
	return 15;
}


int StateCreate::exit(){
	std::cout << "Retours au début du programme ! Êtes vous sure ?" << std::endl;
	std::string rep;
	std::cin >> rep;
	int decode = manager->analys(rep);

	if(decode ==1){
		manager->setState(manager->getStateStart());
		return 0;
	}else if(decode == 2){
		std::cout << "Ok, on ne fait rien !" << std::endl;
		return 1;
	}else{
		std::cout << "Ce n'étais pas trop la réponse atendus !" << std::endl;
		help();
		return -1;
	}
}
