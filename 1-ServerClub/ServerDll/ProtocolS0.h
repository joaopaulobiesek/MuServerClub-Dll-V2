#pragma once

class CProtocolS0
{
public:
	void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS0 gProtocolS0;
