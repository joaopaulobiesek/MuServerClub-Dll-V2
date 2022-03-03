#pragma once

class CProtocolS6
{
public:
	void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS6 gProtocolS6;
