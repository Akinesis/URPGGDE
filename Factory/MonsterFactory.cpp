#include "MonsterFactory.hpp"

MonsterFactory::MonsterFactory() {}

MonsterFactory::~MonsterFactory() {}

Character* MonsterFactory::createAllRandom(){
	chara = new Monster();
	
	const int nbCategory = 3;
	const int passToH = 9;
	const int tailleH = 5;
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
	//chara = new Monster();

	return chara;
}

Character* MonsterFactory::createCharacterSaved(){
	//chara = new Monster();

	return chara;
}

Character* MonsterFactory::createCharacter(){
	return chara;
}

Character* MonsterFactory::getCharacter(){
	return chara;
}

void MonsterFactory::setCharacter(Character* ch){
	chara = ch;
}