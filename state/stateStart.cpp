#include "stateStart.hpp"

StateStart::StateStart(CommandManager* commandManager) : State(commandManager){	

}

StateStart::~StateStart(){

}

void StateStart::help(){
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
	std::cout << "Liste des commandes disponible :" << std::endl;
	std::cout << "help, creation, jouer"<< std::endl;
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
}

int StateStart::creation(){
	std::cout << "Que la création commence !!!" << std::endl;


	manager->setState(manager->getStateCreate());
	return 1;
}

int StateStart::play(){
	std::cout << "N'oubliez pas, vous ne pourrez jouer que si vous avez des personnages !" << std::endl;

	manager->setState(manager->getStatePlay());
	return 1;
}