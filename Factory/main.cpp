
#include "Character.hpp"
#include "Classes.hpp"
#include "PNJ.hpp"
#include "Inventory.hpp"
#include "Factory.hpp"
#include "PNJFactory.hpp"
#include "../state/commandManager.hpp"

#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "stdlib.h"
#include <stdio.h>
#include <dirent.h>

int main(){
	using namespace std;

	Factory* fact = new PNJFactory();
	Character* chara = fact->createCharacterSaved();
	cout <<chara->getName() << endl;;

	//Character* chara = fact->createCharacter();


	
	/*
	std::ifstream bestiaryFile("../NameGenerator/Bestiary.txt", std::ios::in);
	
	if(bestiaryFile){
		std::string chaine;
		bestiaryFile >> chaine;
		bestiaryFile >> chaine;
		bestiaryFile >> chaine;
		bestiaryFile >> chaine;
		bestiaryFile >> chaine;
		bestiaryFile >> chaine;
		bestiaryFile >> chaine;
		bestiaryFile >> chaine;
		bestiaryFile >> chaine;

		for(int i = 0; i < 7 ; ++i){
			bestiaryFile >> chaine;
		}
		std::cout << prout << std::endl;
	}
	*/

}