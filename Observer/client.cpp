/**
* @file client.cpp
* @brief Classe cliente
* @author VANONI Joachim
* 
* Classe de connexion à un serveur, d'envoi et réception de message.
*/
#include "client.hpp"

/**
* @fn Client()
* @brief Constructeur de @class Client client.cpp
*
* @param
* @return
*/
Client::Client() : userName(""){   
}

/**
* @fn ~Client()
* @brief Destructeur de @class Client client.cpp
*
* @param
* @return
*/
Client::~Client(){
}

/**
* @fn void init()
* @brief Méthode qui initialise la connexion.
*
* Methode qui demande à l'utilisateur son pseudo, le port du serveur ainsi que son adresse
* puis tente de se connecter. Por finir le thread d'écoute et d'envoie de message sont créés.
* @param
* @return
*/
void Client::init(){

    haveMessageToSend = false;
    clientHaveQuit = false;

    std::cout << "Username ?" << std::endl;
    std::cin >> userName;

	std::string rep;
    std::cout << "Avant de vous connecter, soyez sur que le MJ à crée un serveur !" << std::endl;
	std::cout << "Sur quel port voulez vous vous connecter ?\nLes ports valide vont de 1000 à 65535.\nDemandez à votre MJ pour connaitre le port" << std::endl;
	std::cin >> rep;

	//char* plop = (char*)rep.c_str(); //transformation en char* de la réponse

	portno = stoi(rep);

	if(portno <= 999 || portno > 65535){
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
    threadReceive = new std::thread(&Client::receiveThreading, this);
    //création du thread d'envoi
    threadSend = new std::thread(&Client::sendThreading, this, this);
    
}

/**
* @fn void receiveThreading()
* @brief Méthode tampon appelé par le thread de récéption de message.
*
* @param
* @return
*/
void Client::receiveThreading(){
    std::cout << "Thread écoute crée !" << std::endl;
    while(!clientHaveQuit){
        receive();
    }
}

/**
* @fn void sendThreading(Client *cli)
* @brief Méthode tampon appelé par le thread d'envoi de message.
*
* N'appele la fonction send que si le client a un message à envoyer. Le pointeur
* vers un client est necessaire pour récuppérer les données du client d'origine et non
* pas le duplicat créé par les threads.
* @param cli Pointeur vers le client
* @return
*/
void Client::sendThreading(Client *cli){
    std::cout << "Thread écriture crée !" << std::endl;
    while(!clientHaveQuit){
        if(cli->getMessageToSend()){
            send(cli->getMessage());
            cli->setHaveMessageToSend(false);
        }
    }
}

/**
* @fn void send
* @brief Méthode d'envoie de messages.
*
* @param mess string contenant le message à envoyer
* @return
*/
void Client::send(std::string mess){
    int n;
    //transformation du méssage à envoyé en char*
    mess = userName + " dit : " +mess;
    char* sendMess = (char*)mess.c_str();

    //envoi du méssage
    n = write(sockfd,sendMess,strlen(sendMess));
    if (n < 0) 
        perror("ERROR writing to socket");

}

/**
* @fn void receive()
* @brief Méthode qui reçois et affiche le message envoyé par le serveur.
*
* @param
* @return
*/
void Client::receive(){
    int n;
    char buffer [256];
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) perror("ERROR reading from socket");
    if(buffer[0] != 0){
        std::cout << std::string(200,'\b');
        std::cout << buffer << std::endl;
    }

}


////////////////////////////////////////////////////////////
// GETTERS SETTERS
void Client::setHaveMessageToSend(bool b){
    haveMessageToSend = b;
}

void Client::setMessage(std::string mes){
    message = mes;
}

bool Client::getMessageToSend(){
    std::cout << ""; //A NE PAS SUPPRIMER
    return haveMessageToSend;
}

std::string Client::getMessage(){
    return message;
}

void Client::setUserName(std::string name){
    userName = name;
}