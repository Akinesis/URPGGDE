#include "Race.hpp";


void Race::CreateVector(std::vector<std::string> vecn, std::vector<std::string> vecs){
	vecn.push_back(NULL);
	vecn.push_back(NULL);
	for(int i = 0; i < 18 ; i++){
		vecs.push_back(NULL);
	}
}

int Race::randomVariable(int min, int max){
	std::srand(std::time(0));
	int interval = max - min;
	int random_variable = (std::rand() % interval) + 1;
	return random_variable;
}

std::string Race::randomName(std::string race, std::string sexe){
	std::srand(std::time(0));
	const int taille = 150; // Taille des fichiers de nom
	int random_variable = (std::rand() % taille) +1;

	std::string name;
	std::ifstream file;

	if (sexe == "Male"){
		if(race == "human"){
			file("../NameGenerator/HumanMaleNames.txt", std::ios::in);
		}
		else if (race == "orc"){
			file("../NameGenerator/OrcMaleNames.txt", std::ios::in);
		}
		else if (race == "elf"){
			file("../NameGenerator/ElficMaleNames.txt", std::ios::in);
		}
		else{
			std::cout << "Race inconnue. Enrez un race existante." << std::endl;
		}
	}
	else
	{
		if(race == "human"){
			file("../NameGenerator/HumanFemaleNames.txt", std::ios::in);
		}
		else if (race == "orc"){
			file("../NameGenerator/OrcFemaleNames.txt", std::ios::in);
		}
		else if (race == "elf"){
			file("../NameGenerator/ElficFemaleNames.txt", std::ios::in);
		}
		else{
			std::cout << "Race inconnue. Enrez un race existante." << std::endl;
		}

	}

	if(file){
		for(int i = 0; i < random_variable ; i++){
			file >> name;
		}
		file.close();
	}
	return name;
}

std::string Race::randomLastName(std::string race){
	std::srand(std::time(0));
	const int taille = 150; // Taille des fichiers de nom
	int random_variable = (std::rand() % taille) +1;

	std::string lname;
	std::ifstream file;

	if(race == "human"){
		file("../NameGenerator/HumanLastNames.txt", std::ios::in);
	}
	if(race == "orc"){
		file("../NameGenerator/OrcLastNames.txt", std::ios::in);
	}
	if(race == "elf"){
		file("../NameGenerator/ElficLastNames.txt", std::ios::in);
	}
	else{
		std::cout << "Race inconnue. Enrez un race existante." << std::endl;
	}
	if(file){
		for(int i = 0; i < random_variable ; i++){
			file >> lname;
		}
		file.close();
	}
	return lname;
}

////////////////////////////////////////////////////////////////////////////////
// Getters Setters START
std::string Race::getHumanNames(){
	std::string hnames;
	for(int i = 0; i < humanNames.size(); i++){
		hnames += humanNames[i] + ", ";
	}
	return hnames;
}
void Race::setHumanNames(std::string hname, std::string hlname){
	humanNames[0] = hname;
	humanNames[1] = hlname;
 }

void Race::setRandomHumanNames(std::string sexe){
	std::srand(std::time(0));
	const int taille = 150; // Taille des fichiers de nom
	int random_variable = (std::rand() % taille) +1;

	std::string name;
	std::ifstream file;

	if(sexe == "Male"){
		file("../NameGenerator/HumanMaleNames.txt", std::ios::in);
	}
	else{
		file("../NameGenerator/HumanFemaleNames.txt", std::ios::in);
	}
	if(file){
		for(int i = 0; i < random_variable ; i++){
			file >> name;
		}
		file.close();
	}

	std::srand(std::time(0));
	const int taille = 150; // Taille des fichiers de nom
	int random_variable = (std::rand() % taille) +1;
	std::ifstream file2("../NameGenerator/HumanLastNames.txt", std::ios::in);

	if(file2){
		for(int i = 0; i < random_variable ; i++){
			file >> name;
		}
		file.close();
	}
}

