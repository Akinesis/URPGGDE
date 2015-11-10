#ifndef SERVER
#define SERVER
#include "sujet.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <time.h>
#include <vector>

class Server : public Subject{

	private:
		int sockfd, newsockfd, portno; //le initial et celui du server ainsi que le port
		std::vector<Client> clients;   //la liste des clients
		struct sockaddr_in serv_addr;  //l'addresse du serveur
	public:
		Server();
		virtual ~Server();
		void addClient(Client c);
		void removeClient(Client c);
		void notifyClient();

		void init();
		void send(std::string message);
		void receive();
};

#endif