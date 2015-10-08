#ifndef STATE
#define	STATE
#include <iostream>

class State{
	private:

	public:
		State();
		~State();
	
		virtual int help();
		virtual int oui();
		virtual int non();
		virtual int personnage();
		virtual int monstre();
		virtual int boss();
		virtual int creation();
		virtual int jouer();
		virtual int hote();
		virtual int rejoindre();
		virtual int homme();
		virtual int femme();
		virtual int aleatoire();
		virtual int attaquer();
		virtual int elfe();
		virtual int orc();
		virtual int huamin();
		virtual int nain();
		virtual int guerrier();
		virtual int mage();
		virtual int pretre();
		virtual int paladin();
		virtual int chasseur();
		virtual int roublard();

};

#endif