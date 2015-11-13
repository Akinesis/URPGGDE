#include "server.hpp"

Server::Server(){



}

Server::~Server(){


}

void Server::addClient(Client c){
	clients.push_back(c);
}

void Server::removeClient(Client c){

}

void Server::notifyClient(){
	 for (Client &cli : clients) {
	 	cli.send("hello");
	 }
}

void Server::init(){

	struct sockaddr_in cli_addr;
    socklen_t clilen;
    clilen = sizeof(cli_addr);

	std::string rep;
	std::cout << "Quel port voulez vous utilisé ?\nLes port valide vont de 1 à 65535." << std::endl;
	std::cin >> rep;

	//char* plop = (char*)rep.c_str();

	portno = atoi(rep);

	if(portno <= 0 || portno > 65535){
		portno = 2020;
		std::cout << "Port invalide, le port par défaut seras utilisé." << std::endl;
	}

	std::cout << "Le port utiliser seras : " << portno << std::endl;

	//création du socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) 
        perror("ERROR opening socket");

    /*configuration du serveur*/
    //"nétoyage" de serv_addr en metant tout les byts à 0
    bzero((char *) &serv_addr, sizeof(serv_addr));
    //configuration des options du server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    //bind du socket et test de réussite
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
          sizeof(serv_addr)) < 0) 
          perror("ERROR on binding");
    std::cout << "socket crée !" <<std::endl;


    /*
    	création des troi threads : écoute, send et receive
    */


    //à thread normalement
    //listen(sockfd,5);
    //newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    //if( newsockfd < 0){
	//	perror("ERROR on accept");
	//}

}

void Server::send(std::string message){


}

void Server::receive(){


}