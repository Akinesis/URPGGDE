#include "commandManager.hpp"
#include "state.hpp"
#include "stateStart.hpp"
#include "stateCreation.hpp"

CommandManager::CommandManager(): inGame(false), stateStart(new StateStart(this)),
									stateCreate(new StateCreate(this)),
									currentState(stateStart) {

}

CommandManager::~CommandManager(){

}

int CommandManager::analyse(std::string commande){
	//passage de la comamnde en minuscule, au cas oû.
	std::transform(commande.begin(), commande.end(), commande.begin(), ::tolower);

	//début de l'analyse.
	if(commande == "help"){
		currentState->help();
		return 0;
	}else if(commande == "creation"){
		return currentState->creation();
	}else if(commande == "oui"){
		return currentState->yes();
	}else if(commande == "non"){
		return currentState->no();
	}else if(commande == "exit"){
		return currentState->exit();
	}else if(commande == "homme"){
		return currentState->man();
	}else if(commande == "femme"){
		return currentState->woman();
	}else if(commande == "aléatoire"){
		return currentState->random();
	}else if(commande == "attaquer"){
		return currentState->attack();
	}else if(commande == "elfe"){
		return currentState->elf();
	}else if(commande == "orc"){
		return currentState->orc();
	}else if(commande == "humain"){
		return currentState->human();
	}else if(commande == "nain"){
		return currentState->dwarf();
	}else if(commande == "guerrier"){
		return currentState->warrior();
	}else if(commande == "mage"){
		return currentState->mage();
	}else if(commande == "pretre"){
		return currentState->priest();
	}else if(commande == "paladin"){
		return currentState->paladin();
	}else if(commande == "chasseur"){
		return currentState->hunter();
	}else if(commande == "roublard"){
		return currentState->rogue();
	}else if(commande == "personaliser"){
		return currentState->custom();
	}else if(commande == "canard"){
		return currentState->what();
	}else{
		currentState->error();
		return -1;
	}

	return 0;
}

void CommandManager::throwError(){
	currentState->error();
}

State* CommandManager::getCurrentState(){
	return currentState;
}

State* CommandManager::getStateStart(){
	return stateStart;
}

State* CommandManager::getStateCreate(){
	return stateCreate;
}

void CommandManager::setState(State* etat){
	currentState = etat;
}