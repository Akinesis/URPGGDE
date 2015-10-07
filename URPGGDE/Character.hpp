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
		Character(std::string, std::string, Race, int, int, int, int, int, int, int, int, int, int, int, int, int, Inventory);
		virtual ~Character();
		virtual std::string performAttack();
		virtual std::string defend();
>>>>>>> f65488f031f314e53ee45a12ed717564fbc773fe

	// Getters Setters START
		void setName(std::string n);
		virtual void setRandomName(std::string);
		std::string getName();

		void setLifePoints(int);
		int getLifePoints();
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
		void setAttack(int);
		int getDefense();
		void setDefense(int);

		int getProtection();
		void setProtection(int);

		int getLevel();
		void setLevel(int);

		int getBagCapacity();
		void setBagCapacity(int);
	// Getters Setters END

};

#endif
>>>>>>> f65488f031f314e53ee45a12ed717564fbc773fe
