#pragma once

class CProtocolS8
{
public:
	void ProtocolCore(BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS8 gProtocolS8;
