#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "hash.h"
#include "inventory.h"
#include "customer.h"
#include "action.h"
#include "verify.h"
using namespace std;

class Store
{
public:
    Store(); // constructor

    //------------------------- loadMovies ---------------------------------
    // Reads DVD movie information from the specified file.
    //-------------------------------------------------------------------------
    void loadMovies(string);

    //------------------------- loadCustomers ---------------------------------
    // Reads customer information from the specified file.
    //-------------------------------------------------------------------------
    void loadCustomers(string);

    //------------------------- runCommands ---------------------------------
    // Reads and runs command information from the specified file.  
    //-------------------------------------------------------------------------
    void runCommands(string); // reads and runs commands file

    //------------------------- addCustomer ---------------------------------
    // add new customer to the hash table
    //-------------------------------------------------------------------------    
    void addCustomer();

private:
    Hash<int, Customer*> customers_;  // instance variable for Customer class
    Inventory inventory_; // instance variable for Inventory class
    Action action_;       // instance variable for Action class
    Verify Verifier_;   //instance variable for verify class
};
#endif
