#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <string>
#include <iostream>
#include "movie.h"
#include "classic.h"
#include  "comedy.h"
#include "drama.h"
using namespace std;

// ------------------------------------------------Inventory.h -------------------------------------------------------
// CSS 343 B Au 23
// Created on 11/17/2023
// Last Modified on 11/17/2023
// Created by Vince Nguyen, Lok Yin Wong
// --------------------------------------------------------------------------------------------------------------------
// This file contains the headers for the Inventory class which contain functionalities such as borrowing a movie, returning a movie
// and adding a movie to the inventory
// --------------------------------------------------------------------------------------------------------------------
// The Invetory class is using the three vectors as the storage for different kinds of movies.
// --------------------------------------------------------------------------------------------------------------------

class Inventory{

public:

Inventory(); // deafault constructor


bool setBorrow(Movie* &, char movieType, Movie*&);


bool setReturn(Movie* &, char movieType);



void printItmes();



bool addMovie(Movie*&, char movieType); 

private:
vector<Movie*> comedy_movies_; // vector to stroe comedy movies
vector<Movie*> drama_movies_; // vector to store drama movies
vector<Movie*> classics_movies_; // vector to store classcis movies

void dramaSort();
void classcisSort();
void comedySort();
};



#endif