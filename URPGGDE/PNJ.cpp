#include "PNJ.hpp"

// Constructeur Destructeur
PNJ::PNJ(){}

PNJ::~PNJ(){}


// Méthodes de la classe PNJ
///////////////////////////////////////////////////////////////////////////////

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
	std::srand((unsigned int)std::time(0));
	const int taille = 150; // Taille des fichiers de nom
	int random_variable = (std::rand() % taille) +1;

	std::string characterRace = getRace()->getRaceName();
	char* raceFile;
	std::string cast = "../NameGenerator/"+characterRace+sexe+"Names.txt";
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
	std::srand(std::time(0));
	const int taille = 150; // Taille des fichiers de nom
	int random_variable = (std::rand() % taille) +1;
	std::string characterRace = getRace()->getRaceName();
	char* raceFile;
	std::string cast = "../NameGenerator/"+characterRace+"LastNames.txt";
	raceFile = (char*)cast.c_str();
	std::ifstream file(raceFile, std::ios::in);
	if(file){
		std::string chaine;
		for(int i = 0; i < random_variable; i++){
			file >> chaine;
		}
		lastName = chaine;
	}
}

// Getters Setters END
