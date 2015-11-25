#include <iostream>

#include "state/commandManager.hpp"

#include "Observer/connexion.hpp"

int main(){
	CommandManager comm = CommandManager(new Connexion());
	std::string rep;

	//Factory* fact = new BossFactory();
	//Character* chara = fact->createCharacter();

	while(rep!="~stop"){
		std::cin >> rep;
		comm.analyse(rep);
	}
	
	return 0;

}