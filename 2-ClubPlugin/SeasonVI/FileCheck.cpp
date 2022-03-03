#include "pch.h"

CFileCheck gFileCheck;

CFileCheck::CFileCheck()
{
	this->m_count = 0;
}

CFileCheck::~CFileCheck()
{
}

void CFileCheck::Scan()
{
	if ((this->m_count++) < 12)
	{
		CCRC32 CRC32;

		for (std::vector<CSUM_LIST_INFO>::iterator it = gListManager.gChecksumListInfo.begin(); it != gListManager.gChecksumListInfo.end(); it++)
		{
			if (FileExists(it->path) == 1)
			{
				DWORD FileHash;

				if (CRC32.FileCRC(it->path, &FileHash, 1024) == 0)
				{
				gProtocol.ClientDisconnectSend(CLIENT_DISCONNECT_FILE_DETECTION, it->path, 0);
					return;
				}

				if (it->checksum != FileHash)
				{
					gProtocol.ClientDisconnectSend(CLIENT_DISCONNECT_FILE_DETECTION, it->path, 0);
					return;
				}
			}
			else
			{
				gProtocol.ClientDisconnectSend(CLIENT_DISCONNECT_FILE_DETECTION, it->path, 0);
				return;
			}
		}
	}
}
