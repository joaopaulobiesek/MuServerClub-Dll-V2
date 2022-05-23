#include "pch.h"

JCOptionBox gJCOptionBox;


JCOptionBox::JCOptionBox()
{
	this->JCRenderX = 0;
	this->JCRenderY = 0;
	this->JCWidth = 15.0;
	this->JCHeight = 15.0;
	ZeroMemory(this->JCtext, sizeof(this->JCtext));
	wsprintf(this->JCtext, "new JCOptionBox");

}

JCOptionBox::~JCOptionBox()
{

}

void JCOptionBox::SetText(char* Unknown)
{
	ZeroMemory(this->JCtext, sizeof(this->JCtext));
	wsprintf(this->JCtext, Unknown);
}

void JCOptionBox::LoadAction(int Pointer, int Action)
{
	this->JCActive = Pointer;
	this->JCAction = Action;

	switch (this->JCAction)
	{
	case Effect_DisableWing:
	{
		this->JCActive = GetPrivateProfileIntA("Graphics", "DisableWing", 0, "./Config.ini");
	}
	break;
	case Effect_DisableSkill:
	{
		this->JCActive = GetPrivateProfileIntA("Graphics", "DisableSkill", 0, "./Config.ini");
	}
	break;
	case Effect_DisableDropZen:
	{
		this->JCActive = GetPrivateProfileIntA("Graphics", "DisableDropZen", 0, "./Config.ini");
	}
	break;
	case Effect_DisableDropItem:
	{
		this->JCActive = GetPrivateProfileIntA("Graphics", "DisableDropItem", 0, "./Config.ini");
	}
	break;
	case Effect_DisablePet:
	{
		this->JCActive = GetPrivateProfileIntA("Graphics", "DisablePet", 0, "./Config.ini");
	}
	break;
	case Effect_DisableCharMoob1:
	{
		this->JCActive = GetPrivateProfileIntA("Graphics", "DisableCharMoob1", 0, "./Config.ini");
	}
	break;
	case Effect_DisableCharMoob2:
	{
		this->JCActive = GetPrivateProfileIntA("Graphics", "DisableCharMoob2", 0, "./Config.ini");
	}
	break;
	case Effect_DisableObjTerrain:
	{
		this->JCActive = GetPrivateProfileIntA("Graphics", "DisableObjTerrain", 0, "./Config.ini");
	}
	break;
	case Effect_RemoveSet:
	{
		this->JCActive = GetPrivateProfileIntA("Graphics", "RemoveSet", 0, "./Config.ini");
	}
	break;
	case Effect_LagDetection:
	{
		this->JCActive = !GetPrivateProfileIntA("Graphics", "LagDetection", 0, "./Config.ini");
	}
	break;
	case NONE:
		break;
	case DEFAULT:
		break;
	}

}

/*void JCOptionBox::SetBounds(JCRECT Bound)
{
	this->JCRenderX = Bound.x;
	this->JCRenderY = Bound.y;
	this->JCWidth = Bound.w;
	this->JCHeight = Bound.h;
}

void JCOptionBox::SetBounds(float x, float y, float Width, float Height)
{
	this->JCRenderX = x;
	this->JCRenderY = y;
	this->JCWidth = Width;
	this->JCHeight = Height;
}*/

int JCOptionBox::SetVisible()
{
	if (this->JCActive != 0)
	{
		pSetTextColor(pTextThis(), 0x66u, 0x66u, 0x66u, 0xFFu); //-- eGray
	}
	else
	{
		pSetTextColor(pTextThis(), 0x7Fu, 0xB2u, 0xFFu, 0xFFu); //-- eBlue
	}
	pDrawText(pTextThis(), this->JCRenderX + 18, this->JCRenderY + 3, this->JCtext, 0, 0, (LPINT)1, 0);
	pDrawButton(31593, this->JCRenderX, this->JCRenderY, this->JCWidth, this->JCHeight, 0.0, (this->JCActive != 0) ? 15.0 : 0.0);

	return this->JCActive;
}

