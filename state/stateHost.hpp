#ifndef STATEHOST
#define STATEHOST
#include "state.hpp"
#include "commandManager.hpp"

class StateHost : public State{

	public:
		StateHost(CommandManager* commandManager);
		virtual ~StateHost();
		void help();
		int join();

};

#endif