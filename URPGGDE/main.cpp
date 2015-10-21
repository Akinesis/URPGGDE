
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
#include <stdio.h>

int main(){
	Factory* fact = new PNJFactory();
	fact->createAllRandom();
}