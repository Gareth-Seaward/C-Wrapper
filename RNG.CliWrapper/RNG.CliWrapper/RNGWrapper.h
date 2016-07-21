#ifndef H_RNGWRAPPER
#define H_RNGWRAPPER

#include "stdafx.h"
#include "Generator.h"
#include "CustomerWrapper.h"

public ref class RngWrapper
{
public :
	RngWrapper() {}
	~RngWrapper() {}

	System::Collections::Generic::List<ULONG>^ RandomArray();
	CustomerWrapper^ CreateCustomer();

	delegate void CustomerEventHandler(CustomerWrapper^ customer);
	event CustomerEventHandler^ customerSendbackEvent;

	delegate void SomeEventHandler(System::String^ message);
	event SomeEventHandler^ sendbackEvent;
private:
	HINSTANCE hDLL;
};

public ref class MyEventArgs : System::EventArgs {
	System::String^ message;
public:
	MyEventArgs(System::String^ arg) {
		message = arg;
	}
	property System::String^ Message {
		System::String^ get() { return message; }
	}
};

public ref class CustomerEventArgs : System::EventArgs {
	CustomerWrapper^ customerRecord;
public:
	CustomerEventArgs(CustomerWrapper^ arg) {
		customerRecord = arg;
	}
	property CustomerWrapper^ CustomerRecord {
		CustomerWrapper^ get() { return customerRecord; }
	}
};
#endif
