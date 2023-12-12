// ----------------------------------------------------drama.h-------------------------------------------------------
// Vincent Nguyen CSS 343 B
// 11/17/2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This header file has various functions to handle and process the genre, stock, director, title, and release year
// by the charater 'D' which will be used by the parent class "Movie".
// 
// --------------------------------------------------------------------------------------------------------------------
// The only code/genre inputted can only be 'D' for Drama.
// -------------------------------------------------------------------------------------------------------------------- 
#pragma once
#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"
#include <string>
#include <vector>

using namespace std;

class Drama:public Movie
{

public:
	//Constructors
	Drama(int stock, string director, string title, int releaseYear);

	
	//getters
	int getReleaseYear() const;

	//Overloads
	bool operator<(const Drama& other) const;
	bool operator>(const Drama& other) const;
	bool operator==(const Drama& other) const;
	bool operator!=(const Drama& other) const;
	virtual void print() const;
	virtual string sortingCriteria();

private:
	int releaseYear_;
};
#endif