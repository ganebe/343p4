#include "inventory.h"

Inventory::Inventory()
{
}

bool Inventory::setBorrow(Movie &newMovie, char movieType)
{
    vector<Movie>* movies = nullptr;
    if (movieType == 'F')
    {
        movies = &comedy_movies_;
    }
    else if(movieType == 'D')
    {
        movies = &drama_movies_;
    }
    else if (movieType == 'C')
    {
        movies = &classics_movies_;
    }
    else
    {
        return false;
    }

    for (Movie& other : *movies) 
    {
        if (other == newMovie && other.getCurrentStock() > 0) 
        {
            other.borrowMovie();
            return true;
        }
    }

    
    return false;
}

bool Inventory::setReturn(Movie &newMovie, char movieType)
{
   vector<Movie>* movies = nullptr;
    if (movieType == 'F')
    {
        movies = &comedy_movies_;
    }
    else if(movieType == 'D')
    {
        movies = &drama_movies_;
    }
    else if (movieType == 'C')
    {
        movies = &classics_movies_;
    }
    else
    {
        return false;
    }

    for (Movie& other : *movies) 
    {
        if(other == newMovie)
        {
            other.returnMovie();
            return true;
        }
    }

    
    return false;
}

bool Inventory::addMovie(Movie &newMovie, char movieType)
{
    if(movieType == 'C')
    {
        classics_movies_.push_back(newMovie);
    }
    else if(movieType == 'F')
    {
       comedy_movies_.push_back(newMovie);
    }
    else if(movieType == 'D')
    {
        drama_movies_.push_back(newMovie);
    }
    else
    {
        return false;
    }
    return true;
}

void Inventory::movieSort(vector<Movie> & sort_arr) 
{
    for(int i = 0; i < sort_arr.size(); i++){
        for(int j = 0; j < sort_arr.size() - 1; j++ ){
            if(sort_arr[j] > sort_arr [j+1]){
                Movie temp = sort_arr[j];
                sort_arr[j] = sort_arr[j+1];
                sort_arr[j+1] = temp;
            }
        }
    }
}
