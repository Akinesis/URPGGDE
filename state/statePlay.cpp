#include "statePlay.hpp"

StatePlay::StatePlay(CommandManager* commandManager) : State(commandManager){	

}

StatePlay::~StatePlay(){

}

void StatePlay::help(){
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
	std::cout << "Liste des commandes disponible :" << std::endl;
	std::cout << "help, joueur, hote"<< std::endl;
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
}

int StatePlay::join(){
	std::cout << "Vous serrez donc joueur." << std::endl;


	manager->setState(manager->getStateJoin());
	return 0;
}

int StatePlay::host(){
	std::cout << "C'est donc vous qui serrez GM, bravo !" << std::endl;


	manager->setState(manager->getStateHost());
	return 0;
}

int StatePlay::exit(){
	std::cout << "Retours au début du programme ! Êtes vous sure ?" << std::endl;
	std::string rep;
	std::cin >> rep;
	int decode = manager->analyse(rep);

	if(decode == 1){
		manager->setState(manager->getStateStart());
		return 0;
	}else if(decode == 2){
		std::cout << "Ok, on ne fait rien !" << std::endl;
		return 0;
	}else{
		std::cout << "Ce n'étais pas trop la réponse atendus !" << std::endl;
		help();
		return -1;
	}
}