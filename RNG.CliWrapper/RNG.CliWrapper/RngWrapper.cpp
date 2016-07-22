#include "stdafx.h"
#include "RNGWrapper.h"
#include "Poster.h"



System::Collections::Generic::List<System::UInt64>^ RngWrapper::RandomArray()
{
	System::Collections::Generic::List<System::UInt64>^ mngdArray = gcnew System::Collections::Generic::List<System::UInt64>();

	hDLL = LoadLibrary(TEXT("RNG.dll"));
	if (hDLL == NULL) return mngdArray;
	GENERATENUMBERARRAY pfGenerateNumberArray = (GENERATENUMBERARRAY)GetProcAddress(hDLL, "GenerateNumberArray");

	u_int64* pArray = pfGenerateNumberArray();
	
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		mngdArray->Add(ULONG(pArray[i]));
		sendbackEvent(pArray[i].ToString());
	}

	if (hDLL)
		FreeLibrary(hDLL);

	return mngdArray;
};

CustomerWrapper^ RngWrapper::CreateCustomer()
{
	CustomerWrapper^ customer = gcnew CustomerWrapper();

	customerSendbackEvent(customer);

	return customer;
};