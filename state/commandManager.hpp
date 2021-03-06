#ifndef COMMANDMANAGER
#define	COMMANDMANAGER
#include <string>
#include <vector>
#include <algorithm>
#include "../Observer/connexion.hpp"
#include "../Factory/Character.hpp"

class State;
class StateStart;
class StateCreate;
class StatePlay;
class StateJoin;
class StateHost;
class StateGame;
class StateChoose;

/*
Liste des commandes possible :
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
		State *stateGame;
		State *stateChoose;
		State *currentState;
		Connexion *connexion;
		std::vector<Character*> characters;

	public:
		CommandManager();
		CommandManager(Connexion* conect);
		~CommandManager();
		int analyse(std::string commande);
		int analyseGametext(std::string ligne);

		void setState(State* etat);
		int throwError();
		State* getCurrentState();
		State* getStateStart();
		State* getStateCreate();
		State* getStatePlay();
		State* getStateJoin();
		State* getStateHost();
		State* getStateGame();
		State* getStateChoose();

		void createConnexionHost();
		void createConnexionJoin();

		void clientSend(std::string mes);
		void hostSend(std::string mes);
		bool getIsServer();

		void addCharacter(Character* chara);
		std::vector<Character*> getCharacters();
		
		bool is_number(const std::string& s);
	

};

#endif