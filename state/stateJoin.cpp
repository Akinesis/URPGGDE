#include "stateJoin.hpp"

StateJoin::StateJoin(CommandManager* commandManager) : State(commandManager){	

}

StateJoin::~StateJoin(){

}

void StateJoin::help(){}

int StateJoin::join(){
	manager->createConnexionJoin();

	std::string rep;

	std::cout << "entrée dans la boucle" << std::endl;

	while(1){
		std::cout << "Attente du méssage" << std::endl;
		std::getline (std::cin,rep);
		manager->clientSend(rep);
	}

	return 0;
}