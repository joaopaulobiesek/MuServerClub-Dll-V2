#pragma once

class CAntiLagS6
{
public:
	CAntiLagS6();
	virtual ~CAntiLagS6();
	void InitCase(int Parameter);
	void InitKB(int Parameter);
	void ActiveDisabled(int code);
public:


private:
	int case1;
	int case2;
	int case3;
	int case4;
	int case5;
	int case6;
	int case7;
	int case8;
	int case9;
	int case10;
	int case11;
	char GraphicsControl[256];
};

extern CAntiLagS6 gAntiLagS6;
