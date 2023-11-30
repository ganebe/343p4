#include "Store.h"

Store::Store()
{
}

void Store::loadMovies(string fileName)
{
    ifstream in_file;
    in_file.open(fileName);
    if(in_file.is_open() == false){
        cout << "can't open file, please check the file name" << endl;
        return;
    }


    MovieFactory movieCreator;
    bool sucess;
    
    while(!in_file.eof()){
        sucess = false;
        string temp = "";
        in_file >> temp;
        if(temp == ""){
            cout << "Empty file or empty string, please check file"<< endl;
        }else{
            Movie newMovie = movieCreator.createMovie(temp,sucess);
        }
    }

}

void Store::loadCustomers(string fileName)
{
    ifstream in_file;
    in_file.open(fileName);
    if(in_file.is_open() == false){
        cout << "can't open file, please check the file name"<< endl;
        return;
    }

    while(!in_file.eof()){
        string firstName = "";
        string lastName = "";
        int customerId = 0;
        in_file >> customerId >> firstName >> lastName;
        if(customerId > 9999 || customerId < 1000 ){
            cout << "Invaild customer Id, please try again" << endl;
        }else if(firstName == ""){
            cout << "first name can't be blank"<< endl;
        }else if(lastName == ""){
            cout << "last name can't be blank"<< endl;
        }else{
            Customer * newCustomer = new Customer(customerId, lastName, firstName);
            bool added = false;
            added = customers_.addItem(customerId, newCustomer);
            if(added == false){
                cout << "customer id already used, please use a different one"<< endl;
            }
        }
    }
}
