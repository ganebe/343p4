// ----------------------------------------------------drama.cpp-------------------------------------------------------
// Vincent Nguyen CSS 343 B
// 11/17/2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This implementation file has various functions to handle and process the genre, stock, director, title, and release year
// by the charater 'D' which will be used by the parent class "Movie".
// 
// --------------------------------------------------------------------------------------------------------------------
// The only code/genre inputted can only be 'D' for comedy.
// -------------------------------------------------------------------------------------------------------------------- 

#include "drama.h"

//----------------------------Comedy constructor-----------------------
// Constructor for Drama movies 
//---------------------------------------------------------------

Drama::Drama(int stock, string director, string title, int releaseYear):Movie(stock, director, title)
{
    releaseYear_ = releaseYear; //Initialize release year
}

//----------------------------getReleaseYear-----------------------
// Returns release year
//---------------------------------------------------------------

int Drama::getReleaseYear() const
{
    return releaseYear_;
}

//---------------------------operator overload <---------------------------
//Compares two movies to see if the first one less than the second
//---------------------------------------------------------------

bool Drama::operator <(const Drama &other) const
{

    if(*this == other){
        return false;
    }

    
    if(getDirector() < other.getDirector()){
        return true;
    }

    if(getDirector() == other.getDirector() && getTitle() < other.getTitle()){
        return true;
    }

    return false;
}

//---------------------------operator overload >---------------------------
//Compares two movies to see if the first one is greater
//than the second
//---------------------------------------------------------------

bool Drama::operator >(const Drama &other) const
{
    return !(*this < other);
}

//---------------------------operator overload ==---------------------------
//Compares two movies to if the movies are the same
//---------------------------------------------------------------


bool Drama::operator==(const Drama &other) const
{
    if(getTitle() != other.getTitle())  //Comparing titles
    {
        return false;
    }

    if(getDirector() != other.getDirector()) //Comparing directors
    {
        return false;
    }


    return true; //stock and current stock doesn't matter
}

//---------------------------operator overload !=---------------------------
//Compares two movies to if the movies are not the same
//--------------------------------------------------------------- 

bool Drama::operator!=(const Drama &other) const
{
    return !(*this == other);
}

//---------------------------print---------------------------
//Prints the comedy movie in a certain format
//--------------------------------------------------------------- 

void Drama::print() const
{
    cout << "D, " << getCurrentStock() << ", " << getDirector() << ", " << getTitle() << ", " << releaseYear_ << endl;
}

//---------------------------sortingCriteria---------------------------
//Sorts the movies
//--------------------------------------------------------------- 

string Drama::sortingCriteria()
{
    string returnString = getDirector() + ", " + getTitle() + ","; //Sorting the movie by the director and the title
    return returnString; 
}
