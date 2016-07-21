#ifndef H_GENERATOR
#define H_GENERATOR

#include "stdafx.h"
#include <random> //for std::random_device and std::mt19937
#include <utility>
#include "CustomerFactory.h"

#ifdef DLL_EXPORTS
#define DLLCALL extern "C" __declspec(dllexport)
#else
#define DLLCALL extern "C" __declspec(dllimport)
#endif

const int ARRAY_SIZE(48);
typedef unsigned long long u_int64;

DLLCALL u_int64* GenerateNumberArray();
DLLCALL void SortArrayAscending(u_int64 numberArray[], int arrayLength);

DLLCALL CUSTOMER GenerateCustomerRecord();

typedef u_int64* (__cdecl *GENERATENUMBERARRAY)();
typedef CUSTOMER (__cdecl *GENERATECUSTOMERRECORD)();

#endif
