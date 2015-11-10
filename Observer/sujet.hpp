#ifndef SUBJECT
#define SUBJECT
#include "client.hpp"

class Subject{

	public:
		virtual void addClient(Client c) = 0;
		virtual void removeClient(Client c) = 0;
		virtual void notifyClient() =0;


};

#endif