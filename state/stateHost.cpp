#include "stateHost.hpp"

StateHost::StateHost(CommandManager* commandManager) : State(commandManager){	

}

StateHost::~StateHost(){

}

void StateHost::help(){}

int StateHost::join(){
	manager->createConnexionHost();
	manager->setState(manager->getStateGame());
	manager->analyse("joueur");
	return 0;
}