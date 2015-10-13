#include "Character.hpp"
#include "Factory.hpp"
#include "Race.hpp"

#include <ctime> //ancien methode
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


int main()
{
	using namespace std;

	Character chara;
	Factory pnj = new PNJFactory();
	pnj.createAllRandom();
}
