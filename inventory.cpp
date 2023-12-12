#include "inventory.h"

Inventory::Inventory()
{
}

void Inventory::printItmes()
{
    cout << "Inventory items:" << endl;
    for(int i = 0 ; i < comedy_movies_.size(); i++){
        comedy_movies_[i]->print();
    }
    for(int i = 0 ; i < drama_movies_.size(); i++){
        drama_movies_[i]->print();
    }
    for(int i = 0 ; i < classics_movies_.size(); i++){
        classics_movies_[i]->print();
    }

}

bool Inventory::setBorrow(Movie* &newMovie, char movieType, Movie* & rentedMovied )
{

    if (movieType == 'F')
    {
        for (Movie* movie : comedy_movies_) {
            if (Comedy* derivedMovie = dynamic_cast<Comedy*>(movie)) {
                if (*derivedMovie == dynamic_cast<Comedy&>(*newMovie)) {
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

    if(movieType == 'D')
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

    if (movieType == 'C')
    {
        int index = -1;
        Classic* derivedNewMovie = dynamic_cast<Classic*>(newMovie);
        if (!derivedNewMovie) {
            return false; // Handling invalid dynamic cast
        }

        for(int i = 0; i < classics_movies_.size(); i++){
            Classic* derivedClassicMovie = dynamic_cast<Classic*>(classics_movies_[i]);
            if(!derivedClassicMovie){

            }else{
                if(*derivedClassicMovie == *derivedNewMovie){
                    if(derivedClassicMovie->borrowMovie()){
                        rentedMovied = derivedClassicMovie;
                        return true;
                    }
                index = i;
                }
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
            }else{
                if(derivedClassicMovie->getDirector() == searchMovie->getDirector()){
                    if(derivedClassicMovie->getTitle() == searchMovie->getTitle()){
                        if(derivedClassicMovie->getReleaseDate() == searchMovie->getReleaseDate()){
                            sameMovies.push_back(i);
                        }
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
                if (derivedMovie->sortingCriteria() == dynamic_cast<Classic&>(*newMovie).sortingCriteria()) {
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
                    if (derivedMovie->sortingCriteria() == dynamic_cast<Classic&>(*newMovie).sortingCriteria()) {
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
                if (Drama* derivedMovie = dynamic_cast<Drama*>(movie)) {
                    if (*derivedMovie == dynamic_cast<Drama&>(*newMovie)) {
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
    return false;
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
