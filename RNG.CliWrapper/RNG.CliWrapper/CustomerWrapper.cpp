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

	/*delete _customer;
	_customer = 0;*/
}

CustomerWrapper::!CustomerWrapper()
{
	if (hDLL)
		FreeLibrary(hDLL);

	//delete _customer;
	//_customer = 0;
}

void CustomerWrapper::LoadCustomer()
{
	hDLL = LoadLibrary(TEXT("RNG.dll"));
	if (hDLL == NULL) return;

	GENERATECUSTOMERRECORD pfGenerateCustomerRecord = (GENERATECUSTOMERRECORD)GetProcAddress(hDLL, "GenerateCustomerRecord");
	CUSTOMER* customer = &pfGenerateCustomerRecord();

	MapToManaged(customer);
}

void CustomerWrapper::MapToManaged(CUSTOMER* customer)
{
	_customer.cust_firstName = customer->cust_firstName;
	_customer.cust_lastName = customer->cust_lastName;
	
	_customer.cust_id = customer->cust_id;
}

