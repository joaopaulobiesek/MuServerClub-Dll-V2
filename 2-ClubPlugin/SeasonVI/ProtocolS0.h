#pragma once

class CProtocolS0
{
public:
	void ProtocolCore(BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS0 gProtocolS0;
