#pragma once

class CSocketDataServer
{
public:
	CSocketDataServer();
	virtual ~CSocketDataServer();
	bool DataServerConnect(char* IpAddress, WORD port, DWORD wMsg);
	bool DataServerReconnect(char* IpAddress, WORD port, DWORD wMsg);
	void DataServerMsgProc(WPARAM wParam, LPARAM lParam);
	bool DataServer2Connect(char* IpAddress, WORD port, DWORD wMsg);
	bool DataServer2Reconnect(char* IpAddress, WORD port, DWORD wMsg);
	void DataServer2MsgProc(WPARAM wParam, LPARAM lParam);
private:
};
extern CSocketDataServer gSocketDataServer;