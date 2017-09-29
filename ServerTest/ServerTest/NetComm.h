#pragma once
//#include "winsock2.h"
//#include <iostream>

//#pragma comment (lib, "ws2_32.lib")
#define NETWORK_PORT 16921
//using namespace std;


class CNetComm
{
public:
	CNetComm();
	~CNetComm();

	bool InitNetwork(int nPort);
	void Close();
public:
	SOCKET m_socket;
	SOCKET GetListenSocket(int nPort, int MaxCon = SOMAXCONN);
};

