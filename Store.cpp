// ------------------------------------------------store.h -------------------------------------------------------
// CSS 343 B Au 23
// 12/8/2023
// 12/12/2023
// Created by Vince Nguyen, Lok Yin Wong
// --------------------------------------------------------------------------------------------------------------------
// This file contains the implementations for the store class which has functionalities that reads the customer's information
// and all the movie information that is stored from the movie class.
// --------------------------------------------------------------------------------------------------------------------
// All movies should be read correctly
// --------------------------------------------------------------------------------------------------------------------
#include "store.h"

Store::Store()
{
    
}

//------------------------- loadMovies ---------------------------------
// Reads DVD movie information from the specified file.
//-------------------------------------------------------------------------
void Store::loadMovies(string fileName)
{
    ifstream in_file;
    in_file.open(fileName);
    if(in_file.is_open() == false)
    {
        cout << "can't open file, please check the file name" << endl;
        return;
    }


    bool sucess;
    char movieType = ' ';
    while(!in_file.eof())
    {
        movieType = ' ';
        sucess = false;
        char temp[1000];
        in_file.getline(temp, sizeof(temp));
        string movieInfo = temp;
        if(movieInfo.empty())
        {
            cout << "Empty file or empty string, please check file"<< endl;
        }
        else
        {
            Movie * newMovie =  MovieFactory::createMovie(temp, sucess, movieType);
            if(sucess == false)
            {
                cout << "invaid data, movies couldn't be created" << endl;
            }
            else
            {
                sucess = inventory_.addMovie(newMovie, movieType);
                if(sucess == false)
                {
                cout << "Movie already existed, failed to add to the inventory" << endl;
                }           
            }

            
        }
    }

    in_file.close();

}

//------------------------- loadCustomers ---------------------------------
// Reads customer information from the specified file.
//-------------------------------------------------------------------------
void Store::loadCustomers(string fileName)
{
   ifstream in_file; // Declare an input file stream
in_file.open(fileName); // Open the file with the given file name
if (in_file.is_open() == false) // Check if the file is successfully opened
{
    cout << "can't open file, please check the file name" << endl; // Display an error message if the file couldn't be opened
    return; // Exit the function
}

while (!in_file.eof()) // Continue reading lines until the end of the file is reached
{
    string firstName = "";
    string lastName = "";
    int customerId = -1;
    char temp[1000];
    string nextLine = "";
    in_file.getline(temp, sizeof(temp)); // Read a line from the file into the temporary buffer
    nextLine = temp; // Convert the buffer to a string
    if (nextLine.empty()) // Check if the line is empty
    {
        cout << "Empty file or empty string, please check file" << endl; 
    }
    else
    {
        stringstream ss(nextLine); // Create a stringstream to parse the line
        ss >> customerId >> firstName >> lastName; // Extract data from the stringstream
        if (customerId == -1) // Check if the customer ID is invalid
        {
            return; // Exit the function
        }
        if (customerId > 9999 || customerId < 1000) // Check if the customer ID is outside the valid range
        {
            cout << "Invalid customer Id, please try again" << endl; 
        }
        else if (firstName == "") // Check if the first name is blank
        {
            cout << "First name can't be blank" << endl; 
        }
        else if (lastName == "") // Check if the last name is blank
        {
            cout << "Last name can't be blank" << endl; 
        }
        else
        {
            Customer * newCustomer = new Customer(customerId, lastName, firstName); // Create a new Customer object
            bool added = false;
            added = customers_.addItem(customerId, newCustomer); // Add the customer to the collection
            if (added == false)
            {
                cout << "Customer id already used, please use a different one" << endl;
            }
        }
    }
}
in_file.close(); 
}

