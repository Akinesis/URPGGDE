/**
* @file Config.cpp
* @brief Classe de configuraton
* @author HERAUD Xavier 
* 
* Classe qui gère le fichier cfg.ini qui mui-même gère les sauvegardes.
*/
#include "Config.hpp"

/**
* @fn
* @brief 
*
* @param
* @return
*/
Config::Config() {}
/**
* @fn
* @brief 
*
* @param
* @return
*/
Config::~Config() {}

/**
* @fn
* @brief 
*
* @param
* @return
*/
void Config::initialize(){
	std::ifstream cfgFile("cfg.ini", std::ios::in);
	if(cfgFile){
		std::string chaine;
		cfgFile >> chaine;
		cfgFile >> chaine;
		numberPNJSaves = std::stoi(chaine);
		cfgFile >> chaine;
		cfgFile >> chaine;
		numberMonsterSaves = std::stoi(chaine);
		cfgFile >> chaine;
		cfgFile >> chaine;
		numberBossSaves = std::stoi(chaine); 
	}
	else{
		std::cout << "Impossible d'acceder au fichier cfg.ini" << std::endl;
	}
}

/**
* @fn
* @brief 
*
* @param
* @return
*/
void Config::updateMonsterCfg(){
	std::string fileName;
	DIR* rep = NULL;
	struct dirent* fichierLu = NULL;
	rep = opendir("Saves/Monster/");

	if(rep == NULL){
		std::cout << "Erreur repertoire inaccessible." << std::endl;
		exit(1);
	}

	int i = 1;
	int j = 1;
	while((fichierLu = readdir(rep)) != NULL){
		if(i > 2){
			++j;
		}
		++i;
	}
	numberMonsterSaves = j;
}

/**
* @fn
* @brief 
*
* @param
* @return
*/
void Config::updatePNJCfg(){
	std::string fileName;
	DIR* rep = NULL;
	struct dirent* fichierLu = NULL;
	rep = opendir("Saves/PNJ/");

	if(rep == NULL){
		std::cout << "Erreur repertoire inaccessible." << std::endl;
		exit(1);
	}

	int i = 0;
	int j = 0;
	while((fichierLu = readdir(rep)) != NULL){
		if(i > 2){
			++j;
		}
		++i;
	}
	numberPNJSaves = i;
}

/**
* @fn
* @brief 
*
* @param
* @return
*/
void Config::updateBossCfg(){
	std::string fileName;
	DIR* rep = NULL;
	struct dirent* fichierLu = NULL;
	rep = opendir("Saves/Boss/");

	if(rep == NULL){
		std::cout << "Erreur repertoire inaccessible." << std::endl;
		exit(1);
	}

	int i = 0;
	int j = 0;
	while((fichierLu = readdir(rep)) != NULL){
		if(i > 2){
			++j;
		}
		++i;
	}
	numberBossSaves = i;
}

////////////////////////////////////////////////////////////
// GETTERS SETTERS

int Config::getNumberMonsterSaves(){
	return numberMonsterSaves;
}
int Config::getNumberBossSaves(){
	return numberBossSaves;
}
int Config::getNumberPNJSaves(){
	return numberPNJSaves;
}