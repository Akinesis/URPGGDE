/**
* @file 
* @brief 
* @author Vanoni Joachim
* 
* 
*/
#include "stateStart.hpp"

StateStart::StateStart(CommandManager* commandManager) : State(commandManager){	

std::cout << std::endl;
std::cout << "Welcome to : " <<std::endl;
std::cout << "          _______  _______  _______  _______     ______   _______"<< std::endl;
std::cout << "|\\     /|(  ____ )(  ____ )(  ____ \\(  ____ \\   (  __  \\ (  ____ \\ "<< std::endl;
std::cout << "| )   ( || (    )|| (    )|| (    \\/| (    \\/ _ | (  \\  )| (    \\/ "<< std::endl;
std::cout << "| |   | || (____)|| (____)|| |      | |      (_)| |   ) || (__    "<< std::endl;
std::cout << "| |   | ||     __)|  _____)| | ____ | | ____    | |   | ||  __)   "<< std::endl;
std::cout << "| |   | || (\\ (   | (      | | \\_  )| | \\_  ) _ | |   ) || (      "<< std::endl;
std::cout << "| (___) || ) \\ \\__| )      | (___) || (___) |(_)| (__/  )| (____/\\"<< std::endl;
std::cout << "(_______)|/   \\__/|/       (_______)(_______)   (______/ (_______/"<< std::endl;
std::cout << "Ultimate RolePlaying Game Generator : Deluxe Edition " <<std::endl;                                                               

}

StateStart::~StateStart(){

}

void StateStart::help(){
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
	std::cout << "Liste des commandes disponible :" << std::endl;
	std::cout << "help, creation, jouer"<< std::endl;
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
}

int StateStart::creation(){
	std::cout << "Que la création commence !!!" << std::endl;


	manager->setState(manager->getStateCreate());
	manager->getCurrentState()->play();
	return 0;
}

int StateStart::play(){
	std::cout << "N'oubliez pas, vous ne pourrez jouer que si vous avez des personnages !" << std::endl;

	manager->setState(manager->getStatePlay());
	return 0;
}