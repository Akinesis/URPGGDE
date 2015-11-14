#include "MonsterFactory.hpp"

MonsterFactory::MonsterFactory() {}

MonsterFactory::~MonsterFactory() {}

Character* MonsterFactory::createAllRandom(){
	chara = new Monster();
	
	const int nbCategory = 3;
	const int passToH = 9;
	const int tailleH = 4;
	const int tailleB = 5;
	const int tailleF = 5;

	std::ifstream bestiaryFile("../NameGenerator/Bestiary.txt", std::ios::in);
		
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
	}//if
	else if(rdmCategory == 2){
		if(bestiaryFile){
			std::string chaine;
			for(int i = 0; i < (passToH + tailleH +1); ++i){
				bestiaryFile >> chaine;
			}//for

			std::srand(std::time(0));
			int rdmMonster = (std::rand() % tailleB);
			for(int i = 0; i < rdmMonster; ++i){
				bestiaryFile >> chaine;
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
	}//else if
	else{
		if(bestiaryFile){
			std::string chaine;
			for(int i = 0; i < (passToH + tailleH + tailleB +2); ++i){
				bestiaryFile >> chaine;
			}//for

			std::srand(std::time(0));
			int rdmMonster = (std::rand() % tailleF);
			for(int i = 0; i < rdmMonster; ++i){
				bestiaryFile >> chaine;
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
	}//else

	
	return chara;
}//fin

Character* MonsterFactory::createPersonnalize(){
	chara = new Monster();

	std::string = reponseUtilisateur;
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
			std::cout << "Etes-vous sur de vouloir créer un monstre entièrement personnalisé? : " << std::cout;
			std::cin >> reponseUtilisateur;
			rep == commandManager->analyse(reponseUtilisateur);
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

	return chara;
}

Character* MonsterFactory::createCharacterSaved(){
	//chara = new Monster();

	////////////////////////////////////////////////////////////////
	commandManager->setState(commandManager->getStateCreate());
	////////////////////////////////////////////////////////////////

	return chara;
}

Character* MonsterFactory::createCharacter(){
	return chara;
}

void MonsterFactory::createBestiaryMonster(Character* chara){
	const int nbCategory = 3;
	const int passToH = 9;
	const int tailleH = 4;
	const int tailleB = 5;
	const int tailleF = 5;

	std::string = reponseUtilisateur;
	std::string fileName;
	int rep = -1;

	std::ifstream bestiaryFile("../NameGenerator/Bestiary.txt", std::ios::in);
	
	while(rep == -1){
		std::cout << "Vous voulez un monstre de quel type? : " << std::endl;
		if(bestiaryFile){
			std::string chaine;
			for(int i = 0; i < passToH -1; ++i){
				bestiaryFile >> chaine;
			}
			std::cout << "1 : " <<  chaine << std::endl;
			for(int i = 0; i < tailleH; ++i){
				bestiaryFile >> chaine;
			}
			std::cout << "2 : " << chaine << std::endl;
			for(int i = 0; i < tailleB; ++i){
				bestiaryFile >> chaine;
			}
		}

		std::cin >> reponseUtilisateur;

		if(reponseUtilisateur == "1"){
			rep = 1;
			while(rep == 1){
				std::cout << "Voici la liste des Humanoïdes :" << std::endl;
				if(bestiaryFile){
					std::string chaine;
					for(int i = 0; i < passToH ; ++i){
						bestiaryFile >> chaine;
					}
					int cpt = 1;
					for(int j = 0; j < tailleH ;  ++j){
						bestiaryFile >> chaine;
						std::cout << cpt << " : " << chaine << std::endl;
						++cpt;
					}
				}

				std::cin >> reponseUtilisateur;

				
			}
		}	
		else if(reponseUtilisateur == "2"){

		}
		else if(reponseUtilisateur == "3"){

		}
		else{
			std::cout << "Commande invalide!" << std::endl;
			rep = -1;
		}
	}//While

}


Character* MonsterFactory::getCharacter(){
	return chara;
}

void MonsterFactory::setCharacter(Character* ch){
	chara = ch;
}