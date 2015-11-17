#ifndef CLIENT
#define CLIENT
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <string>
#include <thread>
#include <iostream>
#include <time.h>

class Client{
	private:
		int sockfd, portno; 				//Le socket du serveur et le port de connexion
		struct sockaddr_in serv_addr;   	//L'addresse du serveur
    	struct hostent *server;				//Nécéssaire à la création du serveur

    	std::thread *threadSend, *threadReceive;//Les thread pour l'envoi et la reception de méssages
    	bool haveMessageToSend, clientHaveQuit;
    	std::string message;	//Le méssage à envoyer
    	void receiveThreading();//La fonction thread de réception
    	void sendThreading(Client *cli);	//La fonction thread d'envoi
	public:
		Client();
		~Client();
		void send(std::string mess);
		void receive();

		void init();

		void setHaveMessageToSend(bool b);
		void setMessage(std::string mes);

		bool getMessageToSend();
		std::string getMessage();

};

#endif