#include "server.hpp"

Server::Server(){

}

Server::~Server(){


}

void Server::addClient(int c){
	clients.push_back(c);
}

void Server::removeClient(int c){

}

void Server::notifyClient(){
	 for (int &cli : clients) {
	 	//cli.send("hello");
        std::cout << cli << std::endl;
	 }
}

void Server::init(){

    haveMessageToSend = false;
    hostHaveQuit = false;

	std::string rep;
	std::cout << "Quel port voulez vous utilisé ?\nLes port valide vont de 1 à 65535." << std::endl;
	std::cin >> rep;

	//char* plop = (char*)rep.c_str();

	portno = stoi(rep);

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

    //création du thread de connexion
    threadConnect = std::thread(&Server::connectThreading, this);

}

void Server::connectThreading(){
    std::cout << "pré listen" <<std::endl;
    listen(sockfd,5);            //autorisation à passer en mode écoute
    struct sockaddr_in cli_addr; //création du client
    socklen_t clilen;
    clilen = sizeof(cli_addr);
    std::cout << "début de boucle" <<std::endl;
    while(!hostHaveQuit){
        std::cout << "attente" <<std::endl;
        clients.push_back(accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen));
        if (clients.back() < 0){
            perror("ERROR on accept");
        }else{
            //un client est connecter
            //création d'un thread d'écoute pour le nouveau client

            threadsReceive.push_back(std::thread(&Server::receiveThreading, this, clients.size()-1));
        }
    }
}

void Server::receiveThreading(int pos){
    std::cout << "Thread écoute crée !" << std::endl;
    while(!hostHaveQuit){
        std::cout << "méssage recu" << std::endl;
        receive(clients.at(pos));
    }
}

void Server::receive(int cliSockfr){
    int n;
    char buffer [256];
    bzero(buffer,256);
    n = read(cliSockfr,buffer,255);
    if (n < 0) perror("ERROR reading from socket");
    std::cout << buffer << std::endl;
    send(buffer);
}

void Server::send(char* mess){

    int n;
    std::cout << "envoi du méssage" << std::endl;

    //envoi du méssage
    for(int cli : clients){
        n = write(cli,mess,strlen(mess));
        if (n < 0) 
            perror("ERROR writing to socket");
    }
}