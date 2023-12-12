// ------------------------------------------------Inventory.cpp -------------------------------------------------------
// CSS 343 B Au 23
// Created on 11/17/2023
// Last Modified on 11/17/2023
// Created by Vince Nguyen, Lok Yin Wong, Chin Cheung Lam, Thomas Nguyen
// --------------------------------------------------------------------------------------------------------------------
// This file contains the implementation for the Inventory class which contain functionalities such as borrowing a movie, returning a movie
// and adding a movie to the inventory
// --------------------------------------------------------------------------------------------------------------------
// The Invetory class is using the three vectors as the storage for different kinds of movies.
// --------------------------------------------------------------------------------------------------------------------
#include "inventory.h"

//------------------------- Default constructor ---------------------------------
// 
//-------------------------------------------------------------------------
Inventory::Inventory()
{
}

//------------------------- printItems ---------------------------------
// Printing the items that is stored in the Inventory
//-------------------------------------------------------------------------
void Inventory::printItmes()
{
    cout << "Inventory items:" << endl;
    for(int i = 0 ; i < comedy_movies_.size(); i++) //Looping through comedy array
    {
        comedy_movies_[i]->print();
    }
    for(int i = 0 ; i < drama_movies_.size(); i++) //Looping through drama array
    {
        drama_movies_[i]->print();
    }
    for(int i = 0 ; i < classics_movies_.size(); i++) //Looping through classics array
    {
        classics_movies_[i]->print();
    }

}

