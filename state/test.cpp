#include <iostream>
#include <string>
#include "commandManager.hpp"
#include "../Observer/connexion.hpp"

int main(){
	CommandManager comm = CommandManager(new Connexion());

	std::string rep;

	while(rep!="stop"){
		std::cin >> rep;
		comm.analyse(rep);
	}
	
	return 0;
}