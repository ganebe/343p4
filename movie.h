// ------------------------------------------------movie.h -------------------------------------------------------
// CSS 343 B Au 23
// Created on 11/17/2023
// Last Modified on 11/17/2023
// Created by Vince Nguyen, Lok Yin Wong
// --------------------------------------------------------------------------------------------------------------------
// This file contains the headers for the movie class which has functionalities that grab a movies stock, the director,
// the title, allowing to borrow and return a movie, and the release date.
// --------------------------------------------------------------------------------------------------------------------
// Functionalities are common across all movie objects
// --------------------------------------------------------------------------------------------------------------------
#ifndef MOVIE_H_
#define MOVIE_H_
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Movie 
{
public:

    // Constructor	
    Movie(int stock, const string& director, const string& title);


    // Virtual destructor
    virtual ~Movie() = default;

    // get stock
    int getStock() const;

    // set stock
    void setStock(int stock);

    // get current stock
    int getCurrentStock()const;

    // get director
    const string& getDirector() const;
    // get title
    const string& getTitle() const;

    // borrowing and returning functions
    bool borrowMovie();
    bool returnMovie();
    virtual string  sortingCriteria();
    virtual void print() const;
    virtual string getReleaseDate() const;
    // Comparison operators
    virtual bool operator==(const Movie& other) const;
    virtual bool operator!=(const Movie& other) const;
	virtual bool operator<(const Movie& other) const;
	virtual bool operator>(const Movie& other) const;
private:
    int current_stock_; // Number of stock available.
    int stock_; // Number of stock.
    string director_, title_; // Director of the movie and title of the movie.
};
#endif