bool Inventory::setBorrow(Movie* &newMovie, char movieType, Movie* & rentedMovied )
{

    if (movieType == 'F') //If the movie type is the character 'F'
    {
        for (Movie* movie : comedy_movies_) 
        {
            if (Comedy* derivedMovie = dynamic_cast<Comedy*>(movie)) 
            {
                if (*derivedMovie == dynamic_cast<Comedy&>(*newMovie))//If the movies are the same
                {
                    if(derivedMovie->borrowMovie())
                    {
                        rentedMovied = derivedMovie; //Update movie and borrow is good
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }

    else if(movieType == 'D')
    {
        for (Movie* movie : drama_movies_) {
            if (Drama* derivedMovie = dynamic_cast<Drama*>(movie)) {
                if (*derivedMovie == dynamic_cast<Drama&>(*newMovie)) {
                    if(derivedMovie->borrowMovie()){
                        rentedMovied = derivedMovie;
                        return true;
                    }else{
                        return false;
                    }
                }
            }
        }
    }
    else if (movieType == 'C')
    {
        int index = -1;
        Classic* derivedNewMovie = dynamic_cast<Classic*>(newMovie);
        if (!derivedNewMovie) {
            return false; // Handling invalid dynamic cast
        }

        for(int i = 0; i < classics_movies_.size(); i++){
            Classic* derivedClassicMovie = dynamic_cast<Classic*>(classics_movies_[i]);
            if(!derivedClassicMovie){

            }
            if(*derivedClassicMovie == * derivedNewMovie){
                if(derivedClassicMovie->borrowMovie()){
                    rentedMovied = derivedClassicMovie;
                    return true;
                }
                index = i;
            }
        }

        if(index == -1){
            return false;
        }

        vector<int> sameMovies;

        for (int i = 0; i < classics_movies_.size(); i++) {
            Classic* derivedClassicMovie = dynamic_cast<Classic*>(classics_movies_[i]);
            Classic* searchMovie = dynamic_cast<Classic*>(classics_movies_[index]);
            if (!derivedClassicMovie) {
                continue; // Skip if cast fails
            }
            if(derivedClassicMovie->getDirector() == searchMovie->getDirector()){
                if(derivedClassicMovie->getTitle() == searchMovie->getTitle()){
                    if(derivedClassicMovie->getReleaseDate() == searchMovie->getReleaseDate()){
                        sameMovies.push_back(i);
                    }
                }
            }
        }

        for(int i = 0; i < sameMovies.size(); i++){
            Classic* derivedClassicMovie = dynamic_cast<Classic*>(classics_movies_[sameMovies[i]]);
            if(derivedClassicMovie->borrowMovie()){
                rentedMovied = derivedClassicMovie;
                return true;
            }
        }



    }

    return false;
    
}


/*
bool Inventory::setReturn(Movie* &newMovie, char movieType)
{
   vector<Movie*>* movies = nullptr;
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

    for (Movie*& other : *movies) 
    {
        if(*other == *newMovie)
        {
            return other->returnMovie();
        }
    }

    
    return false;
}
*/

bool Inventory::setReturn(Movie* &newMovie, char movieType) {
    if (movieType == 'F') {
        for (Movie* movie : comedy_movies_) {
        if (Comedy* derivedMovie = dynamic_cast<Comedy*>(movie)) {
            if (*derivedMovie == dynamic_cast<Comedy&>(*newMovie)) {
                return derivedMovie->returnMovie();
            }
        }
        }
    

    } else if(movieType == 'D') {

        for (Movie* movie : drama_movies_) {
            if (Drama* derivedMovie = dynamic_cast<Drama*>(movie)) {
                if (*derivedMovie == dynamic_cast<Drama&>(*newMovie)) {
                    return derivedMovie->returnMovie();
                }
            }
        }
    } else if (movieType == 'C') {

          for (Movie* movie : classics_movies_) {
            if (Classic* derivedMovie = dynamic_cast<Classic*>(movie)) {
                if (*derivedMovie == dynamic_cast<Classic&>(*newMovie)) {
                    return derivedMovie->returnMovie();
                }
            }
          }
    }



    return false;
}

bool Inventory::addMovie(Movie* &newMovie, char movieType) {

    switch (movieType) {
        case 'C': {
            for (Movie* movie : classics_movies_) {
                if (Classic* derivedMovie = dynamic_cast<Classic*>(movie)) {
                    if (*derivedMovie == dynamic_cast<Classic&>(*newMovie)) {
                        return false;
                    }
                }
            }
            classics_movies_.push_back(newMovie);
            classcisSort();
            return true;
        }
        case 'F': {
            for (Movie* movie : comedy_movies_) {
                if (Comedy* derivedMovie = dynamic_cast<Comedy*>(movie)) {
                    if (*derivedMovie == dynamic_cast<Comedy&>(*newMovie)) {
                        return false;
                    }
                }
            }
            comedy_movies_.push_back(newMovie);
            comedySort();
            return true;
        }
        case 'D': {
            for (Movie* movie : drama_movies_) {
                if (Classic* derivedMovie = dynamic_cast<Classic*>(movie)) {
                    if (*derivedMovie == dynamic_cast<Classic&>(*newMovie)) {
                        return false;
                    }
                }
            }
            drama_movies_.push_back(newMovie);
            dramaSort();
            return true;
        }
            return false;
    }
}

void Inventory::comedySort() {
    for (int i = 0; i < comedy_movies_.size(); i++) {
        for (int j = 0; j < comedy_movies_.size() - 1; j++) {
            Comedy* movie1 = dynamic_cast<Comedy*>(comedy_movies_[j]);
            Comedy* movie2 = dynamic_cast<Comedy*>(comedy_movies_[j + 1]);

            if (movie1 && movie2 && (*movie1 < *movie2)) {
                Movie* temp = comedy_movies_[j];
                comedy_movies_[j] = comedy_movies_[j + 1];
                comedy_movies_[j + 1] = temp;
            }
        }
    }
}

void Inventory::classcisSort() {
    for (int i = 0; i < classics_movies_.size(); i++) {
        for (int j = 0; j < classics_movies_.size() - 1; j++) {
            Classic* movie1 = dynamic_cast<Classic*>(classics_movies_[j]);
            Classic* movie2 = dynamic_cast<Classic*>(classics_movies_[j + 1]);

            if (movie1 && movie2 && (*movie1 < *movie2)) {
                Movie* temp = classics_movies_[j];
                classics_movies_[j] = classics_movies_[j + 1];
                classics_movies_[j + 1] = temp;
            }
        }
    }
}

void Inventory::dramaSort() {
    for (int i = 0; i < drama_movies_.size(); i++) {
        for (int j = 0; j < drama_movies_.size() - 1; j++) {
            Drama* movie1 = dynamic_cast<Drama*>(drama_movies_[j]);
            Drama* movie2 = dynamic_cast<Drama*>(drama_movies_[j + 1]);

            if (movie1 && movie2 && (*movie1 < *movie2)) {
                Movie* temp = drama_movies_[j];
                drama_movies_[j] = drama_movies_[j + 1];
                drama_movies_[j + 1] = temp;
            }
        }
    }
}
