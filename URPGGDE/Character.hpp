#ifndef _Character;
#define _Character;

#include <string>

class Character {

	public:

	// Getters Setters START
		void setName(std::string n);
		std::string getName();

		void setLifePoints(int lPoints);
		int getLifePoints();
		void setManaPoint(int mPoints);
		int getManaPoints();

		void setStrength(int str);
		int getStrength();
		void setConstitution(int cons);
		int getConstitution();
		void setDexterity(int dex);
		int getDexterity();
		void setIntelligence(int intel);
		int getIntelligence();
		void setWisdom(int wisd);
		int getWisdom();
		void setCharisma(int cha);
		int getCharisma();
	// Getters Setters END

	private:
		virtual std::string name;

		virtual int lifePoints;
		virtual int manaPoints;

		virtual int strength;
		virtual int constitution;
		virtual int dexterity;
		virtual int intelligence;
		virtual int wisdom;
		virtual int charisma;
};


#endif



