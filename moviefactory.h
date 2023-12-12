#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
#include <string>
#include <iostream>
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "inventory.h"
using namespace std;

class MovieFactory{

// ------------------------------------------------MovieFactory.h -------------------------------------------------------
// CSS 343 B Au 23
// 12/8/2023
// 12/12/2023
// Created by Vince Nguyen, Lok Yin Wong
// --------------------------------------------------------------------------------------------------------------------
// This file contains the implementations for the MovieFactory class, which checks to see if the string provided is a valid movie string
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

static Movie* createMovie(string input, bool &sucess, char& movieType);

private:


};


#endif