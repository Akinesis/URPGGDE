CC=g++
CFLAGS=-c -Wall -Wextra -std=c++11
LDFLAGS=
SOURCES=/SimpleSocket/myClient.cpp /SimpleSocket/myHostInfo.cpp /SimpleSocket/myException.cpp /SimpleSocket/myLogTester.cpp /SimpleSocket/mySocketTester.cpp /SimpleSocket/winServer.cpp /SimpleSocket/myExceptionTester.cpp /SimpleSocket/myHostInfoTester.cpp /SimpleSocket/mySocket.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=urpggde
all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm *.o	
