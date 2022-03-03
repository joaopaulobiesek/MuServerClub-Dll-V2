#pragma once

class CProtocolS12
{
public:
	void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS12 gProtocolS12;
