/*
 * PNJFactory.cpp
 *
 *  Created on: 9 oct. 2015
 *      Author: E139824H
 */

#include "PNJFactory.hpp"


PNJFactory::PNJFactory() {}

PNJFactory::~PNJFactory() {}

Character* PNJFactory::createAllRandom(){
	chara = new PNJ();
	std::srand(std::time(0));
	int rdmVar = (std::rand() % 2) + 1;

	// Random du sexe
	if(rdmVar == 1){
		chara->setSexe("Male");
		std::cout << "Vous êtes un Homme" << std::endl;
	}
	else{
		chara->setSexe("Female");
		std::cout << "Vous êtes une femme" << std::endl;
	}

	//Random de la race
	chara->getRace()->createRandomRace();
	chara->applyMinStat();
	std::cout << "Vous êtes un " << chara->getRace()->getFrenchRaceName() << std::endl;

	//Random du prénom
	chara->setRandomName();
	std::cout << "Votre prénom est " << chara->getName() << std::endl;

	//Random du nom de famille
	chara->setRandomLastName();
	std::cout << "Votre Nom de Famille est " << chara->getLastName() << std::endl;

	//Random des attributions des points de compétences
	int competencePoints = 12;
	int i = 0;
	int stat[6];
	//Boucle infinie à corriger
	while(competencePoints != 0){
		std::srand(std::time(0));
		int rdmVar = (std::rand() % 2);

		stat[i] = rdmVar;
		if(i < 6){
			++i;
		}
		else{
			i = 0;
		}
		competencePoints -= rdmVar;
	}
	chara->setStrength(chara->getStrength()+stat[0]);
	chara->setConstitution(chara->getConstitution()+stat[1]);
	chara->setDexterity(chara->getDexterity()+stat[2]);
	chara->setIntelligence(chara->getIntelligence()+stat[3]);
	chara->setWisdom(chara->getWisdom()+stat[4]);
	chara->setCharisma(chara->getCharisma()+stat[5]);

	//Random de la classe
	chara->getClasse()->createRandomClass();
	chara->applyModifications();
	std::cout << "Votre classe est " << chara->getClasse()->getClassName() << std::endl;

	//Application des stats à la vie, au mana à l'attaque et à la défense
	chara->setLifePoints(chara->getConstitution() * 3);
	chara->setManaPoint(((chara->getIntelligence() + chara->getWisdom()) / 2) * 3);
	chara->setAttack((chara->getStrength() + chara->getDexterity()) / 2);
	chara->setDefense(chara->getConstitution());
	chara->setCurrentLifePoints(chara->getLifePoints());
	chara->setCurrentManaPoints(chara->getManaPoints());
	//Création fichier texte
	int num = getNum();
	std::string n = std::to_string(num);
	std::string mySave = "../Saves/" + chara->getName() + chara->getRace()->getRaceName() + chara->getClasse()->getClassName() + ".txt";
	std::ofstream save(mySave.c_str(), std::ios::out | std::ios::trunc);

	if(save){
		save << "Prenom: " << chara->getName() << "	Nom : " << chara->getLastName() << std::endl;
		save << "Sexe : " << chara->getSexe() << "	Race : " << chara->getRace()->getRaceName() << std::endl;
		save << "Classe : " << chara->getClasse()->getClassName() << std::endl;
		save << std::endl;
		save << "Points de vie :  " << chara->getCurrentLifePoints() << " / " << chara->getLifePoints() << std::endl;
		save << "Points de mana : " << chara->getCurrentManaPoints() << " / " << chara->getManaPoints() << std::endl;
		save << std::endl;
		save << "Force : 		" << chara->getStrength() << std::endl;
		save << "Constitution : " << chara->getConstitution() << std::endl;
		save << "Dexterite : 	" << chara->getDexterity() << std::endl;
		save << "Intelligence : " << chara->getIntelligence() << std::endl;
		save << "Sagesse : 		" << chara->getWisdom() << std::endl;
		save << "Charisme :		" << chara->getCharisma() << std::endl;
	}
	setNum(getNum()+1);
	return chara;
}

Character* PNJFactory::createPersonalize(){
	chara = new PNJ();
	std::cout << "Quel personnage voulez-vous charger?" << std::endl;
	return chara;
}

Character* PNJFactory::createCharacterSaved(){
	chara = new PNJ();

	return chara;
}


void PNJFactory::setCharacter(Character* charac){
	chara = charac;
}
Character* PNJFactory::getCharacter(){
	return chara;
}
