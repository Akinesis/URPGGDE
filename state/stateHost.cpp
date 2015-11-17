#include "stateHost.hpp"

StateHost::StateHost(CommandManager* commandManager) : State(commandManager){	

}

StateHost::~StateHost(){

}

void StateHost::help(){}

int StateHost::join(){
	manager->createConnexionHost();
	std::string rep;

	while(1){
		std::cout << "Attente du méssage" << std::endl;
		std::getline (std::cin,rep);
		manager->hostSend(rep);
	}
	return 0;
}