#pragma once

class CProtocolS10
{
public:
	void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS10 gProtocolS10;
