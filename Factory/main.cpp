
#include "Character.hpp"
#include "Classes.hpp"
#include "PNJ.hpp"
#include "Inventory.hpp"
#include "Factory.hpp"
#include "PNJFactory.hpp"
#include "MonsterFactory.hpp"
#include "BossFactory.hpp"
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

	Factory* fact = new BossFactory();
	Character* chara = fact->createCharacter();

}