#include "pch.h"

COffsetS1702 gOffsetS1702;

COffsetS1702::COffsetS1702() // OK
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
	this->MAIN_SCREEN_STATE = 0x0;
	this->MAIN_VIEWPORT_STRUCT = 0x0;
	this->MAIN_MAP_CODE = 0x0;
	this->pDrawMessage = 0x01518ECC;
	this->gCameraPosXC = 0x0;
	this->gCameraPosYC = 0x0;
	this->WingActive = 0x0;
	this->Skill1Active = 0x0;
	this->Skill2Active = 0x0;
	this->Skill3Active = 0x0;
	this->Skill4Active = 0x0;
	this->Skill5Active = 0x0;
	this->Skill6ActiveHook = 0x0;
	this->ZenActive = 0x0;
	this->ItemActive = 0x0;
	this->Pet1Active = 0x0;
	this->Pet2ActiveHook = 0x0;
	this->Pet3Active = 0x0;
	this->Pet4ActiveHook = 0x0;
	this->Char1Moob1Active = 0x0;
	this->Char1Moob2ActiveHook = 0x0;
	this->Char2Moob3Active = 0x0;
	this->Char2Moob4Active = 0x0;
	this->Char2Moob5ActiveHook = 0x0;
	this->Terrain1Active = 0x0;
	this->Terrain2Active = 0x0;
	this->Terrain3Active = 0x0;
	this->Terrain4Active = 0x0;
	this->RemoveSet1Active = 0x0;
	this->RemoveSet2Active = 0x0;
	this->RemoveSet3Active = 0x0;
	this->RemoveSet4Active = 0x0;
	this->RemoveSet5Active = 0x0;
	this->RemoveSet6Active = 0x0;
	this->RemoveSet7Active = 0x0;
	this->RemoveMoob = 0x0;
	this->CameraY = 0x0;
	this->CameraZ = 0x0;
	this->CameraX = 0x0;
	this->CameraZoom1 = 0x0;
	this->CameraZoom2 = 0x0;
	this->CameraZoom3 = 0x0;
	this->CameraZoomByte = 0x0;
	this->CameraArena = 0x0;
	this->CameraFuncNull = 0x0;
	this->CameraHook = 0x0;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

COffsetS1702::~COffsetS1702() // OK
{

}

void COffsetS1702::InitOffset(SDHP_CLIENT_INFO_RECV* lpMsg)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		gOffset.PortNumberAddress = lpMsg->PortNumberAddress;
		gOffset.IpAddressAddress = lpMsg->IpAddressAddress;
	gOffset.ClientVersionAddress = lpMsg->ClientVersionAddress;
	gOffset.ClientSerialAddress = lpMsg->ClientSerialAddress;
	gOffset.AccountAddress = lpMsg->AccountAddress;
	gOffset.CharacterAddress = lpMsg->CharacterAddress;
	gOffset.HwndAddress = lpMsg->HwndAddress;
	gMain.hWnd = *(HWND*)(lpMsg->HwndAddress);
	gOffset.FileProtectAddress1 = lpMsg->FileProtectAddress1;
	gOffset.FileProtectAddress2 = lpMsg->FileProtectAddress2;
	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}

void COffsetS1702::RecvOffset(SDHP_REQUEST_OFFSET_S1702_RECV* lpMsg)
{
	VM_TIGER_BLACK_START
		STR_ENCRYPT_START
		this->MAIN_SCREEN_STATE = lpMsg->MAIN_SCREEN_STATE;
	this->MAIN_VIEWPORT_STRUCT = lpMsg->MAIN_VIEWPORT_STRUCT;
	this->MAIN_MAP_CODE = lpMsg->MAIN_MAP_CODE;
	this->pDrawMessage = lpMsg->pDrawMessage;
	this->gCameraPosXC = lpMsg->gCameraPosXC;
	this->gCameraPosYC = lpMsg->gCameraPosYC;
	this->WingActive = lpMsg->WingActive;
	this->Skill1Active = lpMsg->Skill1Active;
	this->Skill2Active = lpMsg->Skill2Active;
	this->Skill3Active = lpMsg->Skill3Active;
	this->Skill4Active = lpMsg->Skill4Active;
	this->Skill5Active = lpMsg->Skill5Active;
	this->Skill6ActiveHook = lpMsg->Skill6ActiveHook;
	this->ZenActive = lpMsg->ZenActive;
	this->ItemActive = lpMsg->ItemActive;
	this->Pet1Active = lpMsg->Pet1Active;
	this->Pet2ActiveHook = lpMsg->Pet2ActiveHook;
	this->Pet3Active = lpMsg->Pet3Active;
	this->Pet4ActiveHook = lpMsg->Pet4ActiveHook;
	this->Char1Moob1Active = lpMsg->Char1Moob1Active;
	this->Char1Moob2ActiveHook = lpMsg->Char1Moob2ActiveHook;
	this->Char2Moob3Active = lpMsg->Char2Moob3Active;
	this->Char2Moob4Active = lpMsg->Char2Moob4Active;
	this->Char2Moob5ActiveHook = lpMsg->Char2Moob5ActiveHook;
	this->Terrain1Active = lpMsg->Terrain1Active;
	this->Terrain2Active = lpMsg->Terrain2Active;
	this->Terrain3Active = lpMsg->Terrain3Active;
	this->Terrain4Active = lpMsg->Terrain4Active;
	this->RemoveSet1Active = lpMsg->RemoveSet1Active;
	this->RemoveSet2Active = lpMsg->RemoveSet2Active;
	this->RemoveSet3Active = lpMsg->RemoveSet3Active;
	this->RemoveSet4Active = lpMsg->RemoveSet4Active;
	this->RemoveSet5Active = lpMsg->RemoveSet5Active;
	this->RemoveSet6Active = lpMsg->RemoveSet6Active;
	this->RemoveSet7Active = lpMsg->RemoveSet7Active;
	this->RemoveMoob = lpMsg->RemoveMoob;
	this->CameraY = lpMsg->CameraY;
	this->CameraZ = lpMsg->CameraZ;
	this->CameraX = lpMsg->CameraX;
	this->CameraZoom1 = lpMsg->CameraZoom1;
	this->CameraZoom2 = lpMsg->CameraZoom2;
	this->CameraZoom3 = lpMsg->CameraZoom3;
	this->CameraZoomByte = lpMsg->CameraZoomByte;
	this->CameraArena = lpMsg->CameraArena;
	this->CameraFuncNull = lpMsg->CameraFuncNull;
	this->CameraHook = lpMsg->CameraHook;

	if(gFeatures.camera3D == 1) gCamera3dS1702.Init();

	STR_ENCRYPT_END
		VM_TIGER_BLACK_END
}