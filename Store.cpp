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
                borrow(in_file);
            }

            if(actionType == "R"){
                returnMovie(in_file);
                int customerId = 0;
                Customer * returnCustomer = new Customer(12, "s", "d");
                bool foundCustomer = false;
                in_file >> customerId;
                foundCustomer = customers_.getItem(customerId, returnCustomer);
                if(foundCustomer == false){
                    cout << "Invaild customer Id, return failed" << endl;
                }
                delete returnCustomer;                
            }


        }else{
            cout << "Invaild commands, please check data";
        }   
    }

    in_file.close();

}

void Store::borrow(ifstream& in_file)
{
    int customerId = 0;
    Customer * returnCustomer = new Customer(12, "s", "d");
    bool foundCustomer = false;
    in_file >> customerId;
    foundCustomer = customers_.getItem(customerId, returnCustomer);
    if(foundCustomer == false){
        cout << "Invaild customer Id, borrow failed" << endl;
    }else{
        string mediaType;
        in_file >> mediaType;
        if(mediaType != "D"){
            cout << "Invaild media type, borrow failed" << endl;
        }else{
            char movieType;
            in_file >> movieType;
            if(movieType == 'D' || movieType == 'C' || movieType == 'F'){
                char rest[100];
                in_file.getline(rest, sizeof(rest));
                string borrowMoiveInfo;
                bool returnBool;
                char returnChar;
                if(movieType == 'C'){
                    borrowMoiveInfo = "C, 1, temp, temp,";
                    stringstream ss(rest);
                    int month, year;
                    ss >> month >> year;
                    char majorActor[100];
                    ss.getline(majorActor, sizeof(majorActor));
                    borrowMoiveInfo += majorActor; // need to swap the order(date first then name)
                    borrowMoiveInfo += " ";
                    borrowMoiveInfo += month;
                    borrowMoiveInfo += " ";
                    borrowMoiveInfo += year;
                }
                            
                if(movieType == 'F'){
                    borrowMoiveInfo = "F, 1, temp,";
                    borrowMoiveInfo = borrowMoiveInfo + rest;
                }

                if(movieType == 'D'){
                    borrowMoiveInfo = "D, 1,";
                    borrowMoiveInfo = borrowMoiveInfo + rest;
                    borrowMoiveInfo = borrowMoiveInfo + " 1234";
                }
                           
                Movie tempMoive = MovieFactory::createMovie(borrowMoiveInfo, returnBool, returnChar);
                returnBool = false;
                returnBool = inventory_.setBorrow(tempMoive, 'C');
                if(returnBool == false){
                    cout << "couldn't borrow movie, movie may no exist or out of stock" << endl;

                }else{
                    string bookDeatils = rest;
                    bookDeatils = bookDeatils.substr(1,99);
                    returnCustomer->addHistory(bookDeatils, false);
                }
                        
            }else{
                cout << "Invaild Movie Type, borrow failed" << endl;
            }
        }
    }
                   
}

void Store::returnMovie(ifstream & in_file)
{
    int customerId = 0;
    Customer * returnCustomer = new Customer(12, "s", "d");
    bool foundCustomer = false;
    in_file >> customerId;
    foundCustomer = customers_.getItem(customerId, returnCustomer);
    if(foundCustomer == false){
        cout << "Invaild customer Id, return failed" << endl;
    }

}
