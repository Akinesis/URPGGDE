#include "Race.hpp";


void Race::humanCreateVector(std::vector<std::string> vecn, std::vector<std::string> vecs){
	vecn.push_back(NULL);
	vecn.push_back(NULL);
	for(int i = 0; i < 12 ; i++){
		vecs.push_back(NULL);
	}
}

int Race::randomVariable(int min, int max){
	std::srand(std::time(0));
	int interval = max - min;
	int random_variable = (std::rand() % interval) + 1;
	return random_variable;
}




////////////////////////////////////////////////////////////////////////////////
// Getters Setters START
