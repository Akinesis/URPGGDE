#include "client.hpp"

Client::Client(){


}

Client::~Client(){


}

void Client::init(){
	std::string rep;
	std::cout << "Sur quel port voulez vous vous connecter ?\nLes ports valide vont de 1 à 65535.\nDemandez à votre MJ pour connaitre le port" << std::endl;
	std::cin >> rep;

	char* plop = (char*)rep.c_str();

	portno = atoi(plop);

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
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        perror("ERROR connecting");
}

void Client::send(std::string message){


}

void Client::receive(){


}