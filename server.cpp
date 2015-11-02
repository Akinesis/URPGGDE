/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <time.h>
#include <vector>

bool stop = false;
std::vector<int> clients;
std::vector<sockaddr_in> cli_addrS;
void clientConnect(int sockfd);
void notifClient(int sender, char buffer[]);
void *conectThreading( void *ptr );
void removeClient(int newsockfd);

void setStop(){
    stop = true;
}

struct socketStruc{
    char buffer[256];
    int cliSockfd;
};

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

bool receivMess(char buffer[], int newsockfd){
    int n;
    bzero(buffer,256);
    n = read(newsockfd,buffer,255);
    bool ret = false;
    if (n < 0) error("ERROR reading from socket");
    if(buffer == "#stop"){
        strcpy(buffer, "client déconecter");
        std::cout << "déconexion" << std::endl;
        removeClient(newsockfd);
        ret = true;
    }
    printf("Here is the message: %s\n",buffer);
    notifClient(newsockfd, buffer);

    return ret;

}

void sendMess(char buffer[], int sockfd){
    int n;
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");
    bzero(buffer,256);
}

void *receiveThreading( void *ptr ){
    socketStruc* sock = (socketStruc *) ptr;
    std::cout << sock->buffer << std::endl;
    bool ret = false;

    while(!stop){
        ret = receivMess(sock->buffer, sock->cliSockfd);
    }

    close(sock->cliSockfd);
}

void *conectThreading( void *ptr ){
    int sockfd =  *((int *)&ptr);
    std::cout << "pré listen" <<std::endl;
    listen(sockfd,5);
    struct sockaddr_in cli_addr;
    socklen_t clilen;
    clilen = sizeof(cli_addr);
    std::cout << "début de boucle" <<std::endl;
    while(!stop){
        std::cout << "attente" <<std::endl;
        clients.push_back(accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen));
        if (clients.back() < 0){
            error("ERROR on accept");
        }else{
            cli_addrS.push_back(cli_addr);

            //création d'un thread d'écoute pour le nouveau client
            socketStruc socketInfo;
            pthread_t threadReceive;
            int iretReceive;

            socketInfo.cliSockfd = clients.back();
            void* voidCast = &socketInfo;

            std::cout << "conecter" <<std::endl;
            iretReceive = pthread_create( &threadReceive, NULL, receiveThreading, voidCast);
             if(iretReceive){
                fprintf(stderr,"Error - pthread_create() return code: %d\n",iretReceive);
                exit(EXIT_FAILURE);
            }
        }
    }


}

void notifClient(int sender, char buffer[]){
    int i;
    for(i = 0; i < clients.size(); i++ ){
        if(clients.at(i) != sender){
            sendMess(buffer, clients.at(i));
        }
    }
}

void removeClient(int newsockfd){
    int i;
    std::cout << "supretion" << std::endl;
    for(i = 0; i < clients.size(); i++){
        if(clients.at(i)==newsockfd){
            std::cout << "trouver" << std::endl;
            clients.erase(clients.begin()+i);
            cli_addrS.erase(cli_addrS.begin()+i);
        }
    }
}

int main(int argc, char *argv[]){
    int sockfd, newsockfd, portno;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    pthread_t threadReceive, threadConnect;
    int iretReceive, iretConnect;
    socketStruc socketInfo;
    void* voidCast;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    //configuration du serveur
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    //bind du socket et test de réussite
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
          sizeof(serv_addr)) < 0) 
          error("ERROR on binding");
    std::cout << "socket crée" <<std::endl;
    // attente d'un client
    /*listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, 
             (struct sockaddr *) &cli_addr, 
             &clilen);
    if (newsockfd < 0) 
      error("ERROR on accept");*/
    //un client est accepter

    iretConnect = pthread_create( &threadConnect, NULL, conectThreading, (void *) sockfd);
    if(iretConnect){
        fprintf(stderr,"Error - pthread_create() return code: %d\n",iretConnect);
        exit(EXIT_FAILURE);
    }

    while(!stop){

    }
    
    //fermeture du client
    //close(newsockfd);
    //fermeture du serveur
    close(sockfd);
    return 0; 
}
