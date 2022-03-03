#pragma once

class CAntiLagS17
{
public:
	CAntiLagS17();
	virtual ~CAntiLagS17();
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
	int case12;
	int case13;
	char GraphicsControl[256];
};

extern CAntiLagS17 gAntiLagS17;
