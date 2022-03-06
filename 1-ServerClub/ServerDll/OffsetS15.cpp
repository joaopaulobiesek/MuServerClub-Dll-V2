#include "pch.h"

COffsetS15 gOffsetS15;

COffsetS15::COffsetS15() // OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
	this->IpAddressAddress = 0x017A73E8;
	this->ClientVersionAddress = 0x017B0B00;
	this->ClientSerialAddress = 0x017B0B08;
	this->AccountAddress = 0x0A5CC994;
	this->CharacterAddress = 0x0A5CCB3C;
	this->HwndAddress = 0x017DF8D4;
	this->FileProtectAddress1 = 0x011EBB5D;
	this->FileProtectAddress2 = 0x011EB743;
	this->MAIN_SCREEN_STATE = 0x0A5CCA10;
	this->MAIN_VIEWPORT_STRUCT = 0x09D3A79C;
	this->MAIN_MAP_CODE = 0X017A8074;
	this->pDrawMessage = 0x005C5197;
	this->gCameraPosXC = 0x084FE490;
	this->gCameraPosYC = 0x084FE48C;
	this->WingActive = 0x00A553B9;
	this->Skill1Active = 0x00771B82;
	this->Skill2Active = 0x007E8C30;
	this->Skill3Active = 0x007F40A7;
	this->Skill4Active = 0x00A3A189;
	this->Skill5Active = 0x0063CADE;
	this->Skill6ActiveHook = 0x0063FD7B;
	this->ZenActive = 0x00610917;
	this->ItemActive = 0x00610D09;
	this->Pet1Active = 0x0050A48B;
	this->Pet2ActiveHook = 0x0057919E;
	this->Pet3Active = 0x0050A4AC;
	this->Pet4ActiveHook = 0x0051D2D2;
	this->Char1Moob1Active = 0x00A451A0;
	this->Char1Moob2ActiveHook = 0x00A2CFB7;
	this->Char2Moob3Active = 0x0065BDFA;
	this->Char2Moob4Active = 0x0065BE2D;
	this->Char2Moob5ActiveHook = 0x00640427;
	this->Terrain1Active = 0x00604DFB;
	this->Terrain2Active = 0x00608EA3;
	this->RemoveSetActive = 0x006115B5;
	this->HitBox1Active = 0x005CC65B;
	this->HitBox2Active = 0x005CC698;
	this->HitBox3Active = 0x005CC6A4;
	this->HitBox4Active = 0x005CC6E1;
	this->HitBox5Active = 0x005CC7E1;
	this->CameraY = 0x01587784;
	this->CameraZ = 0x01584E68;
	this->CameraX = 0x08C66208;
	this->CameraZoom1 = 0x017A80E0;
	this->CameraZoom2 = 0x017A80E4;
	this->CameraZoom3 = 0x017A80E8;
	this->CameraZoomByte = 0x017DFDC4;
	this->CameraArena = 0x005068D7;
	this->CameraFuncNull = 0x0050BCB6;
	this->CameraHook = 0x004FF758;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

COffsetS15::~COffsetS15() // OK
{

}

void COffsetS15::InitOffset()
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		gOffset.IpAddressAddress = this->IpAddressAddress;
	gOffset.ClientVersionAddress = this->ClientVersionAddress;
	gOffset.ClientSerialAddress = this->ClientSerialAddress;
	gOffset.AccountAddress = this->AccountAddress;
	gOffset.CharacterAddress = this->CharacterAddress;
	gOffset.HwndAddress = this->HwndAddress;
	gOffset.FileProtectAddress1 = this->FileProtectAddress1;
	gOffset.FileProtectAddress2 = this->FileProtectAddress2;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}