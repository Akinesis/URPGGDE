#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <string>
#include <iostream>
#include <pthread.h>
#include <time.h>

bool stop = false;

void setStop(){
    stop = true;
}

struct socketStruc{
    char buffer[256];
    int newsockfd;
};

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void receivMess(char buffer[], int newsockfd){
    int n;
    bzero(buffer,256);
    n = read(newsockfd,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    printf("Here is the message: %s\n",buffer);
}

int sendMess(char buffer[], int sockfd){
    int n;
    std::string message;
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    message = buffer;

    if(message != "/stop\n"){
        n = write(sockfd,buffer,strlen(buffer));
        if (n < 0) 
            error("ERROR writing to socket");
        bzero(buffer,256);
        return 1;
    }else{
        strcpy(buffer, "#stop");
        n = write(sockfd,buffer,strlen(buffer));
        if (n < 0) 
            error("ERROR writing to socket");
        bzero(buffer,256);
        return 0;
    }
}

void *sendThreading( void *ptr ){
    socketStruc* sock = (socketStruc *) ptr;
    std::cout << sock->buffer << std::endl;

    while(!stop){
        receivMess(sock->buffer, sock->newsockfd);
    }
}

void *receiveThreading( void *ptr ){
    socketStruc* sock = (socketStruc *) ptr;
    std::cout << sock->buffer << std::endl;

    while(!stop){
        if(!sendMess(sock->buffer, sock->newsockfd)){
            setStop();
        }
    }
}

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    pthread_t threadSend, threadReceive;
    int  iretSend, iretReceive;
    socketStruc socketInfo;
    void* voidCast;

    //récupération du port
    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    //ouverture du socket sur le port;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    //récupération addresse serveur
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    //configuration dus erveur
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    //tentative de connexion au serveur
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    strcpy(socketInfo.buffer, buffer);
    socketInfo.newsockfd = sockfd;

    voidCast = &socketInfo;

    iretReceive = pthread_create( &threadReceive, NULL, receiveThreading, voidCast);
    if(iretReceive){
        fprintf(stderr,"Error - pthread_create() return code: %d\n",iretReceive);
        exit(EXIT_FAILURE);
    }

    iretSend = pthread_create( &threadSend, NULL, sendThreading, voidCast);
    if(iretSend){
        fprintf(stderr,"Error - pthread_create() return code: %d\n",iretSend);
        exit(EXIT_FAILURE);
    }

    while(!stop){
    }
    close(sockfd);
    return 0;
}
