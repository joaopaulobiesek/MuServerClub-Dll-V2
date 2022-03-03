#pragma once

class CProtocolS14
{
public:
	void ProtocolCore(BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS14 gProtocolS14;