void JCOptionBox::SetSize(float Width, float Height)
{
	this->JCWidth = Width;
	this->JCHeight = Height;
}

void JCOptionBox::SetLocation(float x, float y)
{
	this->JCRenderX = x;
	this->JCRenderY = y;
}

void JCOptionBox::SetLocationX(float x)
{
	this->JCRenderX = x;
}

void JCOptionBox::SetLocationY(float y)
{
	this->JCRenderY = y;
}

char* JCOptionBox::GetText()
{
	return this->JCtext;
}

/*JCRECT JCOptionBox::GetBounds()
{
	JCRECT Bounds;
	Bounds.x = this->JCRenderX;
	Bounds.y = this->JCRenderY;
	Bounds.w = this->JCWidth;
	Bounds.h = this->JCHeight;

	return Bounds;
}*/

void JCOptionBox::mouseClicked()
{
	if (pCheckMouseOver(this->JCRenderX, this->JCRenderY, this->JCWidth, this->JCHeight) && *(BYTE*)0x8793386)
	{
		if (GetTickCount() >= this->JCTimerEvent + 300)
		{
			if (this->JCActive)
			{
				this->JCActive = 0;
			}
			else
			{
				this->JCActive = 1;
			}
			this->ActionListener();
			this->JCTimerEvent = GetTickCount();
		}
		PlayBuffer(25, 0, 0);
	}
}

void JCOptionBox::mouseEntered()
{
}

void JCOptionBox::ActionListener()
{
	/*switch (this->JCAction)
	{
	case Effect_DisableWing:
	{
		WritePrivateProfileStringA("Graphics", "DisableWing", (this->JCActive != 0) ? "1" : "0", "./Config.ini");
		ActiveAntiLag(3, true);
	}
	break;
	case Effect_DisableSkill:
	{
		WritePrivateProfileStringA("Graphics", "DisableSkill", (this->JCActive != 0) ? "1" : "0", "./Config.ini");
		ActiveAntiLag(4, true);
	}
	break;
	case Effect_DisableDropZen:
	{
		WritePrivateProfileStringA("Graphics", "DisableDropZen", (this->JCActive != 0) ? "1" : "0", "./Config.ini");
		ActiveAntiLag(5, true);
	}
	break;
	case Effect_DisableDropItem:
	{
		WritePrivateProfileStringA("Graphics", "DisableDropItem", (this->JCActive != 0) ? "1" : "0", "./Config.ini");
		ActiveAntiLag(6, true);
	}
	break;
	case Effect_DisablePet:
	{
		WritePrivateProfileStringA("Graphics", "DisablePet", (this->JCActive != 0) ? "1" : "0", "./Config.ini");
		ActiveAntiLag(9, true);
	}
	break;
	case Effect_DisableCharMoob1:
	{
		WritePrivateProfileStringA("Graphics", "DisableCharMoob1", (this->JCActive != 0) ? "1" : "0", "./Config.ini");
		ActiveAntiLag(10, true);
	}
	break;
	case Effect_DisableCharMoob2:
	{
		WritePrivateProfileStringA("Graphics", "DisableCharMoob2", (this->JCActive != 0) ? "1" : "0", "./Config.ini");
		ActiveAntiLag(11, true);
	}
	break;
	case Effect_DisableObjTerrain:
	{
		WritePrivateProfileStringA("Graphics", "DisableObjTerrain", (this->JCActive != 0) ? "1" : "0", "./Config.ini");
		ActiveAntiLag(7, true);
	}
	break;
	case Effect_RemoveSet:
	{
		WritePrivateProfileStringA("Graphics", "RemoveSet", (this->JCActive != 0) ? "1" : "0", "./Config.ini");
		ActiveAntiLag(8, true);
	}
	break;
	case Effect_LagDetection:
	{
		WritePrivateProfileStringA("Graphics", "LagDetection", (this->JCActive != 0) ? "1" : "0", "./Config.ini");
		LagDetectionOption = (this->JCActive != 0) ? 0 : 1;
	}
	break;
	case NONE:
		break;
	case DEFAULT:
		break;
	}*/
}