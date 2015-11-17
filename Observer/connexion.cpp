#include "connexion.hpp"

Connexion::Connexion(){
}

Connexion::~Connexion(){}

void Connexion::initServer(){
	server.init();
}

void Connexion::initClient(){
	client.init();
}

void Connexion::setUserName(){
	std::cout << "Quel seras votre pseudonyme ?" << std::endl;
	std::cin >> userName;
	std::cout << "Bonjour " << userName << " !" << std::endl;
}

std::string Connexion::getUserName(){
	return userName;
}

void Connexion::clientHaveMessageToSend(std::string mes){
	client.setHaveMessageToSend(true);
	client.setMessage(mes);
}

void Connexion::hostHaveMessageToSend(std::string mes){
	mes = server.getUserName() + " dit : " + mes;
	char* ret = (char*)mes.c_str();
	server.send(ret);
}