#include "stateChoose.hpp"

StateChoose::StateChoose(CommandManager* commandManager) : State(commandManager){
}

StateChoose::~StateChoose(){

}

void StateChoose::help(){
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
	std::cout << "Liste des commandes disponible :" << std::endl;
	std::cout << "help, oui, non, PNJ, boss, monstre"<< std::endl;
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
}

int StateChoose::play(){
	bool end = false;
	std::string rep;

	if(manager->getIsServer()){
		int ret = -1;

		std::cout << "Vous serez MJ, vous pouvez prendre avec vous autant de personnage que vous voulez." << std::endl;
		while(!end){
			while(ret == -1){
				std::cout << "Quel type de personnage voulez vous selectionez ?\nPNJ, boss, monstre ?" << std::endl;
				std::cin >> rep;
				ret = manager->analyse(rep);
				if(ret != 42 && ret != 43 && ret !=44 ){
					ret = -1;
				}
			}

			ret = -1;
			manager->addCharacter(fact->createCharacterSaved());

			while(ret == -1){
				std::cout << "voulez vous prendre un autre personnage ?" << std::endl;
				std::cin >> rep;
				ret = manager->analyse(rep);
				if(ret == 1){
					end = false;
				}else if(ret == 2){
					std::cout << "Que le jeu commence !" << std::endl;
					end = true;
				}else{
					std::cout << "oui ou non, ce n'est pas compliquer si ?" << std::endl;
					ret = -1;
				}
			}
			ret = -1;
		}
	}else{
		std::cout << "Vous serez joueur, vous pouvez prendre un personnage avec vous." << std::endl;
		npc();

		manager->addCharacter(fact->createCharacterSaved());
	}

	manager->setState(manager->getStateGame());
	manager->analyse("joueur");
	return 0;
}

int StateChoose::npc(){
	fact = new PNJFactory(manager);

	return 42;
}

int StateChoose::boss(){
	fact = new BossFactory(manager);

	return 43;
}

int StateChoose::monster(){
	fact = new MonsterFactory(manager);

	return 44; // != bzh
}