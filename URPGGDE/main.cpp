#include <ctime> //ancien methode
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


int main()
{
	using namespace std;

	ifstream fichier("../NameGenerator/HumanMaleNames.txt", ios::in);

	if(fichier){
		int pos = 51;
		string chaine;
		for(int i = 0; i < pos ; i++){
			fichier >> chaine;
		}
		cout << chaine << endl;
		fichier.close();

	}
	else{
		cout << "Impossible d'ouvrir le fichier" << endl;
	}

}
