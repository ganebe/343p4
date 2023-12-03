#include "movie.h"

Movie::Movie(int stock, const string &director, const string &title)
{
    current_stock_ = stock;
    stock_ = stock;
    director_ = director;
    title_ = title;
}


int Movie::getStock() const
{
    return stock_;
}

void Movie::setStock(int stock)
{
    stock_ = stock;
}

int Movie::getCurrentStock() const
{
    return current_stock_;
}

const string &Movie::getDirector() const
{
    return director_;
}

const string &Movie::getTitle() const
{
    return title_;
}

bool Movie::borrowMovie()
{
    if(current_stock_ > 0 )
    {
        current_stock_ --;
        return true;
    }

    return false;
}

bool Movie::returnMovie()
{
    if(current_stock_ >= stock_)
    {
        return false;
    }

    current_stock_++;
    return true;
    
}

void Movie::print() const
{
}

bool Movie::operator==(const Movie &other) const
{
    return false;
}

bool Movie::operator!=(const Movie &other) const
{
    return false;
}

bool Movie::operator<(const Movie &other) const
{
    return false;
}

bool Movie::operator>(const Movie &other) const
{
    return false;
}
