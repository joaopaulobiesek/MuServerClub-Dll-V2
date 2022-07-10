#pragma once

#define Color4f(r, b, g, o)			((o << 24) + (g << 16) + (b << 8) + r)

namespace ASM
{
	enum T
	{
		JMP = 0xE9,
		JE = 0x74,
		JNE = 0x75,
		JGE = 0x7D,
		NOP = 0x90,
		CALL = 0xE8,
		CALLD = 0xFF,
		PUSH = 0x68,
	};
};


enum ColorMacro
{
	eShinyGreen = Color4f(172, 255, 56, 255),
	eShinyGreen100 = Color4f(172, 255, 56, 100),
	eGold = Color4f(255, 189, 25, 255),
	eGold150 = Color4f(255, 189, 25, 150),
	eGold180 = Color4f(255, 189, 25, 180),
	eWhite = Color4f(255, 255, 255, 255),
	eWhite150 = Color4f(255, 255, 255, 150),
	eWhite180 = Color4f(255, 255, 255, 180),
	eOrange = Color4f(255, 105, 25, 255),
	eGray100 = Color4f(211, 211, 211, 100),
	eGray150 = Color4f(50, 50, 50, 150),
	eGray190 = Color4f(50, 50, 50, 190),
	eBlowPink = Color4f(220, 20, 60, 255),
	eRed = Color4f(225, 0, 0, 255),
	eRed2 = Color4f(225, 95, 45, 255),
	eExcellent = Color4f(0, 225, 139, 255),
	eAncient = Color4f(1, 223, 119, 255),
	eSocket = Color4f(153, 102, 204, 255),
	eBlue = Color4f(36, 242, 252, 255),
	eBlue250 = Color4f(36, 242, 252, 250),
	eYellow = Color4f(255, 255, 0, 255),
	eYellow170 = Color4f(255, 255, 0, 170),
	eBrown = Color4f(69, 39, 18, 255),
	ePurple = Color4f(135, 0, 255, 255),
	hero1 = Color4f(0, 255, 255, 255),
	hero2 = Color4f(0, 128, 255, 255),
	hero3 = Color4f(0, 0, 255, 255),
	pk1 = Color4f(255, 102, 0, 255),
	pk2 = Color4f(255, 0, 0, 255),
	pk3 = Color4f(160, 0, 0, 255),
};