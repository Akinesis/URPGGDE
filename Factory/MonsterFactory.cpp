#include "MonsterFactory.hpp"

MonsterFactory::MonsterFactory() {}

MonsterFactory::~MonsterFactory() {}

void MonsterFactory::createAllRandom(Character* chara){	
	const int nbCategory = 3;
	const int passToH = 9;
	const int tailleH = 4;
	const int tailleB = 5;
	const int tailleF = 5;
	std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
		
	std::srand(std::time(0));
	int rdmCategory = (std::rand() % nbCategory) + 1;

	if(rdmCategory == 1){
		if(bestiaryFile){
			std::string chaine;
			for(int i = 0; i < passToH; ++i){
				bestiaryFile >> chaine;
			}//for

			std::srand(std::time(0));
			int rdmMonster = (std::rand() % tailleH);
			for(int i = 0; i < rdmMonster; ++i){
				for(int j = 0; j < 7; ++i){
					bestiaryFile >> chaine;
				}//for
			}//for
			
			//Attribution NOM
			chara->setName(chaine);
			//Attribution VIE
			bestiaryFile >> chaine;
			chara->setLifePoints(std::stoi(chaine));
			chara->setCurrentLifePoints(std::stoi(chaine));
			//Attribution ATT
			bestiaryFile >> chaine;
			chara->setAttack(std::stoi(chaine));
			//Attribution PRD
			bestiaryFile >> chaine;
			chara->setDefense(std::stoi(chaine));
			//Attribution PR
			bestiaryFile >> chaine;
			chara->setProtection(std::stoi(chaine));
			//Attribution DMGD
			bestiaryFile >> chaine;
			chara->setDommagesDe(std::stoi(chaine));
			//Attribution DMGA
			bestiaryFile >> chaine;
			chara->setDommagesAdditionnels(std::stoi(chaine));
		}//if
		else{
			std::cout << "Impossible d'acceder au fichier" << std::endl;
		}
	}//if
	else if(rdmCategory == 2){
		if(bestiaryFile){

			std::string chaine;
			for(int i = 0; i < (passToH); ++i){
				bestiaryFile >> chaine;
			}
			for(int i = 0; i < tailleH; ++i){
				for(int j = 0; j < 7; ++j){
					bestiaryFile >> chaine;
				}
			}
			bestiaryFile >> chaine;

			std::srand(std::time(0));
			int rdmMonster = (std::rand() % tailleB);
			for(int i = 0; i < rdmMonster; ++i){
				for(int j = 0; j < 7; ++j){
					bestiaryFile >> chaine;
				}
			}//for
			//Attribution NOM
			chara->setName(chaine);
			//Attribution VIE
			bestiaryFile >> chaine;
			chara->setLifePoints(std::stoi(chaine));
			chara->setCurrentLifePoints(std::stoi(chaine));
			//Attribution ATT
			bestiaryFile >> chaine;
			chara->setAttack(std::stoi(chaine));
			//Attribution PRD
			bestiaryFile >> chaine;
			chara->setDefense(std::stoi(chaine));
			//Attribution PR
			bestiaryFile >> chaine;
			chara->setProtection(std::stoi(chaine));
			//Attribution DMGD
			bestiaryFile >> chaine;
			chara->setDommagesDe(std::stoi(chaine));
			//Attribution DMGA
			bestiaryFile >> chaine;
			chara->setDommagesAdditionnels(std::stoi(chaine));
		}//if
		else{
			std::cout << "Impossible d'acceder au fichier" << std::endl;
		}
	}//else if
	else{
		if(bestiaryFile){
			std::string chaine;

			for(int i = 0; i < (passToH); ++i){
				bestiaryFile >> chaine;
			}//for

			for(int i = 0; i < tailleH; ++i){
				for(int j = 0; j < 7; ++j){
					bestiaryFile >> chaine;
				}
			}
			bestiaryFile >> chaine;

			for(int i = 0; i < tailleB; ++i){
				for(int j = 0; j < 7; ++j){
					bestiaryFile >> chaine;
				}
			}
			bestiaryFile >> chaine;

			std::srand(std::time(0));
			int rdmMonster = (std::rand() % tailleF);
			for(int i = 0; i < rdmMonster; ++i){
				for(int j = 0; j < 7; ++j){
					bestiaryFile >> chaine;
				}
			}//for
			//Attribution NOM
			chara->setName(chaine);
			//Attribution VIE
			bestiaryFile >> chaine;
			chara->setLifePoints(std::stoi(chaine));
			chara->setCurrentLifePoints(std::stoi(chaine));
			//Attribution ATT
			bestiaryFile >> chaine;
			chara->setAttack(std::stoi(chaine));
			//Attribution PRD
			bestiaryFile >> chaine;
			chara->setDefense(std::stoi(chaine));
			//Attribution PR
			bestiaryFile >> chaine;
			chara->setProtection(std::stoi(chaine));
			//Attribution DMGD
			bestiaryFile >> chaine;
			chara->setDommagesDe(std::stoi(chaine));
			//Attribution DMGApiou
			bestiaryFile >> chaine;
			chara->setDommagesAdditionnels(std::stoi(chaine));
		}//if
		else{
			std::cout << "Impossible d'acceder au fichier" << std::endl;
		}
	}//else
}


