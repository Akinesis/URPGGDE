/*
 * CharacterFactory.cpp
 *
 *  Created on: 30 sept. 2015
 *      Author: E139824H
 */

// uppercase
#include "CharacterFactory.hpp";

Character createAllRandomCharacter(std::string chara){
	if(chara == "PNJ"){
		Character pnj = new PNJ[];

		return pnj;
	}
	else if (chara == "BOSS"){
		Character boss = new Boss[];

		return boss;
	}
	else if (chara == "MONSTER"){
		Character monster = new Monster[];

		return monster;
	}
	else{
		std::cout << "Le nom " << chara << "n'est pas reconnu. Entrez PNJ, BOSS ou MONSTRE" << std::endl;
		exit(1);
	}
}


