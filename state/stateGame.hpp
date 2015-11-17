#ifndef STATEGAME
#define STATEGAME
#include <iostream>
#include "state.hpp"
#include "commandManager.hpp"

class StateGame : public State{

	public:
		StateGame(CommandManager* commandManager);
		virtual ~StateGame();
		void help();
		int join();

};

#endif