//------------------------- runCommands ---------------------------------
// Reads and runs command information from the specified file.  
//-------------------------------------------------------------------------
void Store::runCommands(string fileName)
{
ifstream in_file; // Declare an input file stream
in_file.open(fileName); // Open the file with the given file name
if (in_file.is_open() == false) // Check if the file is successfully opened
{
    cout << "can't open file, please check the file name" << endl; 
    return; // Exit the function
}

while (!in_file.eof()) // Continue reading lines until the end of the file is reached
{
    string actionType = " ";
    string nextLine = " ";
    char temp[1000];
    in_file.getline(temp, sizeof(temp)); // Read a line from the file into the temporary buffer
    nextLine = temp; // Convert the buffer to a string
    if (nextLine.empty()) // Check if the line is empty
    {
        cout << "Empty file or empty string, please check file" << endl; 
    }
    else
    {
        stringstream ss(nextLine); // Create a stringstream to parse the line
        ss >> actionType; // Extract the action type from the stringstream
        if (actionType == "B" || actionType == "R" || actionType == "H" || actionType == "I") // Check if the action type is valid
        {

            if (actionType == "I") // If the action is 'I' (Inventory)
            {
                inventory_.printItmes(); // Call the printItems function of the Inventory
            }

            if (actionType == "H") // If the action is 'H' (Customer History)
            {
                int customerId = 0;
                Customer * returnCustomer;
                bool foundCustomer = false;
                ss >> customerId; // Extract the customer ID from the stringstream
                foundCustomer = customers_.getItem(customerId, returnCustomer); // Check if the customer ID exists
                if (foundCustomer == false)
                {
                    cout << "Can't print customer history, customer ID doesn't exist" << endl; 
                }
                else
                {
                    returnCustomer->displayHistory(); // Call the displayHistory function of the Customer
                }
            }

            if (actionType == "B") // If the action is 'B' (Borrow)
            {
                borrow(ss); // Call the borrow function with the stringstream as an argument
            }

            if (actionType == "R") // If the action is 'R' (Return)
            {   
                returnMovie(ss); // Call the returnMovie function with the stringstream as an argument
            }

        }
        else
        {
            cout << "Invalid commands, please check data" << endl; 
        }   
    }
}

in_file.close(); 

}

//------------------------- borrow ---------------------------------
// Borrowing a movie from the inventory
//-------------------------------------------------------------------------
void Store::borrow(stringstream& in_file)
{
int customerId = 0; 
Customer * returnCustomer; 
bool foundCustomer = false; 
in_file >> customerId; 
foundCustomer = customers_.getItem(customerId, returnCustomer); // Check if the customer with the given ID exists

if(foundCustomer == false) // If the customer is not found
{
    cout << "Invalid customer ID, borrow failed" << endl; // Display an error message and exit the function
    return;
}

string mediaType = " "; // Declare a string to store the media type
in_file >> mediaType; // Read media type from the file

if(mediaType != "D") // If the media type is not 'D'
{
    cout << "Invalid media type, borrow failed" << endl; 
    return;
}

string movieType = " "; // Declare a string to store the movie type
in_file >> movieType; // Read movie type from the file

if(movieType == "D" || movieType == "C" || movieType == "F") // If the movie type is valid
{
    char rest[100];
    in_file.getline(rest, sizeof(rest)); // Read the rest of the line into the buffer
    
    string borrowMovieInfo = " "; // Declare a string to store the movie information for borrowing
    bool returnBool;
    char returnChar;

    if(movieType == "C") // If the movie type is 'C' (Classic)
    {
        borrowMovieInfo = "C, 1, temp, temp, "; // Initialize with common information
        stringstream ss(rest);
        string firstname, lastname, month, year;
        ss >> month >> year;
        ss >> firstname >> lastname;
        borrowMovieInfo += firstname;
        borrowMovieInfo += " ";
        borrowMovieInfo += lastname;
        borrowMovieInfo += " ";
        borrowMovieInfo += month;
        borrowMovieInfo += " ";
        borrowMovieInfo += year;
    }
    
    if(movieType == "F") // If the movie type is 'F' (Comedy)
    {
        borrowMovieInfo = "F, 1, temp,"; // Initialize with common information
        borrowMovieInfo = borrowMovieInfo + rest; // Add the rest of the information
    }

    if(movieType == "D") // If the movie type is 'D' (Drama)
    {
        borrowMovieInfo = "D, 1,"; // Initialize with common information
        borrowMovieInfo = borrowMovieInfo + rest; // Add the rest of the information
        borrowMovieInfo = borrowMovieInfo + " 1234"; // Add additional information for Drama
    }
    
    char movieChar = movieType[0]; // Get the first character of the movie type
    Movie * tempMovie = MovieFactory::createMovie(borrowMovieInfo, returnBool, returnChar); // Create a temporary Movie object
    if(returnBool == false) // If creating the movie object failed
    {
        cout << "Couldn't borrow movie, movie info not valid" << endl; 
    }
    else
    {
        returnBool = false;
        Movie * rentedMovie;
        returnBool = inventory_.setBorrow(tempMovie, movieChar, rentedMovie); // Try to borrow the movie
        if(returnBool == false) // If borrowing failed
        {
            cout << "Couldn't borrow movie, movie may not exist or out of stock" << endl; 
        }
        else
        {
            // Update customer history based on the movie type
            if(movieType == "F")
            {
                if (Comedy* derivedMovie = dynamic_cast<Comedy*>(tempMovie))
                {
                    returnCustomer->addHistory(derivedMovie->sortingCriteria(), false, "F");
                }
            }
            if(movieType == "C")
            {
                if (Classic* derivedMovie = dynamic_cast<Classic*>(rentedMovie))
                {
                    returnCustomer->addHistory(derivedMovie->sortingCriteria(), false, "C");
                }
            }
            if(movieType == "D")
            {
                if( Drama* derivedMovie = dynamic_cast<Drama*>(tempMovie))
                {
                    returnCustomer->addHistory(derivedMovie->sortingCriteria(), false, "D");
                }
            }
        }
    }   
}
else
{
    cout << "Invalid Movie Type, borrow failed" << endl; 
}

}

