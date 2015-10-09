/*
 * PNJFactory.cpp
 *
 *  Created on: 9 oct. 2015
 *      Author: E139824H
 */

#include "PNJFactory.hpp"

PNJFactory::PNJFactory() {
	// TODO Auto-generated constructor stub

}

PNJFactory::~PNJFactory() {
	// TODO Auto-generated destructor stub
}

Character PNJFactory::createAllRandom(){
	Character chara = new PNJ<>;
	std::srand(std::time(0));
	int rdmVar = (std::rand() % 2) + 1;
	if(rdmVar == 1){
		chara.setSexe("Male");
		std::cout << "Vous êtes un Homme" << std::endl;
	}
	else{
		chara.setSexe("Female");
		std::cout << "Vous êtes une femme" << std::endl;
	}

	chara.getRace().createRandomRace();
	// create getRace in Character
	std::cout << "Vous êtes un " << chara.getRace().getRace() << std::endl;

	chara.setRandomName();
	std::cout << "Votre prénom est " << chara.getName() << std::endl;
	chara.setRandomLastName();
	std::cout << "Votre Nom de Famille est " << chara.getLastName() << std::endl;



}
