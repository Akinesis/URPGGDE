#include "stateHost.hpp"

StateHost::StateHost(CommandManager* commandManager) : State(commandManager){	

}

StateHost::~StateHost(){

}

void StateHost::help(){}

int StateHost::join(){
	manager->createConnexionHost();
	return 0;
}