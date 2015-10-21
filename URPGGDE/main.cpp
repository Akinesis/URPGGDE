
#include "Character.hpp"
#include "Classes.hpp"
#include "PNJ.hpp"
#include "Inventory.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

int main(){

	Character* chara = new PNJ();
	chara->setName("Roger");
	chara->setLastName("Simon");
	chara->getBag()->setWeapon1("épée");
	chara->getRace()->createHuman();
	chara->getClasse()->createRandomClass();
	std::string a = chara->getClasse()->getClassName();
	std::cout << a << std::endl;
}