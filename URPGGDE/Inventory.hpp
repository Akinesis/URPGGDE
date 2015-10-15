/*
 * Inventory.hpp
 *
 *  Created on: 25 sept. 2015
 *      Author: Xavier
 */

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

#include <string>
#include <stdlib.h>
#include <cstddef>
#include <vector>

class Inventory{
	private:
		std::string weapon1;
		std::string weapon2;
		std::string shield;

		std::string headEquip;
		std::string torsoEquip;
		std::string legsEquip;
		std::string footEquip;

		std::vector<std::string> bag;
		int maxBagCapacity;

	public:
		Inventory(std::string, std::string, std::string, std::string, std::string, std::string, std::string, int);
		~Inventory();

	//Getters and Setters
		std::string getWeapon1();
		void setWeapon1(std::string);
		std::string getWeapon2();
		void setWeapon2(std::string);
		std::string getShield();
		void setShield(std::string);

		std::string getHeadEquip();
		void setHeadEquip(std::string);
		std::string getTorsoEquip();
		void setTorsoEquip(std::string);
		std::string getLegsEquip();
		void setLegsEquip(std::string);
		std::string getFootEquip();
		void setFootEquip(std::string);

		std::string getBag();
		void addBag(std::string);
		void deleteBag(std::string);
		int freeBagSpace();

		int getMaxBagCapacity();
		void setMaxBagCapacity(int);
};


#endif /* INVENTORY_HPP_ */
