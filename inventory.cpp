// ------------------------------------------------Inventory.cpp -------------------------------------------------------
// CSS 343 B Au 23
// Created on 11/17/2023
// Last Modified on 11/17/2023
// Created by Vince Nguyen, Lok Yin Wong
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
    for(int i = comedy_movies_.size() - 1 ; i >= 0; i--){
        comedy_movies_[i]->print();
    }
    for(int i = drama_movies_.size() - 1 ; i >= 0; i--){
        drama_movies_[i]->print();
    }
    for(int i = classics_movies_.size() - 1 ; i >= 0; i--){
        classics_movies_[i]->print();
    }

}

//------------------------- setBorrow ---------------------------------
// Borrowing a movie from the inventory
//-------------------------------------------------------------------------
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

    if(movieType == 'D') //If the movie type is 'D'
    {
        for (Movie* movie : drama_movies_) //Iterate through the drama movie
        {
            if (Drama* derivedMovie = dynamic_cast<Drama*>(movie)) //Check if the movie is a drama
            {
                if (*derivedMovie == dynamic_cast<Drama&>(*newMovie)) //If the movies match
                {
                    if(derivedMovie->borrowMovie())
                    {
                        rentedMovied = derivedMovie; //Update the movie
                        return true; //Borrow is good
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }

    if (movieType == 'C') //If the movie type is 'C'
    {
        int index = -1;
        Classic* derivedNewMovie = dynamic_cast<Classic*>(newMovie);
        if (!derivedNewMovie) 
        {
            return false; // Handling invalid dynamic cast
        }

        for(int i = 0; i < classics_movies_.size(); i++) //Looping through the classic inventory
        {
            Classic* derivedClassicMovie = dynamic_cast<Classic*>(classics_movies_[i]);
            if(!derivedClassicMovie)
            {

            }
            else
            {
                if(*derivedClassicMovie == *derivedNewMovie) //If the movies match
                {
                    if(derivedClassicMovie->borrowMovie()) //If borrowing is successful
                    {
                        rentedMovied = derivedClassicMovie; //Update movie
                        return true;
                    }
                index = i;
                }
            }
        }

        if(index == -1)
        {
            return false;
        }

        vector<int> sameMovies;

         for (int i = 0; i < classics_movies_.size(); i++) 
        {
            Classic* derivedClassicMovie = dynamic_cast<Classic*>(classics_movies_[i]); // Attempt to cast current movie to Classic
            Classic* searchMovie = dynamic_cast<Classic*>(classics_movies_[index]); // Attempt to cast searchMovie to Classic
            if (!derivedClassicMovie) 
            {
                continue; // Skip if cast fails
            }
            else
            {
                if(derivedClassicMovie->getDirector() == searchMovie->getDirector()) // If directors match
                {
                    if(derivedClassicMovie->getTitle() == searchMovie->getTitle()) // If titles match
                    {
                        if(derivedClassicMovie->getReleaseDate() == searchMovie->getReleaseDate()) // If release dates match
                        {
                            sameMovies.push_back(i);
                        }
                    }
                }
            }
        }

        for(int i = 0; i < sameMovies.size(); i++){
            Classic* derivedClassicMovie = dynamic_cast<Classic*>(classics_movies_[sameMovies[i]]); // Attempt to cast current movie to Classic
            if(derivedClassicMovie->borrowMovie()) // If borrowing is successful
            {
                rentedMovied = derivedClassicMovie; // Update the rented movie
                return true;
            }
        }
    }

    return false;
    
}


//------------------------- setReturn ---------------------------------
// Return a movie from the inventory
//-------------------------------------------------------------------------
bool Inventory::setReturn(Movie* &newMovie, char movieType) 
{
     if (movieType == 'F') // If the movie type is 'F'
    {
        for (Movie* movie : comedy_movies_) // Iterate through comedy movies
        {
            if (Comedy* derivedMovie = dynamic_cast<Comedy*>(movie)) // Check if the movie is a Comedy
            {
                if (*derivedMovie == dynamic_cast<Comedy&>(*newMovie)) // If movies match
                {
                    return derivedMovie->returnMovie(); 
                }
            }
        }
    } 
    else if(movieType == 'D') // If the movie type is 'D'
    {
        for (Movie* movie : drama_movies_) // Iterate through drama movies
        {
            if (Drama* derivedMovie = dynamic_cast<Drama*>(movie)) // Check if the movie is a Drama
            {
                if (*derivedMovie == dynamic_cast<Drama&>(*newMovie)) // If movies match
                {
                    return derivedMovie->returnMovie(); 
                }
            }
        }
    } 
    else if (movieType == 'C') // If the movie type is 'C'
    {
        for (Movie* movie : classics_movies_) // Iterate through classic movies
        {
            if (Classic* derivedMovie = dynamic_cast<Classic*>(movie)) // Check if the movie is a Classic
            {
                if (derivedMovie->sortingCriteria() == dynamic_cast<Classic&>(*newMovie).sortingCriteria()) // If sorting criteria matches
                {
                    return derivedMovie->returnMovie(); 
                }
            }
        }
    }

    return false; 
}

//------------------------- addMovie ---------------------------------
// Adds a movie to the inventory
//-------------------------------------------------------------------------
bool Inventory::addMovie(Movie* &newMovie, char movieType) 
{

    switch (movieType) 
{
    case 'C': // If the movie type is 'C'
    {
        for (Movie* movie : classics_movies_) // Iterate through classic movies
        {
            if (Classic* derivedMovie = dynamic_cast<Classic*>(movie)) // Check if the movie is a Classic
            {
                if (derivedMovie->sortingCriteria() == dynamic_cast<Classic&>(*newMovie).sortingCriteria()) // If sorting criteria matches
                {
                    return false; // Return false, movie already exists
                }
            }
        }
        classics_movies_.push_back(newMovie); // Add the new movie to the classics inventory
        classcisSort(); // Sort the classics inventory
        return true; 
    }
    case 'F': // If the movie type is 'F'
    {
        for (Movie* movie : comedy_movies_) // Iterate through comedy movies
        {
            if (Comedy* derivedMovie = dynamic_cast<Comedy*>(movie)) // Check if the movie is a Comedy
            {
                if (*derivedMovie == dynamic_cast<Comedy&>(*newMovie)) // If movies match
                {
                    return false;
                }
            }
        }
        comedy_movies_.push_back(newMovie); // Add the new movie to the comedy inventory
        comedySort(); // Sort the comedy inventory
        return true; // Return true, movie added successfully
    }
    case 'D': // If the movie type is 'D'
    {
        for (Movie* movie : drama_movies_) // Iterate through drama movies
        {
            if (Drama* derivedMovie = dynamic_cast<Drama*>(movie)) // Check if the movie is a Drama
            {
                if (*derivedMovie == dynamic_cast<Drama&>(*newMovie)) // If movies match
                {
                    return false; 
                }
            }
        }
        drama_movies_.push_back(newMovie); // Add the new movie to the drama inventory
        dramaSort(); // Sort the drama inventory
        return true; // Return true, movie added successfully
    }
    return false; 
}
return false; 
}

//------------------------- comedySort ---------------------------------
// Sorts the comedy movies
//-------------------------------------------------------------------------
void Inventory::comedySort() 
{
   for (int i = 0; i < comedy_movies_.size(); i++) // Iterate through the comedy movies
{
    for (int j = 0; j < comedy_movies_.size() - 1; j++)
    {
        Comedy* movie1 = dynamic_cast<Comedy*>(comedy_movies_[j]); //cast the j-th movie to Comedy
        Comedy* movie2 = dynamic_cast<Comedy*>(comedy_movies_[j + 1]); //cast the (j+1)-th movie to Comedy

        if (movie1 && movie2 && (*movie1 < *movie2)) // If both casts are successful and movie1 is less than movie2
        {
            Movie* temp = comedy_movies_[j]; // Swap the movies
            comedy_movies_[j] = comedy_movies_[j + 1];
            comedy_movies_[j + 1] = temp;
        }
    }
}
}

//------------------------- classicsSort ---------------------------------
// Sorts the classic movies
//-------------------------------------------------------------------------
void Inventory::classcisSort() 
{
    for (int i = 0; i < classics_movies_.size(); i++) // Iterate through the classics movies
{
    for (int j = 0; j < classics_movies_.size() - 1; j++)
    {
        Classic* movie1 = dynamic_cast<Classic*>(classics_movies_[j]); //cast the j-th movie to Classic
        Classic* movie2 = dynamic_cast<Classic*>(classics_movies_[j + 1]); //cast the (j+1)-th movie to Classic

        if (movie1 && movie2 && (*movie1 < *movie2)) // If both casts are successful and movie1 is less than movie2
        {
            Movie* temp = classics_movies_[j]; // Swap the movies
            classics_movies_[j] = classics_movies_[j + 1];
            classics_movies_[j + 1] = temp;
        }
    }
}
}

//------------------------- dramaSort() ---------------------------------
// Sorts the drama movies
//-------------------------------------------------------------------------
void Inventory::dramaSort() 
{
    for (int i = 0; i < drama_movies_.size(); i++) // Iterate through the drama movies
{
    for (int j = 0; j < drama_movies_.size() - 1; j++) 
    {
        Drama* movie1 = dynamic_cast<Drama*>(drama_movies_[j]); //cast the j-th movie to Drama
        Drama* movie2 = dynamic_cast<Drama*>(drama_movies_[j + 1]); //cast the (j+1)-th movie to Drama

        if (movie1 && movie2 && (*movie1 < *movie2)) // If both casts are successful and movie1 is less than movie2
        {
            Movie* temp = drama_movies_[j]; // Swap the movies
            drama_movies_[j] = drama_movies_[j + 1];
            drama_movies_[j + 1] = temp;
        }
    }
}
}
