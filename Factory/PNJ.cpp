/**
* @file PNJ.cpp
* @brief Classe de personnage PNJ.
* @author HERAUD Xavier 
* 
* Classe fille de Character qui possèdes les variables et méthodes propres aux PNJs.
*/
#include "PNJ.hpp"

/**
* @fn
* @brief 
*
* @param
* @return
*/
PNJ::PNJ(){}

/**
* @fn
* @brief 
*
* @param
* @return
*/
PNJ::~PNJ(){}


// Méthodes de la classe PNJ
///////////////////////////////////////////////////////////////////////////////

/**
* @fn
* @brief 
*
* @param
* @return
*/
std::string PNJ::performAttack(){
	std::srand((unsigned int)std::time(0));
	int random_variable = (std::rand() % 20) + 1;
	if (random_variable <= attack){
		std::cout << "Vous avez lance le de et obtenu " << random_variable << ". C'est une reussite!";
		std::string rdm = std::to_string(random_variable); 
		return name+" a reussi son attaque grace a un "+rdm;
	}
	else {
		std::cout << "Vous avez lance le de et obtenu " << random_variable << ". C'est un echec!";
		std::string rdm = std::to_string(random_variable); 
		return name+" a rate son attaque avec un "+rdm;
	}
}

/**
* @fn
* @brief 
*
* @param
* @return
*/
std::string PNJ::defend(){
	std::srand((unsigned int)std::time(0));
	int random_variable = (std::rand() % 20) + 1;
	if (random_variable <= defense){
		std::cout << "Vous avez lanc� le d� et obtenu " << random_variable << ". C'est une r�ussite!";
		std::string rdm = std::to_string(random_variable); 
		return name+" a r�ussi sa d�fense gr�ce � un "+rdm;
	}
	else {
		std::cout << "Vous avez lanc� le d� et obtenu " << random_variable << ". C'est un �chec!";
		std::string rdm = std::to_string(random_variable); 
		return name+" a rat sa d�fense avec un "+rdm;
	}
}

////////////////////////////////////////////////////////////////////////////////
// Getters Setters START

std::string PNJ::getLastName(){
	return lastName;
}
void PNJ::setLastName(std::string lName){
	lastName = lName;
}

void PNJ::setRandomName(){
	std::string cast;
	
	std::srand((unsigned int)std::time(0));
	const int taille = 150; // Taille des fichiers de nom
	int random_variable = (std::rand() % taille) +1;

	std::string characterRace = getRace()->getRaceName();
	char* raceFile;
	if(characterRace == "Dwarf"){
		cast = "NameGenerator/Orc"+sexe+"Names.txt";
	}
	else{
		cast = "NameGenerator/"+characterRace+sexe+"Names.txt";
	}
	raceFile = (char*)cast.c_str();
	std::ifstream file(raceFile, std::ios::in);

	if(file){
		std::string chaine;
		for(int i = 0; i < random_variable; i++){
			file >> chaine;
		}
		name = chaine;
	}
}

void PNJ::setRandomLastName(){
	std::string cast;
	std::srand(std::time(0));
	const int taille = 150; // Taille des fichiers de nom
	int random_variable = (std::rand() % taille) +1;
	std::string characterRace = getRace()->getRaceName();
	char* raceFile;
	if(characterRace == "Dwarf"){
		cast = "NameGenerator/HumanLastNames.txt";
	}
	else{
		cast = "NameGenerator/"+characterRace+"LastNames.txt";
	}
	raceFile = (char*)cast.c_str();
	std::ifstream file(raceFile, std::ios::in);
	if(file){
		std::string chaine;
		std::string fName;
		for(int i = 0; i < random_variable; i++){
			file >> chaine;
			file >> chaine;
		}
		fName = chaine + " ";
		file >> chaine;
		fName += chaine;
		lastName = chaine;
	}
}

// Getters Setters de Monster
int PNJ::getDommagesDe(){return 1;}
void PNJ::setDommagesDe(int i){i=i;}
int PNJ::getDommagesAdditionnels(){return 1;}
void PNJ::setDommagesAdditionnels(int){}
