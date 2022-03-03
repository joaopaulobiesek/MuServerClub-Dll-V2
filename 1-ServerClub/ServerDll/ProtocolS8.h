#pragma once

class CProtocolS8
{
public:
	void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS8 gProtocolS8;
