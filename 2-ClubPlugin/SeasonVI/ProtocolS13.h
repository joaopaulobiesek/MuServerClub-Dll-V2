#pragma once

class CProtocolS13
{
public:
	void ProtocolCore(BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS13 gProtocolS13;
