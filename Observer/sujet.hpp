#ifndef SUBJECT
#define SUBJECT
#include "client.hpp"

class Subject{

	public:
		virtual void addClient(int c) = 0;
		virtual void removeClient(int c) = 0;
		virtual void notifyClient() =0;


};

#endif