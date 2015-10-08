#ifndef COMMANDMANAGER
#define	COMMANDMANAGER
#include "state.hpp"
#include <string>
#include <algorithm> 

/*Liste des commandes possible :
help, oui, non, personnage, monstre, boss, création, jouer, hote
rejoindre, homme, femme, aléatoire, attaquer, elfe, orc
huamin, nain, guerrier, mage, pretre, paladin, chasseur
roublard, 

*/


class CommandManager{
	private:
		State currentState;
		bool inGame;

	public:
		CommandManager();
		~CommandManager();
		int analys(std::string commande);
		State getCurrentState();
	

};

#endif