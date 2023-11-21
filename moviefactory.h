#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
#include <string>
#include "movie.h"
#include "inventory.h"

class MovieFactory{

// ------------------------------------------------MovieFactory.h -------------------------------------------------------
// CSS 343 B Au 23
// Created on 11/17/2023
// Last Modified on 11/17/2023
// Created by Vince Nguyen, Lok Yin Wong, Chin Cheung Lam, Thomas Nguyen
// --------------------------------------------------------------------------------------------------------------------
// This file contains the headers for the MovieFactory class, parameters are not fully filled and may be changed later.
 // However, it contains the core functions that the MovieFactory has.
// --------------------------------------------------------------------------------------------------------------------
// The MovieFactory class is use to constructor a movie object
// --------------------------------------------------------------------------------------------------------------------

public:

MovieFactory(); // deafualt constructor

//------------------------- createMovie ---------------------------------
//Return a movie based on the string passed in, however
// if the string is not vaild, it will return false with the bool parameter
// and the movie it returns shouldn't be used 
//-------------------------------------------------------------------------

static Movie* createMovie(string type, bool& sucess);

private:

};


#endif