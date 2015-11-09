#ifndef COMMANDMANAGER
#define	COMMANDMANAGER
#include <string>
#include <algorithm>
#include <regex>
#include "../Observer/connexion.hpp"

class State;
class StateStart;
class StateCreate;
class StatePlay;
class StateJoin;
class StateHost;

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
		State *statePlay;
		State *stateJoin;
		State *stateHost;
		State *currentState;
		Connexion *connexion;

	public:
		CommandManager(Connexion* conect);
		~CommandManager();
		int analyse(std::string commande);
		void setState(State* etat);
		void throwError();
		State* getCurrentState();
		State* getStateStart();
		State* getStateCreate();
		State* getStatePlay();
		State* getStateJoin();
		State* getStateHost();

		void createConnexionHost();
		void createConnexionJoin();
	

};

#endif