#ifndef STATEJOIN
#define STATEJOIN
#include "state.hpp"
#include "commandManager.hpp"

class StateJoin : public State{

	public:
		StateJoin(CommandManager* commandManager);
		virtual ~StateJoin();
		void help();
		int join();

};

#endif