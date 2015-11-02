#include "stateStart.hpp"

StateStart::StateStart(CommandManager* commandManager) : State(commandManager){	

}

StateStart::~StateStart(){

}

void StateStart::help(){
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
	std::cout << "Liste des commandes disponible :" << std::endl;
	std::cout << "help, oui, non, creation, joueur, hote"<< std::endl;
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
}

int StateStart::creation(){
	std::cout << "Que la création commence !!!" << std::endl;


	manager->setState(manager->getStateCreate());
	return 1;
}