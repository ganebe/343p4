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


    bool sucess;
    char movieType = ' ';
    while(!in_file.eof()){
        movieType = ' ';
        sucess = false;
        string temp = "";
        in_file >> temp;
        if(temp == ""){
            cout << "Empty file or empty string, please check file"<< endl;
        }else{
            Movie newMovie = MovieFactory::createMovie(temp, sucess, movieType);
            if(sucess == false){
                cout << "invaid data, movies couldn't be created" << endl;
            }else{
                sucess = inventory_.addMovie(newMovie, movieType);           
            }
            
        }
    }

    in_file.close();

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
    in_file.close();
}

void Store::runCommands(string fileName)
{
    ifstream in_file;
    in_file.open(fileName);
    if(in_file.is_open() == false){
        cout << "can't open file, please check the file name"<< endl;
        return;
    }

    while(!in_file.eof()){
        string actionType = " ";
        in_file >> actionType;
        if(actionType == "B" || actionType == "R" || actionType == "H" || actionType == "I"){

            if(actionType == "I"){
                inventory_.printItmes();
            }

            if(actionType == "H"){
                int customerId = 0;
                Customer * returnCustomer = new Customer(12, "s", "d");
                bool foundCustomer = false;
                in_file >> customerId;
                foundCustomer = customers_.getItem(customerId, returnCustomer);
                if(foundCustomer == false){
                    cout << "can't print customer history, customer Id doesn't exist" << endl;
                }else{
                    returnCustomer->displayHistory();
                }
            }

            if(actionType == "B"){
                
            }

            if(actionType == "R"){
                
            }


        }else{
            cout << "Invaild commands, please check data";
        }   
    }

    in_file.close();

}
