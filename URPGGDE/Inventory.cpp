#include "Inventory.hpp"


Inventory::Inventory(){}

Inventory::~Inventory(){}

////////////////////////////////////////////////////////////////////////////////
// Getters Setters START

std::string Inventory::getBag(){
	std::string bagContent = "";
	for(int i = 0; i < bag.size(); i++){
		bagContent += bag.at(i)+", ";
	}
	return bagContent;
}

void Inventory::addBag(std::string obj){
	bag.push_back(obj);
}

void Inventory::deleteBag(std::string obj){
	for(int i = 0 ; i < bag.size(); i++){
		if(bag.at(i) == obj){
			bag.erase(bag.begin()+(i-1));
		}
	}
}

int Inventory::freeBagSpace(){
	return maxBagCapacity - bag.size();
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
//Get Set maxBagCapacity
int Inventory::getMaxBagCapacity(){
	return maxBagCapacity;
}
void Inventory::setMaxBagCapacity(int max){
	maxBagCapacity = max;
}
