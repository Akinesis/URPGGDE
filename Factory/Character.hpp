#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>

#include "Race.hpp"
#include "Classes.hpp"
#include "Inventory.hpp"

class Character {
	protected:
		std::string name;
		std::string sexe;
		Race* race;
		Classes* classe;

		int currentLifePoints;
		int lifePoints;
		int currentManaPoints;
		int manaPoints;

		int strength;
		int constitution;
		int dexterity;
		int intelligence;
		int wisdom;
		int charisma;

		int attack;
		int defense;

		int protection;

		int level;
		int bagCapacity;
		Inventory* bag;

	public:
		Character();
		virtual ~Character() = 0;
		virtual std::string performAttack() = 0;
		virtual std::string defend() = 0;

		void applyMinStat();
		void applyModifications();


	// Getters Setters START
		void setName(std::string n);
		virtual void setRandomName() = 0;
		std::string getName();

		virtual void setRandomLastName() = 0;
		virtual void setLastName(std::string) = 0;
		virtual std::string getLastName() = 0;

		void setSexe(std::string);
		std::string getSexe();

		Race* getRace();

		Classes* getClasse();

		Inventory* getBag();

		void setCurrentLifePoints(int);
		int getCurrentLifePoints();
		void setLifePoints(int);
		int getLifePoints();
		void setCurrentManaPoints(int);
		int getCurrentManaPoints();
		void setManaPoint(int);
		int getManaPoints();

		void setStrength(int);
		int getStrength();
		void setConstitution(int);
		int getConstitution();
		void setDexterity(int);
		int getDexterity();
		void setIntelligence(int);
		int getIntelligence();
		void setWisdom(int);
		int getWisdom();
		void setCharisma(int);
		int getCharisma();

		void setAttack(int);
		int getAttack();
		void setDefense(int);
		int getDefense();

		void setProtection(int);
		int getProtection();
	// Getters Setters END

	// Getters Setters pour Monster
		virtual int getDommagesDe()=0;
		virtual void setDommagesDe(int)=0;
		virtual int getDommagesAdditionnels()=0;
		virtual void setDommagesAdditionnels(int)=0;

};

#endif /* CHARACTER_HPP_ */

