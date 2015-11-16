#ifndef CONNEXION
#define CONNEXION
#include <string>
#include "server.hpp"
#include "client.hpp"

class Connexion{

	private:
		Server server;
		Client client;
		std::string userName;
	public:
		Connexion();
		~Connexion();

		void initServer();
		void initClient();

		void setUserName();
		std::string getUserName();

		void clientHaveMessageToSend(std::string mes);
		void serverHaveMessageToSend(std::string mes);

};

#endif