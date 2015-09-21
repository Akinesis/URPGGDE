#include "mySocket.h"
#include "myLog.h"
#include "myException.h"
#include "myHostInfo.h"

int main(){

int PORTNUM = 443;

myHostInfo uHostAddress;
string localHostName = uHostAddress.getHostName();
string localHostAddr = uHostAddress.getHostIPAddress();
std::cout << "----------------------------------------" << std::endl;
std::cout << "   My local host information:" << std::endl;
std::cout << "         Name:    " << localHostName << std::endl;
std::cout << "         Address: " << localHostAddr << std::endl;
std::cout << "----------------------------------------" << std::endl;

// open socket on the local host
myTcpSocket myServer(PORTNUM);
std::cout << myServer;

myServer.bindSocket();
std::cout   << std::endl << "server finishes binding process... " << std::endl;

myServer.listenToClient();
std::cout   << "server is listening to the port ... " << std::endl;

// wait to accept a client connection.
// processing is suspended until the client connects
std::cout   << "server is waiting for client connecction ... " << std::endl;

// connection dedicated for client communication
myTcpSocket* client;
string clientHost;      // client name etc.
client = myServer.acceptClient(clientHost);

std::cout   << std::endl << "==> A client from [" << clientHost
       << "] is connected!" << std::endl << std::endl;

while(1){
   string clientMessageIn = "";

   // receive from the client

   int numBytes = client->recieveMessage(clientMessageIn);
   if ( numBytes == -99 ) break;

   std::cout   << "[RECV:" << clientHost << "]: "
          << clientMessageIn << std::endl;

   // send to the clien

   char sendmsg[MAX_MSG_LEN+1];
   std::memset(sendmsg,0,sizeof(sendmsg));
   std::cout << "[" << localHostName << ":SEND] ";
   std::cin.getline(sendmsg,MAX_MSG_LEN);

   if ( numBytes == -99 ) break;
   string sendMsg(sendmsg);
   if ( sendMsg.compare("Bye") == 0 || sendMsg.compare("bye") == 0 )
      break;

   client->sendMessage(sendMsg);

}


return 1;
}
