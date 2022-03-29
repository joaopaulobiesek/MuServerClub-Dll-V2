#pragma once

struct CUSTOM_LOGO
{
	int Active;
	int	X;
	int	Y;
};

class User
{
public:
	void		Load();
	void		Refresh();
	bool		GetTarget();
	lpCharObj	lpPlayer;
	lpViewObj	lpViewPlayer;
	lpViewObj	lpViewTarget;
	int			m_MapNumber;
	int			m_CursorX;
	int			MagickAttack;
	int			m_CursorY;
	int GetActiveSkill();
	static void	SetEventEffect(int PreviewStruct);
	CUSTOM_LOGO m_Logo[400];
	DWORD ConnectServerDll;
};
extern User gObjUser;