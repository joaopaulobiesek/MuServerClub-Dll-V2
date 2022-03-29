#include "pch.h"

CSpeed gSpeed;

CSpeed::CSpeed() // OK
{
    SYSTEMTIME time;

    GetLocalTime(&time);

    this->m_SpeedMain.Map = 0;

    this->m_SpeedMain.X = 0;

    this->m_SpeedMain.Y = 0;

    this->LimitMoviment = 6;

    this->ToleranceLimit = 0;

    this->TimeToleranceLimit = time.wSecond;
}

void CSpeed::CheckLimit(int Map, int X, int Y)
{
    SYSTEMTIME time;

    GetLocalTime(&time);

    if (time.wSecond != this->TimeToleranceLimit)
    {
        if (Map == this->m_SpeedMain.Map)
        {
            int PosX = this->m_SpeedMain.X - X;

            int PosY = this->m_SpeedMain.Y - Y;

            int PosXx = X - this->m_SpeedMain.X;

            int PosYy = Y - this->m_SpeedMain.Y;

            if (PosX < 0)
            {
                PosX = PosXx;
            }
            if (PosY < 0)
            {
                PosY = PosYy;
            }
            if (((PosX >= this->LimitMoviment) && PosX < 30) || ((PosY >= this->LimitMoviment) && PosY < 30))
            {
                this->ToleranceLimit++;
            }
        }
        this->m_SpeedMain.Map = Map;

        this->m_SpeedMain.X = X;

        this->m_SpeedMain.Y = Y;

        this->TimeToleranceLimit = time.wSecond;
    }


    if (time.wSecond % 10 == 0)
    {
        if (this->ToleranceLimit >= 3)
        {
            gProtocol.ClientSendHack(gThread.NameAccount, "Speed", 1, Map, X, Y);

            this->ToleranceLimit = 0;
        }
        else
        {
            this->ToleranceLimit = 0;
        }
    }
}