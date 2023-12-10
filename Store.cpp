#include "store.h"

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
        char temp[1000];
        in_file.getline(temp, sizeof(temp));
        string movieInfo = temp;
        if(movieInfo.empty()){
            cout << "Empty file or empty string, please check file"<< endl;
        }else{
            Movie * newMovie =  MovieFactory::createMovie(temp, sucess, movieType);
            if(sucess == false){
                cout << "invaid data, movies couldn't be created" << endl;
            }else{
                sucess = inventory_.addMovie(newMovie, movieType);
                if(sucess == false){
                cout << "Movie already existed, failed to add to the inventory";
                }           
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
        int customerId = -1;
        char temp[1000];
        string nextLine = "";
        in_file.getline(temp, sizeof(temp));
        nextLine = temp;
        if(nextLine.empty()){
            cout << "Empty file or empty string, please check file"<< endl;
        }else{
            
        
        stringstream ss(nextLine);
        ss >> customerId >> firstName >> lastName;
        if(customerId == -1){
            return;
        }
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
        string nextLine = " ";
        char temp[1000];
        in_file.getline(temp, sizeof(temp));
        nextLine = temp;
        if(nextLine.empty()){
            cout << "Empty file or empty string, please check file"<< endl;
        }else{

        
        stringstream ss(nextLine);
        ss >> actionType;
        if(actionType == "B" || actionType == "R" || actionType == "H" || actionType == "I"){

            if(actionType == "I"){
                inventory_.printItmes();
            }

            if(actionType == "H"){
                int customerId = 0;
                Customer * returnCustomer;
                bool foundCustomer = false;
                ss >> customerId;
                foundCustomer = customers_.getItem(customerId, returnCustomer);
                if(foundCustomer == false){
                    cout << "can't print customer history, customer Id doesn't exist" << endl;
                }else{
                    returnCustomer->displayHistory();
                }
            }

            if(actionType == "B"){
                borrow(ss);
            }

            if(actionType == "R"){   
                returnMovie(ss);
            }


        }else{
            cout << "Invaild commands, please check data" << endl;
        }   
        }

    }

    in_file.close();

}

void Store::borrow(stringstream& in_file)
{
    int customerId = 0;
    Customer * returnCustomer;  
    bool foundCustomer = false;
    in_file >> customerId;  
    foundCustomer = customers_.getItem(customerId, returnCustomer);
    if(foundCustomer == false){
        cout << "Invaild customer Id, borrow failed" << endl;
        return;
    }
        string mediaType = " ";
        in_file >> mediaType;
        if(mediaType != "D"){
            cout << "Invaild media type, borrow failed" << endl;
            return;
        }
            string movieType = " ";
            in_file >> movieType;
            if(movieType == "D" || movieType == "C" || movieType == "F"){
                char rest[100];
                in_file.getline(rest, sizeof(rest));
                string borrowMoiveInfo = " ";
                bool returnBool;
                char returnChar;
                if(movieType == "C"){
                    borrowMoiveInfo = "C, 1, temp, temp, ";
                    stringstream ss(rest);
                    string firstname, lastname, month, year;
                    ss >> month >> year;
                    ss >> firstname >> lastname;
                    borrowMoiveInfo += firstname;
                    borrowMoiveInfo += " ";
                    borrowMoiveInfo += lastname;
                    borrowMoiveInfo += " ";
                    borrowMoiveInfo += month;
                    borrowMoiveInfo += " ";
                    borrowMoiveInfo += year;
                }
                            
                if(movieType == "F"){
                    borrowMoiveInfo = "F, 1, temp,";
                    borrowMoiveInfo = borrowMoiveInfo + rest;
                }

                if(movieType == "D"){
                    borrowMoiveInfo = "D, 1,";
                    borrowMoiveInfo = borrowMoiveInfo + rest;
                    borrowMoiveInfo = borrowMoiveInfo + " 1234";
                }
                char movieChar = movieType[0];                           
                Movie * tempMoive = MovieFactory::createMovie(borrowMoiveInfo, returnBool, returnChar);
                if(returnBool == false){
                    cout << "couldn't borrow movie, movie info not vaild not" << endl;
                }else{
                    returnBool = false;
                    Movie * rentedMovied;
                    returnBool = inventory_.setBorrow(tempMoive, movieChar, rentedMovied);
                    if(returnBool == false){
                        cout << "couldn't borrow movie, movie may no exist or out of stock" << endl;

                    }else{

                        if(movieType == "F"){
                            if (Comedy* derivedMovie = dynamic_cast<Comedy*>(tempMoive)){
                                returnCustomer->addHistory(derivedMovie->sortingCriteria(), false, "F");
                            }
                        }
                        if(movieType == "C"){
                            if (Classic* derivedMovie = dynamic_cast<Classic*>(rentedMovied)){
                                returnCustomer->addHistory(derivedMovie->sortingCriteria(), false, "C");
                            }
                        }
                        if(movieType == "D"){
                            if( Drama* derivedMovie = dynamic_cast<Drama*>(tempMoive)){
                                returnCustomer->addHistory(derivedMovie->sortingCriteria(), false, "D");
                            }

                        }
                    }
                }
                        
            }else{
                cout << "Invaild Movie Type, borrow failed" << endl;
            }
}

void Store::returnMovie(stringstream & in_file)
{
    int customerId = 0;
    Customer * returnCustomer;
    bool foundCustomer = false;
    in_file >> customerId;
    foundCustomer = customers_.getItem(customerId, returnCustomer);
    if(foundCustomer == false){
        cout << "Invaild customer Id, return failed" << endl;
        return;
    }

    string mediaType = " ";
    in_file >> mediaType;
    if(mediaType != "D"){
        cout << "Invaild media type, return failed" << endl;
        return;
    }
    char rest[100];
    in_file.getline(rest, sizeof(rest));
    string bookDetail = rest; // start with movie type w/o space infront
    bookDetail = bookDetail.substr(1,99);
    //to-do, check the bookDeatial to sorting criteria only
    if(returnCustomer->containsHistory(bookDetail) == false){ // don't think bookdeatil is the right input here
        cout << "Customer never borrow the book before, return failed" << endl;
        return;
    }

    string movieType = " ";
    stringstream ss(bookDetail);
    ss >> movieType;
    char sortingCriteria[100];
    ss.getline(sortingCriteria, sizeof(sortingCriteria));

    if(movieType == "D" || movieType == "C" || movieType == "F"){

    }else{
        cout << "Invaild movie, return failed" << endl;
    }

    string returnMoiveInfo = " ";
    bool returnBool = false;
    char returnChar = ' ';
    if(movieType == "D"){
        returnMoiveInfo = "D, 1,";
        returnMoiveInfo = returnMoiveInfo + sortingCriteria;
        returnMoiveInfo = returnMoiveInfo + " 1234";        
    }

    if(movieType == "C"){
        returnMoiveInfo = "C, 1, temp, temp, ";
        stringstream ss2(sortingCriteria);
        string firstname, lastname, month, year;
        ss2 >> month >> year;
        ss2 >> firstname >> lastname;
        returnMoiveInfo += firstname;
        returnMoiveInfo += " ";
        returnMoiveInfo += lastname;
        returnMoiveInfo += " ";
        returnMoiveInfo += month;
        returnMoiveInfo += " ";
        returnMoiveInfo += year;
    }

    if(movieType == "F"){
        returnMoiveInfo = "F, 1, temp,";
        returnMoiveInfo = returnMoiveInfo + sortingCriteria;
    }

    Movie *tempMoive = MovieFactory::createMovie(returnMoiveInfo, returnBool, returnChar);
    if(returnBool == false){
        cout << "couldn't borrow movie, movie info not vaild" << endl;
    }
    returnBool = false;
    char movieChar = movieType[0];
    returnBool = inventory_.setReturn(tempMoive, movieChar);

    if(returnBool == false){
        cout << "couldn't return movie, movie may no exist or out of stock" << endl;

    }else{
        returnCustomer->addHistory(bookDetail, true, "D");
        /*
        if(movieType == "F"){
            if (Comedy* derivedMovie = dynamic_cast<Comedy*>(tempMoive)){
                returnCustomer->addHistory(derivedMovie->sortingCriteria(), true, "F");
            }
        }
        if(movieType == "C"){
            if (Classic* derivedMovie = dynamic_cast<Classic*>(tempMoive)){
                returnCustomer->addHistory(derivedMovie->sortingCriteria(), true, "C");
            }
        }else{
            if( Drama* derivedMovie = dynamic_cast<Drama*>(tempMoive)){
                returnCustomer->addHistory(derivedMovie->sortingCriteria(), true, "D");
            }

        }
        */
    }
}
