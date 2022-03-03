#pragma once

class CProtocolS15
{
public:
	void ProtocolCore(int index, BYTE head, BYTE* lpMsg, int size);
public:
};

extern CProtocolS15 gProtocolS15;
