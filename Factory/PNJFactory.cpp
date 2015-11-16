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

	//Random d'attributions des points de compétences
	randomSkillPoints(chara);

	//Random de la classe
	chara->getClasse()->createRandomClass();
	chara->applyModifications();
	std::cout << "Votre classe est " << chara->getClasse()->getClassName() << std::endl;

	//Application des stats à la vie, au mana à l'attaque et à la défense
	ApplySkillPoints(chara);

	//Création fichier texte
	std::string mySave = "Saves/PNJ/" + chara->getName() + chara->getRace()->getRaceName() + chara->getClasse()->getClassName() + ".txt";
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

Character* PNJFactory::createPersonnalize(){
	chara = new PNJ();
	std::string reponseUtilisateur;
	int rep = -1;

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
		else{
			std::cout << "Commande invalide!" << std::endl;
			rep = -1;
		}
	}//while

	rep = -1;
	//Choix de la race
	while(rep == -1){
		std::cout << "Voulez-vous choisir la race de votre pesonnage ou en avoir un aleatoire? : ";
		std::cin >> reponseUtilisateur;
		rep = commandManager->analyse(reponseUtilisateur);
		std::cout << rep << std::endl;
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
		else{
			std::cout << "Commande invalide!" << std::endl;
			rep = -1;
		}
	}
	rep = -1;
	//Choix du prénom
	while(rep == -1){
		std::cout << "Voulez-vous choisir votre prénom ou en obtenir un aléatoire? : " << std::endl;
		std::cin >> reponseUtilisateur;
		rep = commandManager->analyse(reponseUtilisateur);
		if(rep == 5){//Aleatoire
			chara->setRandomName();
			std::cout << "Votre prénom est " << chara->getName() << std::endl;
		}
		else if(rep == 6){//Personnaliser
			std::cout << "Entrez votre prenom : " << std::endl;
			std::cin >> reponseUtilisateur;
			chara->setName(reponseUtilisateur);
		}
		else if(rep == 0){
			std::cout << "Aleatoire : attribue un nom aléatoire" << std::endl;
			std::cout << "personnaliser : vous laisse entrer le prenom de votre personnage" << std::endl;
			rep = -1;
		}
		else{
			std::cout << "Commande invalide!" << std::endl;
			rep = -1;
		}
	}
	rep = -1;
	//Choix du nom de famille
	while(rep == -1){
		std::cout << "Voulez-vous choisir votre nom de famille ou en obtenir un aléatoire? : " << std::endl;
		std::cin >> reponseUtilisateur;
		rep = commandManager->analyse(reponseUtilisateur);
		if(rep == 5){
			chara->setRandomLastName();
			std::cout << "Votre nomde famille est : " << chara->getLastName() << std::endl;
		}
		else if(rep == 6){
			std::cout << "Entrez votre nom de famille : " << std::endl;
			std::cin >> reponseUtilisateur;
			chara->setLastName(reponseUtilisateur);
		}
		else if(rep == 0){
			std::cout << "Aleatoire : attribue un nom de famille aléatoire" << std::endl;
			std::cout << "personnaliser : vous laisse entrer le nom de famille de votre personnage" << std::endl;
			rep = -1;
		}
		else{
			std::cout << "Commande invalide!" << std::endl;
			rep = -1;
		}
	}
	rep = -1;

	//Attribution des points de compétences
	int pts = 12;
	std::cout << "Attribution des points de compétences : " << std::endl;
	std::cout << "Vous disposez de 12 points à répartir dans 6 stats" << std::endl;
	std::cout << "Vous êtes un : " << chara->getRace()->getFrenchRaceName() << std::endl;
	while(rep == -1){

		//Attribution Force
			rep = 0;
		while(rep == 0){
			std:: cout << "Vous possedez de base de " << chara->getRace()->getRangeStrengthMin() << " points en Force" << std::endl;
			std::cout << "Vous pouvez monter au maximum jusqu'a " << chara->getRace()->getRangeStrengthMax() << " points" << std::endl;
			std::cout << "Combien de points voulez-vous y attribuer? : " << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);
			if(rep == 17){ //Un nombre à été entré
				int ru  = std::stoi(reponseUtilisateur);
				if(ru <= 4){
					chara->setStrength(chara->getStrength()+ru);
					pts -= ru;
					std::cout << "Il vous reste " << pts << " points à répartir." << std::endl;
					rep = 1;
				}
				else if(ru > 4){
					std::cout << "Impossible de répartir plus de 4 points dans une compétence." << std::endl;
					rep = 0;
				}
			}
			else if(rep == -1){
				std::cout << "Veuillez entrer un nombre svp." << std::endl;
				rep = 0;
			}
			else{
				std::cout << "Erreur entrez un chiffre entre 0 et 4." << std::endl;
				rep = 0;
			}
		}
		rep = 0;
		//Attribution Constitution
		while(rep == 0){
			std:: cout << "Vous possedez de base de " << chara->getRace()->getRangeConstitutionMin() << " points en Constitution" << std::endl;
			std::cout << "Vous pouvez monter au maximum jusqu'a " << chara->getRace()->getRangeConstitutionMax() << " points" << std::endl;
			std::cout << "Combien de points voulez-vous y attribuer? : " << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);
			if(rep == 17){ //Un nombre à été entré
				int ru  = std::stoi(reponseUtilisateur);
				if(ru <= 4){
					chara->setConstitution(chara->getConstitution()+ru);
					pts -= ru;
					std::cout << "Il vous reste " << pts << " points à répartir." << std::endl;
					rep = 1;
				}
				else if(ru > 4){
					std::cout << "Impossible de répartir plus de 4 points dans une compétence." << std::endl;
					rep = 0;
				}
			}
			else if(rep == -1){
				std::cout << "Veuillez entrer un nombre svp." << std::endl;
				rep = 0;
			}
			else{
				std::cout << "Erreur entrez un chiffre entre 0 et 4." << std::endl;
				rep = 0;
			}
		}
		rep = 0;
		//Attribution Dexterité
		while(rep == 0){
			std:: cout << "Vous possedez de base de " << chara->getRace()->getRangeDexterityMin() << " points en Dexterite" << std::endl;
			std::cout << "Vous pouvez monter au maximum jusqu'a " << chara->getRace()->getRangeDexterityMax() << " points" << std::endl;
			std::cout << "Combien de points voulez-vous y attribuer? : " << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);
			if(rep == 17){ //Un nombre à été entré
				int ru  = std::stoi(reponseUtilisateur);
				if(rep == 17 && ru <= 4){
					chara->setDexterity(chara->getDexterity()+ru);
					pts -= ru;
					std::cout << "Il vous reste " << pts << " points à répartir." << std::endl;
					rep = 1;
				}
				else if(rep == 17 && ru > 4){
					std::cout << "Impossible de répartir plus de 4 points dans une compétence." << std::endl;
					rep = 0;
				}
			}
			else if(rep == -1){
				std::cout << "Veuillez entrer un nombre svp." << std::endl;
				rep = 0;
			}
			else{
				std::cout << "Erreur entrez un chiffre entre 0 et 4." << std::endl;
				rep = 0;
			}
		}
		rep = 0;
		//Attribution Intelligence
		while(rep == 0){
			if(pts == 0){
				rep = 1;
			}
			else{
				std:: cout << "Vous possedez de base de " << chara->getRace()->getRangeIntelligenceMin() << " points en Intelligence" << std::endl;
				std::cout << "Vous pouvez monter au maximum jusqu'a " << chara->getRace()->getRangeIntelligenceMax() << " points" << std::endl;
				std::cout << "Combien de points voulez-vous y attribuer? : " << std::endl;
				std::cin >> reponseUtilisateur;
				rep = commandManager->analyse(reponseUtilisateur);
				if(rep == 17){ //Un nombre à été entré
					int ru  = std::stoi(reponseUtilisateur);
					if(ru <= 4 && ru <= pts){
						chara->setIntelligence(chara->getIntelligence()+ru);
						pts -= ru;
						std::cout << "Il vous reste " << pts << " points à répartir." << std::endl;
						rep = 1;
					}
					else if(ru > 4){
						std::cout << "Impossible de répartir plus de 4 points dans une compétence." << std::endl;
						rep = 0;
					}
					else if(ru > pts){
						std::cout << "Vous ne disposez plus que de " << pts << " points a repartir." << std::endl;
						rep = 0;
					}
				}
				else if(rep == -1){
					std::cout << "Veuillez entrer un nombre svp." << std::endl;
					rep = 0;
				}
				else{
					std::cout << "Erreur entrez un chiffre entre 0 et 4." << std::endl;
					rep = 0;
				}
			}
		}
		rep = 0;
		//Attribution Sagesse
		while(rep == 0){
			if(pts == 0){
				rep = 1;
			}
			else{
				std:: cout << "Vous possedez de base de " << chara->getRace()->getRangeWisdomMin() << " points en Sagesse" << std::endl;
				std::cout << "Vous pouvez monter au maximum jusqu'a " << chara->getRace()->getRangeWisdomMax() << " points" << std::endl;
				std::cout << "Combien de points voulez-vous y attribuer? : " << std::endl;
				std::cin >> reponseUtilisateur;
				rep = commandManager->analyse(reponseUtilisateur);
				if(rep == 17){ //Un nombre à été entré
					int ru  = std::stoi(reponseUtilisateur);
					if(rep == 17 && ru <= 4 && ru <= pts){
						chara->setWisdom(chara->getWisdom()+ru);
						pts -= ru;
						std::cout << "Il vous reste " << pts << " points à répartir." << std::endl;
						rep = 1;
					}
					else if(rep == 17 && ru > 4){
						std::cout << "Impossible de répartir plus de 4 points dans une compétence." << std::endl;
						rep = 0;
					}
					else if(ru > pts){
						std::cout << "Vous ne disposez plus que de " << pts << " points a repartir." << std::endl;
						rep = 0;
					}
				}
				else if(rep == -1){
					std::cout << "Veuillez entrer un nombre svp." << std::endl;
					rep = 0;
				}
				else{
					std::cout << "Erreur entrez un chiffre entre 0 et 4." << std::endl;
					rep = 0;
				}
			}
		}
		rep = 0;
		//Attribution Charisme
		while(rep == 0){
			if(pts == 0){
				rep = 1;
			}
			else{
				std:: cout << "Vous possedez de base de " << chara->getRace()->getRangeCharismaMin() << " points en Charisme" << std::endl;
				std::cout << "Vous pouvez monter au maximum jusqu'a " << chara->getRace()->getRangeCharismaMax() << " points" << std::endl;
				std::cout << "Combien de points voulez-vous y attribuer? : " << std::endl;
				std::cin >> reponseUtilisateur;
				rep = commandManager->analyse(reponseUtilisateur);
				if(rep == 17){ //Un nombre à été entré
					 int ru  = std::stoi(reponseUtilisateur);
					if(ru <= 4 && ru <= pts){
						chara->setCharisma(chara->getCharisma()+ru);
						pts -= ru;
						std::cout << "Il vous reste " << pts << " points à répartir." << std::endl;
						rep = 1;
					}
					else if(ru > 4){
						std::cout << "Impossible de répartir plus de 4 points dans une compétence." << std::endl;
						rep = 0;
					}
					else if(ru > pts){
						std::cout << "Vous ne disposez plus que de " << pts << " points a repartir." << std::endl;
						rep = 0;
					}
				}
				else if(rep == -1){
					std::cout << "Veuillez entrer un nombre svp." << std::endl;
					rep = 0;
				}
				else{
					std::cout << "Erreur entrez un chiffre entre 0 et 4." << std::endl;
					rep = 0;
				}
			}
		}
		if(pts > 0){
			rep = -1;
		}
	}
	rep = -1;
	//Attribution Classe
	while(rep == -1){
		std::cout << "Voulez-vous choisir la classe de votre pesonnage ou en avoir un aleatoire? : ";
		std::cin >> reponseUtilisateur;
		rep = commandManager->analyse(reponseUtilisateur);
		if(rep == 0){ // help
			std::cout << "aleatoire : attribue une classe aléatoire." << std::endl;
			std::cout << "personnaliser : vous laisse le choix de la classe" << std::endl;
			rep = -1;
		}
		else if(rep == 5){//Aléatoire
			chara->getClasse()->createRandomClass();
			chara->applyModifications();
			std::cout << "Vous êtes un " << chara->getClasse()->getClassName() << std::endl;
		}
		else if(rep == 6){//Personnalisé
			while(rep == 6){
				std::cout << "Quelle est la classe de votre personnage? : " << std::endl;
				std::cin >> reponseUtilisateur;
				rep = commandManager->analyse(reponseUtilisateur);
				if(rep == 0){//Help
					std::cout << "Voici la liste des classes : " << std::endl;
					std::cout << "Guerrier : Fort et resistant" << std::endl;
					std::cout << "Mage : Lanceur de sort Intelligent" << std::endl;
					std::cout << "Pretre : Soigne grace à la magie, très Sage" << std::endl;
					std::cout << "Ranger : Agile et connait la nature" << std::endl;
					std::cout << "Roublard : Voleur Agile et sournois" << std::endl;
					rep = 6;
				}
				else if(rep == 11){
					std::cout << "Etes-vous sur de vouloir un guerrier? : " << std::endl;
					std::cin >> reponseUtilisateur;
					rep = commandManager->analyse(reponseUtilisateur);
					if(rep == 1){
						chara->getClasse()->createWarrior();
					}
					else{
						rep = 6;
					}
				}
				else if(rep == 12){
					std::cout << "Etes-vous sur de vouloir un mage? : " << std::endl;
					std::cin >> reponseUtilisateur;
					rep = commandManager->analyse(reponseUtilisateur);
					if(rep == 1){
						chara->getClasse()->createMage();
					}
					else{
						rep = 6;
					}
				}
				else if(rep == 13){
					std::cout << "Etes-vous sur de vouloir un pretre? : " << std::endl;
					std::cin >> reponseUtilisateur;
					rep = commandManager->analyse(reponseUtilisateur);
					if(rep == 1){
						chara->getClasse()->createPriest();
					}
					else{
						rep = 6;
					}
				}
				else if(rep == 14){
					std::cout << "Etes-vous sur de vouloir un paladin? : " << std::endl;
					std::cin >> reponseUtilisateur;
					rep = commandManager->analyse(reponseUtilisateur);
					if(rep == 1){
						chara->getClasse()->createPaladin();
					}
					else{
						rep = 0;
					}
				}
				else if(rep == 15){
					std::cout << "Etes-vous sur de vouloir un ranger? : " << std::endl;
					std::cin >> reponseUtilisateur;
					rep = commandManager->analyse(reponseUtilisateur);
					if(rep == 1){
						chara->getClasse()->createHunter();
					}
					else{
						rep = 0;
					}
				}
				else if(rep == 16){
					std::cout << "Etes-vous sur de vouloir un Roublard? : " << std::endl;
					std::cin >> reponseUtilisateur;
					rep = commandManager->analyse(reponseUtilisateur);
					if(rep == 1){
						chara->getClasse()->createThief();
					}
					else{
						rep = 0;
					}
				}
				else{
				std::cout << "Commande invalide!" << std::endl;
				rep = -1;
				}	
			}
		}
	}
	ApplySkillPoints(chara);

	//creation fichier save
	std::string mySave = "Saves/PNJ/" + chara->getName() + chara->getRace()->getRaceName() + chara->getClasse()->getClassName() + ".txt";
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







