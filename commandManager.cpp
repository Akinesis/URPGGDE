#include "commandManager.hpp"

CommandManager::CommandManager(){
	inGame = false;
	currentState = State();
}

CommandManager::~CommandManager(){

}

int CommandManager::analys(std::string commande){
	//passage de la comamnde en minuscule, au cas oû.
	std::transform(commande.begin(), commande.end(), commande.begin(), ::tolower);

	//début de l'analyse.
	if(commande == "help"){
		return currentState.help();
	}

	return 0;
}

State CommandManager::getCurrentState(){
	return currentState;
}