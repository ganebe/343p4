#include "string"
#include <iostream>
#include <fstream>
#include "store.h"
using namespace std;

int main(){
    Store ms;
    //ms.loadMovies("data4movies.txt");
    ms.loadMovies("test.txt");
    ms.loadCustomers("data4customers.txt");
    //ms.runCommands("data4commands.txt");
    ms.runCommands("test2.txt");
}