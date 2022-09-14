#include "pch.h"

CFeatures gFeatures;

CFeatures::CFeatures() // OK
{
	this->antiLag = 0;
	this->camera3D = 0;
	this->customICO = 0;
	this->removeSplash = 0;
	this->twoFactorAuth = 0;
	this->emoji = 0;
	this->customMoster = 0;
	this->guildIco = 0;
	this->petSafeZone = 0;
	this->customNPC = 0;
	this->customCloak = 0;
	this->customOption = 0;
	this->customEventTime = 0;
	this->dataServer = 0;
}

CFeatures::~CFeatures() // OK
{

}