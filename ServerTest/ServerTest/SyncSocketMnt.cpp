#include "stdafx.h"
#include "SyncSocketMnt.h"


CSyncSocketMnt::CSyncSocketMnt()
{
}


CSyncSocketMnt::~CSyncSocketMnt()
{
}

bool CSyncSocketMnt::InitNetwork(int nPort){

	WSADATA wsd;
	int nErrCode = WSAStartup(MAKEWORD(2, 2), &wsd);
	if (nErrCode){
		U_Log("dev_Log", "WSAStartup failed with error : %d", nErrCode);
	}

	m_socket = GetListenSocket(nPort);
	if (m_socket == INVALID_SOCKET)
	{
		WSACleanup();
		return false;
	}
	U_Log("dev_Log", ">>>>>>>>>>>>>>>> waiting for client's connection");
	return true;
}

void CSyncSocketMnt::Close(){

	if (m_socket != INVALID_SOCKET){
		closesocket(m_socket);
	}
	if (m_socket == INVALID_SOCKET)
	{
		WSACleanup();
	}
}
SOCKET CSyncSocketMnt::GetListenSocket(int nPort, int MaxCon)
{
	//府郊 家南 积己
	SOCKET hsoListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (hsoListen == INVALID_SOCKET){
		U_Log("dev_Log", "socket failed, code : %d" ,WSAGetLastError());
		return INVALID_SOCKET;
	}

	// 官牢靛 林家 瘤沥
	SOCKADDR_IN sa;
	memset(&sa, 0, sizeof(SOCKADDR_IN));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(nPort);
	sa.sin_addr.s_addr = htonl(INADDR_ANY);

	//家南 官牢爹
	int lSockRet = bind(hsoListen, (PSOCKADDR)&sa, sizeof(SOCKADDR_IN));
	if (lSockRet == SOCKET_ERROR){
		U_Log("dev_Log", "bind failed, code : %d ", WSAGetLastError());
		closesocket(hsoListen);
		return INVALID_SOCKET;
	}

	//府郊
	lSockRet = listen(hsoListen, MaxCon);
	if (lSockRet == SOCKET_ERROR){
		U_Log("dev_Log", "listen failed, code : %d" , WSAGetLastError() );
		closesocket(hsoListen);
		return INVALID_SOCKET;
	}
	return hsoListen;
}
