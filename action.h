#ifndef ACTION_H
#define ACTION_H
#include <string>
#include "inventory.h"
#include "customer.h"
#include "hashtable.h"
#include "moviefactory.h"
using namespace std;
// ------------------------------------------------Action.h -------------------------------------------------------
// CSS 343 B Au 23
// Created on 11/17/2023
// Last Modified on 11/17/2023
// Created by Vince Nguyen, Lok Yin Wong, Chin Cheung Lam, Thomas Nguyen
// --------------------------------------------------------------------------------------------------------------------
// This file contains the headers for the Action class, parameters are not fully filled and may be changed later.
 // However, it contains the core functions that the Action has.
// --------------------------------------------------------------------------------------------------------------------
// The class will set a movie to be borrow or return and record in both the history and the all history.
// Furthermore, it can also prints out Inventory history and history from specific customer.
// --------------------------------------------------------------------------------------------------------------------

class Action{

public:
Action(); //Default construction for the action, however there is no variables to initialize, so it basically doesn't do anything
~Action();

//------------------------- Borrow ---------------------------------
//Return true when the movie requested has stock in the inventory
// and the customer exist. Otherwise return false.
//-------------------------------------------------------------------------
bool Borrow(Movie&, int customer_id);


//------------------------- Borrow ---------------------------------
//Return true when the movie returned got borrow before and
// the customer exist and borrow the movie before. Otherwise return false
//-------------------------------------------------------------------------
bool Return(Movie&, int customer_id);


//------------------------- Inventory ---------------------------------
//  outputs the inventory of all the items in the store
//-------------------------------------------------------------------------
void Inventory();


//------------------------- History ---------------------------------
//  outputs all the transactions of a customer if the customer does exist
//-------------------------------------------------------------------------
void History(int customer_id);


//------------------------- addNewMovie ---------------------------------
// create and add the new movie to the inventory
// return true if movie was sucessfully added, otherwise return false
//-------------------------------------------------------------------------
bool addNewMovie(string type);

private:

};


#endif