/**
* @file 
* @brief 
* @author Vanoni Joachim
* 
* 
*/
#include "stateHost.hpp"

StateHost::StateHost(CommandManager* commandManager) : State(commandManager){	

}

StateHost::~StateHost(){

}

void StateHost::help(){}

int StateHost::join(){
	manager->createConnexionHost();
	manager->setState(manager->getStateChoose());
	manager->analyse("jouer");
	return 0;
}