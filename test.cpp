#include "string"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in_file;
    bool test = false;
    in_file.open("test.txt");

    string first,second;
    in_file >> first >> second;
    cout << first << second << endl;
    char rest[100];
    in_file.getline(rest, sizeof(rest));
    cout << rest << endl;

}