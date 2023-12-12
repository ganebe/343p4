// ----------------------------------------------------comedy.cpp-------------------------------------------------------
// Vincent Nguyen CSS 343 B
// 11/17/2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This implementation file has various functions to handle and process the genre, stock, director, title, and release year
// by the charater 'F' which will be used by the parent class "Movie".
// 
// --------------------------------------------------------------------------------------------------------------------
// The only code/genre inputted can only be 'F' for comedy.
// -------------------------------------------------------------------------------------------------------------------- 

#include "comedy.h"

//----------------------------Comedy constructor-----------------------
// Constructor for Comedy movies 
//---------------------------------------------------------------
Comedy::Comedy(int stock, string director, string title, int releaseYear):Movie(stock, director, title)
{
    releaseYear_ = releaseYear; //Initialize release year
}

//----------------------------getReleaseYear-----------------------
// Returns release year
//---------------------------------------------------------------

int Comedy::getReleaseYear() const
{
    return releaseYear_;
}

//---------------------------operator overload <---------------------------
//Compares two movies to see if the first one less than the second
//---------------------------------------------------------------

bool Comedy::operator<(const Comedy &other) const
{

    if(getTitle() < other.getTitle()) //Comparing titles
    {
        return true;
    }
    
    if( getTitle() == other.getTitle() && releaseYear_ < other.releaseYear_) //when title are the same or weight the same(char)
    {
        return true;
    }

    return false;
}

//---------------------------operator overload >---------------------------
//Compares two movies to see if the first one is greater
//than the second
//---------------------------------------------------------------

bool Comedy::operator>(const Comedy &other) const
{
    return !(*this < other);
}

//---------------------------operator overload ==---------------------------
//Compares two movies to if the movies are the same
//---------------------------------------------------------------

bool Comedy::operator==(const Comedy &other) const
{
    if(getTitle() != other.getTitle()) //Comparing titles
    {
        return false;
    }

    if(releaseYear_ != other.releaseYear_) //Comparing release year
    {
        return false;
    }

    return true;//stock and current stock doesn't matter
}

//---------------------------operator overload !=---------------------------
//Compares two movies to if the movies are not the same
//--------------------------------------------------------------- 

bool Comedy::operator!=(const Comedy &other) const
{
    return !(*this == other);
}

//---------------------------print---------------------------
//Prints the comedy movie in a certain format
//--------------------------------------------------------------- 
void Comedy::print() const
{
    cout << "F, " << getCurrentStock() << ", " << getDirector() << ", " << getTitle() << ", " << releaseYear_ << endl;
}

//---------------------------sortingCriteria---------------------------
//Sorts the movies
//--------------------------------------------------------------- 

string Comedy::sortingCriteria()
{
    string returnString = getTitle() + ", " + to_string(releaseYear_); //Storing the title and release year
    return returnString;
}
