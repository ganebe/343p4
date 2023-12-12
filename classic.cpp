// ----------------------------------------------------classic.cpp-------------------------------------------------------
// Vincent Nguyen CSS 343 B
// 11/17/2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This implementation file has various functions to handle and process 
// the genre, stock, director, title, major name, release year, and release month
// by the charater 'C' which will be used by the parent class "Movie".
// 
// --------------------------------------------------------------------------------------------------------------------
// The only code/genre inputted can only be 'C' for classics.
// -------------------------------------------------------------------------------------------------------------------- 
#include "classic.h"

//----------------------------Classic constructor-----------------------
// Constructor for Classic movies 
//---------------------------------------------------------------
Classic::Classic(int stock, string director, string title, string majorActorFirstName, string MajorActorLastName, string releaseDate):Movie(stock, director, title)
{
    majorActorFirstName_ = majorActorFirstName; //Initializing major first name
    majorActorLastName_ = MajorActorLastName; //Initializing major last name
    releaseDate_ = releaseDate;                //Initializing release date
}

//----------------------getFirstName------------------------
//Returns the first name of the actor
//---------------------------------------------------------------
string Classic::getFirstName() const
{
    return majorActorFirstName_; //return first name
}

//----------------------getLastName------------------------
//Returns the last name of the actor
//---------------------------------------------------------------
string Classic::getLastName() const
{
    return majorActorLastName_; //return last name
}

//----------------------getReleaseDate------------------------
//Returns the release date
//---------------------------------------------------------------
string Classic::getReleaseDate() const
{
    return releaseDate_; //return release date
}

//---------------------------operator overload <---------------------------
//Compares two movies to see if the first one less than the second
//---------------------------------------------------------------
bool Classic::operator<(const Classic &other) const
{

    if(*this == other) //If movies are equal 
    {
        return false;
    }

    if(releaseDate_ < other.releaseDate_) //Comparing release dates
    {
        return true;
    }

    if(majorActorFirstName_ < other.majorActorFirstName_) //Comparing first names 
    {
        return true;
    }

    if(majorActorLastName_ < other.majorActorLastName_) //Comparing last names
    {
        return true;
    }

    return false;
}

//---------------------------operator overload >---------------------------
//Compares two movies to see if the first one is greater
//than the second
//---------------------------------------------------------------

bool Classic::operator>(const Classic &other) const
{
    return !(*this < other);
}

//---------------------------operator overload ==---------------------------
//Compares two movies to if the movies are the same
//---------------------------------------------------------------

bool Classic::operator==(const Classic &other) const
{

    if(releaseDate_ != other.releaseDate_) // If release dates are not equal
    {
        return false;
    }

    if(majorActorFirstName_ != other.majorActorFirstName_) //If first names are not equal
    {
        return false;
    }

    if(majorActorLastName_ != other.majorActorLastName_) //If last names are not equal
    {
        return false;
    }
    
    return true;
}

//---------------------------operator overload !=---------------------------
//Compares two movies to if the movies are not the same
//--------------------------------------------------------------- 

bool Classic::operator!=(const Classic &other) const
{
    return !(*this == other);
}

//---------------------------print---------------------------
//Prints the classic movie in a certain format
//--------------------------------------------------------------- 

void Classic::print() const
{
    cout << "C, " << getCurrentStock() << ", " << getDirector() << ", " << getTitle() << ", " << majorActorFirstName_ << " " <<  majorActorLastName_ << " " << releaseDate_ << endl;
}

//---------------------------sortingCriteria---------------------------
//Sorts the movies
//--------------------------------------------------------------- 

string Classic::sortingCriteria()
{
    string returnString = releaseDate_ + " " + majorActorFirstName_ + " " + majorActorLastName_ ; //Storing release date, first and last name of classic movie
    return returnString; 
}
