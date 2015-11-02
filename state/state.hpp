#ifndef STATE
#define	STATE
#include <iostream>

class CommandManager;

class State{
	protected:
		CommandManager* manager;
	public:
		State(CommandManager* commandManager);
		virtual ~State() = 0;
	
		//nb de commande par ligne dans le help : 6
		virtual void help() = 0;
		virtual int exit();
		virtual int cancel();
		virtual int yes();
		virtual int no();
		virtual int character();
		virtual int monster();
		virtual int boss();
		virtual int creation();
		virtual int play();
		virtual int host();
		virtual int join();
		virtual int man();
		virtual int woman();
		virtual int random();
		virtual int custom();
		virtual int attack();
		virtual int elf();
		virtual int orc();
		virtual int human();
		virtual int dwarf();
		virtual int warrior();
		virtual int mage();
		virtual int priest();
		virtual int paladin();
		virtual int hunter();
		virtual int rogue();

		virtual int what();
		virtual void error();

};

#endif