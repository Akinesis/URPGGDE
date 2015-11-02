#include <iostream>
#include <string>
#include "commandManager.hpp"

int main(){
	CommandManager comm = CommandManager();

	std::string rep;

	while(rep!="stop"){
		std::cin >> rep;
		comm.analys(rep);
	}
	
	return 0;
}