#include "mySocket.hpp"
#include "myLog.hpp"
#include "myException.hpp"
#include "myHostInfo.hpp"

int main()
{
    myHostInfo uHostAddress;
	string localHostName = uHostAddress.getHostName();
    string localHostAddr = uHostAddress.getHostIPAddress();
    cout << "Name: " << localHostName << endl;
    cout << "Address: " << localHostAddr << endl;

	// open socket on the local host
	mySocket localSocket(1000);
	cout << localSocket;

	// set linger on
	localSocket.setLingerOnOff(true);
	localSocket.setLingerSeconds(10);

	// show it again
	cout << endl << "After changing the socket settings ... " << endl;
	cout << localSocket;

#ifdef UNIX

    // Retrieve all entries from the host name database
    myHostInfo AllHosts;
    while(AllHosts.cGetNextHost())
    {
        cout << "Name: " << AllHosts.sGetHostName() << endl;
        cout << "Address: " << AllHosts.sGetHostAddress() << endl;
    }

#endif

#ifdef WINDOWS_XP

    // Close the winsock library
	winLog << endl << "system shut down ...";

	try
	{
		if (WSACleanup())
		{
			myException* cleanupException = new myException(0,"Error: calling WSACleanup()");
			throw cleanupException;
        }
	}
	catch(myException* excp)
	{
		excp->response();
		delete excp;
		exit(1);
	}
	winLog << "successful" << endl;

#endif

    return 1;
}
