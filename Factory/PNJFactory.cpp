#include "PNJFactory.hpp"

PNJFactory::PNJFactory() {}

PNJFactory::~PNJFactory() {}

void PNJFactory::randomSex(Character* chara){
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
}

void PNJFactory::randomSkillPoints(Character* chara){
	int competencePoints = 12;
	int i = 0;
	int stat[6];

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
}

void PNJFactory::ApplySkillPoints(Character* chara){
		chara->setLifePoints(chara->getConstitution() * 3);
	chara->setManaPoint(((chara->getIntelligence() + chara->getWisdom()) / 2) * 3);
	chara->setAttack((chara->getStrength() + chara->getDexterity()) / 2);
	chara->setDefense(chara->getConstitution());
	chara->setCurrentLifePoints(chara->getLifePoints());
	chara->setCurrentManaPoints(chara->getManaPoints());
	std::cout << "Vous avez : " << chara->getLifePoints() << " points de vie." << std::endl;
	std::cout << "Vous avez : " << chara->getManaPoints() << " points de mana." << std::endl;
	std::cout << "Vous avez : " << chara->getAttack() << " points d'attaque." << std::endl;
	std::cout << "Vous avez : " << chara->getDefense() << " points de défense." << std::endl;
}

Character* PNJFactory::createAllRandom(){
	chara = new PNJ();
	
	//Random du sexe
	randomSex(chara);

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
	randomSkillPoints(chara);

	//Random de la classe
	chara->getClasse()->createRandomClass();
	chara->applyModifications();
	std::cout << "Votre classe est " << chara->getClasse()->getClassName() << std::endl;

	//Application des stats à la vie, au mana à l'attaque et à la défense
	ApplySkillPoints(chara);

	//Création fichier texte
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
	return chara;
}

