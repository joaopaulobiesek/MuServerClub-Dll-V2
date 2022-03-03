#pragma once

class CProtocolS13
{
public:
	void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS13 gProtocolS13;
