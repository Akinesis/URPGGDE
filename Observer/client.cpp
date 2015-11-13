#include "client.hpp"

Client::Client(){


}

Client::~Client(){


}

void Client::init(){
	std::string rep;
    std::cout << "Avant de vous connecter, soyez sur que le MJ à crée un serveur !" << std::endl;
	std::cout << "Sur quel port voulez vous vous connecter ?\nLes ports valide vont de 1 à 65535.\nDemandez à votre MJ pour connaitre le port" << std::endl;
	std::cin >> rep;

	//char* plop = (char*)rep.c_str(); //transformation en char* de la réponse

	portno = atoi(rep);

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

	plop = (char*)rep.c_str();

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
    int  iretSend, iretReceive;//Les variables de contrôle de créaion de thread

    //création du thread d'écoute et vérification de son bon fonctionement
    iretReceive = pthread_create( &threadReceive, NULL, receiveThreading, voidCast);
    if(iretReceive){
        fprintf(stderr,"Error - pthread_create() return code: %d\n",iretReceive);
        exit(EXIT_FAILURE);
    }
}

void * Client::receiveThreading( void *ptr ){
 
}

void Client::send(std::string message){


}

void Client::receive(){


}