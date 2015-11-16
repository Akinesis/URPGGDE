#include "client.hpp"

Client::Client(){
    haveMessageToSend = false;
    clientHaveQuit = false;
}

Client::~Client(){
}

void Client::init(){
	std::string rep;
    std::cout << "Avant de vous connecter, soyez sur que le MJ à crée un serveur !" << std::endl;
	std::cout << "Sur quel port voulez vous vous connecter ?\nLes ports valide vont de 1 à 65535.\nDemandez à votre MJ pour connaitre le port" << std::endl;
	std::cin >> rep;

	//char* plop = (char*)rep.c_str(); //transformation en char* de la réponse

	portno = stoi(rep);

	if(portno <= 0 || portno > 65535){
		portno = 2020;
		std::cout << "Port invalide, le port par défaut seras utilisé." << std::endl;
	}

	std::cout << "Le port utiliser seras : " << portno << std::endl;

	//ouverture du socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        perror("ERROR opening socket");


	std::cout << "Quel est l'addresse du serveur?\n" << std::endl;
	std::cin >> rep;

	char* plop = (char*)rep.c_str();

    //récupération addresse serveur
    server = gethostbyname(plop);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    //configuration du serveur
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    //tentative de connexion au serveur
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
        perror("ERROR connecting");
    }else{
        std::cout << "Vous êtes connecter au serveur, bon jeu !" << std::endl;
    }

    /*
        Création des deux threads : send et receive
    */

    //création du thread d'écoute
    threadReceive = std::thread(&Client::receiveThreading, this);
    //création du thread d'envoi
    threadSend = std::thread(&Client::sendThreading, this);

    threadReceive.join();
    threadSend.join();
    
}

void Client::receiveThreading(){
    std::cout << "Thread écoute crée !" << std::endl;
    while(!clientHaveQuit){
        receive();
    }
}

void Client::sendThreading(){
    std::cout << "Thread écriture crée !" << std::endl;
    while(!clientHaveQuit){
        if(haveMessageToSend){
           send(); 
        }
    }
}

void Client::send(){
    int n;
    //transformation du méssage à envoyé en char*
    char* sendMess = (char*)message.c_str();

    //envoi du méssage
    n = write(sockfd,sendMess,strlen(sendMess));
    if (n < 0) 
        perror("ERROR writing to socket");

}

void Client::receive(){
    int n;
    char buffer [256];
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) perror("ERROR reading from socket");
    std::cout << buffer;

}

void Client::setHavemessageToSend(bool b){
    haveMessageToSend = b;
}

void Client::setMessage(std::string mes){
    message = mes;
}