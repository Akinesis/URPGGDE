/*
 * PNJFactory.cpp
 *
 *  Created on: 9 oct. 2015
 *      Author: E139824H
 */

#include "PNJFactory.hpp"


PNJFactory::PNJFactory() {}
/*
PNJFactory::PNJFactory(Character ch){
	Factory(ch);
}
*/
PNJFactory::~PNJFactory() {}

void PNJFactory::createAllRandom(Character chara){
	chara = new PNJ<>;
	std::srand(std::time(0));
	int rdmVar = (std::rand() % 2) + 1;

	// Random du sexe
	if(rdmVar == 1){
		chara.setSexe("Male");
		std::cout << "Vous êtes un Homme" << std::endl;
	}
	else{
		chara.setSexe("Female");
		std::cout << "Vous êtes une femme" << std::endl;
	}

	//Random de la race
	chara.getRace().createRandomRace(chara);
	chara.applyMinStat();
	std::cout << "Vous êtes un " << chara.getRace().getRaceName() << std::endl;

	//Random du prénom
	chara.setRandomName();
	std::cout << "Votre prénom est " << chara.getName() << std::endl;

	//Random du nom de famille
	chara.setRandomLastName();
	std::cout << "Votre Nom de Famille est " << chara.getLastName() << std::endl;

	//Random des attributions des points de compétences
	int competencePoints = 12;

	int i = 0;
	int stat[6];

	while(competencePoints != 0){
		std::srand(std::time(0));
		int rdmVar = (std::rand() % competencePoints);

		stat[i] = rdmVar;
		++i;
		competencePoints -= rdmVar;
	}

	chara.setStrength(chara.getStrength()+stat[0]);
	chara.setConstitution(chara.getConstitution()+stat[1]);
	chara.setDexterity(chara.getDexterity()+stat[2]);
	chara.setIntelligence(chara.getIntelligence()+stat[3]);
	chara.setWisdom(chara.getWisdom()+stat[4]);
	chara.setCharisma(chara.getCharisma()+stat[5]);

	//Random de la classe
	chara.getClasse().createRandomClass(chara);
	std::cout << "Votre classe est" << chara.getClasse().getClassName() << std::endl;

	//Application des stats à la vie, au mana à l'attaque et à la défense
	chara.setCurrentLifePoints(chara.getLifePoints());
	chara.setCurrentManaPoints(chara.getManaPoints());
	chara.setLifePoints(chara.getConstitution() * 3);
	chara.setManaPoint(((chara.getIntelligence() + chara.getWisdom()) / 2) * 3);
	chara.setAttack((chara.getStrength() + chara.getDexterity()) / 2);
	chara.setDefense(chara.getConstitution());

	//Création fichier texte
	std::string mySave = "../Saves/save"+num+"txt";
	std::ofstream save(mySave.c_str(), std::ios::out | std::ios::trunc);

	if(save){
		save << "Prenom: " << chara.getName() << "	Nom : " << chara.getLastName() << std::endl;
		save << "Sexe : " << chara.getSexe() << "	Race : " << chara.getRace().getRaceName() << std::endl;
		save << "Classe : " << chara.getClasse().getClassName() << std::endl;
		save << std::endl;
		save << "Points de vie :  " << chara.getCurrentLifePoints() << " / " << chara.getLifePoints() << std::endl;
		save << "Points de mana : " << chara.getCurrentManaPoints() << " / " << chara.getManaPoints() << std::endl;
		save << std::endl;
		save << "Force : 		" << chara.getStrength() << std::endl;
		save << "Constitution : " << chara.getConstitution() << std::endl;
		save << "Dexterite : 	" << chara.getDexterity() << std::endl;
		save << "Intelligence : " << chara.getIntelligence() << std::endl;
		save << "Sagesse : 		" << chara.getWisdom() << std::endl;
		save << "Charisme :		" << chara.getCharisma() << std::endl;
	}
}

void PNJFactory::setCharacter(Character charac){
	chara = charac;
}
int PNJFactory::getCharacter(){
	return chara;
}
