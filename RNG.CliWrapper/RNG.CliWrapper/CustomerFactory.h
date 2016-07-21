#ifndef H_CUSTOMERFACTORY
#define H_CUSTOMERFACTORY

#include "stdafx.h"
#include "Customer.h"

class CustomerFactory {
public :
	CustomerFactory() {};
	~CustomerFactory() {};
	CUSTOMER &CreateCustomerRecord();
};

#endif
