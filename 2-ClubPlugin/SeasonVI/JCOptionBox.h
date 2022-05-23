#pragma once

class JCOptionBox
{
public:
	JCOptionBox();
	virtual ~JCOptionBox();

private:
	char JCtext[32];
	float JCRenderX;
	float JCRenderY;
	float JCWidth;
	float JCHeight;
	int JCActive;
	int JCAction;
	int JCTimerEvent;
	int DisableShadow;
public:

	void SetText(char* Unknown);
	//void SetBounds(JCRECT Bound);
	//void SetBounds(float x, float y, float Width, float Height);
	void LoadAction(int Pointer, int Action);
	int SetVisible();
	void SetSize(float Width, float Height);
	void SetLocation(float x, float y);
	void SetLocationX(float x);
	void SetLocationY(float y);
	char* GetText();
	//JCRECT GetBounds();

public:
	//-- MouseListener
	void mouseClicked();
	void mouseEntered();
	void ActionListener();

};