#include "drama.h"

Drama::Drama(int stock, string director, string title, int releaseYear):Movie(stock, director, title)
{
    releaseYear_ = releaseYear;
}

int Drama::getReleaseYear() const
{
    return releaseYear_;
}

bool Drama::operator <(const Drama &other) const
{

    if(*this == other){
        return false;
    }

    
    if(getDirector() < other.getDirector()){
        return true;
    }

    if(getTitle() < other.getTitle()){
        return true;
    }

    return false;
}

bool Drama::operator >(const Drama &other) const
{
    return !(*this < other);
}

bool Drama::operator==(const Drama &other) const
{
    if(getTitle() != other.getTitle()){
        return false;
    }

    if(releaseYear_ != other.releaseYear_){
        return false;
    }

    if(getDirector() != other.getDirector()){
        return false;
    }

    //stock and current stock doesn't matter
    return true;
}

bool Drama::operator!=(const Drama &other) const
{
    return !(*this == other);
}