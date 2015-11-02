#ifndef STATESTART
#define	STATESTART
#include "state.hpp"
#include "commandManager.hpp"

class StateStart : public State{
	
	public:
		StateStart(CommandManager* commandManager);
		virtual ~StateStart();
		void help();
		int creation();

		/* data */
};

#endif