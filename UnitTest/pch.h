
#pragma once

extern "C"
{
	#include "../z80.h"
	// error C2365: 'state_0': redefinition; previous definition was 'enumerator'
	//#include "../68k.h"
	#include "../fm.h"
	#include "../ympsg.h"

	// Not exported

	void Z80_Clock(z80_t* chip, int clk);

}
