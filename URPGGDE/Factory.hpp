/*
 * CharacterFactory.hpp
 *
 *  Created on: 30 sept. 2015
 *      Author: E139824H
 */

#ifndef FACTORY_HPP_
#define FACTORY_HPP_


/**
 * @param
 *
 **/
class Factory{
	private:
		virtual Character chara;
		static int num;
	public:
		Factory();
		Factory(Character);
		virtual ~Factory()=0;
		virtual void createAllRandom()=0;
		virtual void createPersonalize(std::string)=0;

		void setCharacter(Character);
		int getCharacter();

};


#endif /* FACTORY_HPP_ */