void MonsterFactory::createPersonnalize(Character* chara){

	std::string reponseUtilisateur;
	int rep = -1;

	while(rep == -1){
		std::cout << "Voulez-vous : " << std::endl;
		std::cout << "1 : créer un monstre à partir du bestiaire." << std::endl;
		std::cout << "2 : créer un monstre entierement personnalisé." << std::endl;
		std::cin >> reponseUtilisateur;
		if(reponseUtilisateur == "1"){
			std::cout << "Etes-vous sur de vouloir sélectionner un monstre du bestiaire? : " << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);
			if(rep == 1){
				createBestiaryMonster(chara);
			}
			else if(rep == 2){
				rep = -1;
			}
			else if(rep == 0){
				std::cout << "Oui : vous fait sélectionner un monstre du bestiaire." << std::endl;
				std::cout << "Non : vous fait revenir à la selection." << std::endl;
				rep = -1;
			}
			else{
				std::cout << "Commande invalide!" << std::endl;
				rep = -1;
			}
		}
		else if(reponseUtilisateur == "2"){
			std::cout << "Etes-vous sur de vouloir créer un monstre entièrement personnalisé? : " << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);
			if(rep == 1){
				createPersonnalizeMonster(chara);
			}
			else if(rep == 2){
				rep = -1;
			}
			else if(rep == 0){
				std::cout << "Oui : lance la création de monstre." << std::endl;
				std::cout << "Non : vous fait revenir à la selection." << std::endl;
				rep = -1;
			}
			else{
				std::cout << "Commande invalide!" << std::endl;
				rep = -1;
			}
		}
	}
}

