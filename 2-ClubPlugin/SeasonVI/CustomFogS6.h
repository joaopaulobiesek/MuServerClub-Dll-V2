#pragma once

#define MAX_FOG 150

class cFog
{
public:
	cFog();
	virtual ~cFog();
	void Init();
	void Scan();
	void Load(CUSTOM_FOG* info);
	void SetInfo(CUSTOM_FOG info);
	CUSTOM_FOG* GetFogByMap(int MapNumber);
	CUSTOM_FOG* GetFogByIndex(int Index);
	float* toRGB(float* rgba);


	void MainFogAllowed();
	static void glMainDisable();

	static bool CheckBlackMaps();
	static bool CheckEventMaps();
	static void glMainEnable(GLenum cap);
	static bool glAllowedFog(GLenum cap);
	static void glClearColor(GLclampf r, GLclampf g, GLclampf b, GLclampf a);
	// ----
public:
	CUSTOM_FOG m_CustomFog[MAX_FOG];
	bool EnableFog;
	int MaxAnisotropy;
	int Anisotropy;
	int Linear;
	int Fog;
}; extern cFog gFog;