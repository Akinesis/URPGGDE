#ifndef STATEPLAY
#define	STATEPLAY
#include "state.hpp"
#include "commandManager.hpp"

class StatePlay : public State{
	
	public:
		StatePlay(CommandManager* commandManager);
		virtual ~StatePlay();
		void help();
		int join();
		int host();
		int exit();

		/* data */
};

#endif