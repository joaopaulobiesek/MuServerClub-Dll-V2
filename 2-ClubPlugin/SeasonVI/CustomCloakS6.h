#pragma once

#define MAX_CUSTOMCLOAK        20

class cCustomCloak
{
public:
    cCustomCloak();
    virtual ~cCustomCloak();
    // ----
    void    Init();
    void    Scan();
    void    Load(CLOAKNAME_DATA* info);
    void    SetInfo(CLOAKNAME_DATA info);
    CLOAKNAME_DATA* GetInfo(int index);
    CLOAKNAME_DATA* GetInfoByItem(int ItemIndex);
    void    LoadTexture();
    bool    isCloak(int ItemIndex);
    bool    isCloakStrip(int ItemIndex);
    int        code;
    DWORD        getCodeCape(int ItemIndex); // OK

    // ----
    // ----
public:
    CLOAKNAME_DATA m_Cloak[MAX_CUSTOMCLOAK];


}; extern cCustomCloak gCloak;