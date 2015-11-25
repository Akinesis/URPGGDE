/**
* @file stateGame
* @brief Classe d'état jeu.
* @author Vanoni Joachim
* 
* Classe état qui gère 
*/
#include "stateGame.hpp"

StateGame::StateGame(CommandManager* commandManager) : State(commandManager){

}

StateGame::~StateGame(){

}

void StateGame::help(){
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
	std::cout << "Liste des commandes disponible :" << std::endl;
	std::cout << "/help, /attaque, /exit"<< std::endl;
	std::cout << "Note : toute commande non précédé par un / seras"<< std::endl;
	std::cout << "identifier comme un simple méssage du chat."<< std::endl;
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;

}

int StateGame::join(){
	std::string rep;

	while(1){
		std::cout << "Votre méssage : " << std::endl;
		std::getline (std::cin,rep);
		if(rep.length() != 1){
			if(manager->analyseGametext(rep) == 20){
				if(manager->getIsServer()){
					manager->hostSend(rep);
				}else{
					manager->clientSend(rep);
				}
			}
		}
	}
	return 0;
}