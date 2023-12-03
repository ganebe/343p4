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
    }else{
        return false;
    }
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
