#pragma once

class CProtocolS2
{
public:
	void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS2 gProtocolS2;
