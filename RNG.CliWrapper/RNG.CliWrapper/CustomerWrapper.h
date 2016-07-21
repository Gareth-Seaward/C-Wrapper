#ifndef H_CUSTOMERWRAPPER
#define H_CUSTOMERWRAPPER

#include "stdafx.h"
#include "Customer.h"
#include "Generator.h"

public ref struct CustomerWrapper {
public:
	CustomerWrapper();
	~CustomerWrapper();//Dispose
	!CustomerWrapper();//Finalize

	property System::String ^FirstName
	{
		System::String ^get()
		{
			//return gcnew System::String(_customer->cust_firstName);
			return System::Runtime::InteropServices::Marshal::PtrToStringAnsi(System::IntPtr(_customer->cust_firstName));
		}
		void set(System::String^ value)
		{
			char *unmanagedVal = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(value).ToPointer();
			memcpy(_customer->cust_firstName, unmanagedVal, sizeof(unmanagedVal));
		}
	}

	property System::String ^LastName
	{
		System::String ^get()
		{
			return gcnew System::String(_customer->cust_lastName);
		}
		void set(System::String^ value)
		{
			char *unmanagedVal = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(value).ToPointer();
			memcpy(_customer->cust_lastName, unmanagedVal, sizeof(unmanagedVal));
		}
	}

	property int CustomerId
	{
		int get()
		{
			return _customer->cust_id;
		}
		void set(int value)
		{
			_customer->cust_id = value;
		}
	}
	CUSTOMER *_customer;
private :
	HINSTANCE hDLL;
	void LoadCustomer();
	
};


#endif
