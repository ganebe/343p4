#ifndef Verify_H
#define Verify_H
#include <string>
#include <set>
#include "store.h"

class Customer;

class Verify
{
public:
	friend class Store;

	Verify(){};			 // Default Constructor
	virtual ~Verify(){}; // Destructor

	//------------------------- check ---------------------------------
	// Checks if the request is valid according to expected symbols
	//-------------------------------------------------------------------------
	bool check(std::string identifier);

private:

};

#endif
