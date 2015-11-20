#include "BossFactory.hpp"

BossFactory::BossFactory(){}
BossFactory::~BossFactory(){}

void BossFactory::createAllRandom(Character* chara){
	int rep = -1;
	std::string reponseUtilisateur;

	while(rep == -1){
		std::cout << "Voulez-vous créer aléatoirement un : " << std::endl;
		std::cout << "1 : Monstre." << std::endl;
		std::cout << "2 : PNJ." << std::endl;
		std::cin >> reponseUtilisateur;

		if(reponseUtilisateur == "1"){//Créer un BossMonstre
			monsterFact->createAllRandom(chara);
			chara->setLifePoints(chara->getLifePoints() *2);
			chara->setCurrentLifePoints(chara->getCurrentLifePoints() *2);
			chara->setAttack(chara->getAttack() *2);
			chara->setDefense(chara->getDefense() *2);
			chara->setProtection(chara->getProtection() *2);
			chara->setDommagesAdditionnels(chara->getDommagesAdditionnels() *2);
			monsterFact->save(chara, "Saves/Boss/", true);
			rep = 1;
		}
		else if(reponseUtilisateur == "2"){//Créer un Boss PNJ
			pnjFact->createAllRandom(chara);
			chara->setStrength(chara->getStrength() *2);
			chara->setConstitution(chara->getConstitution() *2);
			chara->setDexterity(chara->getDexterity() *2);
			chara->setIntelligence(chara->getIntelligence() *2);
			chara->setWisdom(chara->getWisdom() *2);
			chara->setCharisma(chara->getCharisma() *2);
			pnjFact->applySkillPoints(chara);
			pnjFact->save(chara, "Saves/Boss/", true);
			rep = 1;
		}
		else{
			std::cout << "Veuillez entrer '1' ou '2'." << std::endl;
			rep = -1;
		}
	}

}

void BossFactory::createPersonnalize(Character* chara){
	std::string reponseUtilisateur;
	int rep = -1;

	while(rep == -1){
		std::cout << "Voulez-vous créer un boss de type montre ou de type PNJ? : " << std::endl;
		std::cout << "1 : Monstre" << std::endl;
		std::cout << "2 : PNJ" << std::endl;
		std::cin >> reponseUtilisateur;

		if(reponseUtilisateur == "1"){
			monsterFact->createPersonnalize(chara);
			chara->setLifePoints(chara->getLifePoints() *2);
			chara->setCurrentLifePoints(chara->getCurrentLifePoints() *2);
			chara->setAttack(chara->getAttack() *2);
			chara->setDefense(chara->getDefense() *2);
			chara->setProtection(chara->getProtection() *2);
			chara->setDommagesAdditionnels(chara->getDommagesAdditionnels() *2);
			monsterFact->save(chara, "Saves/Boss/", true);
			rep = 1;
		}
		else if(reponseUtilisateur == "2"){
			pnjFact->createPersonnalize(chara);
			chara->setStrength(chara->getStrength() *2);
			chara->setConstitution(chara->getConstitution() *2);
			chara->setDexterity(chara->getDexterity() *2);
			chara->setIntelligence(chara->getIntelligence() *2);
			chara->setWisdom(chara->getWisdom() *2);
			chara->setCharisma(chara->getCharisma() *2);
			pnjFact->applySkillPoints(chara);
			pnjFact->save(chara, "Saves/Boss/", true);
			rep = 1;
		}
		else{
			std::cout << "Veuillez entrer '1' ou '2'." << std::endl;
			rep = -1;
		}
	}
}

Character* BossFactory::createCharacterSaved(){
	chara = new Boss();

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
	rep = opendir("Saves/Boss/");
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
		file >> chaine;
		if(chaine == "Prenom"){
			//Recupération du prénom et du nom de famille
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
			//Récupération du nom
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
	}

	return chara;
}

Character* BossFactory::createCharacter(){

	////////////////////////////////////////////////////////////////
	commandManager->setState(commandManager->getStateCreate());
	////////////////////////////////////////////////////////////////

	chara = new Boss();
	pnjFact = new PNJFactory();			//Affiche un nouvel acceuil
	monsterFact = new MonsterFactory();	//Affiche un nouvel acceuil
	config = new Config();
	std::string reponseUtilisateur;
	int rep = -1;

	while(rep == -1){
		std::cout << "Voulez-vous créer un boss aléatoire un un boss personnalisé? : " << std::endl;
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
		}
	}

	return chara;
}

void BossFactory::setCharacter(Character* ch){
	chara = ch;
}

Character* BossFactory::getCharacter(){
	return chara;
}