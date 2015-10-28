
#include "Character.hpp"
#include "Classes.hpp"
#include "PNJ.hpp"
#include "Inventory.hpp"
#include "Factory.hpp"
#include "PNJFactory.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "stdlib.h"
#include <stdio.h>
#include <dirent.h>

int main(){
	/*
	Factory* fact = new PNJFactory();
	fact->createAllRandom();
	*/
	
	DIR* rep = NULL;
	struct dirent* fichierLu = NULL;
	rep = opendir("../Saves/");

	if(rep == NULL)
		exit(1);

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

	if(closedir(rep) == -1)
		exit(-1);
	
}