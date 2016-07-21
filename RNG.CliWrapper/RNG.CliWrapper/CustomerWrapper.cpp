#include "stdafx.h"
#include "CustomerWrapper.h"

CustomerWrapper::CustomerWrapper()
{
	LoadCustomer();
}

CustomerWrapper::~CustomerWrapper()
{
	if (hDLL)
		FreeLibrary(hDLL);

	delete _customer;
	_customer = 0;
}

CustomerWrapper::!CustomerWrapper()
{
	if (hDLL)
		FreeLibrary(hDLL);

	delete _customer;
	_customer = 0;
}

void CustomerWrapper::LoadCustomer()
{
	hDLL = LoadLibrary(TEXT("RNG.dll"));
	if (hDLL == NULL) return;

	GENERATECUSTOMERRECORD pfGenerateCustomerRecord = (GENERATECUSTOMERRECORD)GetProcAddress(hDLL, "GenerateCustomerRecord");
	_customer = &pfGenerateCustomerRecord();
}

