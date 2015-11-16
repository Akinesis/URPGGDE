#include "connexion.hpp"

Connexion::Connexion() : server(Server()){
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

void clientHaveMessageToSend(std::string mes){
	//client.setHaveMessageToSend(true);
	//client.setMessage(mes);
}

void serverHaveMessageToSend(std::string mes){

}