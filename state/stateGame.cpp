#include "stateGame.hpp"

StateGame::StateGame(CommandManager* commandManager) : State(commandManager){

}

StateGame::~StateGame(){

}

void StateGame::help(){
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
	std::cout << "Liste des commandes disponible :" << std::endl;
	std::cout << "/help, /attaque, /exit"<< std::endl;
	std::cout << "Note : toute commande non précédé par un / seras"<< std::endl;
	std::cout << "identifier comme un simple méssage du chat."<< std::endl;
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;

}

int StateGame::join(){
	return 0;
}