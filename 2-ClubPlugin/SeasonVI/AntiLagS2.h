#pragma once

class CAntiLagS2
{
public:
	CAntiLagS2();
	virtual ~CAntiLagS2();
	void InitCase(int Parameter);
	void InitKB(int Parameter);
	void ActiveDisabled(int code);
public:
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
private:
	char GraphicsControl[256];
};

extern CAntiLagS2 gAntiLagS2;
