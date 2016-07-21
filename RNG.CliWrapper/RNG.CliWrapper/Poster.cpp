#include "stdafx.h"
#include "Poster.h"

using namespace System;
using namespace System::Runtime::InteropServices;


int PostArray(u_int64* pArray)
{
	typedef int(*RNG_CALLUI)();

	RNG_CALLUI pfnCALLUI;
	int result = 0;
	pfnCALLUI = (RNG_CALLUI)GetProcAddress(GetCurrentModule(), "CallUserInterface");
	if (pfnCALLUI)
	{
		result = pfnCALLUI();
	}
	return 0;
}



HMODULE GetCurrentModule()
{ // NB: XP+ solution!
	HMODULE hModule = NULL;
	GetModuleHandleEx(
		GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
		(LPCTSTR)GetCurrentModule,
		&hModule);

	return hModule;
}

