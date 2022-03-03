#pragma once

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