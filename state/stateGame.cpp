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
	std::cout << "/help, /attaquer, /exit"<< std::endl;
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

int StateGame::attack(){
	if(manager->getIsServer()){
		std::vector<Character*> persos = manager->getCharacters();
		int taille = persos.size();
		int i =1 ;
		std::string rep;

		std::cout << "Vous avez un total de " << taille << " personages avec vous :" << std::endl;
		for (Character* chara : persos){  
        	std::cout << i << " : " << chara->getName() << std::endl;
        	++i;
   		}

   		int ret = -1;

   		while(ret == -1){
   			std::cout << "Quel personage vas attaquer ?" << std::endl;
   			std::cin >> rep;
   			ret = stoi(rep);
   			std::cout << ret << std::endl;
   			--ret;
   			if(ret < 0 || ret > taille){
   				ret =-1;
   			}
   		}

   		manager->hostSend(persos.at(ret)->performAttack());
	}else{
		manager->clientSend(manager->getCharacters().back()->performAttack());
	}

	return 0;
}