#pragma once

class CSocketDataServer
{
public:
	CSocketDataServer();
	virtual ~CSocketDataServer();
	bool DataServerConnect(DWORD wMsg);
	bool DataServerReconnect(HWND hwnd, DWORD wMsg);
	void DataServerMsgProc(WPARAM wParam, LPARAM lParam);
private:
};
extern CSocketDataServer gSocketDataServer;