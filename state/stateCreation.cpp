#include "stateCreation.hpp"

StateCreate::StateCreate(CommandManager* commandManager) : 	State(commandManager),
															fact(new PNJFactory(manager)){	

}

StateCreate::~StateCreate(){

}

void StateCreate::help(){
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;
	std::cout << "Liste des commandes disponibles :" << std::endl;
	std::cout << "help, oui, non, personnage, monstre, boss"<< std::endl;
	std::cout << "homme, femme, aleatoire, personaliser, elfe, orc"<< std::endl;
	std::cout << "humain, nain, guerrier, mage, pretre, paladin"<< std::endl;
	std::cout << "chasseur, roublard, exit"<< std::endl;
	std::cout << "<::::::::::::::::::::::::::::::::::::::::>" << std::endl;

}

int StateCreate::man(){

	return 3;
}

int StateCreate::woman(){
	return 4;
}

int StateCreate::random(){
	return 5;
}

int StateCreate::custom(){
	return 6;
}

int StateCreate::elf(){
	return 7;
}

int StateCreate::human(){
	return 8;
}

int StateCreate::orc(){
	return 9;
}

int StateCreate::dwarf(){
	return 10;
}

int StateCreate::warrior(){
	return 11;
}

int StateCreate::mage(){
	return 12;
}

int StateCreate::priest(){
	return 13;
}

int StateCreate::paladin(){
	return 14;
}

int StateCreate::hunter(){
	return 15;
}

int StateCreate::rogue(){
	return 16;
}

int StateCreate::play(){

	std::string rep;
	int ret = -2;

	while(ret == -2){
		std::cout << "Quel type de personnage voulez vous crée ?\nPNJ, Boss ou Monstre ?" << std::endl;
		std::cin >> rep;
		ret = manager->analyse(rep);
		if(ret == 42){
			fact = new PNJFactory(manager);
		}else if(ret == 43){
			fact = new MonsterFactory(manager);
		}else if(ret == 44){
			fact = new BossFactory(manager);
		}else{
			ret = -2;
		}
	}

	fact->createCharacter();

	return 0;
}

int StateCreate::npc(){
	return 42;
}

int StateCreate::monster(){
	return 43;
}

int StateCreate::boss(){
	return 44; // != bzh
}

int StateCreate::exit(){
	std::cout << "Retours au début du programme ! Êtes vous sure ?" << std::endl;
	std::string rep;
	std::cin >> rep;
	int decode = manager->analyse(rep);

	if(decode == 1){
		manager->setState(manager->getStateStart());
		return 0;
	}else if(decode == 2){
		std::cout << "Ok, on ne fait rien !" << std::endl;
		return 0;
	}else{
		std::cout << "Ce n'étais pas trop la réponse atendus !" << std::endl;
		help();
		return -1;
	}
}
