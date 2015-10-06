#ifndef _Character;
#define _Character;

<<<<<<< HEAD
#include <string>

class Character {

	public:
=======
#include <string>;

class Character {
	protected:
		std::string name;
		std::string sexe;
		Race race;

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
		int bagCapacity;
		Inventory bag;

	public:
		Character(std::string, std::string, int, int, int, int, int, int, int, int, int, int, int, int, int, Inventory);
		virtual ~Character();
		virtual std::string performAttack();
		virtual std::string defend();
>>>>>>> f65488f031f314e53ee45a12ed717564fbc773fe

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
<<<<<<< HEAD
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



=======

		int getAttack();
		void setAttack(int att);
		int getDefense();
		void setDefense(int def);

		int getProtection();
		void setProtection(int pr);

		int getLevel();
		void setLevel(int l);

		int getBagCapacity();
		void setBagCapacity(int);
	// Getters Setters END

};

#endif
>>>>>>> f65488f031f314e53ee45a12ed717564fbc773fe
