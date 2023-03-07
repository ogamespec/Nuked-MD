#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
	#include "../68k.h"
	void M68K_Clock(m68k_t* chip, int clk1, int clk2);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest68K)
	{
	public:
		
		/// <summary>
		/// Execute 1 million 68000 cycles and see what it does not crash and how long it takes to execute.
		/// </summary>
		TEST_METHOD(M68K_MegaCycles)
		{
			m68k_t state{};
			int clk1 = state_0;
			int clk2 = state_1;

			size_t cycles = 1000000;

			// One cycle consists of two phases (half cycles)

			while (cycles-- != 0)
			{
				M68K_Clock(&state, clk1, clk2);
				clk1 = state_1;
				clk2 = state_0;

				M68K_Clock(&state, clk1, clk2);
				clk1 = state_0;
				clk2 = state_1;
			}

			// Check duration in Test Explorer :-)
		}
	};
}
