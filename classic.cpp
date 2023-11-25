#include "classic.h"

Classic::Classic(int stock, string director, string title, string majorActorFirstName, string MajorActorLastName, int releaseDate):Movie(stock, director, title)
{
    majorActorFirstName_ = majorActorFirstName;
    majorActorLastName_ = MajorActorLastName;
    releaseDate_ = releaseDate;
}

string Classic::getFirstName() const
{
    return majorActorFirstName_;
}

string Classic::getLastName() const
{
    return majorActorLastName_;
}

int Classic::getReleaseDate() const
{
    return releaseDate_;
}

bool Classic::operator<(const Classic &other) const
{

    if(*this == other){
        return false;
    }

    if(releaseDate_ < other.releaseDate_){
        return true;
    }

    if(majorActorFirstName_ < other.majorActorFirstName_){
        return true;
    }

    if(majorActorLastName_ < other.majorActorLastName_){
        return true;
    }

    return false;
}

bool Classic::operator>(const Classic &other) const
{
    return !(*this < other);
}

bool Classic::operator==(const Classic &other) const
{
    if(getDirector() != other.getDirector()){
        return false;
    }

    if(getTitle() != other.getTitle()){
        return false;
    }

    if(releaseDate_ != other.releaseDate_){
        return false;
    }

    if(majorActorFirstName_ != other.majorActorFirstName_){
        return false;
    }

    if(majorActorLastName_ != other.majorActorLastName_){
        return false;
    }
    
    return true;
}

bool Classic::operator!=(const Classic &other) const
{
    return !(*this == other);
}
