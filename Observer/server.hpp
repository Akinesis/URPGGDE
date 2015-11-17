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

class Server{

	private:
		std::string userName, message;	//le userName et le méssage à envoyé
		int sockfd, newsockfd, portno; 	//Le socket initial et celui du server ainsi que le port
		std::vector<int> *clients;   	//la liste des clients
		struct sockaddr_in serv_addr;  	//L'addresse du serveur


		std::thread threadConnect, threadSend;
		std::vector<std::thread> *threadsReceive;
		bool haveMessageToSend, hostHaveQuit;
		//fonction de thread
		void connectThreading(std::vector<int> *cli, std::vector<std::thread> *threads);
		void receiveThreading(int pos);
		void sendThreading(Server *serv);
		void receive(int cliSockfr);

		void send(char* mess, int exep); //Fonction de notification

	public:
		Server();
		virtual ~Server();

		void init();

		void setHaveMessageToSend(bool b);
		void setMessage(std::string mes);
		bool getMessageToSend();
		std::string getMessage();
		std::vector<int>* getClients();
		std::string getUserName();

		void send(char* mess);          //Fonction de communication

		void setUserName(std::string name);
};

#endif