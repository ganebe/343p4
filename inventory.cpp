#include "inventory.h"

Inventory::Inventory()
{
}

void Inventory::printItmes()
{
    for(int i = 0 ; i < comedy_movies_.size(); i++){
        comedy_movies_[i].print();
    }
    for(int i = 0 ; i < drama_movies_.size(); i++){
        drama_movies_[i].print();
    }
    for(int i = 0 ; i < classics_movies_.size(); i++){
        classics_movies_[i].print();
    }

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
        int index = -1;
        for(int i = 0; i < classics_movies_.size(); i++ ){
            if(classics_movies_[i] == newMovie){
                index = i;
            }
        }
        if(index != -1){
            if(classics_movies_[index].borrowMovie() == true){
                return true;
            }

            vector<int> sameMovies;
            for(int i = 0; i < classics_movies_.size(); i++){
                if(classics_movies_[i].getTitle() == classics_movies_[index].getTitle()
                && classics_movies_[i].getDirector() == classics_movies_[index].getDirector()
                && classics_movies_[i].getReleaseDate() == classics_movies_[index].getReleaseDate()){
                    sameMovies.push_back(i);
                }
            }

            for(int i = 0; i < sameMovies.size(); i++){
                if(classics_movies_[sameMovies[i]].borrowMovie() == true){
                    return true;
                }
            }
            return false;
        }

    }
    else
    {
        return false;
    }

    if(movieType == 'D' || movieType == 'F'){
        for (Movie& other : *movies) 
        {
            if (other == newMovie && other.getCurrentStock() > 0) 
            {
                return other.borrowMovie();
            }
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
        int index = -1;
        for(int i = 0; i < classics_movies_.size(); i++ ){
            if(classics_movies_[i] == newMovie){
                index = i;
            }
        }
        if(index != -1){
            if(classics_movies_[index].returnMovie() == true){
                return true;
            }

            vector<int> sameMovies;
            for(int i = 0; i < classics_movies_.size(); i++){
                if(classics_movies_[i].getTitle() == classics_movies_[index].getTitle()
                && classics_movies_[i].getDirector() == classics_movies_[index].getDirector()
                && classics_movies_[i].getReleaseDate() == classics_movies_[index].getReleaseDate()){
                    sameMovies.push_back(i);
                }
            }

            for(int i = 0; i < sameMovies.size(); i++){
                if(classics_movies_[sameMovies[i]].returnMovie() == true){
                    return true;
                }
            }
            return false;


        }else{
            return false;
        }
    }
    else
    {
        return false;
    }

    for (Movie& other : *movies) 
    {
        if(other == newMovie)
        {
            return other.returnMovie();
        }
    }

    
    return false;
}

bool Inventory::addMovie(Movie &newMovie, char movieType)
{
    if(movieType == 'C'){
        for(int i = 0; i < classics_movies_.size(); i ++){
            if(classics_movies_[i] == newMovie){
                return false;
            }
        }
        classics_movies_.push_back(newMovie);
        movieSort(classics_movies_);
        return true;
    }else if(movieType == 'F'){
        for(int i = 0; i < comedy_movies_.size(); i ++){
            if(comedy_movies_[i] == newMovie){
                return false;
            }
        }
        comedy_movies_.push_back(newMovie);
        movieSort(comedy_movies_);
        return true;        
    }else if(movieType == 'D'){
        for(int i = 0; i < drama_movies_.size(); i ++){
            if(drama_movies_[i] == newMovie){
                return false;
            }
        }
        drama_movies_.push_back(newMovie);
        movieSort(drama_movies_);
        return true;
    }

    return false;
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