//------------------------- returnMovie ---------------------------------
// Return a movie from the inventory
//-------------------------------------------------------------------------
void Store::returnMovie(stringstream & in_file)
{
    int customerId = 0; 
Customer * returnCustomer; 
bool foundCustomer = false; 
in_file >> customerId; 
foundCustomer = customers_.getItem(customerId, returnCustomer); // Check if the customer with the given ID exists
if(foundCustomer == false) // If the customer is not found
{
    cout << "Invalid customer ID, return failed" << endl; 
    return;
}

string mediaType = " "; // Declare a string to store the media type
in_file >> mediaType; // Read media type from the file
if(mediaType != "D") // If the media type is not 'D'
{
    cout << "Invalid media type, return failed" << endl; 
    return;
}

char rest[100];
in_file.getline(rest, sizeof(rest)); // Read the rest of the line 
string temp = rest;
string bookDetail = temp.substr(1, temp.size() - 1); // book details from the rest of the line

if(returnCustomer->containsHistory(bookDetail) == false)
{
    cout << "Customer never borrowed the book before, return failed" << endl; 
    return;
}

string movieType = " "; // Declare a string to store the movie type
stringstream ss(bookDetail);
ss >> movieType; // Read movie type from the extracted book details
char sortingCriteria[100];
ss.getline(sortingCriteria, sizeof(sortingCriteria)); // Read sorting criteria from the extracted book details

if(movieType == "D" || movieType == "C" || movieType == "F") // If the movie type is valid
{

}
else
{
    cout << "Invalid movie, return failed" << endl; // Display an error message for an invalid movie type
}

string returnMovieInfo = " "; // Declare a string to store the movie information for returning
bool returnBool = false;
char returnChar = ' ';
if(movieType == "D") // If the movie type is 'D' (Drama)
{
    returnMovieInfo = "D, 1,"; // Initialize with common information
    returnMovieInfo = returnMovieInfo + sortingCriteria; // Add sorting criteria
    returnMovieInfo = returnMovieInfo + " 1234"; 
}

if(movieType == "C") // If the movie type is 'C' (Classic)
{
    returnMovieInfo = "C, 1, temp, temp, "; // Initialize with common information
    stringstream ss2(sortingCriteria);
    string firstname, lastname, month, year;
    ss2 >> month >> year;
    ss2 >> firstname >> lastname;
    returnMovieInfo += firstname;
    returnMovieInfo += " ";
    returnMovieInfo += lastname;
    returnMovieInfo += " ";
    returnMovieInfo += month;
    returnMovieInfo += " ";
    returnMovieInfo += year;
}

if(movieType == "F") // If the movie type is 'F' (Comedy)
{
    returnMovieInfo = "F, 1, temp,"; // Initialize with common information
    returnMovieInfo = returnMovieInfo + sortingCriteria; // Add sorting criteria
}
Movie *returnMovie;
Movie *tempMovie = MovieFactory::createMovie(returnMovieInfo, returnBool, returnChar); // Create a temporary Movie object for returning
if(returnBool == false) // If creating the movie object failed
{
    cout << "Couldn't borrow movie, movie info not valid" << endl; 
    return;
}
returnBool = false;
char movieChar = movieType[0];
returnBool = inventory_.setReturn(tempMovie, movieChar, returnMovie); // Try to return the movie
if(returnBool == false) // If returning failed
{
    cout << "Couldn't return movie, movie may not exist or out of stock" << endl; 
    return;
}
else
{

    returnCustomer->addHistory(bookDetail, true, "D"); // Update customer history for the returned movie

}
}
