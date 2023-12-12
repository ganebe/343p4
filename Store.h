// ------------------------------------------------store.h -------------------------------------------------------
// CSS 343 B Au 23
// Created on 11/17/2023
// Last Modified on 11/17/2023
// Created by Vince Nguyen, Lok Yin Wong
// --------------------------------------------------------------------------------------------------------------------
// This file contains the headers for the store class which has functionalities that reads the customer's information
// and all the movie information that is stored from the movie class.
// --------------------------------------------------------------------------------------------------------------------
// All movies should be read correctly
// --------------------------------------------------------------------------------------------------------------------

#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "hash.h"
#include "inventory.h"
#include "customer.h"
#include "moviefactory.h"
using namespace std;

class Store
{
public:
    Store(); // constructor

    
    void loadMovies(string);

  
    void loadCustomers(string);

    
    void runCommands(string); // reads and runs commands file

private:
    Hash<int, Customer*> customers_;  // instance variable for Customer class
    Inventory inventory_; // instance variable for Inventory class

    void borrow(stringstream&);
    void returnMovie(stringstream&);
};
#endif
