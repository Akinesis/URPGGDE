#include "PNJ.hpp"

PNJ::PNJ(){}

PNJ::PNJ(std::string na, std::string sx, int lPoints, int mPoints, int stgth, int cons, int dex, int intel, int wisd, int chari, int att, int def, int pr, int lvl, int bcap, Inventory b, std::string lName){
	Character(na, sx, lPoints, mPoints, stgth, cons, dex, intel, wisd, chari, att, def, pr, lvl, bcap, b);
	lastName = lName;
}


std::string PNJ::performAttack(){
	std::srand(std::time(0));
	int random_variable = (std::rand() % 20) + 1;
	if (random_variable <= attack()){
		std::cout << "Vous avez lanc� le d� et obtenu " << random_variable << ". C'est une r�ussite!";
		return name+" a r�ussi son attaque gr�ce � un "+random_variable;
	}
	else {
		std::cout << "Vous avez lanc� le d� et obtenu " << random_variable << ". C'est un �chec!";
		return name+" a rat� son attaque avec un "+random_variable;
	}
}

std::string PNJ::defend(){
	std::srand(std::time(0));
	int random_variable = (std::rand() % 20) + 1;
	if (random_variable <= defense()){
		std::cout << "Vous avez lanc� le d� et obtenu " << random_variable << ". C'est une r�ussite!";
		return name+" a r�ussi sa d�fense gr�ce � un "+random_variable;
	}
	else {
		std::cout << "Vous avez lanc� le d� et obtenu " << random_variable << ". C'est un �chec!";
		return name+" a rat sa d�fense avec un "+random_variable;
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
	std::srand(std::time(0));
	const int taille = 150; // Taille des fichiers de nom
	int random_variable = (std::rand() % taille) +1;

	std::string characterRace = getRace().getRaceName();
	char* raceFile;
	std::string cast = "../NameGenerator/"+characterRace+sexe+"Names.txt";
	raceFile = (char*)cast.c_str();
	std::ifstream file(raceFile, std::ios::in);

	if(file){
		std::string chaine;
		for(int i = 0; i < random_variable; i++){
			file << chaine;
		}
		name = file;
	}
}

void PNJ::setRandomLastName(){
	std::srand(std::time(0));
	const int taille = 150; // Taille des fichiers de nom
	int random_variable = (std::rand() % taille) +1;

	std::string characterRace = getRace().getRaceName();
	char* raceFile;
	std::string cast = "../NameGenerator/"+characterRace+"LastNames.txt";
	raceFile = (char*)cast.c_str();
	std::ifstream file(raceFile, std::ios::in);

	if(file){
		std::string chaine;
		for(int i = 0; i < random_variable; i++){
			file << chaine;
		}
		name = file;
	}
}

// Getters Setters END
