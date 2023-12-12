// ------------------------------------------------movie.h -------------------------------------------------------
// CSS 343 B Au 23
// Created on 11/17/2023
// Last Modified on 11/17/2023
// Created by Vince Nguyen, Lok Yin Wong
// --------------------------------------------------------------------------------------------------------------------
// This file contains the implementations for the movie class which has functionalities that grab a movies stock, the director,
// the title, allowing to borrow and return a movie, and the release date.
// --------------------------------------------------------------------------------------------------------------------
// Functionalities are common across all movie objects
// --------------------------------------------------------------------------------------------------------------------
#include "movie.h"

//------------------------- Movie constructor ---------------------------------
// Default constructor for the movie class
//-------------------------------------------------------------------------
Movie::Movie(int stock, const string &director, const string &title)
{
   
    current_stock_ = stock;  //Initializing current stock
    stock_ = stock;  //Initializing stock
    director_ = director;  //Initializing director
    title_ = title;  //Initializing title
}

//------------------------- getStock ---------------------------------
// Returns the stock of movies
//-------------------------------------------------------------------------

int Movie::getStock() const
{
    return stock_;
}

//------------------------- setStock ---------------------------------
// Sets the stock of movies
//-------------------------------------------------------------------------
void Movie::setStock(int stock)
{
    stock_ = stock;
}

//------------------------- getCurrentStock ---------------------------------
// Returns the current stock of movies
//-------------------------------------------------------------------------
int Movie::getCurrentStock() const
{
    return current_stock_;
}

//------------------------- getDirector ---------------------------------
// Returns the director for the movie
//-------------------------------------------------------------------------
const string &Movie::getDirector() const
{
    return director_;
}

//------------------------- getTitle---------------------------------
// Returns the title of the movie
//-------------------------------------------------------------------------
const string &Movie::getTitle() const
{
    return title_;
}

//------------------------- borrowMovie---------------------------------
// Decrements the movie stock if we are trying to borrow
//-------------------------------------------------------------------------
bool Movie::borrowMovie()
{
    if(current_stock_ > 0 ) //If there is a stock available
    {
        current_stock_ --;
        return true;
    }

    return false;
}

//------------------------- returnMovie---------------------------------
// Increments the movie stock if we are trying to return
//-------------------------------------------------------------------------
bool Movie::returnMovie()
{
    if(current_stock_ >= stock_)
    {
        return false;
    }

    current_stock_++;
    return true;
    
}

//------------------------- sortingCriteria---------------------------------
// Sorts the criterias for the movies
//-------------------------------------------------------------------------
string Movie::sortingCriteria()
{
    return string();
}

//------------------------- print---------------------------------
// Default printer for the movie class
//-------------------------------------------------------------------------
void Movie::print() const
{
    cout << "deafault movie print" << endl;
}

//------------------------- getReleaseDate---------------------------------
// returns the release date of the movie
//-------------------------------------------------------------------------
string Movie::getReleaseDate() const
{
    return string();
}

//------------------------- operator overload == ---------------------------------
// Comparison of 2 movies
//-------------------------------------------------------------------------
bool Movie::operator==(const Movie &other) const
{
    return false;
}

//------------------------- operator overload != ---------------------------------
// Comparison of 2 movies
//-------------------------------------------------------------------------
bool Movie::operator!=(const Movie &other) const
{
    return false;
}

//------------------------- operator overload > ---------------------------------
// Comparison of 2 movies
//-------------------------------------------------------------------------
bool Movie::operator<(const Movie &other) const
{
    return false;
}

//------------------------- operator overload < ---------------------------------
// Comparison of 2 movies
//-------------------------------------------------------------------------
bool Movie::operator>(const Movie &other) const
{
    return false;
}
