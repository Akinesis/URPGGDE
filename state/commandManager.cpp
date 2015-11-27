/**
* @file 
* @brief 
* @author Vanoni Joachim
* 
* 
*/
#include "commandManager.hpp"
#include "state.hpp"
#include "stateStart.hpp"
#include "stateCreation.hpp"
#include "statePlay.hpp"
#include "stateJoin.hpp"
#include "stateHost.hpp"
#include "stateGame.hpp"
#include "stateChoose.hpp"

CommandManager::CommandManager(Connexion* conect): inGame(false), stateStart(new StateStart(this)),
									stateCreate(new StateCreate(this)),
									statePlay(new StatePlay(this)),
									stateJoin(new StateJoin(this)),
									stateHost(new StateHost(this)),
									stateGame(new StateGame(this)),
									stateChoose(new StateChoose(this)),
									currentState(stateStart),
									connexion(conect) {

}

CommandManager::CommandManager(): inGame(false), stateStart(new StateStart(this)),
									stateCreate(new StateCreate(this)),
									statePlay(new StatePlay(this)),
									stateJoin(new StateJoin(this)),
									stateHost(new StateHost(this)),
									stateGame(new StateGame(this)),
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
	}else if(commande == "jouer"){
		return currentState->play();
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
	}else if(commande == "personnaliser"){
		return currentState->custom();
	}else if(commande == "joueur"){
		return currentState->join();
	}else if(commande == "hote"){
		return currentState->host();
	}else if(commande == "pnj"){
		return currentState->npc();
	}else if(commande == "monstre"){
		return currentState->monster();
	}else if(commande == "boss"){
		return currentState->boss();
	}else if(commande == "canard"){
		return currentState->what();
	}else if(is_number(commande)){
		if(StateCreate* v = dynamic_cast<StateCreate*>(currentState)){
   			// old was safely casted to NewType
 	  		return 17;
 	  		delete v;
		}else{
			return throwError();
		}
	}else{	
		currentState->error();
		return -1;
	}

	return 0;
}

int CommandManager::analyseGametext(std::string ligne){
	if(ligne.length() > 0){
		if(ligne.at(0)=='/'){
			ligne.erase(ligne.begin());
			return analyse(ligne);
		}else{
			return 20;
		}
	}
	return -1;
}

int CommandManager::throwError(){
	return currentState->error();
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

State* CommandManager::getStatePlay(){
	return statePlay;
}

State* CommandManager::getStateJoin(){
	return stateJoin;
}

State* CommandManager::getStateHost(){
	return stateHost;
}

State* CommandManager::getStateGame(){
	return stateGame;
}

State* CommandManager::getStateChoose(){
	return stateChoose;
}

void CommandManager::setState(State* etat){
	currentState = etat;
}

//Fonction pour l'observer
void CommandManager::createConnexionJoin(){
	connexion->initClient();
}

void CommandManager::createConnexionHost(){
	connexion->initServer();
}

void CommandManager::clientSend(std::string mes){
	connexion->clientHaveMessageToSend(mes);
}

void CommandManager::hostSend(std::string mes){
	connexion->hostHaveMessageToSend(mes);
}

bool CommandManager::getIsServer(){
	return connexion->getIsServer();
}

bool CommandManager::is_number(const std::string& s){
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

void CommandManager::addCharacter(Character* chara){
	characters.push_back(chara);
}

std::vector<Character*> CommandManager::getCharacters(){
	return characters;
}