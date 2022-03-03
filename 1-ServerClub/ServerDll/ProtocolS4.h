#pragma once

class CProtocolS4
{
public:
	void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS4 gProtocolS4;
