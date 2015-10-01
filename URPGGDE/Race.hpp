/*
 * Race.hpp
 *
 *  Created on: 1 oct. 2015
 *      Author: Xavier
 */

#ifndef RACE_HPP_
#define RACE_HPP_

#include <string>;

class Race{
	protected:

	public:
		virtual ~Race();
		virtual int randomLife(int, int);
		virtual int randomMana(int, int);

		virtual int randomStrength(int, int);
		virtual int randomConstitution(int, int);
		virtual int randomDexterity(int, int);
		virtual int randomIntelligence(int, int);
		virtual int randomWisdom(int, int);
		virtual int randomCharisma(int, int);

		virtual int randomAttack(int, int);
		virtual int randomDefense(int, int);

	// Getters Setters START
		int getRandomLife(void);
		void setRandomLife(int);
		int getRandomMana(void);
		void setRandomMana(int);

		int getRandomStrength(void);
		void setRandomStrength(int);
		int getRandomConstitution(void);
		void setRandomConstitution(int);
		int getRandomDexterity(void);
		void setRandomDexterity(int);
		int getRandomIntelligence(void);
		void setRandomIntelligence(int);
		int getRandomWisdom(void);
		void setRandomWisdom(int);
		int getRandomCharisma(void);
		void setRandomCharisma(int);

		int getRandomAttack(void);
		void setRandomAttack(int);
		int getRandomDefense(void);
		void setRandomDefense(int);
	// Getters Setters END

};




#endif /* RACE_HPP_ */
