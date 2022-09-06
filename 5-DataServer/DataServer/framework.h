// header.h : include file for standard system include files,
// or project specific include files
//
typedef unsigned __int64 QWORD;

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#include "targetver.h"

#define DATA_SERVER_VERSION "1.0.0.0"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <stdio.h>
#include <Mmsystem.h>
#include <gl\GL.h>
#include <Shellapi.h>
#include "detours.h"
#include <Shlwapi.h>
#include <wchar.h>
#include <winternl.h>
#include <winioctl.h>
#include <SDKDDKVer.h>
#include <fstream>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// System Include
#include <winsock2.h>
#include <process.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <Rpc.h>
#include <dbghelp.h>
#include <Psapi.h>

//DS
#include <commctrl.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
//DS

//Hexadecimal
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdint>

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Rpcrt4.lib")
#pragma comment(lib,"dbghelp.lib")
#pragma comment(lib,"Psapi.lib")
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"detours.lib")
#pragma comment(lib,"Shlwapi.lib")
#pragma comment(lib,"User32.lib")

////////////////////////////////////

#include "Themida/ThemidaSDK.h"
#include "DataServer.h"
#include "ServerDisplayer.h"
#include "GetVersion.h"
#include "ProtocolCore.h"
#include "SocketManager.h"
#include "Queue.h"
#include "CriticalSection.h"
#include "Log.h"
#include "Util.h"
#include "ServerManager.h"
#include "AllowableIpList.h"
#include "MemScript.h"
#include "QueryManager.h"
#include "BadSyntax.h"
#include "Script_HWID.h"