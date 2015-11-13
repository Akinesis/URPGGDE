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
#include <iostream>
#include <pthread.h>
#include <time.h>

class Client{
	private:
		int sockfd, portno; 				//Le socket du serveur et le port de connexion
		struct sockaddr_in serv_addr;   	//L'addresse du serveur
    	struct hostent *server;				//Nécéssaire à la création du serveur

    	pthread_t threadSend, threadReceive;//Les thread pour l'envoi et la reception de méssages
    	void *receiveThreading( void *ptr );//La fonction thread de réception
    	bool haveMessageToSend;
	public:
		Client();
		~Client();
		void send(std::string message);
		void receive();

		void init();

};

#endif