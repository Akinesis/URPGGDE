/**
* @file server.cpp
* @brief Classe serveur.
* @author VANONI Joachim
* 
* Classe qui accèpte les connexions des clients et qui leur transmet les messages.
* Le MJ est forcement le serveur.
*/
#include "server.hpp"

/**
* @fn Server()
* @brief Constructeur de @class Server server.cpp
*
* @param
* @return
*/
Server::Server(){

}

/**
* @fn Server()
* @brief Destructeur de @class Server server.cpp
*
* @param
* @return
*/
Server::~Server(){


}

/**
* @fn void init()
* @brief Méthode qui initialise la connexion.
*
* Methode qui demande à l'utilisateur son pseudo et le port à utiliser puis tente de se connecter.
* Por finir le thread de réception de client est créé.
* @param
* @return
*/
void Server::init(){

    haveMessageToSend = false;
    hostHaveQuit = false;

    std::cout << "Username ?" << std::endl;
    std::cin >> userName;

    clients = new std::vector<int>();
    threadsReceive = new std::vector<std::thread>;

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

    //création du thread de connexion
    threadConnect = std::thread(&Server::connectThreading, this, clients, threadsReceive);

}

/**
* @fn void connectThreading(std::vector<int> *cli, std::vector<std::thread> *threads)
* @brief Le thread de connexion des client au serveur.
*
* @param std::vector<int> *cli La liste des clients
* @param std::vector<std::thread> *threads Tout les thread d'écoute
* @return
*/
void Server::connectThreading(std::vector<int> *cli, std::vector<std::thread> *threads){
    std::cout << "pré listen" <<std::endl;
    listen(sockfd,5);            //autorisation à passer en mode écoute
    struct sockaddr_in cli_addr; //création du client
    socklen_t clilen;
    clilen = sizeof(cli_addr);
    while(!hostHaveQuit){
        cli->push_back(accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen));
        if (cli->back() < 0){
            perror("ERROR on accept");
        }else{
            //un client est connecter
            //création d'un thread d'écoute pour le nouveau client
            threads->push_back(std::thread(&Server::receiveThreading, this, cli->back()));
        }
    }
}

/**
* @fn void receiveThreading(int sock)
* @brief Le thread d'écoute d'un cleint spécifique
*
* @param sock int Le client à écouter.
* @return
*/
void Server::receiveThreading(int sock){
    std::cout << "Thread écoute crée !" << std::endl;
    while(!hostHaveQuit){
        receive(sock);
    }
}

/**
* @fn void receive(int cliSockRe)
* @brief La méthode d'écoute d'un client spécifique
*
* @param cliSockRe int Le client à écouter.
* @return
*/
void Server::receive(int cliSockRe){
    int n;
    char buffer [256];
    bzero(buffer,256);
    n = read(cliSockRe,buffer,255);
    if (n < 0) perror("ERROR reading from socket");
    if(buffer[0] != 0){ //n'écrire que si il y à un méssage
        std::cout << std::string(200,'\b');
        std::cout << buffer << std::endl;
        send(buffer, cliSockRe); //notifie tout les clients
    }
}

/**
* @fn void send(char* mess)
* @brief La méthode d'envoi de méssage à tout les clients au nom du serveur.
*
* @param mess char* Le méssage du serveur.
* @return
*/
void Server::send(char* mess){
    int n;
    //envoi du méssage
    for(int i =0; i<clients->size(); ++i){
        n = write(clients->at(i),mess,strlen(mess));
        if (n < 0) 
            perror("ERROR writing to socket");
    }
}

/**
* @fn void send(char* mess, int exep)
* @brief La méthode de notification de tout les clients.
*
* Cette méthode est appelée quand un client envoi un méssage, il est alors
* véiculé à tout les autres clients.
* @param mess char* Le méssage du client.
* @param exep int Le client à ne pas notifier.
* @return
*/
void Server::send(char* mess, int exep){
    int n;
    //envoi du méssage
    for(int i =0; i<clients->size(); ++i){
        if(clients->at(i) != exep){
            n = write(clients->at(i),mess,strlen(mess));
            if (n < 0) 
                perror("ERROR writing to socket");
        }
    }
}

///////////////////////////////////////////////////////////////
// GETTERS SETTERS

void Server::setUserName(std::string name){
    userName = name;
}

bool Server::getMessageToSend(){
    return haveMessageToSend;
}

void Server::setHaveMessageToSend(bool b){
    haveMessageToSend = b;
}

void Server::setMessage(std::string mes){
    message = mes;
}

std::string Server::getMessage(){
    return message;
}

std::vector<int>* Server::getClients(){
    return clients;
}
std::string Server::getUserName(){
    return userName;
}