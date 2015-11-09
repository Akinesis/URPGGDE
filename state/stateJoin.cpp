#include "stateJoin.hpp"

StateJoin::StateJoin(CommandManager* commandManager) : State(commandManager){	

}

StateJoin::~StateJoin(){

}

void StateJoin::help(){}

int StateJoin::join(){
	manager->createConnexionJoin();
	return 0;
}