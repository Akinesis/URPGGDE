#ifndef STATESTART
#define	STATESTART
#include "state.hpp"
#include "commandManager.hpp"
#include <iostream>

class StateStart : public State{
	
	public:
		StateStart(CommandManager* commandManager);
		virtual ~StateStart();
		void help();
		int creation();
		int play();

		/* data */
};

#endif