#pragma once

class CProtocolS6
{
public:
	void ProtocolCore(BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS6 gProtocolS6;
