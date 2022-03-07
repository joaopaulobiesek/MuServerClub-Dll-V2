#include "pch.h"

CFeatures gFeatures;

CFeatures::CFeatures() // OK
{
	this->antiLag = 0;
	this->camera3D = 0;
	this->customICO = 0;
	this->removeSplash = 0;
	this->twoFactorAuth = 0;
}

CFeatures::~CFeatures() // OK
{

}