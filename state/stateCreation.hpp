#ifndef STATECREATE
#define	STATECREATE
#include <string>
#include "state.hpp"
#include "commandManager.hpp"

class StateCreate : public State{

	public:
		StateCreate(CommandManager* commandManager);
		~StateCreate();
		void help();
		int exit();
		int man();
		int woman();
		int random();
		int custom();
		int elf();
		int human();
		int orc();
		int dwarf();
		int warrior();
		int mage();
		int priest();
		int paladin();
		int hunter();
		int rogue();

};

#endif