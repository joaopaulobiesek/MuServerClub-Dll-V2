#pragma once

#include "Util.h"

class CWindowCheck
{
public:
	CWindowCheck();
	virtual ~CWindowCheck();
	void Scan();
public:
	int CHeckCheat;
};

extern CWindowCheck gWindowCheck;