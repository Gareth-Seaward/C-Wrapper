#include "stdafx.h"
#include "CustomerFactory.h"

CUSTOMER CustomerFactory::CreateCustomerRecord()
{
	CUSTOMER customerRecord = {};
	customerRecord.cust_firstName = "Jimmy Bob";
	customerRecord.cust_lastName = "Smith";
	customerRecord.cust_id = 1;

	return customerRecord;
}