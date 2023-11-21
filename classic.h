// ----------------------------------------------------comedy.h-------------------------------------------------------
// Vincent Nguyen CSS 343 B
// 11/17/2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This header file has various functions to handle and process 
// the genre, stock, director, title, major name, release year, and release month
// by the charater 'C' which will be used by the parent class "Movie".
// 
// --------------------------------------------------------------------------------------------------------------------
// The only code/genre inputted can only be 'C' for comedy.
// -------------------------------------------------------------------------------------------------------------------- 
#ifndef CLASSICS_H
#define CLASSICS_H
#include "movie.h"
#include <string>
#include <vector>

using namespace std;

class Classic:Movie
{

public:
	//Constructors
	Classic();
	Classic(int stock, string director, string title,  string majorNameAndReleaseDate);

	//Destructor
	~Classic();

	//getters
	string getMajorNameAndReleaseDate() const;

	//Overloads
	bool operator<(const Classic& other) const;
	bool operator>(const Classic& other) const;
	bool operator==(const Classic& other) const;
	bool operator!=(const Classic& other) const;

private:
	string majorNameAndReleaseDate;

};
#endif