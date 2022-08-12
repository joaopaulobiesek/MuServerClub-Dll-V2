#pragma once

typedef unsigned __int64 QWORD;

#define WIN32_LEAN_AND_MEAN             // Excluir itens raramente utilizados dos cabeçalhos do Windows
#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define HACKCLIENT_VERSION "2.0.0.1"

// Arquivos de Cabeçalho do Windows  
#include <windows.h>
#include <iostream>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <winsock2.h>
#include <Mmsystem.h>
#include <time.h>
#include <gl\GL.h>
#include <Shellapi.h>
#include "detours.h"
#include <tchar.h>
#include <Rpc.h>
#include <vector>
#include <Psapi.h>
#include <Shlwapi.h>
#include <Dbghelp.h>
#include <wchar.h>
#include <string>
#include <Rpc.h>
#include <winternl.h>
#include <winioctl.h>
#include <SDKDDKVer.h>
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"detours.lib")
#pragma comment(lib,"Psapi.lib")
#pragma comment(lib,"Shlwapi.lib")
#pragma comment(lib,"Dbghelp.lib")
#pragma comment(lib,"Rpcrt4.lib")
#pragma comment(lib,"Rpcrt4.lib")
#pragma comment(lib,"User32.lib")

//Include Padrões
#include "Connection.h"
#include "ListManager.h"
#include "Util.h"
#include "Message.h"
#include "ThreadCheck.h"
#include "SimpleModules.h"
#include "FileProtect.h"
#include "FileCheck.h"
#include "CCRC32.h"
#include "Util.h"
#include "Protect.h"
#include "SpeedCheck.h"
#include "WindowCheck.h"
#include "ProcessManager.h"
#include "ProcessQuery.h"
#include "ProcessCheck.h"
#include "ThreadCheck.h"
#include "ExecutableCheck.h"
#include "Main.h"
#include "MapName.h"
#include "Clock.h"
#include "Log.h"

#include "Themida/ThemidaSDK.h"
#include "SplashScreen.h"
#include "windowsx.h"
#include "resource.h"
#include "Defines.h"

#include "Object.h"

//Include Protocol
#include "Protocol.h"
#include "ProtocolS0.h"
#include "ProtocolS2.h"
#include "ProtocolS4.h"
#include "ProtocolS6.h"
#include "ProtocolS8.h"
#include "ProtocolS10.h"
#include "ProtocolS12.h"
#include "ProtocolS13.h"
#include "ProtocolS14.h"
#include "ProtocolS15.h"
#include "ProtocolS16.h"
#include "ProtocolS17.h"
#include "ProtocolS1702.h"

//Include Offset
#include "Offset.h"
#include "OffsetS0.h"
#include "OffsetS2.h"
#include "OffsetS4.h"
#include "OffsetS6.h"
#include "OffsetS8.h"
#include "OffsetS10.h"
#include "OffsetS12.h"
#include "OffsetS13.h"
#include "OffsetS14.h"
#include "OffsetS15.h"
#include "OffsetS16.h"
#include "OffsetS17.h"
#include "OffsetS1702.h"

//Include Protocol
#include "Thread.h"
#include "ThreadS6.h"
#include "ThreadS15.h"
#include "ThreadS17.h"
#include "ThreadS1702.h"

//Features
//
// 
#include "Camera3dS6.h"
#include "AntiLagS6.h"
#include "HookKBS6.h"
#include "HookMSS6.h"
#include "SwitchKBS6.h" 
//
#include "Camera3dS15.h"
#include "AntiLagS15.h"
#include "HookKBS15.h"
#include "HookMSS15.h"
#include "SwitchKBS15.h"
//
#include "Camera3dS17.h"
#include "AntiLagS17.h"
#include "HookKBS17.h"
#include "HookMSS17.h"
#include "SwitchKBS17.h"
//
#include "Camera3dS1702.h"
#include "AntiLagS1702.h"
#include "HookKBS1702.h"
#include "HookMSS1702.h"
#include "SwitchKBS1702.h"
//
#include "CustomNpcNameS6.h"
#include "CustomMonsterS6.h"
#include "InterfaceS6.h"
#include "UserS6.h"
#include "CustomInterfaceS6.h"
#include "EmojiSystemS6.h"
#include "GuildIcoS6.h"


// 
#include "CustomOptionS6.h"
#include "JCOptionBox.h"
#include "JCEntryproy.h"
#include "CustomCommonS6.h"
#include "ImportS6.h"
#include "Font.h"
#include "WindowStruct.h"
//
#include "Features.h"

#include "HealthBarS6.h"
#include "RankUserS6.h"
#include "ItemFixS6.h"
#include "EventTimeS6.h"
#include "CustomCloakS6.h"
#include "CapeS6.h"
#include "zzzmathlib.h"
#include "MonsterEffectS6.h"
#include "ModelEffectS6.h"
#include "CustomFogS6.h"
#include "ItemSmokeS6.h"
#include "ItemS6.h"
