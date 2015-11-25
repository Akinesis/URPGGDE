/**
* @file Config.cpp
* @brief Classe de configuraton
* @author HERAUD Xavier 
* 
* Classe qui gère le fichier cfg.ini qui mui-même gère les sauvegardes.
*/
#include "Config.hpp"

/**
* @fn Config()
* @brief Constructeur de @class Config Config.hpp
*
* @param
* @return
*/
Config::Config() {}
/**
* @fn ~Config()
* @brief Destructeur de @class Config Config.hpp
*
* @param
* @return
*/
Config::~Config() {}

/**
* @fn void initialize()
* @brief Affecte aux variables de @class Config Config.cpp le nombre de sauvegardes contenu 
* dans le dossier ./Saves 
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
* @fn void updateMonsterCfg()
* @brief Comptabilise le nombre de sauvegardes dans le dossier ./Saves/Monster et modifie
* le fichier de configuration
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

	int i = 0;
	int j = 0;
	while((fichierLu = readdir(rep)) != NULL){
		if(i >= 2){
			++j;
		}
		++i;
	}
	numberMonsterSaves = j;
	
	updateCfg();
}

/**
* @fn void updatePNJCfg()
* @brief Comptabilise le nombre de sauvegardes dans le dossier ./Saves/PNJ et modifie
* le fichier de configuration
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
		if(i >= 2){
			++j;
		}
		++i;
	}
	numberPNJSaves = j;
	
	updateCfg();
}

/**
* @fn void updateBossCfg()
* @brief Comptabilise le nombre de sauvegardes dans le dossier ./Saves/Monster et modifie
* le fichier de configuration
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
		if(i >= 2){
			++j;
		}
		++i;
	}
	numberBossSaves = j;

	updateCfg();
}

void Config::updateCfg(){
	std::ofstream cfgFile("cfg.ini", std::ios::out | std::ios::trunc);
	if(cfgFile){
		cfgFile << "nbrPNJSaves= ";
		cfgFile << std::to_string(numberPNJSaves) << std::endl;
		cfgFile << "nbreMonsterSaves= ";
		cfgFile << std::to_string(numberMonsterSaves) << std::endl;
		cfgFile << "nbreBossSaves= ";
		cfgFile << std::to_string(numberBossSaves) << std::endl;
	}
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