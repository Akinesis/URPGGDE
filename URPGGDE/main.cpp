#include "Character.hpp"
#include "Factory.hpp"
#include "Race.hpp"
#include "PNJFactory.hpp"
#include "PNJ.hpp"
#include "Classes.hpp"
#include "Inventory.hpp"

#include <ctime> //ancien methode
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


int main()
{
	using namespace std;
	Character* chara = new PNJ();
	Factory* pnjFac = new PNJFactory(chara);

}
