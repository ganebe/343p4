// ----------------------------------------------------classic.cpp-------------------------------------------------------
// Vincent Nguyen and Lok Yin Wong CSS 343 B
// 12/8/2023
// 12/12/2023
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
Classic::Classic(int stock, string director, string title, string majorActorName, string releaseDate):Movie(stock, director, title)
{
    majorActorName_ = new string(majorActorName);
    releaseDate_ = new string(releaseDate);
    sortingCriteria_ = new string(releaseDate + " " +majorActorName);
}

string Classic::getMajorActorName() const
{
    return *majorActorName_;
}

//----------------------getReleaseDate------------------------
//Returns the release date
//---------------------------------------------------------------
string Classic::getReleaseDate() const
{
    return *releaseDate_;
}

//---------------------------operator overload <---------------------------
//Compares two movies to see if the first one less than the second
//---------------------------------------------------------------
bool Classic::operator<(const Classic &other) const
{

    int month, year, otherMonth, otherYear;
    stringstream ss(*releaseDate_);
    stringstream ss2(*other.releaseDate_);
    ss >> month >> year;
    ss2 >> otherMonth >> otherYear;
    if(year < otherYear){
        
        return true;
    }

    if(year == otherYear && month < otherMonth){
        return true;
    }

    if(year == otherYear && month == otherMonth){
        if(*majorActorName_ < *other.majorActorName_){
            return true;
        }
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

    if(*sortingCriteria_ != *other.sortingCriteria_){
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
    cout << "C, " << getCurrentStock() << ", " << getDirector() << ", " << getTitle() << ", " << *majorActorName_ << " " <<  *releaseDate_ << endl;
}

//---------------------------sortingCriteria---------------------------
//Sorts the movies
//--------------------------------------------------------------- 

string Classic::sortingCriteria()
{
    return *sortingCriteria_;
}
