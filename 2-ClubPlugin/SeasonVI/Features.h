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
	int emoji;
	int customMoster;
	int guildIco;
	int petSafeZone;
	int customNPC;
	int customCloak;
};
extern CFeatures gFeatures;