/*
 * Classes.hpp
 *
 *  Created on: 7 oct. 2015
 *      Author: E139824H
 */

#ifndef CLASSES_HPP_
#define CLASSES_HPP_


class Classes{
	private:
		std::string className;

		int modifStrength;
		int modifConstitution;
		int modifDexterity;
		int modifIntelligence;
		int modifWisdom;
		int modifCharisma;

	public:
		Classes(std::string, int, int, int, int, int, int);
		~Classes(std::string, int, int, int, int, int, int);

		void applyModifications(Character);
		void createPaladin(Character);
		void createWarrior(Character);
		void createMage(Character);
		void createHunter(Character);
		void createThief(Character);

		//Getters Setters
		int getModifStrength();
		int getModifConstitution();
		int getModifDexterity();
		int getModifIntelligence();
		int getModifWisdom();
		int getModifCharisma();


};


#endif /* CLASSES_HPP_ */