Character* PNJFactory::createPersonalize(){
	chara = new PNJ();
	std::string reponseUtilisateur;
	int rep = -1;
	////////////////////////////////////////////////////////////////
	commandManager->setState(commandManager->getStateCreate());
	////////////////////////////////////////////////////////////////

	// Choix du sexe
	while(rep == -1){
		std::cout << "Voulez-vous choisir le sexe de votre pesonnage ou en avoir un aleatoire? : ";
		std::cin >> reponseUtilisateur;
		rep = commandManager->analyse(reponseUtilisateur);
		std::cout << rep << std::endl;
		if(rep == 0){ // help
			std::cout << "aleatoire : attribue un sexe aléatoire." << std::endl;
			std::cout << "personnaliser : vous laisse le choix du sexe" << std::endl;
			rep = -1;
		}
		else if(rep == 5){ // aleatoire
			randomSex(chara);
		}
		else if(rep == 6){ // personnaliser
			rep = -1;
			while(rep == -1){
			std::cout << "Quel est le sexe du personnage? : " << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);
				if(rep == -1){
					commandManager->throwError();
				}
				else if(rep == 0){
					std::cout << "Homme : le sexe du personage est homme" << std::endl;
					std::cout << "Femme : le sexe du personnage est femme" << std::endl;
					std::cout << std::endl;
					rep = -1;
				}
				else if(rep == 3){
					while(rep == 3){
						std::cout << "Etes-vous sur de vouloir créer un homme? : " << std::endl;
						std::cin >> reponseUtilisateur;
						rep = commandManager->analyse(reponseUtilisateur);
						
						if(rep == 1){
							chara->setSexe("Homme");
							std::cout << "Le personnage est desormais un Homme" << std::endl;
						}
						else if(rep == 2){
							rep = -1;
						}
						else if(rep == 0){
							std::cout << "'Oui' ou 'Non'" << std::endl;
							rep = 3;
						}
						else{
							rep = 3;
						}
					}
				}
				else if(rep == 4){
					while(rep == 4){

						std::cout << "Etes-vous sur de vouloir créer une femme? : " << std::endl;
						std::cin >> reponseUtilisateur;
						rep = commandManager->analyse(reponseUtilisateur);
						if(rep == 1){
							chara->setSexe("Femme");
							std::cout << "Le personnage est desormais une Femme" << std::endl;
						}
						else if(rep == 2){
							rep = -1;
						}
						else if(rep == 0){
							std::cout << "'Oui' ou 'Non'" << std::endl;
							rep = 4;
						}
						else{
							rep = 4;
						}
					}
				}
			}
		}
	}//while

	rep = -1;
	//Choix de la race
	while(rep == -1){
		std::cout << "Voulez-vous choisir la race de votre pesonnage ou en avoir un aleatoire? : ";
		std::cin >> reponseUtilisateur;
		rep = commandManager->analyse(reponseUtilisateur);
		if(rep == 0){ // help
			std::cout << "aleatoire : attribue une race aléatoire." << std::endl;
			std::cout << "personnaliser : vous laisse le choix de la race" << std::endl;
			rep = -1;
		}
		else if(rep == 5){//Aléatoire
			chara->getRace()->createRandomRace();
			chara->applyMinStat();
			std::cout << "Vous êtes un " << chara->getRace()->getFrenchRaceName() << std::endl;
		}
		else if(rep == 6){
			rep = -1;
			while(rep == -1){
				std::cout << "Quel est la race de votre personnage? : " << std::endl;
				std::cin >> reponseUtilisateur;
				rep = commandManager->analyse(reponseUtilisateur);
	
				if(rep == -1){
				}
				else if(rep == 0){
					std::cout << "Voici les races disponibles : " << std::endl;
					std::cout << "Humain : Incipide, possède des stats moyens partout." << std::endl;
					std::cout << "Orc : Fort et resistant mais idiot et déraisoné." << std::endl;
					std::cout << "Elfe : Agile et beaux mais pas très fort ni résistant" << std::endl;
					std::cout << "Nain : Très résistant assez fort mais pas très sages ni beaux" << std::endl;
					rep = -1;
				}
				else if(rep == 7){//Elfe
					while(rep == 7){
						std::cout << "Etes-vous sur de vouloir créer un Elfe?" << std::endl;
						std::cin >> reponseUtilisateur;
						rep = commandManager->analyse(reponseUtilisateur);
						if(rep == 1){
							chara->getRace()->createElf();
							std::cout << "Votre personnage est un Elfe" << std::endl;
							std::cout << rep << std::endl;
						}
						else if(rep == 2){
							rep = -1;
						}
						else if(rep == 0){
							std::cout << "'Oui' ou 'Non'" << std::endl;
							rep = 7;
						}
						else{
							rep = 7;
						}
					}
				}
				else if(rep == 8){//Humain
					while(rep == 8){
						std::cout << "Etes-vous sur de vouloir créer un Humain? (ils sont vraiment"
						<<	" moyen partout aucun interet quoi! Enfin bon je veux pas vous influencer"
						<<	" vous faites comme vous voulez. Même si je dis que c'est un mauvais choix)"
						<< std::endl;
						std::cin >> reponseUtilisateur;
						rep = commandManager->analyse(reponseUtilisateur);
						if(rep == 1){
							chara->getRace()->createHuman();
							std::cout << "Votre personnage est un Humain (tant pis)" << std::endl;
							std::cout << rep << std::endl;
						}
						else if(rep == 2){
							rep = -1;
						}
						else if(rep == 0){
							std::cout << "'Oui' ou 'Non'" << std::endl;
							rep = 8;
						}
						else{
							rep = 8;
						}
					}
				}
				else if(rep == 9){//Orc
					while(rep == 9){
						std::cout << "Etes-vous sur de vouloir créer un Orc?" << std::endl;
						std::cin >> reponseUtilisateur;
						rep = commandManager->analyse(reponseUtilisateur);
						if(rep == 1){
							chara->getRace()->createOrc();
							std::cout << "Votre personnage est un Orc" << std::endl;
							std::cout << rep << std::endl;
						}
						else if(rep == 2){
							rep = -1;
						}
						else if(rep == 0){
							std::cout << "'Oui' ou 'Non'" << std::endl;
							rep = 9;
						}
						else{
							rep = 9;
						}
					}
				}
				else if(rep == 10){//Nain
					while(rep == 10){
						std::cout << "Etes-vous sur de vouloir créer un Nain?" << std::endl;
						std::cin >> reponseUtilisateur;
						rep = commandManager->analyse(reponseUtilisateur);
						if(rep == 1){
							chara->getRace()->createDwarf();
							std::cout << "Votre personnage est un Nain" << std::endl;
							std::cout << rep << std::endl;
						}
						else if(rep == 2){
							rep = -1;
						}
						else if(rep == 0){
							std::cout << "'Oui' ou 'Non'" << std::endl;
							rep = 10;
						}
						else{
							rep = 10;
						}
					}
				}
			}
		}
	}
	return chara;
}

Character* PNJFactory::createCharacterSaved(){
	chara = new PNJ();
	std::cout << "Quel personnage voulez-vous charger?" << std::endl;
	return chara;
}


void PNJFactory::setCharacter(Character* charac){
	chara = charac;
}

Character* PNJFactory::getCharacter(){
	return chara;
}
