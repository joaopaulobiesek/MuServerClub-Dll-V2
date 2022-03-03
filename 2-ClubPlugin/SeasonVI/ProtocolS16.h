#pragma once

class CProtocolS16
{
public:
	void ProtocolCore(BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS16 gProtocolS16;