Character* MonsterFactory::createCharacterSaved(){
	chara = new Monster();

	std::string reponseUtilisateur;
	std::string fileName;
	std::cout << "Quel personnage voulez-vous charger?" << std::endl;
	DIR* rep = NULL;
	struct dirent* fichierLu = NULL;
	rep = opendir("Saves/Monster/");

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
	rep = opendir("Saves/Monster/");
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
		//Récupération du nom
		file >> chaine;
		file >> chaine;
		chara->setName(chaine);
		file >> chaine;
		file >> chaine;
		chara->setCurrentLifePoints(std::stoi(chaine));
		file >> chaine;
		chara->setLifePoints(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		chara->setAttack(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		chara->setDefense(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		chara->setProtection(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		chara->setDommagesDe(std::stoi(chaine));
		file >> chaine;
		file >> chaine;
		chara->setDommagesAdditionnels(std::stoi(chaine));
	}

	return chara;
}

Character* MonsterFactory::createCharacter(){

	////////////////////////////////////////////////////////////////
	commandManager->setState(commandManager->getStateCreate());
	////////////////////////////////////////////////////////////////
	chara = new Monster();
	config = new Config();
	std::string reponseUtilisateur;
	int rep = -1;

	while(rep == -1){	
		std::cout << "Voulez-vous un monstre créer aléatoirement ou un monstre personnalisé?" << std::endl;
		std::cin >> reponseUtilisateur;
		rep = commandManager->analyse(reponseUtilisateur);

		if(rep == 0){
			std::cout << "Aléatoire : choisis un monstre aléatoirement dans le bestaire." << std::endl;
			std::cout << "Personnaliser : vous fait choisir un monstre du bestiaire ou vous en fait créer un vous même." << std::endl;
			rep = -1;
		}
		else if(rep == 5){
			createAllRandom(chara);
		}
		else if(rep == 6){
			createPersonnalize(chara);
		}
		else if(rep == -1){}
		else{
			std::cout << "Commande invalide!" << std::endl;
			rep = -1;
		}
	}
	std::cout << "Nom Dans CreateCharacter " << chara->getName() << std::endl;
	save(chara, "Saves/Monster/", false);
	return chara;
}

void MonsterFactory::createPersonnalizeMonster(Character* chara){
	std::string reponseUtilisateur;
	std::string memoireReponseUtilisateur;
	int rep = -1;
	//Choix du nom
	while(rep == -1){	
		std::cout << "Quel est le nom de votre monstre" << std::endl;
		std::cin >> memoireReponseUtilisateur;
		std::cout << "Etes-vous sur de vouloir appeller votre monstre : " << memoireReponseUtilisateur << std::endl;
		std::cin >> reponseUtilisateur;
		rep = commandManager->analyse(reponseUtilisateur);

		if(rep == 1){
			std::cout << "Votre monstre se nomme désormais : " << memoireReponseUtilisateur << std::endl;
			chara->setName(memoireReponseUtilisateur);
		}
		else if(rep == 2){
			rep = -1;
		}
		else if(rep == 0){
			std::cout << "Oui : accepiouter." << std::endl;
			std::cout << "Non : refuser." << std::endl;
			rep = -1;
		}
		else if(rep == -1){}
		else{
			std::cout << "Commande invalide!" << std::endl;
			rep = -1;
		}
	}
	rep = -1;
	//Attribution des points de vie.
	while(rep == -1){
		std::cout << "Combien de points de vie a votre monstre" << std::endl;
		std::cin >> memoireReponseUtilisateur;

		if(commandManager->is_number(memoireReponseUtilisateur) == true){
			rep = 0;
		}
		else{
			std::cout << "Veuillez entrer un nombre." << std::endl;
			rep = -1;
		}

		while(rep == 0){
			std::cout << "Etes-vous sur de vouloir que votre monstre ait : " << memoireReponseUtilisateur << " points de vie?" << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);

			if(rep == 1){
				std::cout << "Votre monstre a désormais : " << memoireReponseUtilisateur << "Points de vie." << std::endl;
				chara->setLifePoints(std::stoi(memoireReponseUtilisateur));
				chara->setCurrentLifePoints(std::stoi(memoireReponseUtilisateur));
			}
			else if(rep == 2){
				rep = -1;
			}
			else if(rep == -1){}
			else if(rep == 0){
				std::cout << "Oui : accepter." << std::endl;
				std::cout << "Non : refuser." << std::endl;
				rep = -1;
			}
			else{
				std::cout << "Commande invalide!" << std::endl;
				rep = -1;
			}
		}
	}
	rep = -1;
	//Attribution de l'attaque
	while(rep == -1){
		std::cout << "Quel est l'attaque de votre monstre" << std::endl;
		std::cin >> memoireReponseUtilisateur;

		if(commandManager->is_number(memoireReponseUtilisateur) == true){
			rep = 0;
		}
		else{
			std::cout << "Veuillez entrer un nombre." << std::endl;
			rep = -1;
		}

		while(rep == 0){
			std::cout << "Etes-vous sur de vouloir donner une attaque de : " << memoireReponseUtilisateur << " a votre monstre?" << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);

			if(rep == 1){
				std::cout << "L'attaque de votre monstre est desormais de : " << memoireReponseUtilisateur << std::endl;
				chara->setAttack(std::stoi(memoireReponseUtilisateur));
			}
			else if(rep == 2){
				rep = -1;
			}
			else if(rep == -1){}
			else if(rep == 0){
				std::cout << "Oui : accepter." << std::endl;
				std::cout << "Non : refuser." << std::endl;
				rep = -1;
			}
			else{
				std::cout << "Commande invalide!" << std::endl;
				rep = -1;
			}
		}
	}
	rep = -1;
	//Choix de la défense
	while(rep == -1){
		std::cout << "Quel est la défense de votre monstre" << std::endl;
		std::cin >> memoireReponseUtilisateur;

		if(commandManager->is_number(memoireReponseUtilisateur) == true){
			rep = 0;
		}
		else{
			std::cout << "Veuillez entrer un nombre." << std::endl;
			rep = -1;
		}

		while(rep == 0){
			std::cout << "Etes-vous sur de vouloir donner une défense de : " << memoireReponseUtilisateur << " a votre monstre?" << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);

			if(rep == 1){
				std::cout << "La défense de votre monstre est desormais de : " << memoireReponseUtilisateur << std::endl;
				chara->setDefense(std::stoi(memoireReponseUtilisateur));
			}
			else if(rep == 2){
				rep = -1;
			}
			else if(rep == -1){}
			else if(rep == 0){
				std::cout << "Oui : accepter." << std::endl;
				std::cout << "Non : refuser." << std::endl;
				rep = -1;
			}
			else{
				std::cout << "Commande invalide!" << std::endl;
				rep = -1;
			}		
		}
	}
	rep = -1;
	//Choix de la protection
	while(rep == -1){
		std::cout << "Quel est la protection de votre monstre" << std::endl;
		std::cin >> memoireReponseUtilisateur;

		if(commandManager->is_number(memoireReponseUtilisateur) == true){
			rep = 0;
		}
		else{
			std::cout << "Veuillez entrer un nombre." << std::endl;
			rep = -1;
		}

		while(rep == 0){
			std::cout << "Etes-vous sur de vouloir donner une protection de : " << memoireReponseUtilisateur << " a votre monstre?" << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);

			if(rep == 1){
				std::cout << "La protection de votre monstre est desormais de : " << memoireReponseUtilisateur << std::endl;
				chara->setProtection(std::stoi(memoireReponseUtilisateur));
			}
			else if(rep == 2){
				rep = 0;
			}
			else if(rep == -1){}
			else if(rep == 0){
				std::cout << "Oui : accepter." << std::endl;
				std::cout << "Non : refuser." << std::endl;
				rep = -1;
			}
			else{
				std::cout << "Commande invalide!" << std::endl;
				rep = -1;
			}
		}
	}
	rep = -1;
	//Choix du dé
	while(rep == -1){
		std::cout << "Quel est le dés utilisés par votre monstre votre monstre" << std::endl;
		std::cin >> memoireReponseUtilisateur;

		if(commandManager->is_number(memoireReponseUtilisateur) == true){
			rep = 0;
		}
		else{
			std::cout << "Veuillez entrer un nombre." << std::endl;
			rep = -1;
		}

		while(rep == 0){
			std::cout << "Etes-vous sur de vouloir utiliser un dé : " << memoireReponseUtilisateur << " pour votre monstre?" << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);

			if(rep == 1){
				std::cout << "Votre monstre utilise desormais un dé : " << memoireReponseUtilisateur << std::endl;
				chara->setDommagesDe(std::stoi(memoireReponseUtilisateur));
			}
			else if(rep == 2){

				rep = -1;
			}
			else if(rep == -1){}
			else if(rep == 0){
				std::cout << "Oui : accepter." << std::endl;
				std::cout << "Non : refuser." << std::endl;
				rep = -1;
			}
			else{
				std::cout << "Commande invalide!" << std::endl;
				rep = -1;
			}
		}
	}
	rep = -1;
	//Choix dégats additionnels
	while(rep == -1){
		std::cout << "Quel sont les dégats supplémentaires appliqués au dé utilisés par votre monstre votre monstre" << std::endl;
		std::cin >> memoireReponseUtilisateur;

		if(commandManager->is_number(memoireReponseUtilisateur) == true){
			rep = 0;
		}
		else{
			std::cout << "Veuillez entrer un nombre." << std::endl;
			rep = -1;
		}

		while(rep == 0){
			std::cout << "Etes-vous sur de vouloir ajouter : " << memoireReponseUtilisateur << " de dégats pour votre monstre?" << std::endl;
			std::cin >> reponseUtilisateur;
			rep = commandManager->analyse(reponseUtilisateur);

			if(rep == 1){
				std::cout << "Votre monstre ajoute desormais : " << memoireReponseUtilisateur << " a sa valeur de dé." << std::endl;
				chara->setDommagesAdditionnels(std::stoi(memoireReponseUtilisateur));
			}
			else if(rep == 2){
				rep = -1;
			}
			else if(rep == -1){}
			else if(rep == 0){
				std::cout << "Oui : accepter." << std::endl;
				std::cout << "Non : refuser." << std::endl;
				rep = -1;
			}
			else{
				std::cout << "Commande invalide!" << std::endl;
				rep = -1;
			}
		}
	}

	std::string mySave = "Saves/Monster/" + chara->getName() + chara->getRace()->getRaceName() + chara->getClasse()->getClassName() + ".txt";
	std::ofstream save(mySave.c_str(), std::ios::out | std::ios::trunc);

	if(save){
		save << "Nom: " << chara->getName() << std::endl;
		save << "Points de vie:  " << chara->getCurrentLifePoints() << " / " << chara->getLifePoints() << std::endl;
		save << std::endl;
		save << "Attaque: " << chara->getAttack() << std::endl;
		save << "Defense: " << chara->getDefense() << std::endl;
		save << "Protection: " << chara->getProtection() << std::endl;
		save << "Dé: " << chara->getDommagesDe() << std::endl;
		save << "Dommages additionnels: " << chara->getDommagesAdditionnels() << std::endl;
	}
}

