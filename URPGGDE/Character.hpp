#ifndef _Character;
#define _Character;

#include <string>

class Character {
	protected:
		std::string name;

		int lifePoints;
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

	public:
		Character(std::string, int, int, int, int, int, int, int, int, int, int, int, int);
		virtual ~Character();
		virtual std::string performAttack();
		virtual std::string defend();

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

		int getAttack();
		void setAttack(int att);
		int getDefense();
		void setDefense(int def);

		int getProtection();
		void setProtection(int pr);

		int getLevel();
		void setLevel(int l);
	// Getters Setters END

};

#endif


