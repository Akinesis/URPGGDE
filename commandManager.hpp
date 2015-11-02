#ifndef COMMANDMANAGER
#define	COMMANDMANAGER
#include <string>
#include <algorithm> 

class State;
class StateStart;

/*Liste des commandes possible :
help, oui, non, personnage, monstre, boss, création, jouer, hote
rejoindre, homme, femme, aléatoire, attaquer, elfe, orc
huamin, nain, guerrier, mage, pretre, paladin, chasseur
roublard, 

*/


class CommandManager{
	private:
		State *currentState;
		State *stateStart;
		State *stateCreate;
		bool inGame;

	public:
		CommandManager();
		~CommandManager();
		int analys(std::string commande);
		void setState(State* etat);
		State* getCurrentState();
		State* getStateStart();
		State* getStateCreate();
	

};

#endif