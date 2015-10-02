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

		std::srand(std::time(0));
		const int taille = 2; // Taille des fichiers de nom
		int random_variable = (std::rand() % taille);
		if(random_variable == 0){
			pnj.race.setRandomHumanNames();
		}
		else if(random_variable == 1){

		}
		else{

		}

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


