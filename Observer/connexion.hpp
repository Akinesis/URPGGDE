#ifndef CONNEXION
#define CONNEXION
#include "server.hpp"
#include "client.hpp"

class Connexion{

	private:
		Server server;
		Client client;
	public:
		Connexion();
		~Connexion();

		void initServer();
		void initClient();

};

#endif