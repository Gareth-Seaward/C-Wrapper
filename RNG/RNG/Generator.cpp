#include "stdafx.h"
#include "Generator.h"

u_int64* GenerateNumberArray()
{
	std::random_device rd; //Use a hardware	entropy device if available, otherwise use PRNG
	std::mt19937_64 mersenne(rd());

	u_int64 array[ARRAY_SIZE] = {};

	for (int count = 0; count < ARRAY_SIZE; ++count)
	{
		array[count] = mersenne();
	}

	return (u_int64*)array;
}

void SortArrayAscending(u_int64 numberArray[], int arrayLength)
{
	for (int index = 1; index < arrayLength; index++)
	{
		for (int marker = index; marker > 0; marker--)
		{
			if (numberArray[marker] < numberArray[marker - 1])
				std::swap(numberArray[marker], numberArray[marker - 1]);
			else break;
		}
	}
}

CUSTOMER GenerateCustomerRecord()
{
	CustomerFactory* factory = new CustomerFactory();
	CUSTOMER customerRecord = factory->CreateCustomerRecord();

	//customerRecord = (CUSTOMER)factory->CreateCustomerRecord();
	delete factory;
	factory = 0;

	return customerRecord;
}