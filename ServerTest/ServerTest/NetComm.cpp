#include "stdafx.h"
#include "NetComm.h"


CNetComm::CNetComm()
{
}


CNetComm::~CNetComm()
{
}

bool CNetComm::InitNetwork(int nPort){

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

void CNetComm::Close(){

	if (m_socket != INVALID_SOCKET){
		closesocket(m_socket);
	}
	if (m_socket == INVALID_SOCKET)
	{
		WSACleanup();
	}
}
SOCKET CNetComm::GetListenSocket(int nPort, int MaxCon)
{
	//���� ���� ����
	SOCKET hsoListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (hsoListen == INVALID_SOCKET){
		U_Log("dev_Log", "socket failed, code : %d", WSAGetLastError());
		return INVALID_SOCKET;
	}

	// ���ε� �ּ� ����
	SOCKADDR_IN sa;
	memset(&sa, 0, sizeof(SOCKADDR_IN));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(nPort);
	sa.sin_addr.s_addr = htonl(INADDR_ANY);

	//���� ���ε�
	int lSockRet = bind(hsoListen, (PSOCKADDR)&sa, sizeof(SOCKADDR_IN));
	if (lSockRet == SOCKET_ERROR){
		U_Log("dev_Log", "bind failed, code : %d ", WSAGetLastError());
		closesocket(hsoListen);
		return INVALID_SOCKET;
	}

	//����
	lSockRet = listen(hsoListen, MaxCon);
	if (lSockRet == SOCKET_ERROR){
		U_Log("dev_Log", "listen failed, code : %d", WSAGetLastError());
		closesocket(hsoListen);
		return INVALID_SOCKET;
	}
	return hsoListen;
}
