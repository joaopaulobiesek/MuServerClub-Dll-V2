#pragma once

class CFeatures
{
public:
	CFeatures();
	virtual ~CFeatures();
public:
	int antiLag;
	int camera3D;
	int customICO;
	int removeSplash;
	int twoFactorAuth;
};
extern CFeatures gFeatures;