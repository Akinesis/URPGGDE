#ifndef STATECREATE
#define	STATECREATE
#include <string>

#include "../Factory/Factory.hpp"
#include "../Factory/PNJFactory.hpp"
#include "../Factory/MonsterFactory.hpp"
#include "../Factory/BossFactory.hpp"

#include "state.hpp"
#include "commandManager.hpp"

class StateCreate : public State{

	private:
		Factory* fact;
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
		int play();
		int npc();
		int monster();
		int boss();

};

#endif