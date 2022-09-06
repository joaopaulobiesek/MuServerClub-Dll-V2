#pragma once

typedef unsigned __int64 QWORD;

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define SERVER_VERSION "3.0.0.0"

#define AUTHSERVER_LICENSED_VERSION "3.0.0.0"

#define PROTECT_STATE 1

#include "targetver.h"

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

//////Include Protocol
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
#include "ProtocolValidation.h"

//Offset
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

#include "Features.h"
#include "Resource.h"
#include "ServerDll.h"
#include "ServerDisplayer.h"
#include "Themida/ThemidaSDK.h"

//BasicModules
#include "Log.h"
#include "Util.h"
#include "Queue.h"
#include "CCRC32.H"
#include "BlackList.h"
#include "MemScript.h"
#include "ReadFiles.h"
#include "ServerInfo.h"
#include "ClientManager.h"
#include "SocketManager.h"
#include "CriticalSection.h"

//AuthServer
#include "ProcessQueryAuth.h"
#include "ConnectionAuth.h"
#include "ProtocoloAuth.h"
#include "ThreadAuth.h"
#include "ThreadCheckAuth.h"

//DataServer
#include "Connection.h"
#include "ProtocolDataServer.h"
#include "Protocol2DataServer.h"
#include "SocketDataServer.h"

#include "GetSync.h"