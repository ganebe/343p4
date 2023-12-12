// ----------------------------------------------------comedy.h-------------------------------------------------------
// Vincent Nguyen and Lok Yin Wong CSS 343 B
// 11/17/2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This header file has various functions to handle and process the genre, stock, director, title, and release year
// by the charater 'F' which will be used by the parent class "Movie".
// 
// --------------------------------------------------------------------------------------------------------------------
// The only code/genre inputted can only be 'F' for comedy.
// -------------------------------------------------------------------------------------------------------------------- 

#pragma once
#ifndef COMEDY_H
#define COMEDY_H
#include <string>
#include "movie.h"
#include <vector>

using namespace std;

class Comedy:public Movie
{

public:
	//Constructors
	Comedy(int stock, string director, string title, int releaseYear);


	//getters
	int getReleaseYear() const;

	//Overloads
	bool operator<(const Comedy& other) const;
	bool operator>(const Comedy& other) const;
	bool operator==(const Comedy& other) const;
	bool operator!=(const Comedy& other) const;
	virtual void print() const;
	virtual string  sortingCriteria();

private:
	int releaseYear_;
};
#endif