#include "Boss.hpp"

Boss::Boss(){}

Boss::~Boss(){}

std::string Boss::performAttack(){
	std::srand(std::time(0));
	int random_variable = (std::rand() % 20) + 1;
	if (random_variable <= attack){
		std::cout << name << " a lance une puissante attaque en faisant un " << random_variable << ". C'est une reussite!";
		std::string rdm = std::to_string(random_variable);
		return name+" a reussi sa vil attaque grace a un "+rdm;
	}
	else {
		std::cout << name << " a lance une attaque avec un de de " << random_variable << ". C'est un echec!";
		std::string rdm = std::to_string(random_variable);
		return name+" a bien rate son attaque avec un "+rdm;
	}
}


std::string Boss::defend(){
	std::srand(std::time(0));
	int random_variable = (std::rand() % 20) + 1;
	if (random_variable <= attack){
		std::cout << name << " c'est aisément defendu en faisant un " << random_variable << ". C'est une reussite!";
		std::string rdm = std::to_string(random_variable);
		return name+" effectue une parade reussit grace a un "+rdm;
	}
	else {
		std::cout << name << " c'est defendu en faisant un " << random_variable << ". C'est un echec!";
		std::string rdm = std::to_string(random_variable);
		return name+" a bien rate sa parade avec un "+rdm;
	}
}

////////////////////////////////////////////////////////////////////////////////
// Getters Setters START
std::string Boss::getLastName(){
	return lastName;
}
void Boss::setLastName(std::string ln){
	lastName = ln;
}

void Boss::setRandomName(){
	std::srand(std::time(0));
	const int taille = 150; // Taille des fichiers de nom
	int random_variable = (std::rand() % taille) +1;

	std::string characterRace = race->getRaceName();
	char* raceFile;
	std::string cast = "../NameGenerator/"+characterRace+sexe+"Names.txt";
	raceFile = (char*)cast.c_str();
	std::ifstream file(raceFile, std::ios::in);

	if(file){
		std::string chaine;
		for(int i = 0; i < random_variable; ++i){
			file >> chaine;
		}
		name = chaine;
	}
}

void Boss::setRandomLastName(){
	std::srand(std::time(0));
	const int taille = 150; // Taille des fichiers de noms
	int random_variable = (std::rand() % taille) +1;

	std::string characterRace = race->getRaceName();
	char* raceFile;
	std::string cast = "../NameGenerator/"+characterRace+"LastNames.txt";
	raceFile = (char*)cast.c_str();
	std::ifstream file(raceFile, std::ios::in);

	if(file){
		std::string chaine;
		for(int i = 0; i < random_variable; ++i){
			file >> chaine;
		}
		name = chaine;
	}
}
// Getters Setters END