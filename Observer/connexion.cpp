/**
* @file connexion.cpp
* @brief Classe interface entre client/serveur et commandManager.
* @author VANONI Joachim
* 
* Classe qui possède un client un serveur et qui s'occupe de faire les traitements adéquats.
*/
#include "connexion.hpp"

/**
* @fn Connexion()
* @brief Constructeur de @class Connexion connexion.cpp
*
* @param
* @return
*/
Connexion::Connexion(){
}

/**
* @fn void ~Connexion
* @brief Destructeur de @class Connexion connexion.cpp
*
* @param
* @return
*/
Connexion::~Connexion(){}

/**
* @fn void initServer() 
* @brief Méthode qui appel l'initialisation du serveur.
*
* @param
* @return
*/
void Connexion::initServer(){
	isServer = true;
	server.init();
}

/**
* @fn void initClient() 
* @brief Méthode qui appel l'initialisation du client.
*
* @param
* @return
*/
void Connexion::initClient(){
	isServer = false;
	client.init();
}

/**
* @fn void hostHaveMessageToSend(std::string mes)
* @brief Méthode appelé quand l'hote veut envoyer un message en son nom.
*
* @param mes string contenant le message à envoyer.
* @return
*/
void Connexion::hostHaveMessageToSend(std::string mes){
	mes = server.getUserName() + " dit : " + mes;
	char* ret = (char*)mes.c_str();
	server.send(ret);
}

/**
* @fn void clientHaveMessageToSend(std::string mes)
* @brief Méthode appelé quand le client veut envoyer un message.
*
* @param mes string contenant le message à envoyer.
* @return
*/
void Connexion::clientHaveMessageToSend(std::string mes){
	client.setMessage(mes);
	client.setHaveMessageToSend(true);
}

void Connexion::setUserName(){
	std::cout << "Quel seras votre pseudonyme ?" << std::endl;
	std::cin >> userName;
	std::cout << "Bonjour " << userName << " !" << std::endl;
}

std::string Connexion::getUserName(){
	return userName;
}

bool Connexion::getIsServer(){
	return isServer;
}