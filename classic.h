// ----------------------------------------------------classic.h-------------------------------------------------------
// Vincent Nguyen and Lok Yin Wong CSS 343 B
// 11/17/2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This header file has various functions to handle and process 
// the genre, stock, director, title, major name, release year, and release month
// by the charater 'C' which will be used by the parent class "Movie".
// 
// --------------------------------------------------------------------------------------------------------------------
// The only code/genre inputted can only be 'C' for classics.
// -------------------------------------------------------------------------------------------------------------------- 
#ifndef CLASSICS_H
#define CLASSICS_H
#include "movie.h"
#include <string>
#include <vector>

using namespace std;

class Classic:public Movie
{

public:
	Classic(int stock, string director, string title, string majorActorName, string releaseDate);


	//getters
	string getMajorActorName() const;
	virtual string getReleaseDate() const;

	//Overloads
	bool operator<(const Classic& other) const;	
	bool operator>(const Classic& other) const;
	bool operator==(const Classic& other) const;
	bool operator!=(const Classic& other) const;
	virtual void print() const;
	virtual string  sortingCriteria();

private:
	string * majorActorName_;
	string * releaseDate_;
	string * sortingCriteria_;

};
#endif