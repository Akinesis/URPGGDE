#ifndef COMMANDMANAGER
#define	COMMANDMANAGER
#include <string>
#include <algorithm>

class State;
class StateStart;
class StateCreate;

/*Liste des commandes possible :
help, oui, non, personnage, monstre, boss, création, jouer, hote
rejoindre, homme, femme, aléatoire, personaliser, attaquer, elfe, orc
huamin, nain, guerrier, mage, pretre, paladin, chasseur
roublard, exit,

*/


class CommandManager{
	private:
		bool inGame;
		State *stateStart;
		State *stateCreate;
		State *currentState;

	public:
		CommandManager();
		~CommandManager();
		int analyse(std::string commande);
		void setState(State* etat);
		void throwError();
		State* getCurrentState();
		State* getStateStart();
		State* getStateCreate();
	

};

#endif