void MonsterFactory::createBestiaryMonster(Character* chara){
	const int passToH = 9;
	const int tailleH = 4;
	const int tailleB = 5;
	const int tailleF = 5;

	std::string reponseUtilisateur;
	std::string fileName;
	int rep = -1;

	
	while(rep == -1){
		std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
		std::cout << "Vous voulez un monstre de quel type? : " << std::endl;
		if(bestiaryFile){
			std::string chaine;
			for(int i = 0; i < passToH -1; ++i){
				bestiaryFile >> chaine;
			}
			std::cout << "1 : " <<  chaine << std::endl;
			for(int i = 0; i < tailleH; ++i){
				for(int j = 0; j < 7; ++j){
					bestiaryFile >> chaine;	
				}
			}
			bestiaryFile >> chaine;
			std::cout << "2 : " << chaine << std::endl;
			for(int i = 0; i < tailleB; ++i){
				for(int j = 0 ; j < 7; ++j){
					bestiaryFile >> chaine;
				}
			}
			bestiaryFile >> chaine;
			std::cout << "3 : " << chaine << std::endl;
		}
		else{
			std::cout << "Impossible d'ouvrir le fichier" << std::endl;
			exit(1);
		}

		std::cin >> reponseUtilisateur;

		if(reponseUtilisateur == "1"){
			rep = -1;
			while(rep == -1){
				std::cout << "Voici la liste des Humanoïdes lequel voulez-vous? :" << std::endl;
				std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
				if(bestiaryFile){
					std::string chaine;
					for(int i = 0; i < passToH ; ++i){
						bestiaryFile >> chaine;
					}
					int cpt = 1;
					std::cout << cpt << " : " << chaine << std::endl;
					++cpt;
					for(int i = 0; i < tailleH -1 ;  ++i){
						for(int j = 0; j < 7; ++j){
							bestiaryFile >> chaine;
						}
						std::cout << cpt << " : " << chaine << std::endl;
						++cpt;
					}
				std::cin >> reponseUtilisateur;
				}


				if(reponseUtilisateur == "1"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else if(reponseUtilisateur == "2"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else if(reponseUtilisateur == "3"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else if(reponseUtilisateur == "4"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}

						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else{
					std::cout << "Commande invalide!" << std::endl;
					rep = -1;
				}
			}
		}	
		else if(reponseUtilisateur == "2"){
			rep = -1;
			while(rep == -1){
				std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
				std::cout << "Voici la liste des Bêtes : " << std::endl;
				if(bestiaryFile){
					std::string chaine;
					for(int i = 0; i < passToH ; ++i){
						bestiaryFile >> chaine;
					}
					int cpt = 1;
					for(int i = 0; i < tailleH;  ++i){
						for(int j = 0; j < 7; ++j){
							bestiaryFile >> chaine;
						}
					}
					bestiaryFile >> chaine;


					for(int i = 0 ; i < tailleB -1; ++i){
							std::cout << cpt << " : " << chaine << std::endl;
							++cpt;
						for(int j = 0; j < 7; ++j){
							bestiaryFile >> chaine;
						}
					}
				}
				std::cin >> reponseUtilisateur;

				if(reponseUtilisateur == "1"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					std::cout << "gou" << std::endl;;
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < tailleH;  ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;
						
						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else if(reponseUtilisateur == "2"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < tailleH;  ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;
						
						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else if(reponseUtilisateur == "3"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < tailleH;  ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;
						
						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else if(reponseUtilisateur == "4"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < tailleH;  ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;

						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else if(reponseUtilisateur == "5"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < tailleH;  ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;

						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else{
					std::cout << "Commande invalide!" << std::endl;
					rep = -1;
				}
			}
		}	

		else if(reponseUtilisateur == "3"){
			rep = -1;
			while(rep == -1){
				std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
				std::cout << "Voici la liste des Fantastiques : " <<std::endl;
				if(bestiaryFile){
					std::string chaine;
					for(int i = 0; i < passToH ; ++i){
						bestiaryFile >> chaine;
					}
					int cpt = 1;
					for(int i = 0; i < tailleH;  ++i){
						for(int j = 0; j < 7; ++j){
							bestiaryFile >> chaine;
						}
					}
					bestiaryFile >> chaine;

					for(int i = 0; i < tailleB; ++i){
						for(int j = 0; j < 7; ++j){
							bestiaryFile >> chaine;
						}
					}
					bestiaryFile >> chaine;

					for(int i = 0 ; i < tailleF; ++i){
						std::cout << cpt << " : " << chaine << std::endl;
						++cpt;
						for(int j = 0; j < 7; ++j){
							bestiaryFile >> chaine;
						}
					}
				}

				std::cin >> reponseUtilisateur;

				if(reponseUtilisateur == "1"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < tailleH;  ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;

						for(int i = 0; i < tailleB; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;
						
						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else if(reponseUtilisateur == "2"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < tailleH;  ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;
						
						for(int i = 0; i < tailleB; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;

						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else if(reponseUtilisateur == "3"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < tailleH;  ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;
						
						for(int i = 0; i < tailleB; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;
						
						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						std::cout << "Nom gobelin " << chaine << std::endl;
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else if(reponseUtilisateur == "4"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < tailleH;  ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;

						for(int i = 0; i < tailleB; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;
						
						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else if(reponseUtilisateur == "5"){
					std::ifstream bestiaryFile("NameGenerator/Bestiary.txt", std::ios::in);
					if(bestiaryFile){
						std::string chaine;
						for(int i = 0; i < passToH; ++i){
							bestiaryFile >> chaine;
						}
						for(int i = 0; i < tailleH;  ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;

						for(int i = 0; i < tailleB; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						bestiaryFile >> chaine;
						
						for(int i = 0; i < std::stoi(reponseUtilisateur) -1; ++i){
							for(int j = 0; j < 7; ++j){
								bestiaryFile >> chaine;
							}
						}
						chara->setName(chaine);
						bestiaryFile >> chaine;
						chara->setCurrentLifePoints(std::stoi(chaine));
						chara->setLifePoints(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setAttack(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDefense(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setProtection(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesDe(std::stoi(chaine));
						bestiaryFile >> chaine;
						chara->setDommagesAdditionnels(std::stoi(chaine));
					}
					rep = 1;
				}
				else{
					std::cout << "Commande invalide!" << std::endl;
					rep = -1;
				}
			}
		}
		else{
			std::cout << "Commande invalide!" << std::endl;
			rep = -1;
		}
	}
}

void MonsterFactory::save(Character* chara, std::string path, bool boss){
	config = new Config();
	std::string mySave;
	if(boss == true){
		config->updateBossCfg();
		mySave = path + chara->getName() + std::to_string(config->getNumberBossSaves()) + ".txt";
	}
	else{
		config->updateMonsterCfg();
		mySave = path + chara->getName() + std::to_string(config->getNumberMonsterSaves()) + ".txt";
	}
	std::ofstream save(mySave.c_str(), std::ios::out | std::ios::trunc);

	if(save){
		save << "Nom: " << chara->getName() << std::endl;
		save << "Points de vie:  " << chara->getCurrentLifePoints() << " / " << chara->getLifePoints() << std::endl;
		save << std::endl;
		save << "Attaque: " << chara->getAttack() << std::endl;
		save << "Defense: " << chara->getDefense() << std::endl;
		save << "Protection: " << chara->getProtection() << std::endl;
		save << "Dé: " << chara->getDommagesDe() << std::endl;
		save << "Dommages additionnels: " << chara->getDommagesAdditionnels() << std::endl;
	}
	config->updateMonsterCfg();
	config->updateBossCfg();
	config->initialize();
}


Character* MonsterFactory::getCharacter(){
	return chara;
}

void MonsterFactory::setCharacter(Character* ch){
	chara = ch;
}