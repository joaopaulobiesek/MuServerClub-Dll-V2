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

	
	this->JCActive = Pointer;
	this->JCAction = Action;

	switch (this->JCAction)
	{
	case Effect_DisableWing:
	{
		this->JCActive = gAntiLagS6.case3;
	}
	break;
	case Effect_DisableSkill:
	{
		this->JCActive = gAntiLagS6.case4;
	}
	break;
	case Effect_DisableDropZen:
	{
		this->JCActive = gAntiLagS6.case5;
	}
	break;
	case Effect_DisableDropItem:
	{
		this->JCActive = gAntiLagS6.case6;
	}
	break;
	case Effect_DisablePet:
	{
		this->JCActive = gAntiLagS6.case9;
	}
	break;
	case Effect_DisableCharMoob1:
	{
		this->JCActive = gAntiLagS6.case10;// Desativa tudo
	}
	break;
	case Effect_DisableCharMoob2:
	{
		this->JCActive = gAntiLagS6.case11;// Custom Personalizado
	}
	break;
	case Effect_DisableObjTerrain:
	{
		this->JCActive = gAntiLagS6.case7;
	}
	break;
	case Effect_RemoveSet:
	{
		this->JCActive = gAntiLagS6.case8;
	}
	break;
	case NONE:
		break;
	case DEFAULT:
		break;
	}
}

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
	switch (this->JCAction)
	{
	case Effect_DisableWing:
	{
		gAntiLagS6.InitKB(3);
	}
	break;
	case Effect_DisableSkill:
	{
		gAntiLagS6.InitKB(4);
	}
	break;
	case Effect_DisableDropZen:
	{
		gAntiLagS6.InitKB(5);
	}
	break;
	case Effect_DisableDropItem:
	{
		gAntiLagS6.InitKB(6);
	}
	break;
	case Effect_DisablePet:
	{
		gAntiLagS6.InitKB(9);
	}
	break;
	case Effect_DisableCharMoob1:
	{
		gAntiLagS6.InitKB(10);// Desativa tudo
	}
	break;
	case Effect_DisableCharMoob2:
	{
		gAntiLagS6.InitKB(11);// Custom Personalizado
	}
	break;
	case Effect_DisableObjTerrain:
	{
		gAntiLagS6.InitKB(7);
	}
	break;
	case Effect_RemoveSet:
	{
		gAntiLagS6.InitKB(8);
	}
	break;
	case NONE:
		break;
	case DEFAULT:
		break;
	}
}