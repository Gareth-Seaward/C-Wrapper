#ifndef H_CUSTOMER
#define H_CUSTOMER

#include "stdafx.h"

const unsigned short MAX_FIRSTNAME(20);
const unsigned short MAX_LASTNAME(50);

typedef struct {
public:
	char *cust_firstName;
	char *cust_lastName;
	unsigned int cust_id;
} CUSTOMER;
#endif
