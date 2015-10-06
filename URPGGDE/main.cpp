#include <ctime> //ancien methode
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


int main()
{
	std::string human = "Human";
	char* make;
	std::string make2 =  "../NameGenerator/"+human+"MaleNames.txt";
	make= (char*)make2.c_str() ;
	using namespace std;

	ifstream fichier(make, ios::in);

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
