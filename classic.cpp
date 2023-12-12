#include "classic.h"

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

string Classic::getReleaseDate() const
{
    return *releaseDate_;
}

bool Classic::operator<(const Classic &other) const
{

    if(*this == other){
        return false;
    }

    if(*releaseDate_ < *other.releaseDate_){
        return true;
    }

    if(*majorActorName_ < *other.majorActorName_){
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

    if(*sortingCriteria_ != *other.sortingCriteria_){
        return false;
    }
     return true;
}

bool Classic::operator!=(const Classic &other) const
{
    return !(*this == other);
}

void Classic::print() const
{
    cout << "C, " << getCurrentStock() << ", " << getDirector() << ", " << getTitle() << ", " << *majorActorName_ << " " <<  *releaseDate_ << endl;
}

string Classic::sortingCriteria()
{
    return *sortingCriteria_;
}
