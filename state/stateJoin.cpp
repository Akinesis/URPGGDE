/**
* @file 
* @brief 
* @author Vanoni Joachim
* 
* 
*/
#include "stateJoin.hpp"

StateJoin::StateJoin(CommandManager* commandManager) : State(commandManager){	

}

StateJoin::~StateJoin(){

}

void StateJoin::help(){}

int StateJoin::join(){
	manager->createConnexionJoin();
	manager->setState(manager->getStateGame());
	manager->analyse("joueur");
	return 0;
}