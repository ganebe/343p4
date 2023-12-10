#include "moviefactory.h"

MovieFactory::MovieFactory()
{
}

Movie* MovieFactory::createMovie(string input, bool &sucess, char& movieType)
{
    vector<string> tokens;
    stringstream ss(input);
    string returnString;
    while(getline(ss,returnString, ',' )){
        tokens.push_back(returnString);
    }
    
    if(tokens.size() < 5){
        sucess = false;
        return new Movie(12, " ", " ");
    }

    for(int i = 1; i < tokens.size(); i++){
        if(tokens.size() < 1){
            sucess = false;
            return new Movie(12, " ", " ");
        }
        tokens[i] = tokens[i].substr(1, ( tokens[i].size() - 1 ) ); // get rid of the space before the string
    }   
    if(tokens[0] == "F" || tokens[0] == "C" || tokens[0] == "D"){

    }else{
        sucess = false;
        return new Movie(12, " ", " ");
    }

    if(stoi(tokens[1]) < 0){
        sucess = false;
        return new Movie(12, " ", " ");
    }

    if(tokens[0] == "F" || tokens[0] == "D"){
        if(stoi(tokens[4]) < 0){
            sucess = false;
            return new Movie(12, " ", " ");
        }else{
            if(tokens[0] == "F"){
                Comedy * returnMovie = new Comedy(stoi(tokens[1]), tokens[2], tokens[3], stoi(tokens[4]));
                sucess = true;
                movieType = 'F';
                return returnMovie;
            }
            Drama * returnMovie = new Drama(stoi(tokens[1]), tokens[2], tokens[3], stoi(tokens[4]));
            sucess = true;
            movieType = 'D';
            return returnMovie;
        }
    }else{
        vector<string> rleaseDateAndActor;
        stringstream lastToken(tokens[4]);
        string temp;
        while(getline(lastToken,temp, ' ' )){
            rleaseDateAndActor.push_back(temp);
        }
        if(stoi(rleaseDateAndActor[2]) < 0 || stoi(rleaseDateAndActor[3]) < 0){
            sucess = false;
            return new  Movie(12, " ", " ");
        }
        string relaseDate = ( (rleaseDateAndActor[2].append(" ")).append(rleaseDateAndActor[3]) );
        Classic *  returnMovie = new Classic(stoi(tokens[1]), tokens[2], tokens[3], rleaseDateAndActor[0], rleaseDateAndActor[1], relaseDate);
        movieType = 'C';
        sucess = true;
        
        return returnMovie;
    }


    
}
