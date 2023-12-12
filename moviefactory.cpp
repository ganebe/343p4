#include "moviefactory.h"

MovieFactory::MovieFactory()
{
}

Movie* MovieFactory::createMovie(string input, bool &sucess, char& movieType)
{
    vector<string> tokens; // uses a vector of string to seprate infomration from the input string
    stringstream ss(input);
    string returnString;
    while(getline(ss,returnString, ',' ))
    {
        tokens.push_back(returnString); // seprate string in to substring using comma
    }
    
    if(tokens.size() < 5) // if substring is less that five
    {
        sucess = false;
        return new Movie(12, " ", " ");
    }

    for(int i = 1; i < tokens.size(); i++)
    {
        if(tokens.size() < 1)
        {
            sucess = false;
            return new Movie(12, " ", " ");
        }
        tokens[i] = tokens[i].substr(1, ( tokens[i].size() - 1 ) ); // get rid of the space before the string
    }   
    if(tokens[0] == "F" || tokens[0] == "C" || tokens[0] == "D")
    {

    }
    else
    {
        sucess = false; //if movie type is not a vaild movie type
        return new Movie(12, " ", " ");
    }

    if(stoi(tokens[1]) < 0) // if stock is lower than 1
    {
        sucess = false;
        return new Movie(12, " ", " ");
    }

    if(tokens[0] == "F" || tokens[0] == "D") 
    {
        if(stoi(tokens[4]) < 0) //if year is less than 0
        {
            sucess = false;
            return new Movie(12, " ", " ");
        }
        else
        {
            if(tokens[0] == "F")
            {
                Comedy * returnMovie = new Comedy(stoi(tokens[1]), tokens[2], tokens[3], stoi(tokens[4])); // create a new comedy movie
                sucess = true;
                movieType = 'F';
                return returnMovie;
            }
            Drama * returnMovie = new Drama(stoi(tokens[1]), tokens[2], tokens[3], stoi(tokens[4]));// create a new drama movie
            sucess = true;
            movieType = 'D';
            return returnMovie;
        }
    }
    else
    {
        vector<string> rleaseDateAndActor;
        stringstream lastToken(tokens[4]);
        stringstream lastToken2(tokens[4]);
        string temp, fristName, lastName, month, year;
        while(getline(lastToken,temp, ' ' ))
        {
            rleaseDateAndActor.push_back(temp); // uses space to seprate major actor first name, year, and month
        }
        if(stoi(rleaseDateAndActor[2]) < 0 || stoi(rleaseDateAndActor[3]) < 0) // if month or year smaller than 0
        {
            sucess = false;
            return new  Movie(12, " ", " ");
        }
        lastToken2 >> fristName >> lastName >> month >> year;
        string relaseDate = month + " " + year;
        string actorName = fristName + " " + lastName;
        Classic *  returnMovie = new Classic(stoi(tokens[1]), tokens[2], tokens[3], actorName, relaseDate); // create a new classcis movie
        movieType = 'C';
        sucess = true;
        
        return returnMovie;
    }
    
}
