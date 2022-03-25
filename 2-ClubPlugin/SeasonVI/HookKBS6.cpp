#include "pch.h"

CHookKBS6 gHookKBS6;

CHookKBS6::CHookKBS6() // OK
{
}

CHookKBS6::~CHookKBS6() // OK
{
}

void CHookKBS6::Init(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (((DWORD)lParam & (1 << 30)) != 0 && ((DWORD)lParam & (1 << 31)) != 0)
	{
		switch (wParam)
		{
		case VK_F6:
			if (GetKeyState(VK_CONTROL) & 0x8000)
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Control + Shift + F6
					gSwitchKBS6.Init(19);

				}
				else
				{
					//Control + F6
					gSwitchKBS6.Init(13);
				}
			}
			else
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Shift + F6
					gSwitchKBS6.Init(7);
				}
				else
				{
					// F6
					gSwitchKBS6.Init(1);
				}
			}
			break;
		case VK_F7:
			if (GetKeyState(VK_CONTROL) & 0x8000)
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Control + Shift + F7
					gSwitchKBS6.Init(20);
				}
				else
				{
					//Control + F7
					gSwitchKBS6.Init(14);
				}
			}
			else
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Shift + F7
					gSwitchKBS6.Init(8);
				}
				else
				{
					// F7
					gSwitchKBS6.Init(2);
				}
			}
			break;
		case VK_F8:
			if (GetKeyState(VK_CONTROL) & 0x8000)
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Control + Shift + F8
					gSwitchKBS6.Init(21);
				}
				else
				{
					//Control + F8
					gSwitchKBS6.Init(15);
				}
			}
			else
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Shift + F8
					gSwitchKBS6.Init(9);
				}
				else
				{
					// F8
					gSwitchKBS6.Init(3);
				}
			}
			break;
		case VK_F9:
			if (GetKeyState(VK_CONTROL) & 0x8000)
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Control + Shift + F9
					gSwitchKBS6.Init(22);
				}
				else
				{
					//Control + F9
					gSwitchKBS6.Init(16);
				}
			}
			else
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Shift + F9
					gSwitchKBS6.Init(10);
				}
				else
				{
					// F9
					gSwitchKBS6.Init(4);
				}
			}
			break;
		case VK_F10:
			if (GetKeyState(VK_CONTROL) & 0x8000)
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Control + Shift + F10
					gSwitchKBS6.Init(23);
				}
				else
				{
					//Control + F10
					gSwitchKBS6.Init(17);
				}
			}
			else
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Shift + F10
					gSwitchKBS6.Init(11);
				}
				else
				{
					// F10
					gSwitchKBS6.Init(5);
				}
			}
			break;
		case VK_F11:
			if (GetKeyState(VK_CONTROL) & 0x8000)
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Control + Shift + F11
					gSwitchKBS6.Init(24);
				}
				else
				{
					//Control + F11
					gSwitchKBS6.Init(18);
				}
			}
			else
			{
				if (GetKeyState(VK_SHIFT) & 0x8000)
				{
					//Shift + F11
					gSwitchKBS6.Init(12);
				}
				else
				{
					// F11
					gSwitchKBS6.Init(6);
				}
			}
			break;
		case 0x30:
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				//Shift + 0
				gSwitchKBS6.Init(27);
			}
			break;
		case 0x31:
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				//Shift + 1
				gSwitchKBS6.Init(28);
			}
			break;
		case 0x32:
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				//Shift + 2
				gSwitchKBS6.Init(29);
			}
			break;
		case 0x33:
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				//Shift + 3
				gSwitchKBS6.Init(30);
			}
			break;
		case 0x34:
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				//Shift + 4
				gSwitchKBS6.Init(31);
			}
			break;
		case 0x35:
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				//Shift + 5
				gSwitchKBS6.Init(32);
			}
			break;
		case 0x36:
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				//Shift + 6
				gSwitchKBS6.Init(33);
			}
			break;
		case 0x37:
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				//Shift + 7
				gSwitchKBS6.Init(34);
			}
			break;
		case 0x38:
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				//Shift + 8
				gSwitchKBS6.Init(35);
			}
			break;
		case 0x39:
			if (GetKeyState(VK_SHIFT) & 0x8000)
			{
				//Shift + 9
				gSwitchKBS6.Init(36);
			}
			break;
		case VK_PRIOR:
			gSwitchKBS6.Init(25);
			break;
		case VK_NEXT:
			gSwitchKBS6.Init(26);
			break;
		default:
			break;
		}
	}
}