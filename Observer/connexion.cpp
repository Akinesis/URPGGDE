#include "connexion.hpp"
#include "server.hpp"

Connexion::Connexion() : server(Server()){
}

Connexion::~Connexion(){}

void Connexion::initServer(){
	server.init();
}

void Connexion::initClient(){
	client.init();
}