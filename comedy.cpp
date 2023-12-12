#include "comedy.h"

Comedy::Comedy(int stock, string director, string title, int releaseYear):Movie(stock, director, title)
{
    releaseYear_ = releaseYear;
}

int Comedy::getReleaseYear() const
{
    return releaseYear_;
}

bool Comedy::operator<(const Comedy &other) const
{

    if(getTitle() < other.getTitle()){
        return true;
    }
    //when title are the same or weight the same(char)
    if(releaseYear_ < other.releaseYear_){
        return true;
    }

    return false;
}

bool Comedy::operator>(const Comedy &other) const
{
    return !(*this < other);
}

bool Comedy::operator==(const Comedy &other) const
{
    if(getTitle() != other.getTitle()){
        return false;
    }

    if(releaseYear_ != other.releaseYear_){
        return false;
    }

    //stock and current stock doesn't matter
    return true;
}

bool Comedy::operator!=(const Comedy &other) const
{
    return !(*this == other);
}

void Comedy::print() const
{
    cout << "F, " << getCurrentStock() << ", " << getDirector() << ", " << getTitle() << ", " << releaseYear_ << endl;
}

string Comedy::sortingCriteria()
{
    string returnString = getTitle() + ", " + to_string(releaseYear_);
    return returnString;
}
