#include "inventory.h"

Inventory::Inventory()
{
}

bool Inventory::addMovie(Movie &newMovie, char movieType)
{
    if(movieType == 'C'){

    }else if(movieType == 'F'){
        
    }else if(movieType == 'D'){

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
