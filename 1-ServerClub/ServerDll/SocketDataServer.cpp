#include "pch.h"

CSocketDataServer gSocketDataServer;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSocketDataServer::CSocketDataServer() // OK
{
}

CSocketDataServer::~CSocketDataServer() // OK
{
}

bool CSocketDataServer::DataServerConnect(char* IpAddress, WORD port, DWORD wMsg) // OK
{
	gConnection.Init(hWnd, ProtocolDataServer);

	if (gConnection.Connect(IpAddress, port, wMsg) == 0)
	{
		return 0;
	}

	gProtocolDataServer.GDServerInfoSend();
	return 1;
}

bool CSocketDataServer::DataServerReconnect(HWND hwnd, DWORD wMsg) // OK
{
	if (gConnection.CheckState() == 0)
	{
		return DataServerConnect(wMsg);
	}

	return 1;
}

void CSocketDataServer::DataServerMsgProc(WPARAM wParam, LPARAM lParam) // OK
{
	switch (LOWORD(lParam))
	{
	case FD_READ:
		gConnection.DataRecv();
		break;
	case FD_WRITE:
		gConnection.DataSendEx();
		break;
	case FD_CLOSE:
		gConnection.Disconnect();
		//gObjAllDisconnect();
		break;
	}
}