Character* PNJFactory::createCharacterSaved(){

	////////////////////////////////////////////////////////////////
	commandManager->setState(commandManager->getStateCreate());
	////////////////////////////////////////////////////////////////

	chara = new PNJ();
	std::string reponseUtilisateur;
	std::string fileName;
	std::cout << "Quel personnage voulez-vous charger?" << std::endl;
	DIR* rep = NULL;
	struct dirent* fichierLu = NULL;
	rep = opendir("Saves/PNJ/");

	if(rep == NULL){
		std::cout << "Erreur repertoire inaccessible." << std::endl;
		exit(1);
	}
	int i = 1;
	int j = 1;
	std::cout << "Liste des sauvegardes : " << std::endl;
	while((fichierLu = readdir(rep)) != NULL){
		if(i > 2){
			std::cout << j << " : " << fichierLu->d_name << std::endl;
			++j;
		}
		++i;
	}
	i = 1;
	j = 1;
	rep = opendir("Saves/PNJ/");
	std::cin >> reponseUtilisateur;
	while((fichierLu = readdir(rep)) != NULL){ 
		if(i > 2){
			if(j == std::stoi(reponseUtilisateur)){
				fileName = std::string(fichierLu->d_name);
			}
			++j;
		}
		++i;
	}
	std::string cast = "Saves/PNJ/" + fileName;
	char* raceFile = (char*)cast.c_str();
	std::ifstream file(raceFile, std::ios::in);
	std::string chaine;
	if(file){
		//Recupération du prénom et du nom de famille
		file >> chaine;
		file >> chaine;
		chara->setName(chaine);
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->setLastName(chaine);
		//Récupération du sexe et de la race
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->setSexe(chaine);
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->getRace()->setRaceName(chaine);
		if(chaine == "Human"){
			chara->getRace()->setFrenchRaceName("Humain");
		}
		if(chaine == "Elf"){
			chara->getRace()->setFrenchRaceName("Elfe");
		}
		if(chaine == "Orc"){
			chara->getRace()->setFrenchRaceName("Orc");
		}
		if(chaine == "Dwarf"){
			chara->getRace()->setFrenchRaceName("Nain");
		}
		//Récupération de la classe de la vie et du mana
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->getClasse()->setClassName(chaine);
		file >> chaine;
		file >> chaine;
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->setCurrentLifePoints(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		chara->setLifePoints(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->setCurrentManaPoints(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		chara->setManaPoint(std::stoi(chaine));
		//Récupération des stats 
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->setStrength(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->setConstitution(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->setDexterity(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->setIntelligence(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->setWisdom(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		file >> chaine;
		chara->setCharisma(std::stoi(chaine));
	}
	else{
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
	}


	return chara;
}

Character* PNJFactory::createCharacter(){

	////////////////////////////////////////////////////////////////
	commandManager->setState(commandManager->getStateCreate());
	////////////////////////////////////////////////////////////////

	std::string reponseUtilisateur;
	int rep = -1;
	while(rep == -1){
		std::cout << "Voulez-vous créer un personnage personnalisé ou un personnage aléatoire? : " << std::endl;
		std::cin >> reponseUtilisateur;
		rep = commandManager->analyse(reponseUtilisateur);
		std::cout << rep << std::endl;
		if(rep == 5){// aléatoire
			return createAllRandom();
		}
		else if(rep == 6){
			return createPersonnalize();
		}
		else if(rep == 0){
			std::cout << "aleatoire : attribue un personnage aléatoire." << std::endl;
			std::cout << "personnaliser : vous laisse la création du personnage." << std::endl;
			rep = -1;
		}
		else{
			std::cout << "Commande invalide!" << std::endl;
			rep = -1;
		}
	}
	return createAllRandom();
}

void PNJFactory::setCharacter(Character* charac){
	chara = charac;
}

Character* PNJFactory::getCharacter(){
	return chara;
}
