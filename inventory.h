#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <string>
#include "movie.h"
using namespace std;

// ------------------------------------------------Inventory.h -------------------------------------------------------
// CSS 343 B Au 23
// Created on 11/17/2023
// Last Modified on 11/17/2023
// Created by Vince Nguyen, Lok Yin Wong, Chin Cheung Lam, Thomas Nguyen
// --------------------------------------------------------------------------------------------------------------------
// This file contains the headers for the Inventory class, parameters are not fully filled and may be changed later.
 // However, it contains the core functions that the Inventory has.
// --------------------------------------------------------------------------------------------------------------------
// The Invetory class is using the three vectors as the storage for different kinds of movies.
// --------------------------------------------------------------------------------------------------------------------

class Inventory{

public:

Inventory(); // deafault constructor

//------------------------- setReturn ---------------------------------
// borrow a movie from the inventory
//-------------------------------------------------------------------------
bool setBorrow(Movie&);

//------------------------- setReturn ---------------------------------
// return a movie to the inventory
//-------------------------------------------------------------------------
bool setReturn(Movie&);


//------------------------- addMovie ---------------------------------
//  outputs the inventory of all the items in the store 
//-------------------------------------------------------------------------
void printItmes();


//------------------------- addMovie ---------------------------------
// Adds a movie to the inventory
//-------------------------------------------------------------------------
bool addMovie(Movie&); 

private:
vector<Movie> comedy_movies_; // vector to stroe comedy movies
vector<Movie> drama_movies_; // vector to store drama movies
vector<Movie> classics_movies_; // vector to store classcis movies

};


#endif