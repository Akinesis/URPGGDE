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
#include <vector>
#include <thread>

class Server : public Subject{

	private:
		int sockfd, newsockfd, portno; 	//Le socket initial et celui du server ainsi que le port
		std::vector<int> clients;   	//la liste des clients
		struct sockaddr_in serv_addr;  	//L'addresse du serveur


		std::thread threadConnect;
		std::vector<std::thread> threadsReceive;
		bool haveMessageToSend, hostHaveQuit;
		//fonction de thread
		void connectThreading();
		void receiveThreading(int pos);
		void receive(int cliSockfr);

	public:
		Server();
		virtual ~Server();
		void addClient(int c);
		void removeClient(int c);
		void notifyClient();

		void init();
		void send(char* mess);
};

#endif