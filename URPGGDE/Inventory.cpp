#include "Inventory.hpp"


Inventory::Inventory(std::string weapon1, std::string weapon2, std::string shield, std::string headEquip, std::string torsoEquip, std::string legEquip, std::string footEquip){
	this->weapon1 = weapon1;
	this->weapon2 = weapon2;
	this->shield = shield;
	this->headEquip = headEquip;
	this->torsoEquip = torsoEquip;
	this->legsEquip = legEquip;
	this->footEquip = footEquip;
}

////////////////////////////////////////////////////////////////////////////////
// Getters Setters START

std::string Inventory::getBag(){
	std::string res;
	for(int i = 0; i<= 20; i++){
		if(bag[i] != NULL)
		res += bag[i]+", ";
	}
	return res;
}

void Inventory::addBag(std::string obj){
	for(int i = 0; i <= 20 ; i++){
		if(bag[i] == NULL){
			bag[i] = obj;
		}
	}
}

void Inventory::deleteBag(std::string obj){
	for(int i = 0; i <= 20; i++){
		if(bag[i] == obj){
			bag[i] = NULL;
		}
	}
}

int Inventory::freeBagSpace(){
	int cpt = 0;
	for(int i = 0; i <= 20; i++){
		if(bag[i] != NULL){
			cpt += 1;
		}
	}
	return cpt;
}

//Get Set weapon1 and weapon2
std::string Inventory::getWeapon1(){
	return weapon1;
}
void Inventory::setWeapon1(std::string w1){
	weapon1 = w1;
}

std::string Inventory::getWeapon2(){
	return weapon2;
}
void Inventory::setWeapon2(std::string w2){
	weapon2 = w2;
}
//Get Set shield
std::string Inventory::getShield(){
	return shield;
}
void Inventory::setShield(std::string shld){
	shield = shld;
}
//Get Set head, torso, legs, foot
std::string Inventory::getHeadEquip(){
	return headEquip;
}
void Inventory::setHeadEquip(std::string heq){
	headEquip = heq;
}
std::string Inventory::getTorsoEquip(){
	return torsoEquip;
}
void Inventory::setTorsoEquip(std::string teq){
	torsoEquip = teq;
}
std::string Inventory::getLegsEquip(){
	return legsEquip;
}
void Inventory::setLegsEquip(std::string leq){
	legsEquip = leq;
}
std::string Inventory::getFootEquip(){
	return footEquip;
}
void Inventory::setFootEquip(std::string feq){
	footEquip = feq;
}
