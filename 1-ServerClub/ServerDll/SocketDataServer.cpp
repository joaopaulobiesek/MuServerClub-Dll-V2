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
	gConnectionDS.Init(hWnd, ProtocolDataServer);

	if (gConnectionDS.Connect(IpAddress, port, wMsg) == 0)
	{
		return 0;
	}

	gProtocolDataServer.GDServerInfoSend();

	return 1;
}

bool CSocketDataServer::DataServerReconnect(char* IpAddress, WORD port, DWORD wMsg) // OK
{
	if (gConnectionDS.CheckState() == 0)
	{
		return DataServerConnect(IpAddress, port, wMsg);
	}

	return 1;
}

void CSocketDataServer::DataServerMsgProc(WPARAM wParam, LPARAM lParam) // OK
{
	switch (LOWORD(lParam))
	{
	case FD_READ:
		gConnectionDS.DataRecv();
		break;
	case FD_WRITE:
		gConnectionDS.DataSendEx();
		break;
	case FD_CLOSE:
		gConnectionDS.Disconnect();
		//gObjAllDisconnect();
		break;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CSocketDataServer::DataServer2Connect(char* IpAddress, WORD port, DWORD wMsg) // OK
{
	gConnectionDS2.Init(hWnd, Protocol2DataServer);

	if (gConnectionDS2.Connect(IpAddress, port, wMsg) == 0)
	{
		return 0;
	}

	gProtocol2DataServer.GDServerInfoSend();

	return 1;
}

bool CSocketDataServer::DataServer2Reconnect(char* IpAddress, WORD port, DWORD wMsg) // OK
{
	if (gConnectionDS2.CheckState() == 0)
	{
		return DataServer2Connect(IpAddress, port, wMsg);
	}

	return 1;
}

void CSocketDataServer::DataServer2MsgProc(WPARAM wParam, LPARAM lParam) // OK
{
	switch (LOWORD(lParam))
	{
	case FD_READ:
		gConnectionDS2.DataRecv();
		break;
	case FD_WRITE:
		gConnectionDS2.DataSendEx();
		break;
	case FD_CLOSE:
		gConnectionDS2.Disconnect();
		//gObjAllDisconnect();
		break;
	}
}