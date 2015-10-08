#include <iostream>
#include "commandManager.hpp"

int main(){
	CommandManager comm = CommandManager();

	comm.analys("help");
	return 0;
}