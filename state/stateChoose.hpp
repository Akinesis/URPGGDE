#ifndef STATECHOOSE
#define	STATECHOOSE

#include "../Factory/Factory.hpp"
#include "../Factory/PNJFactory.hpp"
#include "../Factory/MonsterFactory.hpp"
#include "../Factory/BossFactory.hpp"

#include "state.hpp"
#include "commandManager.hpp"

class StateChoose : public State{
	private:
		Factory* fact;
	public:
		StateChoose(CommandManager* commandManager);
		virtual ~StateChoose();
		void help();
		int npc();
		int boss();
		int monster();
		int play();
};

#endif